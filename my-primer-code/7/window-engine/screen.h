#pragma once
#include <string>
#include <iostream>

class Screen {
	friend class WindowManager;
public:
	using pos = std::string::size_type;

	
private:
	//Data Members
	pos cursor_{ 0 };
	pos height_{ 0 }, width_{ 0 };
	std::string contents_;

	//Utility Functions
	pos CalcIndex(pos row, pos col) const;
	inline void DoDisplay(std::ostream &os) const;
	
	pos Size() const 
	{
		return width_*height_;
	}

public:
	//Public Interface:

	//Constructors
	Screen() = default;

	Screen(pos height, pos width) :
		height_(height),
		width_(width),
		contents_(height*width, ' ')
	{}

	Screen(pos height, pos width, char c):
		height_(height), 
		width_(width), 
		contents_(height*width,c)
	{}

	//Get specific char
	char Get() const { return contents_[cursor_]; }
	inline char Get(pos row, pos col) const;
	
	//Set specific char (chainable)
	Screen &Set(char c) 
	{ 
		contents_[cursor_] = c; 
		return *this; 
	}

	Screen &Set(pos row, pos col, char c)
	{
		pos index = CalcIndex(row, col);
		contents_[index] = c;
		return *this;
	}

	//Move Cursor to given location (chainable)
	Screen &MoveCursor(pos row, pos col);

	//display (chainable)
	inline Screen &Display(std::ostream &os);
	inline const Screen &Display(std::ostream &os) const;
	friend std::ostream & operator<<(std::ostream &os, const Screen &screen);
};

inline char Screen::Get(pos row, pos col) const
{
	pos index = CalcIndex(row,col);
	return contents_[index];
}

inline Screen & Screen::MoveCursor(pos row, pos col)
{
	cursor_ = CalcIndex(row, col);
	return *this;
}

inline Screen::pos Screen::CalcIndex(pos row, pos col) const
{
	return row*width_ + col;
}

std::ostream & operator<<(std::ostream & os, const Screen & screen)
{
	for (Screen::pos row = 0; row < screen.height_; ++row) {
		for (Screen::pos col = 0; col < screen.width_; ++col) {
			os << screen.Get(row, col);
		}
		os << std::endl;
	}
	return os;
}

inline void Screen::DoDisplay(std::ostream & os) const
{
	os << *this;
}

inline Screen & Screen::Display(std::ostream & os)
{
	this->DoDisplay(os);
	return *this;
}

inline const Screen & Screen::Display(std::ostream & os) const
{
	this->DoDisplay(os);
	return *this;
}



//returning by reference to *this lets us chain commands
//the return is an lvalue to the original object
//screen.move(2,5).set('r'); is a legal chain