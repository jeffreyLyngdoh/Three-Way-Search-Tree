#include "TWST.h"
#include <stdio.h>
#include <stdlib.h>


struct node *createNode(int value)
{

    struct node *result = malloc(sizeof(struct node));

    result -> lowerLeftBound = value;
    result -> optionUpperRightBound = NULL;
    result -> left = result -> right = result -> center = NULL;

    return result;

}

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



int largestValue(struct node *node)
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


int smallestValue(struct node *node)
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



