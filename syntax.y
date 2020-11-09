%{  
    #include "quadruplets.h"
    #include "tableDesSymboles.h"
    #include "generationCodeObjet.h"
 
  
    // reecupère les variables déclarées dans l'analyseur lexical
    extern int nb_lines ;
    extern int nb_chars ;
    extern char* currentText;
    extern int lexical_error;

    // type d'un ensemble à sa declaration
    char typeEns[20];
    // type d'un ensemble à sa declaration
    char idfName[20];
    // verifie si il recoit 1 cte ou plus
    int unique = 1;
    //guess if it s an arithm or logical exp
    int express = 1;
    char type[20];
    
    int yylex(); // lance l'analyseur lexical
    void yyerror(char *s);// fonction d'affichage d'erreurs


%}

%token <value>idf <value>mc_float <value>mc_int <value>mc_char 
<value>mc_bool mc_if mc_ifelse mc_else mc_for mc_in mc_while 
<value>int_pos <value>int_neg <value>float_value <value>char_value 
<value>bool_value mc_and mc_or <value>sup_equal <value>inf_equal 
<value>equal <value>diff <value>affect saut_ligne

%union{

    char* value;

    listes bool;

    int number;

    br next;
 
}

%type <value> EXP_ARITHME INFO INT_VALUE MGAFF   MGAFFEC_COND
        VALUE MDEXP_COMP MGEXP_COMP INCR DECR FOR_LOOP INDICE 

%type <bool> EXP_LOG EXP_COMP  MGIF_COND MMWHILE_LOOP AFFEC_COND1

%type <number> M MGWHILE_LOOP


%type <next> MDIF_COND BLOC_INSTS IF_COND MDBLOC_INSTS INST  
     COND ELSE_COND MDWHILE_LOOP  MGFOR_LOOP AFFEC_COND2 AFFEC_COND3

%left '+' '-'

%left '*' '/' '%'

%left mc_or mc_and

%%


AXIOME:  MULTI_SAUT_LIGNE  PRG 
        | PRG;

PRG:  INST PRG  
    | {YYACCEPT;}/* ne contient aucune instruction*/

;

// ici ou se trouvent les instructions
INST: DEC MULTI_SAUT_LIGNE  {$$.next = NULL;}
      |AFF MULTI_SAUT_LIGNE {$$.next = NULL;}
      |INCR MULTI_SAUT_LIGNE {$$.next = NULL;}
      |DECR MULTI_SAUT_LIGNE  {$$.next = NULL;}
      |COND MULTI_SAUT_LIGNE {$1.next = removePosQuad($1.next,currentQuad);}
      |AFFEC_COND MULTI_SAUT_LIGNE  {$$.next = NULL;}
      | FOR_LOOP MULTI_SAUT_LIGNE {$$.next = NULL;}
      | WHILE_LOOP MULTI_SAUT_LIGNE {$$.next = NULL}
   
;



MULTI_SAUT_LIGNE: saut_ligne MULTI_SAUT_LIGNE
    | saut_ligne
                  
;

/* DECLARATIONS */
DEC: mc_int idf {strcpy(typeEns,$1);strcpy(idfName,$2);} DEC_D 
    | mc_float idf   {strcpy(typeEns,$1);strcpy(idfName,$2);} DEC_D
    | mc_char idf  {strcpy(typeEns,$1);strcpy(idfName,$2);} DEC_D
    | mc_bool idf  {strcpy(typeEns,$1);strcpy(idfName,$2);} DEC_D
    | mc_int idf affect  {inserer($2,"VARIABLE",$1,1,"YES",nb_lines,nb_chars);} INT_VALUE
    | mc_char idf affect char_value {inserer($2,"VARIABLE",$1,1,"YES",nb_lines,nb_chars);}
    | mc_bool idf affect bool_value {inserer($2,"VARIABLE",$1,1,"YES",nb_lines,nb_chars);}
    | mc_float idf affect float_value  {inserer($2,"VARIABLE",$1,1,"YES",nb_lines,nb_chars);}
  
;

DEC_D: { inserer(idfName,"VARIABLE",typeEns,1,"YES",nb_lines,nb_chars); } ENS
    // this will replace VARIABLE -> TABLEAU
    | '[' int_pos ']' {inserer(idfName,"TABLEAU",typeEns,atoi($2),"YES",nb_lines,nb_chars);}

;


INT_VALUE: int_neg {$$ = $1;}
    | int_pos {$$ = $1;}
