#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

__interface ISort
{
public:
	void Sort(vector<string>& v) = 0;
};

class AlphabetSort : public ISort
{
public:
	void Sort(vector<string>& v)
	{
		sort(v.begin(), v.end());
	}
};

class SizeSort : public ISort
{
public:
	void Sort(vector<string>& v)
	{
		sort(v.begin(), v.end(), [](string a, string b) {return a.size() < b.size(); });
	}
};

class SortMachine
{
private:
	ISort* method = nullptr;
public:
	void SetMethod(ISort* method)
	{
		this->method = method;
	}
	void Sort(vector<string>& v)
	{
		if (method != nullptr)
			method->Sort(v);
	}

};