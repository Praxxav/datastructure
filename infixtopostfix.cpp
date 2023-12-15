#include<iostream>
#include<string.h>
using namespace std;
struct stack
{
	char data;
	stack *next;
}*top=NULL;

struct stack1{
int data;
stack1 *next;
}*top1=NULL;
int precedence(char op)
{
	if(op=='^')
	{
		return 3;
	}
	else if(op=='*'||op=='/')
	{
		return 2;
	}
	else if(op=='+'||op=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void infixtopost(char q[30])
{
	stack *newnode,*temp;
	char p[30];
	int i=0,j=0,l;
	newnode=new stack;
	newnode->data='(';
	newnode->next=top;
	top=newnode;
	
	l=strlen(q);
	q[l]=')';
	
	while(top!=NULL)
	{
		if(q[i]=='(')
		{
			newnode=new stack;
			newnode->data='(';
			newnode->next=top;
			top=newnode;
		}
		else if(q[i]=='*'||q[i]=='-'||q[i]=='+'||q[i]=='/'||q[i]=='^')
		{
			while(precedence(top->data)>=precedence(q[i]))
			{
				p[j]=top->data;
				temp=top;
				top=top->next;
				delete temp;
				j++;
			}
			newnode=new stack;
			newnode->data=q[i];
			newnode->next=top;
			top=newnode;
		}
		else if(q[i]==')')
		{
			while(top->data!='(')
			{
				p[j]=top->data;
				temp=top;
				top=top->next;
				delete temp;
				j++;
			}
			temp=top;
			top=top->next;
			delete temp;
		}
		else
		{
			p[j]=q[i];
			j++;
		}
		i++;
	}
	cout<<"\n Postfix expression is: "<<p;
}
void infixtopre(char q[30])
{
	stack *newnode,*temp;
	char p[30];
	int i,j=0,l;
	i=strlen(q)-1;
	newnode=new stack;
	newnode->data=')';
	newnode->next=top;
	top=newnode;
	
	q[-1]='(';
	
	while(top!=NULL)
	{
		if(q[i]==')')
		{
			newnode=new stack;
			newnode->data=')';
			newnode->next=top;
			top=newnode;
		}
		else if(q[i]=='*'||q[i]=='-'||q[i]=='+'||q[i]=='/'||q[i]=='^')
		{
			while(precedence(top->data)>=precedence(q[i]))
			{
				p[j]=top->data;
				temp=top;
				top=top->next;
				delete temp;
				j++;
			}
			newnode=new stack;
			newnode->data=q[i];
			newnode->next=top;
			top=newnode;
		}
		else if(q[i]=='(')
		{
			while(top->data!=')')
			{
				p[j]=top->data;
				temp=top;
				top=top->next;
				delete temp;
				j++;
			}
			temp=top;
			top=top->next;
			delete temp;
		}
		else
		{
			p[j]=q[i];
			j++;
		}
		i--;
	}

	cout<<"\n Prefix expression is: ";
	for(i=strlen(p)-1;i>=0;i--)
	{
	       cout<<p[i];
	}
	    
	
}

void evalpost(char p[30])
{
   stack1 *newnode,*temp;
   int i=0,a,b,c;
   int l=strlen(p);
   p[l]=')';
   while(p[i]!=')')
{
   if(isdigit(p[i])){
   newnode=new stack1;
   newnode->data=p[i]-'0';
   newnode->next=top1;
   top1=newnode;
}
   else{
   a=top1->data;
   temp=top1;
   top1=top1->next;
   delete temp;
   b=top1->data;
   temp=top1;
   top1=top1->next;
   delete temp;

switch(p[i])
{
   case '+':
     c=b+a;
     break;
  
   case '-':
     c=b-a;
     break;

   case '*':
     c=b*a;
     break;

   case '/':
     c=b/a;
     break;

   case'^':
    c=b^a;
    break;
}
    //cout<<c;
    newnode=new stack1;
    newnode->data=c;
    newnode->next=top1;
    top1=newnode;

}
i++;
}
cout<<"\n value of postfix expression is:"<<top1->data;
}

 void evalpre(char p[30])
{
stack1 *newnode,*temp;
int i=strlen(p)-1,a,b,c;

p[-1]='(';
while(p[i]!='(')
{
  if(isdigit(p[i]))
{
  newnode=new stack1;
  newnode->data=p[i]-'0';
  newnode->next=top1;
  top1=newnode;
}

else{
   
   a=top1->data;
   temp=top1;
   top1=top1->next;
   delete temp;
   b=top1->data;
   temp=top1;
   top1=top1->next;
   delete temp;

  switch(p[i])
{
   case '+':
    c=a+b;
    break;
  
   case '-':
    c=a-b;
    break;
  
   case '*':
    c=a*b;
    break;

   case '/':
    c=a/b;
    break;

   case'^':
    c=a^b;
    break;
}
  //cout<<c;
  newnode=new stack1;
  newnode->data=c;
  newnode->next=top1;
  top1=newnode;

}
i--;
}
   cout<<"\n value of prefix expression is:"<<top1->data;
}


int main()
{
	char q[30],p[30];
	int ch;
	do
	{
		cout<<"\n1. Infix to postfix";
		cout<<"\n2. Infix to prefiex";
		cout<<"\n3. Evaluation of postfix";
		cout<<"\n4. Evaluation of prefix";
		cout<<"\n5. Exit";
		cout<<"\n enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n enter infix expression";
				cin>>q;
				infixtopost(q);
				break;
			case 2: cout<<"\n enter infix expression";
				cin>>q;
				infixtopre(q);
				break;
				
		       case 3: cout<<"\n enter postfix expression:";
		               cin>>p;
		               evalpost(p);
		               break;
		      case 4:  cout<<"\n enter prefix expression:";
		               cin>>p;
		               evalpre(p);
		               break;
		}
	}while(ch!=5);
	return 0;
}

