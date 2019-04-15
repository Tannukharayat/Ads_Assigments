#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Heap
{

	int *a;
	int size;
	int start;
	public:
	Heap()
	{
	}
	Heap(int a)
	{
		this->a=new int[a+1];
		this->size=a+1;
		start=0;
	}
	void add(int a );
	void heapifyup();
	void heapifydown();
	int parent(int in)
	{
		return  (in-2)/2;
	}
	int leftchild(int in)
	{
		return in*2+1;
	}
	int rightchild(int in)
	{
		return in*2+2;
	}
	vector<int> minheapify();
};
vector<int> Heap::minheapify()
{

	int item;
	int length=size;
	vector<int>b;
	while(b.size()!=length)
	{
	b.push_back(a[0]);
	a[0]=a[size-1];
	size--;
	heapifydown();
	}
	return b;
}
void Heap::heapifyup()
{
	int index=start-1;

	while(parent(index)>=0&&a[parent(index)]>a[index])
	{
		swap(a[index],a[parent(index)]);
		index=parent(index);
	}
}

void Heap::heapifydown()
{
	int index=0;
	int s;
	while(leftchild(index)<size)
	{
		s=leftchild(index);
		if(rightchild(index)<size&&a[rightchild(index)]<a[leftchild(index)])
		s=rightchild(index);
		if(a[s]>a[index])
		break;
		else swap(a[s],a[index]);
		index=s;
	}
}
void Heap::add(int b)
{
	a[start]=b;
	start++;
	heapifyup();
}
int main()
{
	int n;
	cout<<"Enter the number of students :";
	cin>>n;
	int a;
	Heap h(100);
	while(n--)
	{
		cout<<"Enter the students online marks :";
		cin>>a;
		h.add(a);
	}
	vector<int>c=h.minheapify();
	cout<<"THe maximum marks is:"<<c[c.size()-1]<<"\n";
	cout<<"THe minimum marks is:"<<c[0]<<"\n";
	return 0;
}

