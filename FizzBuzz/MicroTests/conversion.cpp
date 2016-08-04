#include <iostream>
#include <string>


char ReadIn()
{
	std::string s;
	std::cin >> s;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return s[0];
}

void Interperet(char c)
{
	std::cout << c << " read as int: " << static_cast<int>(c) << std::endl;
}

bool Continue() {
	std::cout << "Continue? enter (y)es or (n)o: ";
	char c = ReadIn();
	if (c == 'y') return true;
	else return false;
}

void Loop()
{
	do {
		std::cout << "enter a char: ";
		Interperet(ReadIn());
	} while (Continue());
}

int main()
{
	Loop();
	return 0;
}