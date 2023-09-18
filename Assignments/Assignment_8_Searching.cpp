#include <bits/stdc++.h>
using namespace std;



int myBinarySearch(int arr[], int left, int right)
{
    int mid, minVal = arr[0];

    while(left <= right)
    {
        mid = left + (right - left)/2;
        cout << "Mid is: " << mid <<endl;

        if(arr[mid+1] <  arr[mid]) //if previous item greater than
        {
            return arr[mid+1];
        }
        else if(arr[mid] > arr[right])
        {
            left = mid+1;
        }
        else{
            right = mid-1;
        }

    }


    return arr[0];

}



/*
Space Complexity: O(m+n)
Time Complexity: O(lg (m))

*/

int main() {
    int m, item;
    cin >> m; //Enter how many items

    int nums1[m+1];

//  take input into the first array
    for(int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    int pos = myBinarySearch(nums1, 0, m-1);

    //  print combined array
    cout << pos <<endl;





    return 0;
}

/*
    Input:

5
3 5 4 1 2


7
4 5 6 7 0 1 2

4
11 13 15 17

*/
