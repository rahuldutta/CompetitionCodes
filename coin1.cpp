using namespace std;
#include<iostream>
#include<cstdio>
int s[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
int count(int n,int m)
{
     if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (m < 0 && n >= 1)
        return 0;
        
        return (count(n,m-1)+count(n-s[m],m));
        }

int main()
{
     float f;
     while(1)
     {
             cin>>f;
             int n=100*f;
             if(n==0)
             break;
             
    printf("%6f%17d\n",f,count(n,10));
     }
}


