#pragma once
#include <iostream>
using namespace std;

class Poll abstract
{
public:
	void TemplateMethod()
	{
		Begin();
		Theory();
		Practice();
		Result();
		Completion();
	}
	virtual void Begin()
	{
		cout << "Begin" << endl;
	}
	virtual void Theory()
	{
		cout << "Theory" << endl;
	}
	virtual void Practice()
	{
		cout << "Practice" << endl;
	}
	virtual void Result()
	{
		cout << "Result" << endl;
	}
	virtual void Completion()
	{
		cout << "Completion" << endl;
	}
};

class Credit : public Poll
{
public:
	void Theory()
	{
		cout << "Credit theory" << endl;
	}
};
class Exam : public Poll
{
public:
	void Practice()
	{
		cout << "Exam pracrice" << endl;
	}
};