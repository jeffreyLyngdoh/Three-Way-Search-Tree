
#include "TWST.h"
#include <stdio.h>
#include <stdlib.h>

/*
    This part is used for testing some of the functionallity of the tree
    A prompt is given with seveal options including creating or deleating a tree
    Adding or removing entries and printing their contents.
    The function will may display error messages if a tree is empty 

    This can be easy run by using "make run" or "make val" in a terminal

*/

int main()
{
    int option = 0;
    struct node *tree = NULL;
    int input;

    printf("Test out this three way search tree to start create a new tree then enter or remove integer values as you like.\n");
    printf("To start from scratch delete the tree and create a new one.\n");
    printf("A tree has to be created before values can be added or removed\n");
    printf("You can only have one tree at any given time\n\n");


    while(option != 6)
    {
        printf("Options: \n");
        printf("1. Create a new tree\n");
        printf("2. Insert value\n");
        printf("3. Remove value\n");
        printf("4. Print tree values\n");
        printf("5. Deleate current tree\n");
        printf("6. Quit\n\n");


        printf("select you number option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:

                if(tree == NULL)
                {
                    printf("Input a starting value: ");
                    scanf("%d", &input);
                    tree = createNode(input);
                    printf("Tree has been created\n\n");

                }
                else
                {
                    printf("Tree has already been created\n\n");
                }

                break;

            case 2:
                if(tree != NULL)
                {
                    printf("Input a value to add: ");
                    scanf("%d", &input);
                    tree = insert(tree, input);
                    printf("Value has been added\n\n");

                }
                else
                {
                    printf("Tree must be created to add values\n\n");
                }
                break;

            case 3:
                if(tree != NULL)
                {
                    printf("Input a value to remove: ");
                    scanf("%d", &input);
                    removeEntry(tree, input);
                    printf("Value has been removed\n\n");

                }
                else
                {
                    printf("Tree must be created to remove values\n\n");

                }
                break;
            case 4:
                if(tree != NULL)
                {
                    printTree(tree);
                    printf("\n");
                    printf("\n");

                }
                else
                {
                    printf("Tree is empty\n\n");
                }
                break;

            case 5:

                if(tree != NULL)
                {
                    deleateNode(tree);
                    tree = NULL;
                }

                printf("Tree has been deleated\n\n");

                break;

        }



    }



    return 0;
}
