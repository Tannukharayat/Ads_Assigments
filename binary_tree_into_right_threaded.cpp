/* *****************PROBLEM STATEMENT*************************
Convert given binary tree into right threaded binary tree. Analyze time and space 
complexity of the algorithm.*/
#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int key;
    node*left;
    node*right;
    bool isThreaded;
};

node *create(node *root)
{
    if (root==NULL)
        return NULL;
    if(root ->left==NULL && root->right==NULL)
        return root;
    if(root->left!=NULL)
    {
        node *l=create(root->left);
        l->right=root;
        l->isThreaded=true;
    }
    if(root->right==NULL)
        return root;
    return create(root->right);
}

node *leftMost( node *root)
{
    while(root!=NULL && root->left!=NULL)

        root=root->left;
        return root;

}

void inorder(node *root)
{
    if(root==NULL)
        return;

    node *curr=leftMost(root);
    while(curr!=NULL)
    {
        cout<<curr->key<<" ";
        if(curr->isThreaded)
            curr=curr->right;
        else
            curr=leftMost(curr->right);
    }
}


void insertnode(int val,node** ptr)
{
    if(!(*ptr))
    {
        (*ptr)=new node;
        (*ptr)->key=val;
        (*ptr)->left=NULL;
        (*ptr)->right=NULL;
    }
    if(val>(*ptr)->key)
        insertnode(val,&(*ptr)->right);
    if(val<(*ptr)->key)
        insertnode(val,&(*ptr)->left);
}


void inorder1(node*ptr)
{
    if(ptr!=NULL)
    {
        inorder1(ptr->left);
        cout<<ptr->key<<" ";
        inorder1(ptr->right);
    }
}



int main()
{
    node *root=NULL;
    int n;
    char ch;
    do
    {
    cout<<"\nEnter the value :";
    cin>>n;
    insertnode(n,&root);
    cout <<"\nDo you want to add more nodes: ";
    cin>>ch;
    }while(ch=='y'|| ch=='Y');

    cout<<"\nInorder traversal of BST is : ";
    inorder1(root);


    cout<<"\n Inorder traversal of TBT is :"<<endl;
    create(root);
    inorder(root);
    return 0;
}


