#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

void InsertionSort(std::vector <std::pair<std::string, int>> &str_int_vector);

//key-value class
class CarPair {
	std::string car_name_;
	size_t car_frequency_ = 0;
public:
	CarPair(std::string car_name, int car_frequency) :
		car_name_(car_name),
		car_frequency_(car_frequency) 
	{/*empty*/}

	bool operator<(const CarPair &b) const
	{
		return (car_frequency_ < b.car_frequency_);
	}

	bool operator>(const CarPair &b) const
	{
		return (car_frequency_ > b.car_frequency_);
	}

	void print() const 
	{
		std::cout << car_name_ << ", " << car_frequency_ << std::endl;
	}
};

//comparison functor
struct {
	bool operator()(const CarPair &a, const CarPair &b) const
	{
		return a > b;
	}
} GreaterFrequency;

void ProcessCars(){
	//build car frequency map
	std::map<std::string, size_t> car_frequency_map;
	std::string current_car_name;

	//process input
	while(std::cin >> current_car_name){
		car_frequency_map[current_car_name]++;
	}

	//build CarPair vector
	std::vector <CarPair> carPair_vector;

	for(std::pair<std::string, size_t> car_pair : car_frequency_map){
		carPair_vector.emplace_back(car_pair.first, car_pair.second);
	}

	//sort car_frequency_vector from greatest to least (
	std::sort(carPair_vector.begin(), carPair_vector.end(), GreaterFrequency);

	//print car_frequency_vector
	for (auto it = carPair_vector.begin(); it != carPair_vector.end(); ++it ) {
		it->print();
	}
}

int main(){
	ProcessCars();
	return 0;
}




//If I couldn't remember how to use std::sort...
void InsertionSort(std::vector <std::pair<std::string, int>> &str_int_vector)
{
	size_t length = str_int_vector.size();

	for (size_t i = 1; i < length; ++i) {
		// sort in element i

		// compare against elements 0 through i-1
		size_t j = 0;
		while (j < i) {
			//if out of place
			if (str_int_vector[i].second > str_int_vector[j].second) {
				//swap into place 
				std::pair<std::string, int> temp = str_int_vector[j];
				str_int_vector[j] = str_int_vector[i];

				//str_int_vector[j + 1] = temp;

				//shift elements
				for (size_t k = j + 1; k <= i; ++k) {
					str_int_vector[k].swap(temp);
				}
				break;
			}
			++j;
		}
	}
}