#ifndef __SELECTIONSORT_HPP__
#define __SELECTIONSORT_HPP__
/*
 * author: Raymond Booth
 * description: my implememtation of selection sort
 */


#include <iostream>
#include <vector>
std::vector<int> SelectionSort(std::vector<int> list)
{
	int smallNum;//saves the smallest number found so far
	int pos;//saves the postion of that smallest numebr
	if (list.empty())//deals with an empty list
		return list;

	for (int i = 0; i < list.size(); i++)
	{
		int otherNum;
		smallNum = list.at(i);

		for (int j = i; j < list.size(); j++)
		{
			if (smallNum > list.at(j)) //if it finds a smaller number it saves it
			{
				pos = j;
				smallNum = list.at(j);
			}
		}
		//does the number swap by current smallest number and the current beginning of the vector
		otherNum = list.at(i);//gets the number at the current beginning of the vector
		if (otherNum != smallNum)//makes sure you don't move a number that is already in the right place
		{
			list.at(i) = smallNum;
			list.at(pos) = otherNum;
		}
		//std::cout<< "number: " << list.at(i) << std::endl;  
	}
	return list;
}
#endif