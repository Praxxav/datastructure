
#include<iostream>
#include<fstream>
using namespace std;

class Student{
int roll_no;
char name[30];
char division[5];
char address[30];

public:
  void accept();
  void display();
  int rollno()
  {
  return roll_no;
     }
  };
  
  
  void Student::accept(){
  cout<<"Enter roll no of student:";
  cin>>roll_no;
  cout<<"Enter name of student:";
  cin>>name;
  cout<<"Enter division of student:";
  cin>>division;
  cout<<"Enter address of student:";
  cin>>address;
  
  cout<<"\n";
  
  
  }
  
  void Student::display(){
  cout<<"\n"<<roll_no<<"\t"<<name<<"\t"<<division<<"\t"<<address;
  }
  
  void create(){
  Student s;
  int n,i;
  
  ofstream out("Student.txt");
  cout<<"\n How many records do you want to enter?";
  cin>>n;
  for(i=0;i<n;i++){
  s.accept();
  out.write((char *)&s,sizeof(s));
  }
  out.close();
  }
  
  
  void search(){
  int n,flag=0;
  
  cout<<"\n Enter roll no to be serached:";
  cin>>n;
  ifstream in("Student.txt");
  Student s;
  while(in.read((char *)&s,sizeof(s))){
  if(s.rollno()==n){
  cout<<"\n Record found";
  
  cout<<"\n Rollnumber      Name    Division      Address";
  s.display();
  flag=1;
  break;
  }
  }
  if(flag==0){
  cout<<"\n Record not found";
  }
  
  in.close();
  }
  
  
  
  void display()
  {
    Student s;
   ifstream in("Student.txt");
     while(in.read((char *)&s,sizeof(s)))
     {
    s.display();
       }
     in.close();
  }
  
  void add_record()
  {
      Student s;
     ofstream out("Student.txt",ios::app);
     s.accept();
     out.write((char *)&s,sizeof(s));
    out.close();
     cout<<"\n Record successfully added";
   }
   
   void delete_record(){
   int n,flag=0;
   Student s;
   cout<<"\n Enter roll no whose record to be deleted:";
   cin>>n;
   ifstream in("Student.txt");
  ofstream out("temp.txt");
  while(in.read((char *)&s,sizeof(s))){
  
  if(s.rollno()!=n)
  {
  
    out.write((char *)&s,sizeof(s));
    }
    
    else{
    flag=1;
    cout<<"\n Record successfully Deleted";
    }
    }
    
    if(flag==0){
    cout<<"Record not found";
    }
    in.close();
    out.close();
    remove("Student.txt");
    rename("temp.txt","Student.txt");
    
    }
    
    int main(){
    int choise,roll_no;
    char Name[30];
    do{
    cout<<"\n";
    cout<<"\n Menu:\n 1)Create Database \n 2) Display \n 3) Add Record \n 4)Search Record \n 5)Delete Record \n 6)Exit";
    
    cout<<"\n Enter your choice:";
    cin>>choise;
    switch(choise){
    case 1: cout<<"\n";
           create();
           break;
   case 2:
   cout<<"\n";
   cout<<"\n RollNumber     Name    Division     Address";
   display();
   break;
   
   case 3:
      cout<<"\n";
      add_record();
      break;
      
  case 4:
    cout<<"\n";
    search();
    break;
    
  case 5:
  cout<<"\n";
  delete_record();
  break;
  case 6:
  cout<<"\n";
  cout<<"You have successfully Exited>>.";
  break;
  }
  }while(choise!=6);
  return 0;
  }              
  