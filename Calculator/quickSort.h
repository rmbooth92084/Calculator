#ifndef __QUICKSORT_H__
#define __QUICKSORT_H__
//#include <iostream>
/*
 * 	author: Raymond Booth
 * 	 */
#include <vector>

 /*
  * This function selects the pivit as the end of point that is inputed
  * as the pivot for the qucick sortand sorts that pivot into the correct
  * place
  */
int sort(std::vector<int>& vec, int start, int end)
{
	int pivot = vec.at(end);
	int notadd = 0;
	int offsetOne = 0;
	int offsetTwo = 0;
	int count = 0;
	int loop = 0;
	//this is when we get to a leaf node
	if (start == end)
		return end;
	int smallNum, largeNum;
	while (1)
	{

		//std::cout<< "in while loop: " << loop << std::endl;
		//these two are the moving pointers going through the vector
		smallNum = start + offsetOne;
		largeNum = end - offsetTwo;

		//this moves the pivot to the correct position
		if ((smallNum) >= ((largeNum)+1) || smallNum >= end)
		{
			if (smallNum >= end)
				return end;
			int termOne = vec.at(largeNum + 1);
			vec.at(end) = termOne;
			vec.at(largeNum + 1) = pivot;
			return largeNum + 1;
		}
		if (vec.at(smallNum) > pivot)
		{
			notadd = 1;
			if (vec.at(largeNum) < pivot)
			{
				int numOne = vec.at(smallNum);
				int numTwo = vec.at(largeNum);

				vec.at(smallNum) = numTwo;
				vec.at(largeNum) = numOne;
				notadd = 0;
			}
			else
				offsetTwo++;
		}
		else if (notadd == 0)
			offsetOne++;

		loop++;
	}
}
/*
 * This funtion does the devide a conquer and divided the inputed
 * vector in such a way so it can call the sort function to dort
 * properly
 */
void quick(std::vector<int>& vec, int lowPoint, int highPoint)
{
	//Base case is when the low Point becomes equal to the high point meaning that it got to the leaf node
	if (lowPoint < highPoint)
	{
		int currentPos = sort(vec, lowPoint, highPoint);
		//std::cout<< "done with first sort" << std::endl;
		//makes the branch left of the previous pivot
		//of the numbers greater than pivot
		quick(vec, currentPos + 1, highPoint);
		//std::cout<< "done with first recursive call" << std::endl;
		//makes other branch left of previous pivot
		//of numbers less than pivot
		quick(vec, lowPoint, currentPos - 1);
		//std::cout<< "done with second recursive call" << std::endl;
	}
}
/*
 * This function is to help be consisted with the pormat of
 * the other sortin function do it can take in the vecor and
 * pass it along to but sorted in the quick sort way and then
 * return the sorted vector
 */
std::vector<int> QuickSort(std::vector<int> vec)
{
	quick(vec, 0, vec.size() - 1);
	return vec;
}
#endif