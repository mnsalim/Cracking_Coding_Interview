#include<iostream>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;

bool myMatch (char inputArray[], int noOfElements)
{
    bool isFirstClosing = true;

    map<char, int> countChar = {
                                {'(', 0},
                                {'{', 0},
                                {'[', 0},
                                {')', 0},
                                {'}', 0},
                                {']', 0},
                                   };
    /*
    Time Complexity = O(n)
    Space Complexity = O(n)

    */

    if (noOfElements%2 == 1) //Check condition 3. Every close bracket has a corresponding open bracket of the same type
        return false;
    for (int i=0; i<noOfElements; i++)
    {
        countChar[inputArray[i]]++; //increase the counter of the char

        if(inputArray[i] == '(' || inputArray[i] == '{' || inputArray[i] == '[' )
        {
            isFirstClosing = true;
        }
        else // for all closing bracket
        {
            if (isFirstClosing && i!=0)
            {
//                cout << "inside isFristClosing" <<endl;

                if(inputArray[i] == ')')
                {
//                    cout << "isFristClosing ( = " << inputArray[i]  << inputArray[i-1]<<endl;
                    if (inputArray[i-1] != '(')
                        return false;
                }

                if(inputArray[i] == '}')
                {
//                    cout << "isFristClosing { = " << inputArray[i]  << inputArray[i-1]<<endl;
                    if (inputArray[i-1] != '{')
                        return false;
                }

                if(inputArray[i] == ']')
                {
                    if (inputArray[i-1] != '[')
                        return false;
                }

                isFirstClosing = false;
            }
        }
    }

//    for (auto it = countChar.cbegin(); it != countChar.cend(); ++it)
//        cout << it->first << "  " << it->second <<endl;

    bool checkCount = ((countChar['('] == countChar[')']) && (countChar['{'] == countChar['}']) && (countChar['['] == countChar[']']));

    if(!checkCount)
    {
//        cout<< "CheckCount : " << checkCount <<endl;
        return false;
    }

    return true;
}

int main()
{
    int noOfElements;
    string input = "";
    cin >> input;

    noOfElements = input.size();
    char inputArray[noOfElements+1];

    strcpy(inputArray, input.c_str());
//    for (int i = 0; i < input.length(); i++)
//		cout << inputArray[i];

    std::cout << std::boolalpha; //to convert 0 1 to false and true in c++
    cout << myMatch(inputArray, noOfElements) <<endl;


    return 0;
}




