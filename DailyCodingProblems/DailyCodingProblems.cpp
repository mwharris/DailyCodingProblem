#include <iostream>
#include <list>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;

/*
Problem 1
Given a list of numbers, return whether any two sums to k.  For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
Bonus: Can you do this in one pass ?
*/
void problem1()
{
	bool found = false;
	int k = 17;
	int test[4] = { 10, 15, 3, 7 };
	std::unordered_map<int, int> solutions;

	for (int x = 0; x < 4; x++) {
		int value = test[x];
		// Check to see if the current value is the solution to another number
		if (!solutions.empty() && solutions.find(value) != solutions.end()) {
			// If so, we're done
			found = true;
			break;
		}
		else {
			// Check what number we need to make a 17 from the current value
			int solution = 17 - value;
			// Add that to our Hashmap
			solutions.insert({ solution, solution });
		}
	}

	std::cout << (found ? "Found!" : "Not Found") << std::endl;
}

int main()
{
	problem1();
	
}