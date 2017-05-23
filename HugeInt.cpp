#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "HugeInt.h"
using namespace std;

ostream& operator << (ostream& out, const HugeInt& number)
{
	if (number.num_list.at(0) == 0)
	{
		out << '-';
		for (int i = 1 ; i < number.num_list.size() ; ++i)
			out << number.num_list.at(i);
	}
	else
	{
		for (int i = 0 ; i < number.num_list.size(); ++i)
                        out << number.num_list.at(i);
	}
	return out;
}

istream& operator >> (istream& in, HugeInt& number)
{
	string str_num;
	in >> str_num;
	for (int i = 0 ; i < str_num.size() ; ++i)
	{
		if (str_num[i] == '-')
			number.num_list.push_back(0);
		else
			number.num_list.push_back(str_num[i] - '0');
	}
	return in;
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
	if (value < 0)
		num_list.push_back(0);
	for (int i = num_bits ; i > -1 ; --i)
		num_list.push_back((buffer / pow(10, i)) % 10);
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

HugeInt HugeInt::operator+(HugeInt add_object)
{
	if (num_list.at(0) == 0 && add_object.num_list.at(0) == 0)
	{
		if (num_list.size() > add_object.num_list.size())
		{
			for (int i = 0 ; i < add_object.num_list.size() ; ++i)
                	        *(num_list.begin() + i) += add_object.num_list.at(i);
			for (int i = 0 ; i < num_list.size() ; ++i)
	                {
                        	if (*(num_list.end() - 1 - i) > 9)
                	        {
        	                        *(num_list.end() - 1 - i) -= 10;
	                                if (num_list.end() - 2 - i != num_list.begin() + 1)
                                        	++(*(num_list.end() - 2 - i));
                                	else
                        	                num_list.insert(num_list.begin() + 1, 1);
                	        }
        	
        	        }
	                return *(this);
		}
		else
		{
			for (int i = num_list.size()-1 ; i > 0 ; --i)
                                *(add_object.num_list.end() - 1 - i) += num_list.at(i);
			for (int i = 0 ; i < add_object.num_list.size()-2 ; ++i)
                        {
                                if (*(add_object.num_list.end() - 1 - i) > 10)
                                {
                                        *(add_object.num_list.end() - 1 - i) -= 10;
                                        if (add_object.num_list.end() - 2 - i != add_object.num_list.begin() + 1)
                                                ++(*(add_object.num_list.end() - 2 - i));
                                        else
                                                add_object.num_list.insert(add_object.num_list.begin() + 1, 1);
                                }

                        }
                        return add_object;
		}
	}
	else if (num_list.at(0) != 0 && add_object.num_list.at(0) != 0)
	{
		if (num_list.size() > add_object.num_list.size())
		{
			for (int i = add_object.num_list.size()-1 ; i > -1 ; --i)
			{
					
                                *(num_list.end() - add_object.num_list.size() + i) += add_object.num_list.at(i);
				std::cout << *(num_list.end() - 1 - i) << std::endl;
			}
			for (int i = 0 ; i < num_list.size() ; ++i)
                        {
                                if (*(num_list.end() - 1 - i) > 9)
                                {
                                        *(num_list.end() - 1 - i) -= 10;
                                        if (num_list.end() - 2 - i != num_list.begin())
                                                ++(*(num_list.end() - 2 - i));
                                        else
                                                num_list.insert(num_list.begin(), 1);
                                }
                        }
                        return *(this);
		}
		else
		{
			for (int i = 0 ; i < num_list.size() ; ++i)
			{
                                *(add_object.num_list.begin() + i) += num_list.at(i);
				std::cout << add_object.num_list.at(i) << std::endl;
			}
			for (int i = 0 ; i < add_object.num_list.size() ; ++i)
                        {
                                if (*(add_object.num_list.end() - 1 - i) > 9)
                                {
                                        *(add_object.num_list.end() - 1 - i) -= 10;
                                        if (add_object.num_list.end() - 2 - i != add_object.num_list.begin())
                                                ++(*(add_object.num_list.end() - 2 - i));
                                        else
                                                add_object.num_list.insert(add_object.num_list.begin(), 1);
                                }

                        }
                        return add_object;
		}
	}
	else if (num_list.at(0) == 0 && add_object.num_list.at(0) != 0)
	{
		if (num_list.size()  -1 > add_object.num_list.size())
                {
                        for (int i = add_object.num_list.size()-1 ; i > -1 ; --i)
                                *(num_list.end() - 1 - i) -= add_object.num_list.at(i);
			for (int i = 0 ; i < num_list.size()-1 ; ++i)
                        {
                                if (*(num_list.end() - 1 - i) < 0)
                                {
                                        *(num_list.end() - 1 - i) += 10;
//                                        if (num_list.end() - 2 - i != num_list.begin() + 1)
                                                --(*(num_list.end() - 2 - i));
//                                        else
//                                                num_list.insert(num_list.begin() + 1, -1);
                                }
                        }
			if (*(num_list.begin()) < 0)
				*(num_list.begin()) == 0;
                        return *(this);
                }
                else
                {
                        for (int i = num_list.size()-1 ; i > -1 ; --i)
                                *(add_object.num_list.end() - 1 - i) -= num_list.at(i);
                }
	}
	else if (num_list.at(0) != 0 && add_object.num_list.at(0) == 0)
        {
		if (num_list.size() > add_object.num_list.size() - 1)
                {
                        for (int i = add_object.num_list.size()-1 ; i > -1 ; --i)
                                *(num_list.end() - 1 - i) -= add_object.num_list.at(i);
                }
                else
                {
                        for (int i = num_list.size()-1 ; i > -1 ; --i)
                                *(add_object.num_list.end() - 1 - i) -= num_list.at(i);
                }
        }
/*
	if (add_object.num_list.size() < num_list.size())
	{
		for (int i = add_object.num_list.size()-1 ; i > -1 ; --i)
		{
			std::cout << i << std::endl;
               		*(num_list.end() - 1 - i) += add_object.num_list.at(i);
		}
		for (int i = 0 ; i < num_list.size()-1 ; ++i)
	        {
        	        if (*(num_list.end() - 1 - i) > 10)
                	{
                        	*(num_list.end() - 1 - i) -= 10;
	                        if (num_list.end() - 2 - i != num_list.begin())
        	                        ++(*(num_list.end() - 2 - i));
                	        else
                        	        num_list.insert(num_list.begin(), 1);
	                }
	
	        }
        	return *(this);
	}
	else
	{
		for (int i = num_list.size()-1 ; i > -1 ; --i)
                {
                        *(add_object.num_list.end() - 1 - i) += num_list.at(i);
                }
		for (int i = 0 ; i < add_object.num_list.size()-1 ; ++i)
                {
                        if (*(add_object.num_list.end() - 1 - i) > 10)
                        {
                                *(add_object.num_list.end() - 1 - i) -= 10;
                                if (add_object.num_list.end() - 2 - i != add_object.num_list.begin())
                                        ++(*(add_object.num_list.end() - 2 - i));
                                else
                                        add_object.num_list.insert(add_object.num_list.begin(), 1);
                        }

                }
                return add_object;


	}
*/
}


HugeInt HugeInt::operator-(HugeInt minus_object)
{
	return *(this) + minus_object*(-1);
}

HugeInt& HugeInt::operator*(int coff)
{
	num_list.insert(num_list.begin(), 0);
	return *(this);
}

HugeInt& HugeInt::operator=(HugeInt clone)
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
