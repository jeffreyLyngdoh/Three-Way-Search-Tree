
/*
We now have several functions declared assisocated with the tree
We can createTrees, deleate them
Insert and remove values 
We can obtain the largest and smallest value and we can print the tree in order
*/
#include "nodeStructure.h"


struct node *createNode(int value);
void deleateNode(struct node *node);
struct node *insert(struct node *node, int value);
int largestValue(struct node *node);
int smallestValue(struct node *node);
struct node *removeEntry(struct node *node, int value);
void printTree(struct node *tree);
