#include <stdio.h>
#include <set>
#include <iostream>
using namespace std;
 
set<int> endv;
set<int>::iterator it;
 
#define NMAX 111111
int N, i, x;
 
int main() {
	scanf("%d", &N);
	for (i = 1; i <= N; i++) {
		scanf("%d", &x);
		if (i == 1)
			endv.insert(x);
		else {
			it = endv.lower_bound(x);
			if (it == endv.begin())
				endv.insert(x);
			else {
				it--;
				endv.erase(*it);
				endv.insert(x);
			}
		}
		for (std::set<int>::iterator it1=endv.begin(); it1!=endv.end(); ++it1)
    std::cout << ' ' << *it1;
    std::cout<<std::endl;
	}
 
	printf("%u\n", endv.size());
	return 0;
}
