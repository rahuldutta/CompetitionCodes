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




double F(long T1,long T2,long T3)
{
	long sum=T1+T2+T3;
	//cout<<T3<<endl;
	//cin.get();
	if(T3==0)
	{
		return (double)T1/(double)sum;
	}
	else
		return (double)T1/(double)sum + ((double)T3/(double)sum) * F(T1,T2,T3-1);
}

double F1(long long T1,long long T2,long long T3)
{
	double r=0;
	for(long long i=0;i<=T3;i++)
	{
		long long sum=T1+T2+i;
		if(i==0)
			r= (double)T1/(double)sum;
		else
			r=(double)T1/(double)sum + ((double)i/(double)sum)*r;
	}
	return r;
}


double P(long T1,long T2,long T3,long T4)
{
	long sum=T1+T2+T3;
	//cout<<"hello "<<T1<<" "<<T2<<" "<<T3<<" "<<T4<<" "<<sum;
	//cin.get();
	if(T4==0)
	{
		return F(T1,T2,T3);
	}
	else
	{
		double t1=0,t2=0,t3=0,t=0;
		if(T1>0)
		t1=(double)T1/(double)sum * P(T1-1,T2,T3,T4-1);
		if(T2>0)
		t2= (double)T2/(double)sum * P(T1,T2-1,T3,T4-1);
		if(T3>0)
		t3= (double)T3/(double)sum * P(T1,T2,T3-1,T4-1);
		t=t1+t2+t3;
		return t;
	}
}


int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		long T1,T2,T3,T4;
		cin>>T1>>T2>>T3>>T4;
		//cout<<"hello";
		//cin.get();
		cout<<P(T1,T2,T3,T4)<<endl;
		cout<<F1(T1,T2,T3)<<endl;
		cout<<(double)T1/(double)(T1+T2)<<endl;
	}
	return 0;
}
