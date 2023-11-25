#include <bits/stdc++.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include <bits/stdc++.h>
#include<unordered_map>


using namespace std;

#define N 4

void printSolution(int maze[N][N])
{
   for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", maze[i][j]);
        printf("\n");
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
        return true;

    return false;
}

/* A recursive utility function to solve Maze problem */
bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    // if (x, y is goal) return true
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true) {
        // mark x, y as part of solution path
        sol[x][y] = 1;

        /* Move forward in x direction */
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;

        /* If moving in x direction doesn't give solution then
           Move down in y direction  */
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;

        /* If none of the above movements work then BACKTRACK:
            unmark x, y as part of solution path */
        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool myFunc (int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };

//    int sol[N][N] = {{0, 0},
//                     {0, 0}};

    if (solveMazeUtil(maze, 0, 0, sol) == false) {
//        printf("Solution doesn't exist");
        return false;
    }

//    printSolution(sol);
    return true;

}

/*
    Time complexity: O(n* n!) where n = noOfElements;
    Space Complexity: O(n)
*/

int main()
{

     int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 1, 1, 0, 0 },
                       { 0, 1, 1, 1 } };

//    int maze[N][N] = { { 1, 0 },
//                       { 1, 0}};

     cout<<boolalpha<< myFunc(maze) <<endl;


    return 0;
}




