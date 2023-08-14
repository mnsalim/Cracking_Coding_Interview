#include<iostream>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;

string myShfl (char inputArray[], int narr[], int noOfElements)
{
    /*
    Time Complexity = O(n)
    Space Complexity = O(n)

    */
    string result = "";

    for (int i=0; i<noOfElements; i++)
    {
       result = result + inputArray[narr[i]];
    }

    return result;
}

int main()
{
    int noOfElements;
    string input = "";
    cin >> input;

noOfElements = input.size();
    char inputArray[noOfElements+1];
    int narr[noOfElements+1];
    
    for (int i=0; i<noOfElements; i++)
    {
        cin >> narr[i];
    }

    strcpy(inputArray, input.c_str());

    
    cout << myShfl(inputArray, narr, noOfElements) <<endl;


    return 0;
}



