/* ***************PROBLEM STATEMENT****************
Beginning with an empty binary search tree, Construct binary search tree by 
inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at
every node
v. Search a value
*/
#include <iostream>

using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};

void insertnode(int val,node** ptr)
{
    if(!(*ptr))
    {
        (*ptr)=new node;
        (*ptr)->data=val;
        (*ptr)->left=NULL;
        (*ptr)->right=NULL;
    }
    if(val>(*ptr)->data)
        insertnode(val,&(*ptr)->right);
    if(val<(*ptr)->data)
        insertnode(val,&(*ptr)->left);
}

int height(node* ptr)
{
    int hr,hl;
    if(ptr==NULL)
        return 0;
    if(ptr->left==NULL && ptr->right==NULL)
        return 0;
    hl=height(ptr->left);
    hr=height(ptr->right);
     if (hr>hl)
        return (hr+1);
    return (hl+1);
}

void minimum(node* ptr)
{
    node* current=ptr;
    while (current->left!=NULL)
    {
        current=current->left;
    }
    cout<<"\nMinimum value of the BST is: "<<current->data;
}

node* swapp(node*ptr)
{
    node*p;
    if(ptr!=NULL)
    {
        p=ptr->left;
        ptr->left=swapp(ptr->right);
        ptr->right=swapp(p);
    }
    return (ptr);

}

int srch_val(int val,node *ptr)
{
    if(!ptr)
        return 0;

    if(val>ptr->data)
        srch_val(val,ptr->right);

    if(val<ptr->data)
        srch_val(val,ptr->left);

    if(val==ptr->data)
        cout<<"\nFOUND";
}

void inorder(node*ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<ptr->data<<" ";
        inorder(ptr->right);
    }
}


void preorder(node*ptr)
{
    if(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}


void postorder(node*ptr)
{
    if(ptr!=NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->data<<" ";
    }
}

int cnt(node*ptr)
{
    int ct;
    if (ptr==NULL)
        return 0;

    ct= 1 + cnt(ptr->left) + cnt(ptr->right);
    return ct;
}



int main()
{
    char ch;
    int h,n,c,x,key;
    node* root=NULL;
    node* root1;
    do
    {
    cout<<"\n**************OPERATION****************";
    cout<<"\n1.Insert\n2.No. of nodes in longest path\n3.Minimum value\n4.Swapping of nodes\n5.Search\n6.Display\n7.Count";
    cout<<"\nEnter choice: ";
    cin>>x;
    switch(x)
    {
    case 1:
        cout<<"\nEnter the value: ";
        cin>>n;
        insertnode(n,&root);
        break;
    case 2:
         h=height(root);
        cout<<"\nNo. of nodes in the longest path is: "<<h+1;
        break;
    case 3:
        minimum(root);
        break;
    case 4:
        root1= swapp(root);
        inorder(root1);
        break;
    case 5:
        cout<<"\nEnter the value to be searched: ";
        cin>>key;
        srch_val(key,root);
        break;
    case 6:
        cout<<"\nInorder: "<<endl;
        inorder(root);
        cout<<"\nPreorder"<<endl;
        preorder(root);
        cout<<"\nPostorder"<<endl;
        postorder(root);
        break;
    case 7:
        c=cnt(root);
        cout<<"\nNo. of nodes in a tree is: "<<c;
        break;
    }
    cout<<"\nDo you want to continue?";
    cin>>ch;
    }while(ch=='y'||ch=='Y');

    return 0;
}
