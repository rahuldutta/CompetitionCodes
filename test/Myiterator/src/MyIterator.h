// std::iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag

class MyIterator : public std::iterator<std::random_access_iterator_tag, int>
{
	private:
	int *p;
	public:
	MyIterator(int * i) : p(i){}
	MyIterator(const MyIterator& it) : p(it.p){}
	MyIterator& operator++(); 
	bool operator==(const MyIterator&);
	bool operator!=(const MyIterator&);
	int& operator*();
	const MyIterator MyIterator::operator+(const MyIterator &) const;
	const MyIterator MyIterator::operator+(const MyIterator ) const;
};
