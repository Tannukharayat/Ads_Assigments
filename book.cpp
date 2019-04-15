/* *************PROBLEM STATEMENT*****************
A book consists of chapters, chapters consist of sections and sections consist of 
subsections. Construct a tree and print the nodes. Find the time and space 
requirements of your method.*/

# include <iostream>
# include <cstdlib>
# include <string.h>
using namespace std;

class node
{
    public:
    char name[10];
    int ch_count;
    node *child[10];
}*root;

class tree
{
    public:
        void create();
        void display(node*ptr);

        tree()
        {
            root = NULL;
        }
};

void tree::create()
{
 int chap,i,j,k;
 root = new node();
 cout<<"\nEnter name of book: ";
 cin>>root->name;
 cout<<"\nEnter no. of chapters:  ";
 cin>>chap;
 root->ch_count = chap;
 for(i=0;i<chap;i++)
 {
  root->child[i] = new node;
  cout<<"\nEnter Chapter name: ";
  cin>>root->child[i]->name;
  cout<<"\nEnter no. of sections in  Chapter "<<root->child[i]->name;
  cin>>root->child[i]->ch_count;
  for(j=0;j<root->child[i]->ch_count;j++)
  {
   root->child[i]->child[j] = new node;
   cout<<"\nEnter Section "<<j+1<<"name";
   cin>>root->child[i]->child[j]->name;
   cout<<"\nEnter no. of subsections in "<<root->child[i]->child[j]->name;
   cin>>root->child[i]->child[j]->ch_count;
    int l=root->child[i]->child[j]->ch_count;
   for(k=0;k<l;k++)
   {
       root->child[i]->child[j]->child[k]=new node;
       cout<<"\nEnter subsection "<<k+1<<" name";
       cin>>root->child[i]->child[j]->child[k]->name;
   }
  }

 }

}


void tree::display(node*ptr)
{
 int i,j,k,chap;
 if( ptr!= NULL)
 {
  cout<<"\n-------BOOK----------";

  cout<<"\n Book title : "<<ptr->name;
  chap = ptr->ch_count;
  for(i=0;i<chap;i++)
  {

   cout<<"\n  Chapter : "<<i+1;
   cout<<" "<<ptr->child[i]->name;
   cout<<"\n Sections :";
   for(j=0;j<ptr->child[i]->ch_count;j++)
   {
    cout<<"\n  "<<ptr->child[i]->child[j]->name;
    cout<<"\n Subsections :";
    for(k=0;k<ptr->child[i]->child[j]->ch_count;k++)
    {
        cout<<"\n "<<ptr->child[i]->child[j]->child[k]->name;
    }
   }

  }
 }
}


int main()
{
    int choice;
    tree t;
    char c;
    do
    {
        cout<<"\n**************Creation of book ***********"<<endl;
        cout<<"\n1.Create";
        cout<<"\n2.Display";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
              t.create();
        case 2:
              t.display(root);
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
        cout<<"\nDo you want to continue?";
        cin>>c;
    }while(c=='y'||c=='Y');
 return 0;
}


