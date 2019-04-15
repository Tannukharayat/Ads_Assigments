/********************PROBLEM STATEMENT**********************
Consider telephone book database of N clients. Make use of a hash table 
implementation to quickly look up client's telephone number
*/
#include<iostream>
#define max 10
using namespace std;

class hash
{
	long tel_num[100];
	int key;
	long number;

	public:
		void display();
		void create();
			hash();


};

hash::hash()
{
	for(int i=0;i<max;i++)
	{
		tel_num[i]=-999;
	}
}
void hash::create()
{
	int flag=0,count=0;
	cout<<"\nEnter telephone number:=>";
	cin>>number;

	key=number% max;

	if(tel_num[key]==-999)
	{
		tel_num[key]=number;
	}
	else
	{
		cout<<"\nOops...There is a collision..!!!"<<endl;
		for(int i=0;i<max;i++)
		{
			if(tel_num[i]!=-999)
			{
				count++;
			}
		}
		if(count==max)
		{
		cout<<"\nSorry....Hash table is Full.";
		}

		else
		{
			for(int i=key+1;i<max;i++)
			{
				if(tel_num[i]==-999)
				{
					tel_num[i]=number;
					flag=1;
					break;
				}
			}

			for(int i=0;i<key;i++)
			{
				if(tel_num[i]==-999 && flag==0)
				{
					tel_num[i]=number;
					break;
				}
			}

		}
	}

}

void hash::display()
{
	cout<<"\n****Hash Table****\n";
	for(int i=0;i<max;i++)
	{
		cout<<tel_num[i]<<"\n";;
	}
}

int main()
{
	hash s;
	int ch,n;
	char ans;



	do
	{
	cout<<"\n__Hash_Table_MEnu__";
	cout<<"\n\n1)Create Hash Table";
	cout<<"\n2)Display Hash table";
	cout<<"\n\nEnter your choice:=>";
	cin>>ch;
		switch(ch)
		{
		case 1:cout<<"\nHow many numbers do u want to inset..???";
				cin>>n;
				for(int i=0;i<n;i++)
				{
				s.create();
				}
				break;
		case 2:s.display();
				break;
		}cout<<"\n\nDo another...(y/n)";
	cin>>ans;
	}while(ans=='y'||ans=='Y');

}
