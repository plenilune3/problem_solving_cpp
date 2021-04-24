#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, S, C, A[MAX][MAX], answer = INT_MAX;
vector< pair<int, int> > virus;
vector< pair<int, int> > active;
bool selected[11];

void combinations(int depth, int index);
int spread(vector< pair<int, int> > &active);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];

            if (A[i][j] == 2)
            {
                virus.push_back(make_pair(i, j));
                S += 1;
            }
            else if (A[i][j] == 0)
                C += 1;
        }

    combinations(0, 0);

    if (answer != INT_MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void combinations(int depth, int index)
{
    if (depth == M)
    {
        int result = spread(active);

        if (result != -1)
            answer = min(answer, result);

        return;
    }

    for (int i = index; i < S; i++)
    {
        if (selected[i])
            continue;
        
        selected[i] = true;
        active.push_back(virus[i]);
        combinations(depth + 1, i);
        selected[i] = false;
        active.pop_back();
    }
}

int spread(vector< pair<int, int> > &active)
{
    int time = 0, infected = 0;
    int visited[MAX][MAX];
    queue< pair<int, int> >q;
    
    fill_n(&visited[0][0], MAX * MAX, -1);

    for (vector< pair<int ,int> >::iterator i = active.begin(); i != active.end(); i++)
    {
        visited[(*i).first][(*i).second] = 0;
        q.push((*i));
    }

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (A[x][y] == 0)
        {
            infected += 1;
            time = max(time, visited[x][y]);
        }

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            if (visited[nx][ny] != -1|| A[nx][ny] == 1)
                continue;
            
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    if (infected == C)
        return time;
    else
        return -1;
}