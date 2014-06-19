#include <iostream>
#include <stdlib.h>
#include<stack>
using namespace std;

char buf[10000];
stack<char> mystack;

bool parse(int sum, int left, int  right)
{
     if(right==(left+1)) return false;
     int left_l,left_r,right_l,right_r;
     left++;
     int cur=atoi(&buf[left]);
     left_l=left;
     while(buf[left_l]!='(')left_l++;
     left_r=left_l+1;
     mystack.push('(');
     while(!mystack.empty())
     {
                           if(buf[left_r]=='(')
                           mystack.push('(');
                           else if(buf[left_r]==')')
                           mystack.pop();
                           left_r++;
     }
     left_r--;
     right_l=left_r+1;
     right_r=right-1;
     if(sum==cur&&left_r==left_l+1&&right_r==right_l+1)
     return true;
     else 
     return parse(sum-cur,left_l,left_r) || parse(sum-cur,right_l,right_r);
     
     return false;
}

int main()
{
    int Sum;
    while(cin>>Sum)
    {
                   int i=0;
                   cin>>ws;
                   char ch;
                   cin>>ch;
                   buf[i++]=ch;
                   mystack.push('(');
                   while(!mystack.empty())
                   {
                                         cin>>ws;
                                         cin>>ch;
                                         buf[i++]=ch;
                                         if(ch=='(')
                                         mystack.push('(');
                                         else if(ch==')')
                                         mystack.pop();
                   }
                   //for (int k=0;k<i;k++)
                   //cout<<buf[k];
                   //cin.get();
                   if(i==2)
                   cout<<"no\n";
                   else if(parse(Sum,0,i-1))
                   cout<<"yes\n";
                   else
                   cout<<"no\n";
    }
    return 0;
}
