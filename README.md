# 0x16. C - Simple Shell

## Description

This project is an implementation of the shell created as a Milestone Project for the C code at ALX Africa Software Engineering.
The shell is a project in the first trimester, that helps student to understand the advanced concepts behind the shell program include process, system call, bit manipulation, file management, error handling etc....
Shell is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh).
This program was written entirely in C Language.

## Requirements

### General

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)
* Write a README with the description of your project
* You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

## Features

* This program displays a prompt and waits for the user to types a command. A command line always ends with a new line (when user push ENTER key).
* The prompt is displayed again each time a command has been executed.
* The user could stop the program using Ctrl+D (end of file).
* The shell handles the command lines with arguments and pathways.
* The program prints the current enviroment when the user types env.
* The shell handles the setenv and unsetenv builtin commands
* This program executes the most common shell commands as ls, cd, pwd, rm, cp, mkdir, rmdir, exit, env, etc... with arguments.
* If an executable cannot be found, It prints an error message and displays the prompt again.
* This Shell supports commentaries using #,
* The Shell Handle the $? variable and $$ variable.
* This shell support shell logical operators as && or ||, and commands separator ;.
* The shell handle the alias builtin command
* When the user enters exit, the shell will end.

## Compilation

### This shell is compiled this way:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

