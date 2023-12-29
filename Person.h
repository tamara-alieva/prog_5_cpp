#pragma once
#include <string>

class Person {
private:
	std::string name;
	int balance;
public:
	Person();
	Person(std::string name);
	Person(int balance);
	Person(std::string name, int balance);
	void setName(std::string name);
	void setBalance(int balance);
	std::string getName();
	int getBalance();
	void input();
	void output();
};