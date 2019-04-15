/**********************PROBLEM STATEMENT*************************
Company maintains employee information as employee ID, name, designation and salary.
Allow user to add, delete information of employee. Display information of particular
employee. If employee does not exist an appropriate message is displayed. If it is, 
then the system displays the employee details. Use index sequential file to maintain
the data.*/
#include<bits/stdc++.h>
using namespace std;
class EMP_CLASS
{
  typedef struct EMPLOYEE
  {
      char name[10];
      int emp_id;
      int salary;
  }Rec;
  typedef struct INDEX
  {
    int emp_id;
    int position;
  }Ind_Rec;
    Rec Records;
    Ind_Rec Ind_Records;
  public:
    EMP_CLASS();
    void Create();
    void Display();
    void Update();
    void Delete();
    void Append();
    void Search();
};
EMP_CLASS::EMP_CLASS()
{
   strcpy(Records.name,"");
}
void EMP_CLASS::Create()
{
 int i,j;
 char ch='y';
 fstream seqfile;
 fstream indexfile;
 i=0;
 indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 do
 {
  cout<<"\n Enter Name: ";
  cin>>Records.name;
  cout<<"\n Enter Emp_ID: ";
  cin>>Records.emp_id;
  cout<<"\n Enter Salary: ";
  cin>>Records.salary;
  seqfile.write((char*)&Records,sizeof(Records))<<flush;
  Ind_Records.emp_id=Records.emp_id;
  Ind_Records.position=i;
  indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
  i++;
  cout<<"\nDo you want to add more records?";
  cin>>ch;
  }while(ch=='y');
  seqfile.close();
  indexfile.close();
}
void EMP_CLASS::Display()
{
 fstream seqfile;
 fstream indexfile;
 int n,i,j;
 seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
 indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
 indexfile.seekg(0,ios::beg);
 seqfile.seekg(0,ios::beg);
 cout<<"\n The Contents of file are ..."<<endl;
 i=0;
 while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
 {

   i=Ind_Records.position*sizeof(Rec);
   seqfile.seekg(i,ios::beg);
   seqfile.read((char *)&Records,sizeof(Records));
   if(Records.emp_id!=-1)
   {   
    cout<<"\nName: "<<Records.name<<flush;
    cout<<"\nEmp_ID: "<<Records.emp_id;
    cout<<"\nSalary: "<<Records.salary;
    cout<<"\n";
    }

 }
 seqfile.close();
 indexfile.close();
}
void EMP_CLASS::Update()
{
  int pos,id;
  char New_name[10];
  int New_emp_id;
  int New_salary;
  cout<<"\n For updation,";
  cout<<"\n Enter the Emp_ID for for searching ";
  cin>>id;
  fstream seqfile;
  fstream indexfile;
  seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
  indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
  indexfile.seekg(0,ios::beg);

  pos=-1;
 
  while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
  {
      if(id==Ind_Records.emp_id)
      {
        pos=Ind_Records.position;
        break;
      }
  }
  if(pos==-1)
  {
    cout<<"\n The record is not present in the file";
    return;
  }
  else
  {
    cout<<"\n Enter the values for updation...";
    cout<<"\n Name: ";cin>>New_name;
    cout<<"\n Salary: ";cin>>New_salary;
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);
    strcpy(Records.name,New_name);
    Records.emp_id=id;
    Records.salary=New_salary;
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
    cout<<"\n The record is updated!!!";
  }
  seqfile.close();
  indexfile.close();

}
void EMP_CLASS::Delete()
{
  int id,pos;
  cout<<"\n For deletion,";
  cout<<"\n Enter the Emp_ID for for searching ";
  cin>>id;
  fstream seqfile;
  fstream indexfile;
  seqfile.open("EMP.DAT",ios::in|ios::out|ios::binary);
  indexfile.open("IND.DAT",ios::in|ios::out|ios::binary);
  seqfile.seekg(0,ios::beg);
  indexfile.seekg(0,ios::beg);
  pos=-1;
  while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
  {
    if(id==Ind_Records.emp_id)
    {
    pos=Ind_Records.position;
    Ind_Records.emp_id=-1;
    break;
    }
  }
  if(pos==-1)
  {
    cout<<"\n The record is not present in the file";
    return;
  }
  
  int offset=pos*sizeof(Rec);
  seqfile.seekp(offset);
  strcpy(Records.name,"");
  Records.emp_id=-1; 
  Records.salary=-1; 
  seqfile.write((char*)&Records,sizeof(Records))<<flush;
      
  offset=pos*sizeof(Ind_Rec);
  indexfile.seekp(offset); 
  Ind_Records.emp_id=-1; 
  Ind_Records.position=pos;
  indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
  seqfile.seekg(0);
  indexfile.close();
  seqfile.close();
  cout<<"\n The record is Deleted!!!";
}
void EMP_CLASS::Append()
{
  fstream seqfile;
  fstream indexfile;
  int pos;
  indexfile.open("IND.DAT",ios::in|ios::binary);
  indexfile.seekg(0,ios::end);
  pos=indexfile.tellg()/sizeof(Ind_Records);
  indexfile.close();

  indexfile.open("IND.DAT",ios::app|ios::binary);
  seqfile.open("EMP.DAT",ios::app|ios::binary);

  cout<<"\n Enter the record for appending";
  cout<<"\nName: ";cin>>Records.name;
  cout<<"\nEmp_ID: ";cin>>Records.emp_id;
  cout<<"\nSalary: ";cin>>Records.salary;
  seqfile.write((char*)&Records,sizeof(Records));
  Ind_Records.emp_id=Records.emp_id;           
  Ind_Records.position=pos;                         
  indexfile.write((char*)&Ind_Records,sizeof(Ind_Records))<<flush;
  seqfile.close();
  indexfile.close();
  cout<<"\n The record is Appended!!!";
}
void EMP_CLASS::Search()
{
  fstream seqfile;
  fstream indexfile;
  int id,pos,offset;
  cout<<"\n Enter the Emp_ID for searching the record ";
  cin>>id;
  indexfile.open("IND.DAT",ios::in|ios::binary);
  pos=-1;
  
  while(indexfile.read((char *)&Ind_Records,sizeof(Ind_Records)))
  {
    if(id==Ind_Records.emp_id)
    {
    pos=Ind_Records.position;
    break;
    }
  }
    if(pos==-1)
    {
    cout<<"\n Record is not present in the file";
    return;
    }
  
    offset=pos*sizeof(Records);
    seqfile.open("EMP.DAT",ios::in|ios::binary);
    seqfile.seekg(offset,ios::beg);
    seqfile.read((char *)&Records,sizeof(Records));
    if(Records.emp_id==-1)
    {
    cout<<"\n Record is not present in the file";
    return;
    }
    else 
    {
    cout<<"\n The Record is present in the file and it is...";
    cout<<"\n Name: "<<Records.name;
    cout<<"\n Emp_ID: "<<Records.emp_id;
    cout<<"\n Salary: "<<Records.salary;
    }
    seqfile.close();
    indexfile.close();
}
int  main()
{
  EMP_CLASS List;
  char ans='y';
  int choice,key;
  do
  {
    cout<<"\n             Main Menu             "<<endl;
    cout<<"\n 1.Create";
    cout<<"\n 2.Display";
    cout<<"\n 3.Update";
    cout<<"\n 4.Delete";
    cout<<"\n 5.Append";
    cout<<"\n 6.Search";
    cout<<"\n 7.Exit";
    cout<<"\n Enter your choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:List.Create();
        break;
    case 2:List.Display();
        break;
    case 3:List.Update();
        break;
    case 4:List.Delete();
        break;
    case 5:List.Append();
        break;
    case 6:List.Search();
        break;
    case 7:exit(0);
    }
  cout<<"\nDo you want to go back to Main Menu?";
  cin>>ans;
  }while(ans=='y');
}
