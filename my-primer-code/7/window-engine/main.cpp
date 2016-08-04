#include <iostream>
#include "screen.h"
#include "window-manager.h"
int main()
{
	Screen screen{ 10,16,'z' };
	
	//std::cout << screen;
	
	//screen.Display(std::cout);

	WindowManager manager;

	auto i = manager.AddScreen(screen);

	//manager.Display(0);
	//manager.Display(i);

	system("pause");
	return 0;
}