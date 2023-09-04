#include <bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;

void printRevStk(stack<char> s)
{
    if(s.empty())
        return;

    char top_item = s.top();
    s.pop();

    printRevStk(s);
    cout << top_item;
}

void myFunc (string inputStr)
{
    stack<char> stk;

    for(auto ch:inputStr)
    {
        if(stk.empty())
        {
           stk.push(ch);
        }
        else
        {
            if(stk.top() == ch)
            {
                stk.pop();
            }
            else{
                stk.push(ch);
            }
        }
    }

    printRevStk(stk);

}

int main()
{
    string input = "";
    cin >> input;

    myFunc(input);

    /*
        Time complexity: O(N)
        Space Complexity: O(N)
    */

    return 0;
}



/*
abbaca


azxxzy

*/

