using namespace std;
#include <iostream>
#include <stdio.h>
#include<string>
#include<ctype.h>
//#include<stdlib>
long long mat[10];
long long gift[10];

 int main()
 	   {
	   	   long long time=0;
	 // freopen("test.txt", "r", stdin);
 	 //freopen("testO.txt", "w", stdout);
	   	   long long N;
	   	   while(scanf("%lld",&N)!=EOF)
	   	   {
		   
	   	   long long flag,i=0,c=0,j=0,k=0,money,no,share,left,l1,pos;
	   	   for(i=0;i<10;i++)
	   	   {
		   					gift[i]=0;
		   					mat[i]=0;
							
			 }
		if(time!=0)
		cout<<"\n";
			  char ch,ch1;
			  string str[10];
			  string str1;
			 
		   for(i=0;i<N;i++)
		   cin>>str[i];
		   l1=N;
		
		   for(k=0;k<N;k++)
		   {
		   cin>>str1;
		   for(i=0;i<l1;i++)
		   {
		   					if(str[i]==str1)
		   					{
							   pos=i;
							   break;
  					        }
		   }
		   //cout<<pos;
		   scanf("%lld",&money);
		   scanf("%lld",&no);
		   //cout<<money;
		   //cout<<no;
		  
		   if(no!=0)
		   {
		   			//gift[pos]=-money;
		   share=money/no;
		   left=money%no;
		   mat[pos]-=(money-left);
		   }
		   else
		   {
		   	   //gift[pos]=0;
		   	   mat[pos]+=0;
		   	   left=0;
		   }
		   for(c=0;c<no;c++)
		   {
		   					
		   				
		   cin>>str1;
		   					long long pos1;
		   for(i=0;i<l1;i++)
		   {
		   					if(str[i]==str1)
		   					{
							   pos1=i;
							   break;
							}
		   }
		   //cout<<pos1;
		   					mat[pos1]+=share;
		}
		   					//mat[pos][pos]=left;
							}
							for(j=0;j<l1;j++)
							{
							 				 
															 cout<<str[j]<<" "<<(mat[j])<<"\n";
											 }
															 
															 time++;
															 }
															 return 0;
															 }
															  
