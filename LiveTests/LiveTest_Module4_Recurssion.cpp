#include<iostream>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;

char inputArray[111];

bool myFunc (int startInd, int endIndex)
{
    /*
    Time Complexity = O(n) where n is the length of the string
    Space Complexity = O(n)

    */

//    cout << "StartInd: " << startInd << " endInd: " << endIndex << endl;
//    cout << "StartVal: " << inputArray[startInd] << " endVal: " << inputArray[endIndex] << endl;
    if (startInd >= endIndex)
    {
//        cout << "startInd >= endIndex cond!"<< endl;
        return true;
    }
    else if(inputArray[startInd] != inputArray[endIndex])
    {
//        cout << "inputArray[startInd] != inputArray[endIndex] cond"<< endl;
        return false;
    }
    else
    {
//        cout << "inside noen"<< endl;
        return myFunc(startInd + 1, endIndex - 1);
    }
}

int main()
{
    int noOfElements;
    string input = "";
    cin >> input;

    noOfElements = input.size();

    strcpy(inputArray, input.c_str());

    std::cout << std::boolalpha; //to convert 0 1 to false and true in c++
    cout << myFunc(0, noOfElements-1) <<endl;


    return 0;
}




