#include<iostream>
#include<tuple>
#include<vector>

using namespace std;

std::tuple<int, int> myIndices (int nums[], int n, int target)
{
    int indice1 = 0, indice2 = 1, sum = 0;

    /*
    Time Complexity = O(n^2)
    Space Complexity = O(n)
    */


//    for (int i=0; i<n; i++)
//    {
//        for (int j=i+1; j<n; j++)
//        {
//            sum = nums[i] + nums[j];
//            if (sum == target)
//            {
////                cout << "in loop" << i << " " << j <<endl;
//
//                return make_tuple(i, j);
//            }
//        }
//    }


    /*
    Time Complexity = O(n)
    Space Complexity = O(n)

    sample input:
    4 10
    18 5 -8 2
    */

    for (int i=0; i<n; i++)
    {
        sum = sum + nums[i];
        if (sum >= target)
        {
            indice1 = i;
        }
        else if(sum >= target)
        {

        }
    }


    return std::make_tuple(indice1, indice2);
}

int main()
{
    int n, nums[111], target;
    tuple <int, int> output;

    cin >> n;
    cin >> target;

    for (int i=0; i<n; i++)
        cin >> nums[i];


    output =  myIndices(nums, n, target);

    cout << get<0>(output) <<" " << get<1>(output) <<endl;

    return 0;
}




