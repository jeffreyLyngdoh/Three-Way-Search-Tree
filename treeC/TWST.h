
#include "nodeStructure.h"


struct node *createNode(int value);
void deleateNode(struct node *node);
struct node *insert(struct node *node, int value);
int largestValue(struct node *node);
int smallestValue(struct node *node);
struct node *removeEntry(struct node *node, int value);
void printTree(struct node *tree);
