#include "binTree.h"

#define LENGTN 7

int main()
{
    BinTreeDataType cArr[LENGTN] = {'a','b','c','d','e','f','g'};

    //测试建树
    BinTree B;
    B = createBinTree(B, cArr, LENGTN);

    //测试递归遍历
    printf("\n先序递归遍历-------------------\n");
    preOrder(B);
    printf("\n中序递归遍历-------------------\n");
    inOrder(B);
    printf("\n后序递归遍历-------------------\n");
    postOrder(B);

    //测试非递归遍历
    printf("\n非递归先序遍历-------------------\n");
    preOrderNot(B);
    printf("\n非递归中序遍历-------------------\n");
    inOrderNot(B);
    printf("\n非递归后序遍历-------------------\n");
    postOrderNot(B);
    printf("\n层次遍历-------------------\n");
    sequenceOreder(B);
    
    printf("\n");
    return 0;
}