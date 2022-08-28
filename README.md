# Three-Way-Search-Tree (TWST)

This is a basic data structure I made to test my knowledge in C
The program creates a Three way search tree of Integers
A tree way searched tree is defined as followed.

A tree is either empty (NULL) or a node which can contain two integers and three branches.
The first integer (lowerLeftBound) must always be there but the second integer (optionUpperRightBound) may not be, it is a int pointer which can point to a value or be NULL.
When both values are present the left integer must strictly be smaller than the right value. 
When both integers are present the first branch(left) contains integers smaller than the lowerLeftBound.
The second branch (center) contains values greater than the lowerLeftBound but less than the optionUpperRightBound.
The third branch (right) contains values greater than the optionUpperRightBound 
We do not have duplicate values

In the program folder we have nodeStructure.h which details the format of our data structure.
We also have TWST.h which contains the delecations of the functions assoicated with the tree.
We have TWST.c where all the functions are made and a driver which allows for testing of most functions.

There is a Makefile, the execuatbles many not work on other devices so running make before you start is advised. 
calling make run will allow for inutative testing and make val demonsrates the memoery management.
