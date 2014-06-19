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
#define MAXN 5002000
#define MAXP 5001
#define MAXLG 24
char A[MAXN];
long long llow;
//char Pat[501][MAXP];
string Pat[501];
long long index1[501];

/*
struct pattern{
	char Pat[MAXP];
	long long index;
	pattern(char* p, long long ind):index(ind)
	{
		strcpy(Pat,p);
	}
	pattern(const pattern &pt)
	{
		strcpy(Pat,pt.Pat);
		index=pt.index;
	}
	pattern()
	{
		strcpy(Pat,"");
		index=0;
	}
}pat[500];
*/
long long Ans[501];
 
struct entry {
	long long nr[2], p;
} L[MAXN];
long long P[MAXLG][MAXN];
long long SA[MAXN];
//vector<pattern> pat;


long long cmp(struct entry a, struct entry b)
{
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
 

bool comp(const string a, const string b)
{
	return a.compare(b) < 0;
}

bool comp1(long long a, long long b)
{
	return Pat[a].compare(Pat[b]) < 0;
}


void SuffixArray()
{
	long long N,i,stp,cnt;
	for (N = strlen(A), i = 0; i < N; i ++)
	P[0][i] = A[i] - 'a';
	for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
	{
		for (i = 0; i < N; i ++)
		{
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L, L + N, cmp);
		for (i = 0; i < N; i ++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
	}
	memset(SA,0,sizeof(SA));
	for (i = 0; i < N; i ++)
	{
		SA[P[stp-1][i]]=i;
	}
	/*
	for (i = 0; i < N; i ++)
	{
	cout<<SA[i]<<endl;
	}*/
}
 
/*
int lcp(int x, int y)
{
int k, ret = 0;
if (x == y) return N - x;
for (k = stp - 1; k >= 0 && x < N && y < N; k --)
if (P[k][x] == P[k][y])
x += 1 << k, y += 1 << k, ret += 1 << k;
return ret;
}
*/
long long suffixAt(const char* P1, long long pos)
{
	long long n=strlen(A);
	long long m=strlen(P1);
	long long i;
	for(i=0;i<m&&pos<n;i++,pos++)
	{
		if(P1[i]!=A[pos])
		{
		break;
		}
	}
	if(i==m)
		return 0;
	else if(pos==n)
		return 1;
	else if(P1[i]<A[pos])
		return -1;
	else
		return 1;
}
 
long long search(const char* P1)
{

	long long l = llow; long long r = strlen(A)-1;
	while (l < r)
	{
		long long mid = (l+r) / 2;
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if(suffixAt(P1,SA[mid])==1)
			l = mid + 1;
		else
			r = mid;
	}
	if(suffixAt(P1,SA[l])!=0)
	return 0;
	//cout<<"now we are here\n";
	long long s = l; r = strlen(A)-1;
	while (l < r)
	{
		long long mid = ceil((double)(l+r)/ 2);
		//cout<<l<<" "<<r<<" "<<mid<<endl;
		if (suffixAt(P1,SA[mid])==0)
		l = mid;
		else
		r = mid-1;
	}
	llow=r;
	return (r-s+1);
}
int main(void)
{
	long long W;

	//scanf("%d",&W);
	cin>>W;
	long long i,j;
	
	for(i=0;i<W;i++)
	{
		//cout<<"hello1\n";
		//char p[MAXP];
		//scanf("%s",&Pat[i]);
		cin>>Pat[i];
		//cout<<Pat[i]<<endl;
		index1[i]=i;
		
	}
	sort(index1,index1+W,comp1);
	sort(Pat,Pat+W,comp);
	//cout<<"hello";
	long long N;
	//scanf("%d",&N);
	cin>>N;
	//cout<<N<<endl;
	for(j=0;j<N;j++)
	{
		
		if(j==0)
			scanf("%s",A);
		else
		{
			char str[50001];
			scanf("%s",str);
			strcat(A,str);
		}
		if(j!=(N-1))
			strcat(A,"-");	
	}
	//printf("%s",A);
	SuffixArray();
	llow=0;
	for(i=0;i<W;i++)
	{
		//cout<<"Searching\n";
		//cout<<index1[i]<<" "<<Pat[i]<<endl;
		Ans[index1[i]]=search(Pat[i].c_str());
	}
	
	for(i=0;i<W;i++)
	{
		printf("%lld\n",Ans[i]);
	}
	return 0;
} 
