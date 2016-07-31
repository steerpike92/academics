#include <iostream>
#include <string>
#include <vector>
void Notes()
{
	// conditional opterator (the ?: operator)
	//allows for simple if-else logic in a single expression

	//cond ? expr1 : expr2;

	//i.e.
	//if (cond){expr1;}
	//else {expr2;}

	//expr1 and expr2 must yeild a common type, or be convertable to a common type

	double grade = 68;
	std::string final_grade = (grade < 60) ? "failing" : "passing";

	std::cout << grade << " is a " << final_grade << " grade" << std::endl;
}

void Problem_21()
{
	std::vector<int> ivec{ 1,2,3,4,5,6,7,8,9,10,11 };

	for (auto &i : ivec) {
		i = (i % 2) ? i * 2 : i;
	}

	for (auto i : ivec)
		std::cout << i << std::endl;

}

std::string PassRatingConditional(int grade)
{
	std::string final_grade = 
		(grade > 60) ? 
			((grade > 90) ?
				("high pass")
				:((grade > 75) ?
					("pass")
					:("low pass")))
			:("fail");
	
	return final_grade;
}

std::string PassRatingIf(int grade)
{
	std::string final_grade;
		
	if (grade > 60) {
		if (grade > 90) {
			final_grade = "high pass";
		}
		else {
			if (grade > 75) {
				final_grade = "pass";
			}
			else {
				final_grade = "low pass";
			}
		}
	}
	else {
		final_grade = "fail";
	}

	return final_grade;
}

void Problem_22()
{
	std::vector<int> grades{ 23,63,71,12,92,78,43 };
	
	for (auto i : grades) {
		std::cout << i << " is a " << PassRatingIf(i) << std::endl;
	}
}

int main()
{
	//Notes();
	//Problem_21();
	//Problem_22();


	return 0;
}