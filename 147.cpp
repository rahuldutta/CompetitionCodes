using namespace std;
#include<iostream>
#include<cstdio>
int s[11]={5,10,20,50,100,200,500,1000,2000,5000,10000};
   long long table[30000+1][10+1];
   int n=30000;
   int m=10;
    
void count()
{
    int i,j;
for(i=0;i<=n;i++)
for(j=0;j<=m;j++)
table[i][j]=0;
    for(i=0;i<=m;i++)
    table[0][i]=1;
     for (i=1 ;i<=n;i++)
     {
    for( j=0;j<=m;j++)
    {
        long long t;
        long long k;
          if ((i-s[j])<0)
          t=0;
          else
        t=table[i-s[j]][j];
    if (j-1< 0&&i>=1)
        k=0;
        else
        k=table[i][j-1];
      table[i][j] =t + k;
}
}
  
        
        
        }

int main()
{
    count();
    int s=0,i;
    
    
    
     double f;
     while(1)
     {
             cin >> f;
             if (f <= 0)
                break;
                float fl=100.00 * f;
             long long n= (long long)(fl);
    //         cout << f << " "  << n <<" "<<fl<< endl;
           //cout<<table[95][m]<<" ";
           //cout<<table[n][m];
    printf("%6.2lf%17lld\n",f,table[n][m]);
     }
     return 0;
}
