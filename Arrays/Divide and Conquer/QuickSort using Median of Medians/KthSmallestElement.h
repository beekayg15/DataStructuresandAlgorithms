
// Header Files
#include <iostream>			// For standard input/ouput handling
#include <vector>			// To use dynamic arrays
#include <algorithm>			// To use sort() function
#include <cmath>			// To use ceil() function

// Marcos
#define vint vector<int>		// vint refers to vector<int>

/*

Median of Medians Algorithms for kth smallest element

Time Complexity : O(N), N -> Number of elements
Space Complexity : O(N), N -> Number of elements

*/

using namespace std;			// Using the standard namespace

// Function Prototypes
void swap (vint &arr , int i , int j);
int partition (vint &arr , int start , int end , int pivot);
int kthSmallestElement (vint arr , int start , int end , int k);

// ----------------------------------------------------
// A Function to swap values in two indices of an array
//	Description	: Swaps elements in an array
//	arr 		- dynamic array
//	i 		- index 1
//	j		- index 2
// ----------------------------------------------------
void swap (vint &arr , int i , int j) 
{
	// Swaps element at index 'i' with element at index 'j'
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return;
}

// ------------------------------------------------------------------------------------
// A Function to partition an array with respect to the pivot
//	Description	: partitions elements smaller than pivot to left and vice-versa
//	arr 		- dynamic array
//	start 		- starting index of array/sub-array
//	end		- ending index of array/sub-array
//	pivot		- pivoting element
// ------------------------------------------------------------------------------------
int partition (vint &arr , int start , int end , int pivot) 
{
	// Moving the pivot element to the end
	// Last occurence of pivot has been chosen to maintain stability
	for (int i = end-1; i >= start; i--) 
	{
		if (arr[i] == pivot) 
		{
			swap (arr , i , end);
			break;
		}
	}

	int insert = start;

	// Partitioning smaller elements to left
	for (int i = start; i <= end; i++)
	{
		if (arr[i] <= pivot)
		{
			swap (arr , i , insert);
			insert++;
		}
	}
	// Return the index of pivot after partitioning
	return insert - 1;
}

// -----------------------------------------------------------------------------------
// A Function to find the k'th smallest element in an array/sub-array
//	Description	: finds k'th smallest element using medain of medians approach
//	arr 		- dynamic array
//	start 		- starting index of array/sub-array
//	end		- ending index of array/sub-array
//	k 		- k'th samllest in array/sub-array
// -----------------------------------------------------------------------------------
int kthSmallestElement (vint arr , int start , int end , int k)
{
	int n = end - start + 1;		// Number of elements in array/sub-array
	int median_count = 0;			// Number of subgroup medians
	vint medians;				// Dynamic array to store median of subgroups

	// Partition array into groups of five
	for (int i = 0; i < n/5; i++)
	{
		vint group;
		for (int j = 0; j < 5; j++)
		{
			group.push_back(arr[start + 5*i + j]);
		}	

		// Finding median of each 5-element subgroup by sorting
		sort (group.begin() , group.end());
		medians.push_back (group[2]);
		median_count++;
	}

	// Grouping left-out elements 
	if (n%5)
	{
		vint group;
		for (int i = 0; i < n%5; i++)
		{
			group.push_back(arr[start + 5*(n/5) + i]);
		}

		// Finding median of last subgroup by sorting
		sort (group.begin() , group.end());
		medians.push_back (group[(n%5 - 1)/2]);
		median_count++;
	}


	int median_of_medians;	// To find the median in the 'medians' array

	// When number of elements equal to 1 -> median is the element itself
	if (median_count == 1)
	{
		median_of_medians = medians[0];
	}

	// Finding the median in the 'medains' array via recursion
	else
	{
		median_of_medians = kthSmallestElement(medians , 0 , median_count-1 , ceil (median_count/2.0));
	}

	// Partition the array/sub-array with respect to median_of_medians
	// To find its position as in sorted array/sub-array
	int position = partition(arr , start , end , median_of_medians);

	// The chosen pivot resides in the required position
	if (position == start + k - 1)
	{
		return median_of_medians;
	}

	// The chosen pivot resides after the required position
	// Therefore the required element will be present in the left sub-array
	else if (position > start + k - 1)
	{
		// Searching k'th smallest element in the left sub-array
		return kthSmallestElement (arr , start , position-1 , k);
	}

	// The chosen pivot resides before the required position
	// Therefore the required element will be present in the right sub-array
	else
	{
		// Searching (k+start-(position+1))'th smallest element in the right sub-array
		return kthSmallestElement (arr , position+1 , end , k + start - position - 1);
	}

	// Return statement never visited
	return -1;
}