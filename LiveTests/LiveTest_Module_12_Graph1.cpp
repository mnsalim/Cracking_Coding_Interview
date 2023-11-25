#include <bits/stdc++.h>

using namespace std;



bool findPath (int n, vector<vector<int>>& edges, int start, int end) {
    unordered_map<int,vector<int>> graph;

    //    make adjacency list
    for(auto e : edges) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }

    vector<bool> visited(n,0);
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        if(curr == end)
            return true;
        for(auto &node : graph[curr]){
            if(!visited[node]){
                visited[node] = 1;
                q.push(node);
            }
        }
    }

    return false;
}



/*
    Time complexity: O(V * E) where V = noOfNodes, E= noOfEdges;
    Space Complexity: O(V+E)
*/

int main()
{
    int n, source, dest;
    cin >> n >> source >> dest;

//    vector<vector<int>> edges{{0,1},{1,2},{2,0}};
    vector<vector<int>> edges{{0,1},{0,2},{3,5},{5,4},{4,3}};

    cout<<boolalpha<< findPath(n, edges, source, dest) <<endl;
    return 0;
}
