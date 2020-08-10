#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

const int target = 123456789;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int FromCoordinateToIndex(pair<int, int> c)
{
    return c.first * 3 + c.second; 
}

pair<int, int> FromIndexToCoordinate(int index)
{
    return make_pair(index / 3, index % 3);
}

bool IsOutOfRange(int x, int y)
{
    if (x < 0 || x >= 3 || y < 0 || y >= 3)
        return true;
    
    return false;
}

int FindIndexOfNine(int *arr)
{
    for (int i = 0; i < 9; i++)
        if (arr[i] == 9)
            return i;
    
    return 0;
}

int FromArrToInt(int *arr)
{
    int result = 0;

    for (int i = 0; i < 9; i++)
        result = result * 10 + arr[i];
    
    return result;
}

void FromIntToArr(int num, int* arr)
{
    for (int i = 8; i >= 0; i--)
    {
        arr[i] = num % 10;
        num /= 10;
    }
}

int bfs(int start)
{
    map<int, int> visited;
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while (!q.empty())
    {
        int currentPuzzle = q.front();
        q.pop();

        if (currentPuzzle == target)
            return visited[target] - 1;
        
        int board[9];
        FromIntToArr(currentPuzzle, board);
        int indexOfNine = FindIndexOfNine(board);

        pair<int, int> coordinate = FromIndexToCoordinate(indexOfNine);

        for (int i = 0; i < 4; i++)
        {
            int nx = coordinate.first + dx[i], ny = coordinate.second + dy[i];

            if (IsOutOfRange(nx, ny))
                continue;
            
            int nextBoard[9], nextIndex = FromCoordinateToIndex(make_pair(nx, ny));
            copy(board, board + 9, nextBoard);
            swap(nextBoard[indexOfNine], nextBoard[nextIndex]);
            int nextPuzzle = FromArrToInt(nextBoard);

            if (visited[nextPuzzle] == 0)
            {
                visited[nextPuzzle] = visited[currentPuzzle] + 1;
                q.push(nextPuzzle);
            }
        }

    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int board[9];

    for (int i = 0; i < 9; i++)
    {
        cin >> board[i];

        if (board[i] == 0)
            board[i] = 9;
    }

    int start = FromArrToInt(board);
    cout << bfs(start) << "\n";

    return 0;
}

