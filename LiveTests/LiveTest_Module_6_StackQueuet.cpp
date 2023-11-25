#include <bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include <bits/stdc++.h>

using namespace std;



int myFunc (int N, int tickets[], int k)
{
    int n=N;
    int time=tickets[k];
    for(int i=0;i<N;i++)
    {
        if(i<k){
            if(tickets[i] <= tickets[k]){
                time+=tickets[i];
            }
            else{
                time+=tickets[k];
            }
        }
        else if(i>k){
            if(tickets[i] < tickets[k]){
                time+=tickets[i];
            }
            else{
                time+=(tickets[k]-1);
            }
        }
    }
    return time;
}
/*
    Input:

3
2 3 2
2



4
5 1 1 1
0


6
10 5 6 4 3 8
3

*/

/*
Space Complexity: O(N)
Time Complexity: O(N)

*/

int main() {
    int N;
    cin >> N; //Enter how many items

    int tickets[N+1];
    for(int i=0; i<N; i++)
    {
        cin >> tickets[i];
    }

    int position_K;
    cin >> position_K;

    cout << myFunc(N, tickets, position_K);


    return 0;
}


