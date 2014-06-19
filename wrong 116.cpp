using namespace std;
#define Inf 1ll<<60
#include<iostream>
#include<stdio.h>

long long min2(long long a,long long b,long long c)
{
long long d=a<b?a:b;
return(d<c?d:c);
}

int main()
{
 	//freopen("test.txt", "r", stdin);
 	//freopen("testO.txt", "w", stdout);
long long r,c,i,j;
while (cin>>r>>c)
{
 	  long long matrix[r][c];

long long cost[r][c];
       long long weight[r][c];
for( i=0;i<r;i++)
{
for( j=0;j<c;j++)
{
//cost[i][j]=0;
matrix[i][j]=0;
cin>>weight[i][j];
}
}
for(j=c-1;j>=0;j--)
{
for(i=0;i<r;i++)
{
long long rl,rh;

rl=(r+i-1)%r;
rh=(i+r+1)%r;
long long t;
long long wl,w0,wh;
if(j==(c-1))
{
wl=weight[rl][j];
w0=weight[i][j];
wh=weight[rh][j];
}
else
{
wl=weight[rl][j]+cost[rl][j+1];
w0=weight[i][j]+cost[i][j+1];
wh=weight[rh][j]+cost[rh][j+1];
}
t=min2(wl,w0,wh);

long long pos1=Inf,pos2=Inf,pos3=Inf;
if(wl==t)
{
pos1=rl;
}
if(w0==t)
{
pos2=i;
}
if(wh==t)
{
pos3=rh;
}
matrix[i][j]=min2(pos1,pos2,pos3);
cost[i][j]=t;

}
}
long long min1=cost[0][0];
long long pos=0;
for(i=1;i<r;i++)
{
if(cost[i][0]<min1)
{
min1=cost[i][0];
pos=i;
}
}
long long arr[c];
j=pos;

for(i=0;i<c;i++)
{
arr[i]=matrix[j][i];
j=matrix[j][i];
}
for(i=0;i<c;i++)
{
if(i<(c-1))
{
printf("%lld ",(arr[i]+1));
}
else
{
printf("%lld",(arr[i]+1));
}
}
printf("\n%lld\n",min1);
}
return 0;
}
