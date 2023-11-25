#include <bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include <bits/stdc++.h>
#include<unordered_map>

using namespace std;
vector<string> allSolution;

bool myFunc (string &inputString, int startInd, int endInd)
{
    if(startInd == endInd)
    {
        allSolution.push_back(inputString);
        cout << inputString << endl;
    }

    else{
        for (int i=startInd; i<=endInd; i++)
        {
//            cout << "i: " << i << "   startInd: " << startInd << "   endInd: " << endInd << endl;
            swap(inputString[startInd], inputString[i]);
//            cout << "Frist swap & recursive call: " << inputString << endl;
            myFunc(inputString, startInd+1, endInd);

            swap(inputString[startInd], inputString[i]);
//            cout << "2nd Swap: " << inputString << endl;
        }
    }

}

/*
    Time complexity: O(n* n!) where n = noOfElements;
    Space Complexity: O(n)
*/

int main()
{

    string input = "";
    cin >> input;

    int noOfElements = input.size();

    myFunc(input, 0, noOfElements-1);


    return 0;
}