;

ENS: ',' idf ENS {inserer($2,"VARIABLE",typeEns,1,"YES",nb_lines,nb_chars);}
    |
;

/* EXPRESSIONS ARITHMETIQUES */

EXP_ARITHME :  EXP_ARITHME '+' EXP_ARITHME { 
                    strcpy(type,checkCompatible($1,$3,nb_lines,nb_chars));
                    $$= getTemp(); 
                    inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                    genererQuad("+",$1,$3,$$);}


             | EXP_ARITHME '-' EXP_ARITHME { 
                unique = 0; 
                strcpy(type,checkCompatible($1,$3,nb_lines,nb_chars)); 
                $$= getTemp(); inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                genererQuad("-",$1,$3,$$);}


             | EXP_ARITHME '*' EXP_ARITHME { 
                unique = 0; 
                strcpy(type,checkCompatible($1,$3,nb_lines,nb_chars)); 
                $$= getTemp(); 
                inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                genererQuad("*",$1,$3,$$);}


             | EXP_ARITHME '/' EXP_ARITHME { 
                 unique = 0; 
                 divisionParZero($3,nb_lines,nb_chars);
                 strcpy(type,checkCompatible($1,$3,nb_lines,nb_chars)); 
                 $$= getTemp(); 
                 inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                 genererQuad("/",$1,$3,$$);}


             | EXP_ARITHME '%' EXP_ARITHME { 
                 unique = 0; 
                 strcpy(type,checkCompatible($1,$3,nb_lines,nb_chars)); 
                 $$= getTemp(); 
                 inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars); 
                 genererQuad("%",$1,$3,$$);}


             | '(' EXP_ARITHME ')' {$$ = $2;unique = 0;}
             
             | INFO { $$ = $1; }


INFO : float_value { $$ = $1; if(express && unique){inserer(idfName,"VARIABLE","NUMERIC",1,"NO",nb_lines,nb_chars); } express=1;} 
    | INT_VALUE {  $$ = $1; if(express && unique){inserer(idfName,"VARIABLE","INTEGER",1,"NO",nb_lines,nb_chars); } express=1;}
    | idf { $$ = $1;}
    | idf  '[' INDICE ']' { char tmp [50];
                            snprintf(tmp, sizeof(tmp),"%s[%s]",$1,$3);
                            strcpy($$,tmp);
                            checkTableau($1,$3,nb_lines,nb_chars);}

// l'indice d un tableau peut etre une valeur ou un idf 

INDICE : INT_VALUE {  $$ = $1;}
        | idf { $$ = $1;};


/* EXPRESSION DE COMPARAISON */
EXP_COMP : '(' EXP_ARITHME MGEXP_COMP MDEXP_COMP {  checkCompatible($2,$4,nb_lines,nb_chars);
                                                    $$.true=NULL;
                                                    $$.true = addPosQuad($$.true);
                                                    genererQuad($3,$2,$4," ");
                                                    $$.false=NULL;
                                                    $$.false = addPosQuad($$.false);
                                                    genererQuad("BR","",""," ");
                                                 }
;

MGEXP_COMP :    '<' {$$ = "<";}
             |  '>' {$$ = ">";}
             |  sup_equal {$$ =  $1;}
             | inf_equal {$$ = $1;}
             | equal {$$ = $1;}
             |  diff {$$ = $1;}
;

MDEXP_COMP : EXP_ARITHME  ')' {$$ = $1;} ;
            
/* EXPRESSION LOGIQUE */

EXP_LOG : EXP_LOG mc_and M EXP_LOG {$1.true = removePosQuad($1.true,$3);
                                    $$.true = $4.true;
                                    $$.false = fusion($1.false,$4.false); 
                                    } 
          | EXP_LOG mc_or M EXP_LOG {$1.false = removePosQuad($1.false,$3);
                                     $$.false = $4.false;
                                     $$.true = fusion($1.true,$4.true);} 
          | EXP_COMP {$$ = $1;}
          
         ;

M :  {$$ = currentQuad;}
;

/* AFFECTATION */

AFF :   MGAFF  MDAFF
    
;

MGAFF : idf   '[' INDICE ']'  affect  { 
                                        char tmp [50];
                                        snprintf(tmp, sizeof(tmp),"%s[%s]",$1,$3);
                                        strcpy(idfName,tmp);
                                        checkTableau($1,$3,nb_lines,nb_chars);} 

        |idf affect  {strcpy(idfName,$1);}

