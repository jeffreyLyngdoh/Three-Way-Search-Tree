#include "TWST.h"
#include <stdio.h>
#include <stdlib.h>

/*
    We are able to intialize head or root of a tree with this function
    The a node is allocated space and the lower left value is assigned
    The right value is null and the branches are set to NULL
*/

struct node *createNode(int value)
{

    struct node *result = malloc(sizeof(struct node));

    result -> lowerLeftBound = value;
    result -> optionUpperRightBound = NULL;
    result -> left = result -> right = result -> center = NULL;

    return result;

}

/*
    This function deleates tree nodes and frees memory if the node is not NULL
    This function frees memory recurivly freeing the left and center first
    We then free the optional right value
    We then deleate the right tree and finally the node itself
*/

void deleateNode(struct node *node)
{
    if(node != NULL)
    {
        deleateNode(node -> left);
        deleateNode(node -> center);
        free(node -> optionUpperRightBound);
        deleateNode(node -> right);
        free(node);
    }
}


/*
    This function allows for the insertion of integers into the tree it takes in a node and an integer to insert
    If the current node is NULL we simply create a new node with the integer
    If node node is not NULL but the optional right value is we allocate space and assign the value to it. If the right value is 
    smaller than the left one we swap the values.
    Else if the value is smaller than the left bound we will recursivly insert it to the left node.
    If the value is larger than the left but smaller than the right value we will insert it to the center branch
    Else if the node is greater than the right value we insert it into the right branch.
    Values that are equal to an already existing value will not be added.
*/
struct node *insert(struct node *node, int value)
{
    if(node == NULL)
    {
        return createNode(value);
    }
    else if(node -> optionUpperRightBound == NULL)
    {
        if(node -> lowerLeftBound < value)
        {
            node -> optionUpperRightBound = malloc(sizeof(int));

            *(node -> optionUpperRightBound) = value;

            return node;
        }
        else if(node -> lowerLeftBound > value)
        {
            node -> optionUpperRightBound = malloc(sizeof(int));

            *(node -> optionUpperRightBound) = node -> lowerLeftBound;

            node -> lowerLeftBound = value;

            return node;

        }
        else
        {
            return node ;
        }



    }
    else
    {
        int rightValue =  *(node -> optionUpperRightBound);
        int leftValue = node -> lowerLeftBound;

        if(value < leftValue)
        {
            node -> left = insert(node -> left, value);
            return node;
        }
        else if(leftValue < value && value < rightValue)
        {
            node -> center = insert(node -> center, value);
            return node;
        }
        else if(rightValue < value)
        {
            node -> right = insert(node -> right, value);
            return node;
        }
        else
        {
            return node;
        }

    }


}




/*
    This function returns the largest value within the tree
    This is done node curr and prev
    curr will continue moving right until it is NULL prev will be the node before it
    prev will be the right most value
    We can then return the optional right value if it is present or the left value
    If the given node is NULL we just return zero with a message
*/
int largestValue(struct node *node)
{
    if(node != NULL)
    {
        struct node *curr = node;
        struct node *prev = NULL;

        while(curr != NULL)
        {
            prev = curr;
            curr = curr -> right;

        }

        if(prev -> optionUpperRightBound != NULL)
        {
            return *(prev -> optionUpperRightBound);

        }
        else
        {

            return prev -> lowerLeftBound;

        }
    }
    else 
    {
        printf("Tree is empty\n");
        return 0;
    }

}

/*
    This function returns the smallest value from a given tree
    Similar to largest we do this by locating the leftmost node and returning its left value
*/
int smallestValue(struct node *node)
{
    if(node !- NULL)
    {
        struct node* curr = node;
        struct node* prev;

        while(curr != NULL)
        {
            prev = curr;
            curr = curr -> left;
        }

        return prev -> lowerLeftBound;
    }
    else 
    {
        printf("Tree is empty\n");

        return 0;
    }
}

