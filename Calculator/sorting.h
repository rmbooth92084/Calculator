#ifndef _SORTING_H_
#define _SORTING_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;
//global variable
vector<int> list;

/*
 * This funtion will prompt the user to select what type of
 * sort to use on thier list of integers
 */
void selectSort()
{
	cout << "Please select a sorting method: " << endl;
	cout << "a) Bubble sort " << endl;
	cout << "b) Selection sort " << endl;
	cout << "c) Quick sort " << endl;
	cout << "d) Merge sort " << endl;

	char userInput;
	int validInput;
	cin >> userInput;
	while (1)
	{
		validInput = 1;


		switch (userInput)
		{
		case 'a':
		case 'A':
			list = BubbleSort(list);
			break;
		case 'b':
		case 'B':
			list = SelectionSort(list);
			break;
		case 'c':
		case 'C':
			list = QuickSort(list);
			break;
		case 'd':
		case 'D':
			list = MergeSort(list);
			break;
		default:
			validInput = 0;
			cout << "invalid input, please try again" << endl;
			cin >> userInput;
			break;
		}
		if (validInput)
			break;
	}

}
/*
 * This function propts the user to input a list of integers
 * to sort in another punction
 */
void getUserListInput()
{
	cout << "Please enter a list of integers to be sorted from least to greatest." << endl;
	cout << "Must input 5 integers." << endl;
	int input;
	for (int i = 0; i < 5; i++)
	{
		cin >> input;
		list.push_back(input);
	}
}

#endif // _SORTING_H_