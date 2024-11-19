using namespace std;

#include "dishstack.cpp"
#include <iostream>
#include <string>
#include <assert.h>

class Dish {
    private:
	    string description;

    public:
	    Dish() {
	    	this->description = "This is a Standard Dish";
	    }

	    Dish(string description) {
	    	this->description = description;
	    }

	    string get_description() {
		    return this->description;
	    }
};

int main()
{
    DishStack<Dish> stack = DishStack<Dish>(5);

	assert(stack.size() == 0);

    try
	{
		Dish new_dish;
		new_dish = stack.pop();
	}
	catch(const std::invalid_argument &e)
	{
		cerr << e.what() << endl;
	}
	
	try
	{
		Dish new_dish;
		new_dish = stack.peek();
	}
	catch(const std::invalid_argument &e)
	{
		cerr << e.what() << endl;
	}

	Dish one_dish("First Dish");
	Dish two_dish("Second Dish");
	Dish three_dish("Third Dish");

	stack.push(one_dish);
	stack.push(two_dish);
	stack.push(three_dish);

	assert(stack.size() == 3);

	Dish four_dish("Fourth Dish");
	Dish five_dish("Fifth Dish");

	stack.push(four_dish);
	stack.push(five_dish);

	assert(stack.size() == 5);

	try
	{
		Dish extra_dish("This Will Not Push");
		stack.push(extra_dish);
	}
	catch(const std::invalid_argument &e)
	{
		cerr << e.what() << endl;
	}

	Dish popped = stack.pop();

	assert(popped.get_description() == "Fifth Dish");

	cout << "Dish Stack Code Works" << endl;
	

    return 0;
}