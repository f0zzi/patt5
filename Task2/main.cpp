#include <iostream>
#include "Observer.h"
using namespace std;

int main()
{
	Euro euro(28.00, 29.00);
	IClient* bank = new Bank;
	IClient* broker = new Broker;
	euro.Attach(bank);
	euro.Attach(broker);
	euro.SetPrice(29.5, 30.6);
	euro.SetPrice(27.5, 30.2);
	system("pause");
	return 0;
}