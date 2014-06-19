#include "MyIterator.h"

MyIterator& MyIterator::operator++()
{
	++p;
	return *this;
}

bool MyIterator::operator==(const MyIterator& rhs)
{
	return p==rhs.p;
}

bool MyIterator::operator!=(const MyIterator& rhs)
{
	return p!=rhs.p;
}
int& MyIterator::operator*()
{
	return *p;
}

const MyIterator MyIterator::operator+(const MyIterator &other) const {
    MyIterator result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
    result.p += other.p;            // Use += to add other to the copy.
    return result;              // All done!
  }
  
const MyIterator MyIterator::operator-(const MyIterator &other) const {
    MyIterator result = *this;     // Make a copy of myself.  Same as MyClass result(*this);
    result.p -= other.p;            // Use += to add other to the copy.
    return result;              // All done!
  }
