#include <iostream>
#include <stack>

using namespace std;

typedef int Status;

//5个常量定义
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1

//树结点数据结构
template<typedef T>
class BSTNode
{
public:
    T _key; //关键字
    BSTNode * _lchild;
    BSTNode * _rchild;
    BSTNode * _parent;

    //构造函数
    BSTNode(T key, BSTNode * lchild, BSTNode * rchild, BSTNode * parent):
    _key(key), _lchild(lchild), _rchild(rchild), _parent(parent){};
};

//二叉搜索树数据结构
template<typedef T>
class BSTree
{
private:
    BSTNode<T> * _root;
public:
    Status insert(T key);
    // Status remove(T key);
    // Status travel();  //顺序遍历（二叉树中序遍历）
    // Status search(T key); 
private:
    Status insert(BSTNode<T> * &root, T key);
    // Status search(BSTNode<T> * &root, T key);
    // Status remove(BSNode<T> * root, T key);};
    // Status deleteNode(BSNode<T> * root);
};
template<typedef T>
Status BSTree<T>::insert(BSTNode<T> * &root, T key)
{   
    BSTNode<T> * cur = root;
    
    if(NULL == root)
    {
        root->_key = T;
    } 
    else if(cur->_key < root->_key)
    {
        cur = root->_lchild;
        cur->_parent = root;
        insert(root->_lchild, key);
    }    
    else
    {
        cur = root->_rchild;
        cur->_parent = root;
        insert(root->_rchild, key);
    }
        
}

template<typedef T>
Status BSTree<T>::insert(T key)
{
    BSTNode<T> * cur = new BSTNode<T>(key, NULL, NULL, NULL);
    if(NULL == cur) return OVERFLOW;
    
    insert(_root, key);
}


template<typedef T>
Status BSTree<T>::search(BSNode<T> * root, T key)
{
    if(NULL == root) return FALSE;
    else if(key == root->_key) return TRUE;
    else if(key < root->_key) return search(root->lchild, key);
    else return search(root->rchild, key);
}

template<typedef T>
Status BSTree<T>::search(T key)
{
    if(NULL == _root) return FALSE;
    return search(_root, key);
}

// templata<class T>
// Status BSTree<T>::remove(T key)
// {
//     if(FALSE == search(key)) return FALSE;
//     remove(root, key);
//     return TRUE;
// }

// template<typedef T>
// Status BSTree<T>::remove(BSNode<T> * root, T key)
// {
//     if(NULL == root) return FALSE;
//     else if(key == root->_key) return deleteNode(root);
//     else if(key < root->_key) return remove(root->lchild, key);
//     else return remove(root->rchild, key);
// }

// template<typedef T>
// Status BSTree<T>::deleteNode(BSNode<T> * root)
// {
//     if(NULL == root->rchild)
//     {
//         if()
//         root->parent->rchild = root->lchild;
//         root->rchild->parent = root->parent;
//     }
//     else if(NULL == root->lchild)
//     {
//         root->parent->l
//     }
// }