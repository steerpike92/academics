#pragma once
#include "screen.h"
#include <vector>

class WindowManager {
public:
	using screen_index = std::vector<Screen>::size_type;

private:
	std::vector<Screen> screens_{ Screen(24,80,' ') };

public:
	void Clear(size_t screen_index)
	{
		Screen &current_screen = screens_[screen_index];
		Screen::pos length = current_screen.Size();
		current_screen.contents_ = std::string(length, ' ');
	}

	screen_index AddScreen(const Screen &screen) 
	{
		screens_.push_back(screen);
		return screens_.size()-1;
	}

	void Display(screen_index i)
	{
		screens_[i].Display(std::cout);
	}

private:
	

};