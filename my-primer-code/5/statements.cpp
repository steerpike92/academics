#include <iostream>
#include <string>
#include <vector>
#include <map>

void SimpleStatements()
{
	int sum = 0, val = 1;
	while (sum+=val, val++, val <= 10) {}
	//std::cout << sum << std::endl;

}

void Blocks()
{
	//{}	//an empty block, equivalent to a null statement
	//;	//a null statment
}

void Scope()
{
	//control statments only affect the next statment
	//to use multiple statements, put them in a fucking block

	//variables defined in a control statement are scoped to that statement
	//they are destroyed when the statement ends

	std::string s{ "asdfjkl" };

	auto iter = s.begin();

	while ( iter!= s.end()) {
		++iter;
	}
	
}

void IfStatement()
{
	//if (condition)	condition must be convertable to a bool
	//	statment
	
	std::vector<std::string> letter_grades{ "F", "D", "C", "B", "A", "A++" };

	std::vector<int> scores{ 53,16,72,12,90, 100, 73, 63, 89, 95, 50 };


	for (auto grade : scores) {
		std::string current_grade;

		if (grade < 60) {
			current_grade = letter_grades[0];
		}
		else {
			current_grade = letter_grades[(grade - 50) / 10];
		}

		std::cout << grade << " is a " + current_grade << std::endl;
		

	}


}

using CharMap = std::map<char, size_t>;

void VowelSwitch(char c, CharMap &char_map) 
{
	if (!isalpha(c)) return;
	c = static_cast<char>(tolower(c));
	switch (c) {
	case('a') :
		++char_map['a'];
		break;
	case('e') : 
		++char_map['e'];
		break;
	case('i') : 
		++char_map['i'];
		break;
	case('o') :
		++char_map['o'];
		break;
	case('u') : 
		++char_map['u'];
		break;
	default: 
		++char_map['c'];
		break;
	}

}

void SwitchStatement()
{
	std::string text, line;
	while (std::getline(std::cin, line)) {
		text += line+"\n";
	}
	//std::cout << text;

	CharMap char_map;
	for (auto c : text) {
		VowelSwitch(c, char_map);
	}

	for (auto char_count : char_map) {
		if (char_count.first == 'c') {
			continue;
		}
		else {
			std::cout
				<< "There are " << char_count.second << " " << char_count.first
				<< "'s in the text" << std::endl;
		}
		
	}
	std::cout << "There are " << char_map['c'] << " consonants in the text" << std::endl;

}

int main()
{
	//SimpleStatements();
	//Blocks();
	//Scope();
	//IfStatement();
	SwitchStatement();
	return 0;
}