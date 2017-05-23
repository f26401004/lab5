#ifndef HUGEINT_H
#define HUGEINT_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class HugeInt
{
	friend ostream& operator << (ostream&, const HugeInt&);
	friend istream& operator >> (istream&, HugeInt&);
	friend HugeInt operator + (HugeInt, HugeInt);
	friend HugeInt operator - (HugeInt, HugeInt);
	public:
		HugeInt();
		HugeInt(long long int);
		HugeInt(string);
		HugeInt operator*(int);
		HugeInt operator=(HugeInt);
	private:
		long long int pow(int, int);
		vector<int> num_list;
		
};
#endif