;

MDAFF : EXP_LOG  {   
                    $1.true = removePosQuad($1.true,currentQuad); 
                    genererQuad("<-","TRUE"," ",idfName); 
                    $1.true= addPosQuad($1.true);
                    genererQuad("BR",""," ",""); 

                    $1.false = removePosQuad($1.false,currentQuad);
                    genererQuad("<-","FALSE"," ",idfName);
                    $1.true = removePosQuad($1.true,currentQuad);   

                    express = 0;
                    inserer(idfName,"VARIABLE","LOGICAL",1,"NO",nb_lines,nb_chars);} 

        | EXP_ARITHME {genererQuad("<-",$1," ",idfName); unique = 1;}
        | VALUE {genererQuad("<-",$1," ",idfName); }
;


/*valeurs elementaires */

VALUE:  char_value {$$ = $1;inserer(idfName,"VARIABLE","CHARACTER",1,"NO",nb_lines,nb_chars);}
        | bool_value {$$ = $1;inserer(idfName,"VARIABLE","LOGICAL",1,"NO",nb_lines,nb_chars);}
      
      
;


/*INCREMENTATION + DECREMENTATION */

INCR : idf '+' affect int_pos { strcpy(type,checkCompatible($1,$4,nb_lines,nb_chars)); 
                                $$= getTemp(); 
                                inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                genererQuad("+",$1,$4,$$);
                                genererQuad($3,$$,"",$1);} 


       | idf '[' INDICE ']' '+' affect int_pos { 
                                checkTableau($1,$3,nb_lines,nb_chars);
                                strcpy(type,checkCompatible($1,$7,nb_lines,nb_chars)); 
                                $$= getTemp(); 
                                inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                char tmp [50];
                                snprintf(tmp, sizeof(tmp),"%s[%s]",$1,$3);
                                genererQuad("+",tmp,$7,$$);
                                genererQuad($6,$$,"",tmp);}  ;

DECR : idf '-' affect int_pos { strcpy(type,checkCompatible($1,$4,nb_lines,nb_chars)); 
                                $$ = getTemp(); 
                                inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                genererQuad("-",$1,$4,$$);
                                genererQuad($3,$$,"",$1);} 

       | idf '[' INDICE ']' '-' affect int_pos  { 
                                checkTableau($1,$3,nb_lines,nb_chars);
                                strcpy(type,checkCompatible($1,$7,nb_lines,nb_chars)); 
                                $$= getTemp(); 
                                inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                char tmp [50];
                                snprintf(tmp, sizeof(tmp),"%s[%s]",$1,$3);
                                genererQuad("-",tmp,$7,$$);
                                genererQuad($6,$$,"",tmp);};


/* BLOC d'INSTRUCTIONS */

BLOC_INSTS :  MGBLOC_INSTS  MDBLOC_INSTS { $$ = $2;};

MGBLOC_INSTS : MULTI_SAUT_LIGNE
                |
;

 MDBLOC_INSTS : INST   MDBLOC_INSTS {$$=$1;}
                | {$$.next = NULL;}
;


/* CONDITION */

COND : IF_COND  saut_ligne  ELSE_COND { 

                                        $$.next = fusion($1.next,$3.next);
                                      } 
;

/* IF CONDITION */

IF_COND : MGIF_COND   MDIF_COND { 
                                  $$.next = addPosQuad($$.next); 
                                  genererQuad("BR"," "," "," "); 
                                  $1.false = removePosQuad($1.false,currentQuad);

                                  $$.next = fusion($$.next,$2.next);
                            }  ;

MGIF_COND :  mc_if '(' EXP_LOG ')' MULTI_SAUT_LIGNE {
                                                        $3.true = removePosQuad($3.true,currentQuad); 
                                                        $$ = $3;
                                                    } 

;

MDIF_COND : '{' BLOC_INSTS  '}' {$$ =$2;};

/* ELSE ET ELSE IF CONDITION*/ 

ELSE_COND :  mc_else   MULTI_SAUT_LIGNE  '{' BLOC_INSTS '}' { $$ = $4;}
            | mc_else  COND  { $$ = $2;}
            |  { $$.next = NULL;}
;


/* AFFECTATION AVEC CONDITION */ 

AFFEC_COND : MGAFFEC_COND AFFEC_COND1 AFFEC_COND2 AFFEC_COND3{
                                                $2.false = removePosQuad($2.false,$3.quad);
                                                $3.next = removePosQuad($3.next,currentQuad);
                                                }
          
