#include <algorithm>  
#include "MyIterator.h"

bool myfunction (int i,int j) { return (i<j); }

int main(int argc, char* argv[])
{
	int numbers[]={10,20,30,40,50};
	MyIterator from(numbers);
	MyIterator half(numbers+2);
	MyIterator until(numbers+5);
	std::nth_element(from, half, until, myfunction);
	return 0;
}
