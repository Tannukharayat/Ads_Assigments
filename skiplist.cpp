/***********************PROBLEM STATEMENT************************
For given set of elements create skip list. Find the element in the set that is 
closest to some given value.*/
#include<iostream>
using namespace std;
struct node
{
	int x;
	node *next;
	node *down;
};
class skiplist
{
	node* head[100];
	int l;
	public:
	skiplist()
	{
		for(int i=0;i<100;i++)
			head[i]=NULL;
		l=0;
	}
	void create_list()
	{
		int n;node *temp;
		cout<<"Enter number of elements: "<<endl;
		cin>>n;
		cout<<"Enter the elements in sorted order(increasing) :"<<endl;
		for(int i=0;i<n;i++)
		{
			node *p=new node;
			cin>>p->x;
			p->next=NULL;
			p->down=NULL;
			if(head[0]==NULL)
			{
				head[0]=p;
			}
			else
			{
				temp=head[0];
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=p;
			}
		}
		while(n/3>1)
		{
			node *temp,*temp1;
			temp=head[l];
			n=n/3;
			l++;
			node *p=new node;
			p->x=temp->x;
			p->down=temp;
			p->next=NULL;
			head[l]=p;
			temp1=head[l];
			while(temp->next!=NULL)
			{
				for(int i=3;i>0;i--)
				{
					if(temp->next!=NULL)
					temp=temp->next;
				}
				node *t=new node;
				t->x=temp->x;
				t->down=temp;
				t->next=NULL;
				temp1->next=t;
				temp1=t;
			}
		}
	}
	void display_list()
	{
		cout<<"List:"<<endl;
		for(int i=0;i<=l;i++)
		{
			node *temp=head[i];
			cout<<"Level "<<i<<" : ";
			while(temp!=NULL)
			{
				 cout<<temp->x<<"  ";
				 temp=temp->next;
			}
			cout<<endl;
		}
	}
	void search_list()
	{
		int k;int cmp=0;int flag=0;
		cout<<"Enter the element to be searched: "<<endl;
		cin>>k;
		node *p,*n;
		p=head[l];
		n=p;
		while(n!=NULL)
		{
			cmp++;
			if(n->x==k)
			{
				cout<<"Element found !"<<endl;
				flag=1;
				break;
			}
			else if(n->x>k)
			{
				n=p->down;
				p=n;
			}
			p=n;
			n=n->next;
		}
		if(flag==0)
		cout<<"Element not found !"<<endl;
		cout<<"No. of comparisons = "<<cmp<<endl;
	}
};

int main()
{
	skiplist o;
	o.create_list();
	o.display_list();
	o.search_list();
	return 0;
}
