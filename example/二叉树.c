#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;
typedef struct treenode
{
    ElementType data;
    struct treenode *leftchild;
    struct treenode *rightchild;
} TreeNode;

TreeNode *create_bitree()
{
    ElementType ch;
    TreeNode *T;

    scanf("%c",&ch);
    if(ch!='#')
    {
        T=(TreeNode*)malloc(sizeof(TreeNode));
        T->data=ch;
        T->leftchild=create_bitree();
        T->rightchild=create_bitree();
    }
    else
    {
        T=NULL;
    }
    return T;
}

void pre_order_traversal(TreeNode *T)
{

    ElementType data;
    if(T!=NULL)
    {
        data=T->data;
        printf("%c ",data);
        pre_order_traversal(T->leftchild);
        pre_order_traversal(T->rightchild);
    }
}
void center_order_traversal(TreeNode *T)
{

    ElementType data;
    if(T!=NULL)
    {
        data=T->data;
        pre_order_traversal(T->leftchild);
        printf("%c ",data);

        pre_order_traversal(T->rightchild);
    }
}
void post_order_traversal(TreeNode *T)
{

    ElementType data;
    if(T!=NULL)
    {
        data=T->data;
        pre_order_traversal(T->leftchild);
        pre_order_traversal(T->rightchild);
        printf("%c ",data);

    }
}
int main(){
    TreeNode *treeNode=  create_bitree();
    pre_order_traversal(treeNode);
    return 0;

}
