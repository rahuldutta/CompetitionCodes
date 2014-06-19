#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
#include<cstdlib>

using namespace std;
//int checkerBoard[8][8]={{0}};


bool check(int checkerBoard[8][8],int r, int c)
{
 	 if(r<0||r>8||c<0||c>8)
 	 return false;
 	 for(int i=0;i<8;i++)
 	 		 if(checkerBoard[r][i]>0||checkerBoard[i][c]>0)
 	 		 	   return false;
     for(int i=1;i<=8;i++)
     {
	  		 if(r-i>=0&&c-i>=0&&checkerBoard[r-i][c-i]>0)
			   return false;
			 if(r-i>=0&&c+i<8&&checkerBoard[r-i][c+i]>0)
			   return false;
			 if(r+i<8&&c+i<8&&checkerBoard[r+i][c+i]>0)
			   return false;
			 if(r+i<8&&c-i>=0&&checkerBoard[r+i][c-i]>0)
			   return false;  
	 }
	 return true;
}

bool putQueens(int checkerBoard[8][8], int c,int N, vector<int> result, int col,int counter)
{
 	 static int count=0;
 	 if(counter==0)
 	 count=1;
 	 if(N==0)
 	 {
	  		 //cout<<count<<" ";
	  		 printf("%2d",count);
	  		 count++;
	  		 printf("      ");
	  		 for(int i=0;i<result.size()-1;i++)
	  		 printf("%d ",result[i]);
	  		 printf("%d",result[result.size()-1]);
	  		 cout<<"\n";
	  		 return true;
	 }
	 for(int r=0;r<8;r++)
	 {
	  		 if(check(checkerBoard,r,c))
	  		 {
	  		  checkerBoard[r][c]=N;
	  		  result[c]=r+1;
	  		  if(c+1!=col)
	  		  {
			   			  /*if(!putQueens(checkerBoard,c+1,N-1,result,col))
			   			  {
										 checkerBoard[r][c]=0;
						  }*/
						  putQueens(checkerBoard,c+1,N-1,result,col,1);
  			 }
  			 else
  			 {
			  	 /*if(!putQueens(checkerBoard,c+2,N-1,result,col))
	   			  {
								 checkerBoard[r][c]=0;
				  }*/
				  putQueens(checkerBoard,c+2,N-1,result,col,1);
			 }
			 checkerBoard[r][c]=0;
			  result[c]=0;
			 }
	  		 
	 }
	 return false;
}


int main()
{
 	
	int N;
	cin>>N;
 	//while(cin>>N)
 	//{
 	int g=0;
 	for(int i=0;i<N;i++)
 	{
	 		if(g==0)
	 		g=1;
	 		else
	 		printf("\n");
	 		int r,c;
	 		int checkboard[8][8]={{0}};
	 		cin>>r>>c;
	 		checkboard[r-1][c-1]=8;
	 		vector<int> res(8,0);
	 		res[c-1]=r;
	 		printf("SOLN       COLUMN\n");
			printf(" #      1 2 3 4 5 6 7 8\n"); 
			printf("\n");
			if(c==1)
	 		putQueens(checkboard,1,7,res,c-1,0);
	 		else
	 		putQueens(checkboard,0,7,res,c-1,0);
	 		
	 		
	//}
}
	return 0;
}
