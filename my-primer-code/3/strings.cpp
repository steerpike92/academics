//	section 3.2, std::string
//	7/28/2016

#include <iostream>
#include <string>

using std::string;

//3.2.1
//======
void StringInits()
{
	//if an initializer uses "=" you are really initializing the rhs and then
	//invoking the copy constructor.
	//different than assignment which also uses "="

	string s1;		//default initialization to empty string	
	

	string s2(s1);		//copy construction
	string s3{ s2 };	//list copy construction

	string s4 = "ey";	//copy initialization				
	string s5("ey");	//string literal initialization	
	string s6("what?",3);	//takes first 3 characters of string literal
	string s7("what?", 30);	//read garbage past end of string literal. I would guess undefined behavior
				//yep. It even changes run to run while the rest of the program is 100% deterministic

	string s8(30, 'c');	//initialize s8 with 30 copies of char 'c'


	//note that the following are equivalent

	string s9(30, 'l');

	string s10 = string(30, 'l');

	string temp=string(30, 'l');
	string s11 = temp;

	//except s9 is clearly the best;


	//std::cout << s7 << std::endl;
	
}

//3.2.2
//======
void StringOps()
{
	string s;		
	std::cin >> s;			//istream >> string;		
	////////////////////		//read whitespace separated input into string. returns istream
					//i.e. the result of the expression is an istream object
					//note that this just takes the first word of input

	std::cout << s << std::endl;	//ostream << string;		read string into output
	////////////////////
	std::getline(std::cin, s);	//read in a line of input.	returns istream
	////////////////////		//note that is>>s only cared for words.
					//getline reads everything up to the newline character,
					//the newline character is not included in the string, but isn't destroyed from the input either
	std::cout << s << std::endl;
	
	bool e=s.empty();		//returns true if s is empty string, false otherwise
	////////////////////
	auto len = s.size();		//returns number of characters in s
					//auto deduces type as std::string::size_type.
					//can also use size_t
					//important because strings can potentially be bigger than an int can represent!
					//i.e. 2 billion characters. not infeasible for dna strands or something
	////////////////////
	int n = 2;

	char &c = s[n] ;		//[] operator returns reference to char at position n in s; positions indexed from 0;
	////////////////////
	c = 'z';
	std::cout << s << std::endl;;

	string s2{ "blarh" };

	string s3 = s + s2;		// + operator returns string concatonation of s and s2
	////////////////////
	
	//note
	//s3 = "2041" + s1		//legal, + result stored as string
					//we can use one type where another is expected
					//so long as there is a conversion between the type and the expected type

	//s3 = "2041" + "2491"		//error,  can't add string literal type

	//s3 = s2 + "12124" + "0921"	//legal, result of first + operation stored as string, then chained forward
					//i.e. s3 = (s2+"12124") + "0921";
	//s3 = "12124" + "0921" + s2	//error, first operation is adding two string literals

	std::cout << s3 << std::endl;

	std::cout << s2 << std::endl;
	s2 = s;				// = operator, copy assignment
	////////////////////
	std::cout << s2 << std::endl;

	bool are_equal = s2 == s;	// == operator checks equality
	////////////////////
	bool are_equa1 = s2 != s;	// != operator for non equality.
	////////////////////
					//both case sensitive

	//<, <=, >, >=			//comparisons using dictionary ordering with case sensitivity
	////////////////////

	//always remember, string literals are NOT std::string objects
}

void GetLine()
{
	std::string s;
	while (std::getline(std::cin, s)) {
		std::cout << s<<std::endl;
	}
}

//misread problem, I mean "reinterpreted"
void Problem_4()
{
	//compare strings s1 and s2 alphabetically for storing result ptrs
	string s1, s2, *smaller=nullptr, *larger=nullptr;
	std::cin >> s1 >> s2;
	
	if (s1 < s2) {
		smaller = &s1;
		larger = &s2;
	}
	else if (s1>s2) {
		larger = &s1;
		smaller = &s2;
	}
	
	if (s1 == s2) {
		std::cout << s1<<", and " << s2 << " are equal.";
	}
	else {
		std::cout << *smaller << " comes before " << *larger;
	}

}

//3.2.3

void RangeBasedFor()
{
	string s{ "a bunch of characters" };

	//range-based for
	for (auto c : s) {			//auto deduced to be char
		//std::cout << c << std::endl;
	}

	s = "Howdy! B1Z.Nasty!>!>!";
	
	//decltype is great when you would have used auto, but you want to define the
	//variable before the expression it's really used in.
	decltype(s.size()) punct_count{ 0 };

	for (auto c : s) {			//auto deduced to be char
		if (ispunct(c)) {
			++punct_count;
			std::cout << c;
		}
	}

}

template< class T > 
inline void
print(T t)
{
	std::cout << t << std::endl;
}

void CharOps()
{
	char c='c';

	//sort of bool. returns an int indicating the type, 0 if the answer to the question is no.
	print(isalnum(c));	//is letter or digit (alpha numeric)
	print(isalpha(c));	//is letter
	print(iscntrl(c));	//is control character
	print(isdigit(c));	//is digit
	print(isxdigit(c));	//is hexidecimal digit
	print(isgraph(c));	//is printable and not a space
	print(isspace(c));	//is space
	print(isprint(c));	//is printable (space or character)
	print(ispunct(c));	//is punctuation character (not a control character, digit, letter, or printable whitespace)
	print(islower(c));	//is lowercase letter
	print(isupper(c));	//is uppercase letter

	print(c=tolower(c));	//if c is upper or lower, return lowercase c. Note that expression c=tolower(c) returns  char &c; 
	decltype(c = tolower(c)) C=c;//see

	print(c=toupper(c));	//if c is upper or lower, return uppercase c

	print(char(tolower('c')));	//temporary expression from the ASCII or whatever
}

void MakeUpper(string &s)
{
	for (auto &c : s) {
		c = toupper(c);
	}
}

void UseMakeUpper()
{
	string lower{ "sad lowercase string" };
	std::cout << lower << std::endl;
	MakeUpper(lower);
	std::cout << lower << std::endl;
}

void Subscripting()
{
	string str = "blah blahh";
	auto len = str.length();
	decltype (len) i = 0;

	if (len != 0) {	//or (!str.empty())
		str[i] = toupper(str[i]);
	}
	std::cout << str << std::endl;

	
	
}

void FirstWordUpper()
{
	string str = "blah blahh";
	
	for (size_t i = 0; i < str.length() && !isspace(str[i]); ++i) {
		str[i] = toupper(str[i]);
	}

	std::cout << str << std::endl;
}

void Problem_11()
{
	const string s = "keep out!";
	for (auto &c : s) {
		std::cout << c;
	}
}

int main()
{
	//StringInits();
	//StringOps();
	//GetLine();
	//Problem_4();
	//RangeBasedFor();
	//CharOps();
	//UseMakeUpper();
	//Subscripting();
	//FirstWordUpper();
	//Problem_11();

	return 0;
}