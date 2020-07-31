// Problem2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using std::cout;
using std::endl;

/*
Problem 2
Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.
For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
Follow-up: what if you can't use division?
*/
void problem2(int input[5])
{
	int left[5];
	int right[5];

	// Create the L array
	// L is the cumulative product of the index (all numbers to be the left + the current one multiplied by each other)
	int max = 1;
	for (int i = 0; i < 5; i++) {
		max *= input[i];
		left[i] = max;
	}

	// Create the R array
	// R is the same but starting on the right
	max = 1;
	for (int i = 4; i >= 0; i--) {
		max *= input[i];
		right[i] = max;
	}

	//Using L and R you can find the answer by doing L[i - 1] * R[i + 1]
	cout << "[ ";
	for (int i = 0; i < 5; i++) {
		if (i == 0) {
			cout << right[i + 1] << ", ";
		}
		else if ((i + 1) == 5) {
			cout << left[i - 1];
		}
		else {
			cout << left[i - 1] * right[i + 1] << ", ";
		}
	}
	cout << " ]" << endl;
}

int main()
{
	int input[5] = { 1, 2, 3, 4, 5 };
	problem2(input);
}