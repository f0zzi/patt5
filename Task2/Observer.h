#pragma once
#include <iostream>
#include <vector>	
#include <algorithm>
using namespace std;

enum RATE { DOWN, UP };
string Rate[] { "DOWN", "UP" };

class Currency;

__interface IClient
{
public:
	virtual void Update(Currency* c) = 0;
};

class Currency abstract
{
private:
	string name;
	double sell;
	double buy;
	RATE rate = DOWN;
	vector<IClient*> clients;
public:
	Currency(double sell, double buy) :sell(sell), buy(buy) {}
	void Attach(IClient* client)
	{
		clients.push_back(client);
	}
	void Detach(IClient* client)
	{
		auto del = find(clients.begin(), clients.end(), client);
		if (del != clients.end())
			clients.erase(del);
	}
	void Notify()
	{
		for (auto el : clients)
			el->Update(this);
	}
	void SetPrice(double sell, double buy)
	{
		if (this->sell > sell)
			rate = DOWN;
		else
			rate = UP;
		this->sell = sell;
		this->buy = buy;
		cout << name << "\t- Sell: " << sell << " Buy: " << buy << " Rate: " << Rate[rate] << endl;
		Notify();
	}
	RATE GetRate()
	{
		return rate;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName() const { return name; }
};
class Euro : public Currency
{
public:
	Euro(double sell, double buy) :Currency(sell, buy) { SetName("Euro"); }
};

class Bank: public IClient
{
private:
	string name = "Privat";
public:
	void Update(Currency* c)
	{
		if (c->GetRate() == DOWN)
			cout << "Bank is buying " << c->GetName() << endl;
	}
};

class Broker : public IClient
{
private:
	string name = "John";
public:
	void Update(Currency* c)
	{
		if (c->GetRate() == DOWN)
			cout << "Broker is buying " << c->GetName() << endl;
		else
			cout << "Broker is selling " << c->GetName() << endl;
	}
};