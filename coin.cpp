using namespace std;
#include<iostream>
#include<cstdio>
int arr[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};

int main()
{
     int i,j;
     float f;
     while(1)
     {
             cin>>f;
             int n=100*f;
             if(n==0)
             break;
             cout<<n;
             int C[n+1];
             C[0] = 0;
for (j =1;j<n+1;j++)

{
    C[j] = 1000000000;
    
for (i=0;i<11;i++)
{
    if (j >= arr[i] && (1 + C[j - arr[i]]) < C[j])
    C[j]= 1 + C[j-arr[i]];
}
}
printf("%-6f%-17d",f,C[n]);
}
}
