#include <iostream>
#include "Strategy.h"
using namespace std;

void Print(vector<string>& v)
{
	for (auto el : v)
		cout << el << "  ";
	cout << endl;
}

int main()
{
	vector<string> v{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };
	ISort* alpha = new AlphabetSort;
	ISort* sizes = new SizeSort;
	SortMachine sort;
	cout << "Alpha: ";
	sort.SetMethod(alpha);
	sort.Sort(v);
	Print(v);
	cout << "Size: ";
	sort.SetMethod(sizes);
	sort.Sort(v);
	Print(v);
	cout << endl;
	system("pause");
	return 0;
}