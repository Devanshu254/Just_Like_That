#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
const int MAX_ROWS = 15;
const int MAX_COLS = 15;

struct Point
{
    int x, y, dist, numDanger;
};

int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};

bool isValid(int row, int col, vector<vector<int>> &maze, vector<vector<bool>> &visited, int numDanger)
{
    return (row >= 0) && (row < maze.size()) && (col >= 0) && (col < maze[0].size()) &&
           (maze[row][col] != 1) && (!visited[row][col] || (maze[row][col] == 3 && numDanger <= 1)) &&
           numDanger <= 2;
}

int findShortestPath(vector<vector<int>> &maze, Point src, Point dest)
{
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    queue<Point> q;

    visited[src.x][src.y] = true;
    q.push(src);

    while (!q.empty())
    {
        Point pt = q.front();
        q.pop();

        if (pt.x == dest.x && pt.y == dest.y)
        {
            return pt.dist;
        }

        for (int i = 0; i < 4; ++i)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];

            if (isValid(row, col, maze, visited, pt.numDanger))
            {
                visited[row][col] = true;

                int danger = (maze[row][col] == 3) ? pt.numDanger + 1 : pt.numDanger;

                Point adj = {row, col, pt.dist + 1, danger};
                q.push(adj);
            }
        }
    }

    return -1;
}

int main()
{
    int R, C;
    cin >> R >> C;

    vector<vector<int>> maze(R, vector<int>(C));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> maze[i][j];
        }
    }

    Point src, dest;
    cin >> src.x >> src.y;
    cin >> dest.x >> dest.y;

    src.dist = 0;
    src.numDanger = 0;

    int shortestPath = findShortestPath(maze, src, dest);
    if (shortestPath != -1)
    {
        cout << shortestPath << endl;
    }
    else
    {
        cout << "STUCK" << endl;
    }

    return 0;
}