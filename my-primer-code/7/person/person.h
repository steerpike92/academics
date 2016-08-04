#pragma once
#include <string>
#include <iostream>

class Person {
	friend std::istream& operator >> (std::istream& is, Person& person);
	friend std::ostream& operator << (std::ostream& os, const Person& person);

	std::string name_;
	std::string address_;
public:
	Person() = default;

	Person(std::istream& is) {
		is >> *this;
	}

	Person(std::string name, std::string address) :
		name_(name),
		address_(address)
	{}
	
	std::string GetName() const { return name_; }
	std::string GetAddress() const { return address_; }
};


std::istream& operator >> (std::istream& is, Person& person) 
{
	//in
	std::getline(is, person.name_);
	std::getline(is, person.address_);
	return is;
}

std::ostream& operator << (std::ostream& os, const Person& person) 
{
	//out
	os << person.name_ << "\n" << person.address_;
	return os;
}