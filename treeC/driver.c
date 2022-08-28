
#include "TWST.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    struct node *example = NULL;

    example = insert(example, 6);
    example = insert(example, 1);
    example = insert(example, 5);
    example = insert(example, 2);
    example = insert(example, 10);
    example = insert(example, 4);
    example = insert(example, 13);
    example = insert(example, 7);
    example = insert(example, 11);
    example = insert(example, 0);


    printTree(example);
    printf("\n");

    removeEntry(example, 2);
    removeEntry(example, 6);
    removeEntry(example, 5);
    removeEntry(example, 20);
    removeEntry(example, 13);
    removeEntry(example, 0);
    example = insert(example, 13);

    printTree(example);
    printf("\n");





    return 0;
}