/*
    This function removes a given value from an tree then returns the altered tree
    It works with two cases based on left and right values.

    We start with the left
    If the removed value is smaller than the current left value we move to the left branch
    If the left value is the value that needs to be removed we do the following.
    
    Base case: 
    if the left, right, and center branches are all NULL we have two options
    we attempt to swap the left value with the right value and remove it
    If there is no optional right value we just deleate the node and return NULL

    If the left branch is present we obtain the largest value from the left branch, replace our left value with this largest value and 
    remove that largest value from the left branch

    Else if the center branch is present we obtain the smallest value from the center branch to replace our current left value

    Else if both left and center branches are NULL we have to push everything left a position. We make the right value our left value and 
    our right value the smallest value on the right branch. We then remove and replace the entire right branch.
    I consider this to be the worst case senerio.


    Now the right case 
    If the value is larger than the left but smaller than the right be send it to the center branch. 
    If the value is larger than the right we send it to the right branch.
    
    Base case:
    If the left right and center branch are all NULL we simply free the optionalRightValue and make it NULL
    Similar to the left value we try and replace the rightvalue with the largest value on the center or the smallest value on the right
    We then remove those replacement values from the other branches
    If the left branch is the only one present we push the values down a position.


*/
struct node *removeEntry(struct node *node, int value)
{
    if(node != NULL)
    {
        if(value < node -> lowerLeftBound)
        {
            node -> left = removeEntry(node -> left, value);
            return node;
        }
        else if(node -> lowerLeftBound == value)
        {
            if(node -> right == NULL && node -> left == NULL && node -> center == NULL)
            {
                if(node -> optionUpperRightBound != NULL)
                {
                    node -> lowerLeftBound = *(node -> optionUpperRightBound);
                    node -> optionUpperRightBound = NULL;
                    return node;
                }
                else
                {
                    deleateNode(node);
                    return NULL;
                }
            }
            else if(node -> left != NULL)
            {
                int replace = largestValue(node -> left);

                node -> lowerLeftBound = replace;

                node -> left = removeEntry(node -> left, replace);

                return node;

            }
            else if(node -> center != NULL)
            {
                int replace = smallestValue(node -> center);

                node -> lowerLeftBound = replace;

                node -> center  = removeEntry(node -> center, replace);

                return node;


            }
            else if(node -> right != NULL)
            {
                int replace = *(node -> optionUpperRightBound);

                node -> lowerLeftBound = replace;

                replace = smallestValue(node -> right);

                *(node -> optionUpperRightBound) = replace;

                node -> right = removeEntry(node -> right, replace);

                return node;
            }

        }
        else if (node -> optionUpperRightBound != NULL)
        {
            int rightValue = *(node -> optionUpperRightBound);
            int leftValue = node -> lowerLeftBound;

            if(leftValue < value && value < rightValue)
            {
                node -> center = removeEntry(node -> center, value);

                return node;
            }
            else if(rightValue < value)
            {
                node -> right = removeEntry(node -> right, value);

                return node;
            }
            else if(rightValue == value)
            {
                if(node -> right == NULL && node -> left == NULL && node -> center == NULL)
                {
                    free(node -> optionUpperRightBound);

                    node -> optionUpperRightBound = NULL;

                    return node;
                }
                else if(node -> right != NULL)
                {
                    int replace = smallestValue(node -> right);

                    *(node -> optionUpperRightBound) = replace;

                    node -> right = removeEntry(node -> right, replace);

                    return node;

                }
                else if(node -> center != NULL)
                {
                    int replace = largestValue(node -> center);

                    *(node -> optionUpperRightBound) = replace;

                    node -> center = removeEntry(node -> center, replace);

                    return node;

                }
                else if(node -> left != NULL)
                {
                    int replace = node -> lowerLeftBound;

                    *(node -> optionUpperRightBound) = replace;

                    replace = largestValue(node -> left);

                    node -> lowerLeftBound = replace;

                    node -> left = removeEntry(node -> left, replace);

                    return node;

                }



            }



        }




    }

    return node;



}


/*
    This function prints all the entires in the tree
    If the given tree is not NULL we start by recusivly printing the left branch
    We then print the left value
    We then print the center branch 
    We then print the right value if it is present 
    Then the right branch (This step many not be nesseary if the right branch is NULL)

*/
void printTree(struct node *tree)
{
    if(tree != NULL)
    {
        printTree(tree -> left);
        printf("%d " , tree -> lowerLeftBound);
        printTree(tree -> center);

        if(tree -> optionUpperRightBound != NULL)
        {
            printf("%d " , *(tree -> optionUpperRightBound));


        }

        printTree(tree -> right);


    }
}



