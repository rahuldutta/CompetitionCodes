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
long double X[35];
long double Y[35];

void centrad1(long double ax,long double ay,long double bx,long double by, long double cx, long double cy,long double *cr)
{
	long double ctx,cty,radius;
    long double yDelta_a= by-ay;
	long double xDelta_a= bx - ax;
	long double yDelta_b= cy - by;
	long double xDelta_b= cx - bx;
	

    long double aSlope=yDelta_a/xDelta_a; 
	long double bSlope=yDelta_b/xDelta_b;


	ctx= (aSlope*bSlope*(ay - cy) + bSlope*(ax + bx)-aSlope*(bx+cx) )/(2* (bSlope-aSlope) );
	cty= ((cx - ax) + bSlope*(cy + by)-aSlope*(by+ay) )/(2* (bSlope-aSlope) );
	
	radius=(ctx-ax)*(ctx-ax)+(cty-ay)*(cty-ay);
	//radius=sqrt(radius);
	cr[0]=ctx;
	cr[1]=cty;
	cr[2]=radius;

}

int deathCircle(int a, int b, int c, int d)
{
	long double x0,x1,x2,y0,y1,y2,x3,y3,center[3],dist;
	long double r;
	int sum=0;
	
	x0=X[a],x1=X[b],x2=X[c],x3=X[d];
	y0=Y[a],y1=Y[b],y2=Y[c],y3=Y[d];
		
	if(!((x1-x0==0&&x1-x2==0)||((y2-y1)*(x1-x0)/((x2-x1)*(y1-y0)))==1))
	{
		if(x1-x0==0)
		{
			centrad1(x1,y1,x2,y2,x0,y0,center);
		}
		else if (x1-x2==0)
		{
			centrad1(x1,y1,x0,y0,x2,y2,center);
		}
		else
			centrad1(x0,y0,x1,y1,x2,y2,center);
		dist=(x3-center[0])*(x3-center[0])+(y3-center[1])*(y3-center[1]);
		if(dist<center[2]||(dist<center[2]+.000001&&dist>center[2]-.000001))
			sum++;
	}
	//cout<<x0<<" "<<y0<<endl<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl<<x3<<" "<<y3<<endl<<sum<<endl;
	
	
	x0=X[a],x1=X[b],x2=X[d],x3=X[c];
	y0=Y[a],y1=Y[b],y2=Y[d],y3=Y[c];
	if(!((x1-x0==0&&x1-x2==0)||((y2-y1)*(x1-x0)/((x2-x1)*(y1-y0)))==1))
	{
		if(x1-x0==0)
		{
			centrad1(x1,y1,x2,y2,x0,y0,center);
		}
		else if (x1-x2==0)
		{
			centrad1(x1,y1,x0,y0,x2,y2,center);
		}
		else
			centrad1(x0,y0,x1,y1,x2,y2,center);
		dist=(x3-center[0])*(x3-center[0])+(y3-center[1])*(y3-center[1]);
		if(dist<=center[2]||(dist<center[2]+.000001&&dist>center[2]-.000001))
			sum++;
	}
	//cout<<x0<<" "<<y0<<endl<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl<<x3<<" "<<y3<<endl<<sum<<endl;
	
	x0=X[a],x1=X[d],x2=X[c],x3=X[b];
	y0=Y[a],y1=Y[d],y2=Y[c],y3=Y[b];
	if(!((x1-x0==0&&x1-x2==0)||((y2-y1)*(x1-x0)/((x2-x1)*(y1-y0)))==1))
	{
		if(x1-x0==0)
		{
			centrad1(x1,y1,x2,y2,x0,y0,center);
		}
		else if (x1-x2==0)
		{
			centrad1(x1,y1,x0,y0,x2,y2,center);
		}
		else
			centrad1(x0,y0,x1,y1,x2,y2,center);
		dist=(x3-center[0])*(x3-center[0])+(y3-center[1])*(y3-center[1]);
		if(dist<=center[2]||(dist<center[2]+.000001&&dist>center[2]-.000001))
			sum++;
	}
	//cout<<x0<<" "<<y0<<endl<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl<<x3<<" "<<y3<<endl<<sum<<endl;
	
	x0=X[d],x1=X[b],x2=X[c],x3=X[a];
	y0=Y[d],y1=Y[b],y2=Y[c],y3=Y[a];
	if(!((x1-x0==0&&x1-x2==0)||((y2-y1)*(x1-x0)/((x2-x1)*(y1-y0)))==1))
	{
		if(x1-x0==0)
		{
			centrad1(x1,y1,x2,y2,x0,y0,center);
		}
		else if (x1-x2==0)
		{
			centrad1(x1,y1,x0,y0,x2,y2,center);
		}
		else
			centrad1(x0,y0,x1,y1,x2,y2,center);
		dist=(x3-center[0])*(x3-center[0])+(y3-center[1])*(y3-center[1]);
		if(dist<=center[2]||(dist<center[2]+.000001&&dist>center[2]-.000001))
			sum++;
	}
	//cout<<x0<<" "<<y0<<endl<<x1<<" "<<y1<<endl<<x2<<" "<<y2<<endl<<x3<<" "<<y3<<endl<<sum<<endl;
	
	return sum;
}

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		int N;
		cin>>N;
		memset(X,0,sizeof(X));
		memset(Y,0,sizeof(Y));
		for(int i=0;i<N;i++)
		{
			cin>>X[i]>>Y[i];
		}
		int no=0;
		int tot=0;
		for(int a=0;a<N;a++)
		{
			for(int b=a+1;b<N;b++)
			{
				for(int c=b+1;c<N;c++)
				{
					for(int d=c+1;d<N;d++)
					{
						no+=deathCircle(a,b,c,d);
						tot+=4;
						//cin.get();
					}
				}
			}
		}
		//cout<<no<<" "<<tot<<endl;
		cout<<(long double)no/(long double)tot<<endl;
	}
	return 0;
}
