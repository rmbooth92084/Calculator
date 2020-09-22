#ifndef __MERGESORT_H__
#define __MERGESORT_H__
/*
 * Author: Raymond Booth
 */

#include <iostream>
#include <vector>
 /*
  * 	This takes the vector and the markers given by the mergeFormat function
  * 	and orginizes the ssction that are marked out by it
  */
void merge(std::vector<int>& vec, int leftMark, int rightMark, int middleMark)
{
	int tempVal;

	for (int i = leftMark; i <= middleMark; i++)
	{
		tempVal = 0;
		for (int j = middleMark + 1; j <= rightMark; j++)
		{
			if (vec.at(j) < vec.at(i))
			{
				tempVal = vec.at(j);
				vec.erase(vec.begin() + j);
				vec.insert(vec.begin() + i, tempVal);

				/*	std::cout<< "finished swap" <<std::endl;
					for(int i = 0; i < vec.size(); i++)
					{
						std::cout<< vec.at(i) << " ";
					}
					std::cout<<std::endl;
				*/
			}
		}
	}

}

/*
 * This function provided the divide and coquure aspect
 * of merge sort by useing recurtion to divide up the vector
 * and call the meger fucntion to orginize the sections that
 * are divided up by this function
 */
void mergeFormat(std::vector<int>& vec, int left, int right)
{
	int middle;
	if (left < right)
	{
		middle = left + (right - left) / 2;// finds the middle of the the portion of vector selected
		//these two recusive calls will get it so we can divide up the parts of
		//the vector to make it a merge sort 
		mergeFormat(vec, left, middle);
		mergeFormat(vec, middle + 1, right);
		//starts merging the parts adn sorting the vector
		merge(vec, left, right, middle);
	}
}
/*
 *  This function is to help be consisted with the format of
 *  the other sortin function do it can take in the vector and
 *  pass it along to but sorted in the merge sort way and then
 *  return the sorted vector
 */
std::vector<int> MergeSort(std::vector<int> vec)
{
	mergeFormat(vec, 0, vec.size() - 1);
	//called it a second time to fix an issue with how I implemented the sorting 
	//when it merges
	mergeFormat(vec, 0, vec.size() - 1);
	return vec;
}
#endif