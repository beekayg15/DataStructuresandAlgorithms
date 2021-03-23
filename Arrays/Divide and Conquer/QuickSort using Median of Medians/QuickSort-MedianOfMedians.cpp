
// Header Files
#include "KthSmallestElement.h"

/*

Quick Sort Algorithm using Median of Medians Algorithm

Time Complexity: O(NlogN)
Space Complexity: O(N) -> Input Array

Check on the link below for Visualization:
https://barathkumarbk-15.github.io/SortingAlgorithms/

*/

// Function Prototypes
void quicksort (vint &arr , int start , int end);

// ----------------------------------------------------------------------------
// A Function to perform quicksort with the help of median of medians algorithm
//	Description	: sorts elements of an array in ascending order
//	arr 		- dynamic array
//	start 		- starting index of array/sub-array
//	end		- ending index of array/sub-array
// ----------------------------------------------------------------------------
void quicksort (vint &arr , int start , int end)
{
	// When no elements or one element is present
	// Sorting is not necessary
	if (start >= end)
	{
		return;
	}

	int n = end - start + 1;	// Number of elements in array/sub-array

	// Finding median in the array/sub-array using medain of medians algorithm
	// To maximize time efficiency as median provides equi-length sub-problems
	int median = kthSmallestElement(arr , start , end , ceil (n/2.0));

	// Partitioning elements with respect to the median
	// And finding position of median in the partitioned array
	int position = partition (arr , start , end , median);

	// Sorting left and right sub-arrays
	quicksort (arr , start , position - 1);
	quicksort (arr , position + 1 , end);

	return;
}

// Driver Program
int main()
{
	// For fast input/output
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

/*
	// For file handling
	#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
	freopen ("output.txt" , "w" , stdout);
	#endif
*/

	// Recieveing Input
	int n;
	cout << "\n\t\tEnter the number of elements : ";
	cin >> n;
	cout << "\n\t\tEnter the elements (space-seperated) : ";
	vint arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// Sorting using QuickSort Algorithm
	quicksort (arr , 0 , n-1);

	//Printing sorted array
	cout << "\n\t\tResult : ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n\n";

	return 0;
}