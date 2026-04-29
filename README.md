*This project has been created as part of the 42 curriculum by <lschawer>.*
# Get Next Line


## Description
This project is about programming a function that returns a line read from a file descriptor.

This project allowed me to add a highly useful function to my collection in my libft library, and it also taugth me an important concept in C programming: static variables.


## Instructions
**Compilation**

The Makefile compiles with the flags `-Wall`, `-Wextra`, and `-Werror`, using `cc`.
The Makefile contains the following rules:

make all = default rule to create `get_next_line.a`
make clean = deletes the object files generated during compilation
make fclean = deletes the object files AND the library (`get_next_line.`)
make re = performs `fclean` followed by an `all` to re-compile everything from scratch

**Using get_next_line**
To use Libft in your project, include the header and link the library:
cc main.c -L. -lft


## Resources
To build this library I have used the following resources:
• subject.pdf: Detailed assignment requirements.
• man7.org: Linux manual pages for standard functions.
• 42-cursus.gitbook.io: Simplified descriptions and logic for non-standard functions.
• libftTester (Tripouille): Unit testing for all functions.
• CS50 & freeCodeCamp: Conceptual learning for linked lists.
• AI Assistance: Used for clarifying concepts (e.g., understanding double pointers lst).


## Detailed about the algorithm
A detailed explanation and justification of the algorithm selected for this project
must also be included.
