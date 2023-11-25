#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    // Create a vector to store paths
	vector<vector<int>> pathArray;
	vector<int> currentPath; //used to store the current path

    vector<bool> A;
    int C=0, noOfGoodPath = 0;

    void addEdge(vector<vector<int>> edges);

    void DFS(int v);

    void printPath(vector<int> path);

};


void Graph::printPath(vector<int> path)
{
    int countGood = 0;
//    store the path list
    pathArray.push_back(path);
//    print the path list
    for(int i=0; i<path.size(); i++)
    {
//        cout << path[i] << " ";
//        Check is it a good or not
        if(A[path[i]-1])
            countGood++;
    }
//    cout << endl;

    if(countGood <= C)
        noOfGoodPath++;
}


void Graph::addEdge(vector<vector<int>> edges)
{
    for(auto e : edges) {
        adj[e[0]].push_back(e[1]);
    }
}

void Graph::DFS(int v)
{
//    mark the current node as visited and add it to the path list
    visited[v] = true;
    currentPath.push_back(v);
//    cout <<v << " ";

//    if a node does not has any adjacent node that means it is a leaf node. So print the list and store it as one path
    if(adj[v].empty())
    {
        printPath(currentPath);
    }

    list<int>:: iterator i;

    for(i=adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i])
            DFS(*i);
    }

//    for backtracking
    visited[v] = false;
    currentPath.pop_back(); // remove the last element

}

int main()
{
    Graph g;

    vector<vector<int>> edges{{1,2},{1,5},{1,6},{2,3},{2,4}};
    g.addEdge(edges);

    vector<bool> vect{0, 1, 0, 1, 1, 1};
    g.A = vect;
    g.C = 1;

//    cout << "DFS traversal: " <<endl;

    g.DFS(1);

    cout << g.noOfGoodPath <<endl;

    return 0;
}
