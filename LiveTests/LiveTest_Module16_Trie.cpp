


#include <bits/stdc++.h>

using namespace std;


bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second > p2.second;
}

int myfunc (int arr[], int N, int K)
{
    unordered_map<int, int> umap;
    for (int i = 0; i < N; i++)
        umap[arr[i]]++;


    vector<pair<int, int> > freq_nums(umap.begin(), umap.end());


    sort(freq_nums.begin(), freq_nums.end(), compare);


    for (int i = 0; i < K; i++)
        cout << freq_nums[i].first << " ";
}



/*
    Time complexity: O(N) where N = noOfElements, P= noOfUniqueElements
    Space Complexity: O(P)
*/

int main()
{
    int arr[] = { 1,1,1,2,2,3 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;

    // Function call
    myfunc(arr, N, K);
    return 0;
}
