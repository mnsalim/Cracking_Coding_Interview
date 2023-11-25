
#include<bits/stdc++.h>
using namespace std;


class Graph{
public:
    map<int, bool> visited;
    map<int, list<int>> adj;

    bool hasCycle = false;
    int A;

    void addEdge(vector<vector<int>> edges);

    bool DFS(int v);

    bool checkCycle()
    {
        for(int i=0; i<A; i++)
        {
          if(!visited[i+1] && !hasCycle)
            if(DFS(i+1))
                return true;
        }

        return false;
    }


};



void Graph::addEdge(vector<vector<int>> edges)
{
    for(auto e : edges) {
        adj[e[0]].push_back(e[1]);
    }

//    for(auto it = adj.cbegin(); it != adj.cend(); ++it)
//    {
//        cout << it->first << " ";
//        for (auto v : it->second)
//            std::cout << v << " ";
//        cout << endl;
//    }
}

bool Graph::DFS(int v)
{
    //If already visited than there is a loop
//    if(visited[v])
//
    visited[v] = true;
//    cout <<v << " ";

    list<int>:: iterator i;

    for(i=adj[v].begin(); i != adj[v].end(); ++i)
    {
        if(!visited[*i] && !hasCycle)
            DFS(*i);
        else
        {
//            cout << "There is a cycle for " << *i <<endl;
            hasCycle = true;
            return true;
        }
    }

    return false;

}

int main()
{
    Graph g;

//    vector<vector<int>> edges{{1,2},{4,1},{2,4},{3,4},{5,2},{1,3}};
    vector<vector<int>> edges{{1,2},{2,3},{3,4},{4,5}};
    g.addEdge(edges);

    g.A = 5;

//    cout << "DFS traversal: " <<endl;

    cout << g.checkCycle() << endl;

    return 0;
}
