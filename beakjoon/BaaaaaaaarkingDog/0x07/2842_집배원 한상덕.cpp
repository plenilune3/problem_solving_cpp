#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, answer = 10e6 + 1, minAltitude, maxAltitude;
char area[MAX][MAX];
int altitude[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int x, int y)
{
    int numberOfHouse = 0;

    if (altitude[x][y] < minAltitude || altitude[x][y] > maxAltitude)
        return 0;
    
    if (area[x][y] == 'K')
        numberOfHouse = 1;

    visited[x][y] = true;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
            continue;
        
        numberOfHouse += dfs(nx, ny);
    }

    return numberOfHouse;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int px, py, totalNumberOfHouse = 0;
    set<int> s;

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> area[i][j];

            if (area[i][j] == 'P')
                px = i, py = j;
            
            if (area[i][j] == 'K')
                totalNumberOfHouse += 1;
        }
    
    for  (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> altitude[i][j];
            s.insert(altitude[i][j]);
        }
    
    set<int>::iterator left = s.begin(), right = s.begin();

    while (right != s.end())
    {
        while (left != s.end())
        {
            fill_n(&visited[0][0], MAX * MAX, false);
            minAltitude = (*left), maxAltitude = (*right);

            int VisitedNumberOfHouse = dfs(px, py);

            if (totalNumberOfHouse != VisitedNumberOfHouse)
                break;
            
            answer = min(answer, maxAltitude - minAltitude);
            left++;
        }
        right++;
    }

    cout << answer << "\n";
    
    return 0;
}
