# EMAIL SERVER

project developed in C++, for the discipline of data structures at UFMG.

The objective of this work is the implementation of an email server simulator. Nonetheless,
In addition to proper system memory management, there is now also a focus on optimizing the
search by users and messages. The simulated system will support the delivery, consultation and removal of
messages to users. The focus of the simulation is to verify the correct functioning of the system by
perform the various server operations in different situations.

# Implementation

The program was developed in the C++ language, compiled by the GNU GCC compiler
Compiler Collection, on the Linux operating system.

# Data structure

The implementation of the program was based on the data structure of a
hash table, which supports insert, remove, and lookup functions. That
data structure was assembled in a class called Server. following default standards.
In addition, we have the use of the Binary Tree data structure that was
implemented inside the hash table to handle collisions. This data structure
was built into a class called Users and supports user functions.
insertion, removal and search. Following default patterns.

# Classes

To modularize the implementation, 3 classes were used, the first of them
being the Email class, containing as attributes id_usuario, id_email, qt_palavras and
quantity, the class being used as the nodes of the binary tree.
We have the User class, which has a pointer to Email as an attribute.
It is also in this class that the functions were structured to assist in the assembly
of a binary tree, containing the users' emails. Finally, we have the Server class that has as an attribute a pointer to
user, in addition to implementing the functions necessary for the operation of a
Users hash table.

# Instructions for compiling and running

1. get the email-server folder. enter the folder and run the makefile using the "make" command (in the folder, there are already
   a folder input with a few test runs)
2. the "make" command will generate the \*.o file, and also executable in the bin folder.
3. For the "make run" command to work, the input folder must be in the root next to the makefile,
4. the command “make run” will generate the folder output in the root folder of the
   makefile with results
