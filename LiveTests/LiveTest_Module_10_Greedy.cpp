#include <bits/stdc++.h>

using namespace std;

// Structure for an BoxType which stores
// noOfBox & corresponding noOfUnitPerBox of BoxType
struct BoxType {
	int noOfBox, noOfUnitPerBox;

	// Constructor
	BoxType(int noOfBox, int noOfUnitPerBox)
		: noOfBox(noOfBox), noOfUnitPerBox(noOfUnitPerBox)
	{
	}
};

// Comparison function to sort BoxType
// according to val/noOfBox ratio
bool cmp(struct BoxType a, struct BoxType b)
{
	double r1 = (double)a.noOfUnitPerBox;
	double r2 = (double)b.noOfUnitPerBox;
	return r1 > r2;
}


double fractionalKnapsack(struct BoxType arr[],
						int N, int size)
{
	// Sort BoxType on basis of noOfUnit
	sort(arr, arr + size, cmp);

	// Current noOfBox in knapsack
	int curnoOfBox = 0;

	double finalnoOfUnitPerBox = 0.0;

	// Looping through all BoxTypes
	for (int i = 0; i < size; i++) {

		// add it completely
		if (curnoOfBox + arr[i].noOfBox <= N) {
			curnoOfBox += arr[i].noOfBox;
			finalnoOfUnitPerBox += (arr[i].noOfBox * arr[i].noOfUnitPerBox);
		}

		// add fractional part of it
		else {
			int remain = N - curnoOfBox;
			finalnoOfUnitPerBox += (arr[i].noOfUnitPerBox * (double)remain);

			break;
		}
	}

	// Returning final noOfUnitPerBox
	return finalnoOfUnitPerBox;
}


int main()
{
	// noOfBox of the truck
	int N = 10;

	// Given noOfBoxs and noOfUnitPerBoxs as a pairs
//	BoxType arr[] = { { 1, 3 },
//				{ 2, 2 },
//				{ 3, 1 } };

    BoxType arr[] = { { 5, 10 },
				{ 2, 5 },
				{ 4, 7 },
				{ 3, 9 } };

	int size = sizeof(arr) / sizeof(arr[0]);


	cout << "The maximum total number of units that can be put on the truck is = "
		<< fractionalKnapsack(arr, N, size);
	return 0;
}
