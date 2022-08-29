
/*
A node within our tree is defined as followed
We have a lowerBound integer and a pointer to a optionalRight integer
This optional value can be NULL or be assigned
We then have three branches left, right, and center
*/

struct node
{
    int lowerLeftBound;
    int *optionUpperRightBound;
    struct node *left, *right,*center;

};
