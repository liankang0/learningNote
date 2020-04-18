#include "binSearchTree.h"

int main()
{
    class BSTree<int> BST;
    int arr[5] = {3, 4, 1, 5, 2};
    for(int i = 0; i < 5; i++)
    {
        BST.insert(arr[i]);
    }
       

    return 0;
}