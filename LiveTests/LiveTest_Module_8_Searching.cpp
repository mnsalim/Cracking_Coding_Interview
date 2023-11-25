#include <bits/stdc++.h>
using namespace std;



int myBinarySearch(int arr[], int left, int right, int item)
{
    int mid;

    while(left <= right)
    {
        mid = left + (right - left)/2;
//        cout << mid <<endl;

        if(arr[mid] ==  item)
        {
            return mid;
        }
        else if(arr[mid] < item)
        {
            left = mid+1;
        }
        else{
            right = mid-1;
        }

    }


    return -1;

}

/*
Space Complexity: O(m)
Time Complexity: O(lg (m))

*/

int main() {
    int m, item;
    cin >> m >> item; //Enter how many items

    int nums1[m+1];

//  take input into the first array
    for(int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    int pos = myBinarySearch(nums1, 0, m, item);

    //  print combined array
    cout << pos <<endl;

    return 0;
}

/*
    Input:

6
2
-1 0 3 5 9 12


*/
