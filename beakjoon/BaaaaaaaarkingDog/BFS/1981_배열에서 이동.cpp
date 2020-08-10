#include <iostream>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 101;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, arr[MAX][MAX], answer = 201;
bool visited[MAX][MAX];

bool bfs(int minValue, int maxValue)
{
    fill_n(&visited[0][0], MAX * MAX, false);
    queue< pair<int, int> > q;
    visited[1][1] = true;
    q.push(make_pair(1, 1));

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (arr[x][y] < minValue || arr[x][y] > maxValue)
            continue;

        if (x == N && y == N)
            return true;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N || visited[nx][ny])
                continue;
            
            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
        }
    }

    return false;
}


int main(int argc, char const *argv[])
{
    set<int> s;
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
            s.insert(arr[i][j]);
        }

    set<int>::iterator left = s.begin(), right = s.begin();

    while (right != s.end())
    {
        while (left != s.end())
        {
            int minValue = (*left), maxValue = (*right);

            if (bfs(minValue, maxValue) == false)
                break;
            
            answer = min(answer, maxValue - minValue);
            left++;
        }
        right++;
    }

    cout << answer << "\n";

    return 0;
}
