#include <iostream>

using namespace std;

const int MAX = 29;
const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

int N, simpleMove;
double answer;
double probability[4];
bool visited[MAX][MAX];

double MoveRobot(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < 4; i++)
    {
        cin >> probability[i];
        probability[i] /= 100.0;
    }
    
    cout.precision(11);
    cout << fixed;
    visited[15][15] = true;
    cout << MoveRobot(0, 15, 15) << "\n";

    return 0;
}

double MoveRobot(int depth, int x, int y)
{
    if (depth == N)
        return 1;
    
    double ret = 0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (visited[nx][ny] == false)
        {
            visited[nx][ny] = true;
            ret += MoveRobot(depth + 1, nx, ny) * probability[i];
            visited[nx][ny] = false;
        }
    }

    return ret;
}



