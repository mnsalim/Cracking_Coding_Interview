#include<iostream>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;

int myFunc (int a, int b)
{
    if (b == 0)
        return 0;
    return (a + myFunc(a, b-1));
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << myFunc(a, b) <<endl;

    /*
    Time Complexity = O(b)
    Space Complexity = O(1)

    */

    return 0;
}




