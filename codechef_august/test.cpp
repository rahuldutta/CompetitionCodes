#include <cstring> //for strcmp
#include <algorithm> //for sort
#include <iostream>
using namespace std;

class CStringCompare {
   public:
//Return true if s1 < s2; otherwise, return false.
bool operator()(const char* s1, const char* s2) {
    return strcmp(s1, s2) < 0;
}
};

bool comp(const char* a, const char* b)
{
	return strcmp(a, b) < 0;
}

int main(int numberOfArgs, char** args) {
    sort(args, args + numberOfArgs, comp);
    for (int i = 0; i < numberOfArgs; ++i) {
        cout << args[i] << endl;
    }
    return 0;
}
