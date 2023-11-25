


#include <bits/stdc++.h>

using namespace std;



int findConnectedComponent (int n, vector<vector<int>>& edges) {
    unordered_map<int,vector<int>> graph;

    //    make adjacency list
    for(auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n,0);
    int count = 0;
    for (int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            count++;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()) {
                int curr = q.front();
                q.pop();
                for(auto &node : graph[curr]){
                    if(!visited[node]){
                        visited[node] = 1;
                        q.push(node);
                    }
                }
            }
        }

    }

    return count;
}



/*
    Time complexity: O(V * E) where V = noOfNodes, E= noOfEdges;
    Space Complexity: O(V+E)
*/

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> edges{{1,2},{2,3}, {4, 5}};
//    vector<vector<int>> edges{{0,1},{0,2},{3,5},{5,4},{4,3}};

    cout<< findConnectedComponent(n, edges) <<endl;
    return 0;
}
