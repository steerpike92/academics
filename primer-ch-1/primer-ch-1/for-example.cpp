#include "header.h"
#include <iostream>

void ForExample() {


	for (	
		int i = 0;	//init-statement : creates int i which has for-loop-scope. init statment executes once 
		i < 10;		//condition : (bool) test for entry and re-entry into body
		i += 2		//expression : evaluated after body
			) 

	{// begin body block
		std::cout << i << std::endl;
	}//end body


}