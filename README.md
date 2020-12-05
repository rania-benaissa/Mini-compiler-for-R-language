# Mini-compiler for R language
 A mini-compiler for R language using C, Flex and Bison

## Table of contents
* [Features](#features)
* [Technologies](#technologies)
* [Usage](#usage)
* [Exemple](#exemple)

## Features
This project is a simple compiler for R language. It includes:
* A lexical analyzer.
* A parser.
* Symbols table generation.
* Semantic errors detection such as:
  * Division by zero.
  * Type incompatibility between variables, constants and arrays.
  * Undeclared identifiers.
  * An identifier's double declaration (only when the identifier's type is mentionned).
* Intermediate code (quadruples).
* Code generation in assembly.
	
## Technologies
This compiler is created with:
* MingW
* Flex version: 2.4.1 
* Bison version: 2.5.4a
	
## Usage 
To run the compiler, clone this repo to your desktop and open it in your ***command prompt*** then run the ***com.bat*** file as following :

```
$ com

```
To analyze a code exemple in R, all that's left to do is to create a new file with a ***".txt"*** extension then run this code:

```
$ compil <file_name.txt

```

You can also edit the existing file "test.txt" and test it:

```
$ compil <test.txt

```

## Exemple

Let's compile the following code exemple writing in R (in test.txt file). 

```R

#This is a test 

INTEGER AB <- 2

NUMERIC C <- 385.5

INTEGER ABBA

D <- AB - 5 + 2 * ABBA
WHILE ( (AB != 0) )
{
  
     C <- C/2.0
}

```

### Generated symbols table

![Symbols Table](/readme_images/table_des_symboles.png)

### Generated intermediate code ( quadruples )

![Quadruples Table](/readme_images/table_des_quadruplets.png)

### Generated code in assembly

![Assembly code](/readme_images/code_objet.png)

