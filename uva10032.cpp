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

using namespace std;

long long find(int Sum, int arr[],int k,int n)
{
	long long x=find(Sum+arr[n],arr,k-1,n-1);
	long long y=find(Sum,arr,k,n-1);
	long long diff1=
}
