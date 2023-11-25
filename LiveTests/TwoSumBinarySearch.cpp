#include <bits/stdc++.h>
using namespace std;



int myBinarySearch(std::vector<pair<int, int>> numbers,  int start, int k)
{
    int left = start;
    int right = numbers.size()-1;

    while (left <= right)
    {
        int mid = (left+right)/2;

        if(k == numbers[mid].first)
        {
            return numbers[mid].second;
        }
        else if(numbers[mid].first < k)
        {
            left = mid+1;
        }
        else{
            right = mid-1;
        }

    }
    return -1;

}




void myFunc (int arr1[], int arr2[], int m, int n)
{


}

/*
Space Complexity: O(m+n)
Time Complexity: O(m+n log (m+n))

*/

int main() {
    int m, item;
    cin >> m >> item; //Enter how many items

    int nums1[m+1];

    std::vector<pair<int, int>> numbers;

//  take input into the first array
    for(int i = 0; i < m; i++)
    {
        cin >> nums1[i];
    }

    for (int i=0; i<m; i++)
    {
        numbers.push_back(make_pair(nums1[i], i));
    }

    sort(numbers.begin(), numbers.end());

    std::vector<int> result;

    for(int i=0; i<numbers.size(); i++)
    {
        int k = item - numbers[i].first;
        int indx = myBinarySearch(numbers, i+1, k);
        if(indx != -1)
        {
            result.push_back(numbers[i].second);
            result.push_back(indx);
        }

    }

    std::cout << result[0] << " " << result[1] << endl;


    return 0;
}

/*
    Input:

6
9
2 3 5 7 11 15


*/
