#include<iostream> 
using namespace std; 
class Heap 
            { 
            int a[50],b[50],n; 
            public: 
            Heap() 
                { 
                n=-1;; 
                } 
            void insheap(int); 
            int delheap(); 
            void display(); 
            void heapsort(); 
        }; 
void Heap::insheap(int item) 
    { 
            int i,j; 
            n++; 
            i=n; 
            while(i>0) 
            { 
            j=(i-1)/2; 
            if(item<=a[j]) 
            { 
            a[i]=item; 
            return ; 
            } 
            a[i]=a[j]; 
            i=j; 
            } 
            a[0]=item; 
    } 
int Heap::delheap() 
     { 
            int leŌ,right,last,i,item;
            item=a[0]; 
            last=a[n]; 
            n--; 
            i=0; 
            leŌ=1;
            right=2; 
            while(right<=n) 
            { 
            if(last>=a[leŌ] && last >=a[right])
            { 
            a[i]=last; 
            return item; 
            } 
            if(a[right]<=a[leŌ])
            { 
            a[i]=a[leŌ];
            i=leŌ;
            } 
            else 
            { 
            a[i]=a[right]; 
            i=right; 
            } 
            leŌ=(2*i)+1;
            right=leŌ+1;
            } 
            if(leŌ==n)
            { 
            if(last<a[leŌ])
            { 
            a[i]=a[leŌ];
            i=leŌ;
            } 
            } 
            a[i]=last; 
            return item; 
        } 
void Heap::display() 
     { 
    cout<<"\n Elements in heaps are:\n"; 
    for(int i=0;i<=n;i++) 
    { 
    cout<<" "<<a[i]; 
    } 
      } 
void Heap::heapsort() 
{ 
int item,ch,temp,j=0; 
do 
{cout<<"\n enter item to insert:"; 
cin>>item; 
insheap(item); 
cout<<"\n do you want to insert again ? press 1 for Yes and 0 for NO"; 
cin>>ch; 
}while(ch!=0); 
cout<<"\n before sorƟng\n"; 
for(int i=0;i<=n;i++) 
{ 
cout<<" "<<a[i]; 
} 
temp=n; 
while(n!=-1) 
{ 
b[j]=delheap(); 
j++; 
} 
cout<<"\n aŌer sorƟng\n"; 
for(int i=temp;i>=0;i--) 
{ 
cout<<" "<<b[i]; 
} 
} 
int main() 
{ 
Heap h=Heap(); 
h.heapsort(); 
return 0; 
} 