;

MGAFFEC_COND : idf affect mc_ifelse  { strcpy(idfName,$1);}

                | idf '[' INDICE ']' affect mc_ifelse  {char tmp [50];
                                                        snprintf(tmp, sizeof(tmp),"%s[%s]",$1,$3); 
                                                        strcpy(idfName,tmp);
                                                        checkTableau($1,$3,nb_lines,nb_chars);}
;


AFFEC_COND1 : '(' EXP_LOG ','  { $2.true =  removePosQuad($2.true,currentQuad);
                                 $$ = $2;       };

AFFEC_COND2 : EXP_ARITHME ',' { genererQuad("<-",$1,"",idfName);
                                $$.next = NULL;
                                $$.next = addPosQuad($$.next);
                                genererQuad("BR","","","");
                                $$.quad = currentQuad;}
              | EXP_LOG ',' {   
                                $$.next = NULL;
                                $1.true = removePosQuad($1.true,currentQuad);
                                genererQuad("<-","TRUE","",idfName);
                                $$.next = addPosQuad($$.next);
                                genererQuad("BR","","","");

                                $1.false = removePosQuad($1.false,currentQuad);
                                genererQuad("<-","FALSE","",idfName);
                                $$.next = addPosQuad($$.next);
                                genererQuad("BR","","","");


                                $$.quad = currentQuad;

                                }
;

AFFEC_COND3 :  EXP_ARITHME ')' {            
                                    genererQuad("<-",$1,"",idfName); }

              | EXP_LOG ')'  {  $$.next = NULL;
                                $1.true = removePosQuad($1.true,currentQuad);
                                genererQuad("<-","TRUE","",idfName);
                                $$.next = addPosQuad($$.next);
                                genererQuad("BR","","","");

                                $1.false = removePosQuad($1.false,currentQuad);
                                genererQuad("<-","FALSE","",idfName);
                                $$.next = addPosQuad($$.next);
                                genererQuad("BR","","","");

                                $$.next = removePosQuad($$.next,currentQuad);
                                }
;

/* FOR LOOP */

FOR_LOOP :  MGFOR_LOOP MDFOR_LOOP  {
                                       strcpy(type,checkCompatible($1.idf,"1",nb_lines,nb_chars)); 
                                       $$= getTemp(); 
                                       inserer($$,"VARIABLE",type,1," / ",nb_lines,nb_chars);
                                       genererQuad("+",$1.idf,"1",$$);
                                       genererQuad("<-",$$,"",$1.idf);
                                       genererQuad("BR","","",intToChar($1.quad+1));
                                       $1.next = removePosQuad($1.next,currentQuad);
                                    }
;

MGFOR_LOOP : mc_for '(' idf mc_in int_pos ':' int_pos ')'  MULTI_SAUT_LIGNE {
                                                            
                                                            genererQuad("<-",$5," ",$3);
                                                            $$.quad = currentQuad;
                                                            genererQuad("<=",$3,$7,intToChar($$.quad+3));
                                                            $$.next = NULL;
                                                            $$.next = addPosQuad($$.next);
                                                            genererQuad("BR"," "," "," ");
                                                            $$.idf = $3;

                                                        }
;


MDFOR_LOOP : '{' BLOC_INSTS '}'  ;


/* WHILE LOOP */

WHILE_LOOP : MGWHILE_LOOP MMWHILE_LOOP MDWHILE_LOOP {
                                                        genererQuad("BR"," "," ",intToChar($1+1));
                                                        $2.false = removePosQuad($2.false,currentQuad);
                                                    }
;

MGWHILE_LOOP : mc_while '('  {  $$ = currentQuad;}

;

MMWHILE_LOOP :  EXP_LOG ')'  MULTI_SAUT_LIGNE { $1.true = removePosQuad($1.true,currentQuad);
                                               
                                                $$ = $1;}
;


MDWHILE_LOOP : '{' BLOC_INSTS '}' { $$=$2;};

%%

int main () 
{
    yyparse();

    if(error && lexical_error){
        
        afficherTS();

        afficherQuads();

        generateCode();
    }

}


void yyerror(char *s){

    printf("Erreur syntaxique a la ligne %d, colonne %d, sur l'entite : %s \n",nb_lines,nb_chars,currentText);
    error = 0;
}

int yywrap()
{}

