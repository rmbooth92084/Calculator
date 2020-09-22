#ifndef __BUBBLESORT_HPP__
#define __BUBBLESORT_HPP__
/*
	Author: Raymond Booth
	Description: This is my implentation of bubble sort
*/
#include <iostream>
#include <vector>
std::vector<int> BubbleSort(std::vector<int> list){
	int num1, num2, counter;
	counter = 0;//Added this to make this compiler happy

	if (list.empty())//deals with an empty list
		return list;

	while (1){
		for (int i = 0; i < list.size() - 1; i++){
			if (list.at(i + 1) < list.at(i)){
				num1 = list.at(i + 1);
				num2 = list.at(i);

				list.at(i) = num1;
				list.at(i + 1) = num2; //flips the the two numbers
			}
			else
				counter++;
		}
		if (counter == list.size() - 1){// breaks out of while loop if vector is sorted
			/*for(int i = 0; i < list.size(); i++){//prints out the vector
				std::cout << list.at(i) << std::endl;
			}*/
			return list;
		}
		counter = 0;
	}
}
#endif