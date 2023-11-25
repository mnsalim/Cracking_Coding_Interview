#include <bits/stdc++.h>
using namespace std;



void myMerge(int arr[], int left, int mid, int right)
{
    int leftArrayLen = mid - left + 1;
    int rightArrayLen = right - mid;
    int i, j, k;

    int leftArr[leftArrayLen], rightArr[rightArrayLen];

    for(i=0; i<leftArrayLen; i++)
    {
        leftArr[i] = arr[left+i];
    }

    for(i=0; i<rightArrayLen; i++)
    {
        rightArr[i] = arr[mid+1+i];
    }

    //merge two subarray
    for(i=0, j=0, k=left; i<leftArrayLen && j<rightArrayLen; k++)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
    }

    // copy rest from leftArr
    while (i < leftArrayLen) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // copy rest from rightArr
    while (j < rightArrayLen) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = left+(right - left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);

        myMerge(arr, left, mid, right);
    }
}



/*
Space Complexity: O(n)
Time Complexity: O(n * log(n))

*/

int main() {
    int n;
    cin >> n; //Enter how many items

    int nums1[n+1];

//  take input into the first array
    for(int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }


    mergeSort(nums1, 0, n-1);

    //  print combined array
    for(int i = 0; i< n; i++)
    {
        cout << nums1[i] << " ";
    }




    return 0;
}

/*
    Input:

4
5 2 3 1

6
5 1 1 2 0 0



5
10 25 65 10 24


*/
