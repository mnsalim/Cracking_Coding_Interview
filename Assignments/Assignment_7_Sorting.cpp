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


void myFunc (int arr1[], int arr2[], int m, int n)
{
    for(int i=0; i<n; i++)
    {
        arr1[m+i] = arr2[i];
    }

    mergeSort(arr1, 0, m+n-1);

}

/*
Space Complexity: O(m+n)
Time Complexity: O(m+n log (m+n))

*/

int main() {
    int m, n;
    cin >> m >> n; //Enter how many items

    int nums1[m+n+1], nums2[n+1];

//  take input into the first array
    for(int i = 0; i < (m+n); i++)
    {
        cin >> nums1[i];
    }

    //  take input into 2nd array
    for(int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }

    myFunc(nums1, nums2, m, n);

    //  print combined array
    for(int i = 0; i<(m+n); i++)
    {
        cout << nums1[i] << " ";
    }




    return 0;
}

/*
    Input:

3
3
1 2 3 0 0 0
2 5 6


1
0
1



5
10 25 65 12 24


*/
