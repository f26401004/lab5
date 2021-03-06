#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "HugeInt.h"
using namespace std;

ostream& operator << (ostream& out, const HugeInt& number)
{
	if (number.num_list.at(0) < 0)
	{
		out << "-";
	}
	for (int i = 0 ; i < number.num_list.size(); ++i)
                out << std::abs(number.num_list.at(i));
	return out;
}

istream& operator >> (istream& in, HugeInt& number)
{
	string str_num;
	in >> str_num;
	for (int i = 0 ; i < str_num.size() ; ++i)
	{
		if (str_num[0] == '-')
		{
			if (i != 0)
				number.num_list.push_back((-1)*(str_num[i] - '0'));
		}
		else
			number.num_list.push_back(str_num[i] - '0');
	}
	return in;
}

HugeInt operator+(HugeInt a, HugeInt b)
{
	if (a.num_list.size() < b.num_list.size())
        {
                for (int i = a.num_list.size() - 1 ; i > -1 ; --i)
		{
			std::cout << a.num_list.at(i) << std::endl;
                        *(b.num_list.end() - (a.num_list.size() - i)) += a.num_list.at(i);
		}
                for (int i = b.num_list.size() - 1 ; i > -1 ; --i)
                {
                        if (b.num_list.at(i) < -9)
                        {
                                *(b.num_list.begin() + i) += 10;
                                if (i == 0)
                                        b.num_list.insert(b.num_list.begin(), -1);
                                else
                                        --*(b.num_list.begin() + i - 1);
                        }
                        else if (b.num_list.at(i) > 9)
                        {
                                *(b.num_list.begin() + i) -= 10;
                                if (i == 0)
                                        b.num_list.insert(b.num_list.begin(), 1);
                                else
                                        ++*(b.num_list.begin() + i - 1);
                        }
                }
		// erase the zero
		while (b.num_list.at(0) == 0)
		{
			b.num_list.erase(b.num_list.begin());
		}
                return b;
        }
        else
        {
                for (int i = b.num_list.size() - 1 ; i > -1 ; --i)
                        *(a.num_list.end() - (b.num_list.size() - i)) += b.num_list.at(i);
                for (int i = a.num_list.size() - 1 ; i > -1 ; --i)
                {
			if (a.num_list.at(i) < -9)
                        {
                                *(a.num_list.begin() + i) += 10;
                                if (i == 0)
                                        a.num_list.insert(a.num_list.begin(), -1);
                                else
                                        --*(a.num_list.begin() + i - 1);
                        }
                        else if (a.num_list.at(i) > 9)
                        {
                                *(a.num_list.begin() + i) -= 10;
                                if (i == 0)
                                        a.num_list.insert(a.num_list.begin(), 1);
                                else
                                        ++*(a.num_list.begin() + i - 1);
                        }
                }
		// erase the zero
                while (a.num_list.at(0) == 0)
                {
                        a.num_list.erase(a.num_list.begin());
                }
                return a;
        }


}

HugeInt operator-(HugeInt a, HugeInt b)
{
	return a + b * (-1);
}

HugeInt::HugeInt()
{
}

HugeInt::HugeInt(long long int value)
{
	int num_bits = 0;
	long long int buffer = value;
	while(std::abs(buffer / 10) > 0)
	{
		++num_bits;
		buffer /= 10;
	}
	buffer = std::abs(value);
	for (int i = num_bits ; i > -1 ; --i)
	{
		if (value < 0)
			num_list.push_back((-1)*(buffer / pow(10, i)) % 10);
		else
			num_list.push_back((buffer / pow(10, i)) % 10);
	}
}

HugeInt::HugeInt(string s_value)
{
	for (int i = 0 ; i < s_value.size() ; ++i)
	{
		if (s_value[i] == '-')
                        num_list.push_back(0);
                else 
			num_list.push_back(s_value[i] - '0');
	}
}

HugeInt HugeInt::operator*(int coff)
{
	for (int i = 0; i < num_list.size() ; ++i)
		num_list.at(i) = (-1)*num_list.at(i);
	return *(this);
}

HugeInt HugeInt::operator=(HugeInt clone)
{
	num_list.clear();
	for (int i = 0 ; i < clone.num_list.size() ; ++i)
		num_list.push_back(clone.num_list.at(i));
	return *(this);
}

long long int HugeInt::pow(int a, int b)
{
	if (b == 0)
		return 1;
	else
		return a * pow(a, b - 1);
}
