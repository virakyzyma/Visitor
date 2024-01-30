#include <iostream>
using namespace std;

class House;
class Bank;
class Factory;
class BaseVisitor abstract
{
public:
	virtual void Visit(House* house) abstract;
	virtual void Visit(Factory* factory) abstract;
	virtual void Visit(Bank* bank) abstract;
};

class Building abstract
{
	double term;
	double price;
public:
	void SetPrice(double price) 
	{ 
		this->price = price; 
	}
	void SetTerm(double term)
	{ 
		this->term = term;
	}
	double GetPrice()
	{
		return price; 
	}
	double GetTerm()
	{
		return term; 
	}
	virtual void Accept(BaseVisitor* visitor)abstract;
};

class House : public Building
{
public:
	void Accept(BaseVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};
class Factory : public Building
{
public:
	void Accept(BaseVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};
class Bank : public Building
{
public:
	void Accept(BaseVisitor* visitor) override
	{
		visitor->Visit(this);
	}
};


class Visitor : public BaseVisitor
{
public:
	void Visit(House* house) override
	{
		cout << "Medical insurance";
		cout << "\nPrice: " << house->GetPrice();
		cout << "\nTerm: " << house->GetTerm();
	}
	void Visit(Factory* factory) override 
	{
		cout << "\nInsurance from fire";
		cout << "\nPrice: " << factory->GetPrice();
		cout << "\nTerm: " << factory->GetTerm();
	}
	void Visit(Bank* bank) override 
	{
		cout << "\nInsurance from robbery";
		cout << "\nPrice: " << bank->GetPrice();
		cout << "\nTerm: " << bank->GetTerm();
	}
};


int main() 
{
	BaseVisitor* visitor = new Visitor;
	Bank* bank = new Bank;
	House* house = new House;
	Factory* factory = new Factory;

	house->SetPrice(10000);
	house->SetTerm(2);
	house->Accept(visitor);

	factory->SetPrice(20000);
	factory->SetTerm(3);
	factory->Accept(visitor);

	bank->SetPrice(30000);
	bank->SetTerm(4);
	bank->Accept(visitor);

	delete visitor;
	delete house;
	delete factory;
	delete bank;
	return 0;
}