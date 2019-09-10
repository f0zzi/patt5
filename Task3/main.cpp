#include <iostream>
#include "Template.h"
using namespace std;

int main()
{
	Credit credit;
	Exam exam;
	cout << "Credit:" << endl;
	credit.TemplateMethod();
	cout << "Exam:" << endl;
	exam.TemplateMethod();
	system("pause");
	return 0;
}