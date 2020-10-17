#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 50;
const int GREEN = 1;
const int RED = 2;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, G, R, K, answer;
int board[MAX][MAX];
bool selected[11];
vector< pair<int, int> > v, a, b;

int calculate_flower();
void combinations(int depth, int index, int green, int red);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 2)
                v.push_back(make_pair(i, j));
        }
    
    K = (int) v.size();

    combinations(0, 0, 0, 0);

    cout << answer << "\n";
            
    return 0;
}

int calculate_flower()
{
    pair<int, int> visited[MAX][MAX];
    fill_n(&visited[0][0], MAX * MAX, make_pair(-1, 0));

    int flower = 0;
    queue< pair<int, int> > q;

    for (vector< pair<int, int> >::iterator i = a.begin(); i != a.end(); i++)
    {
        visited[(*i).first][(*i).second].first = 0;
        visited[(*i).first][(*i).second].second = GREEN;
        q.push((*i));
    }

    for (vector< pair<int, int> >::iterator i = b.begin(); i != b.end(); i++)
    {
        visited[(*i).first][(*i).second].first = 0;
        visited[(*i).first][(*i).second].second = RED;
        q.push((*i));
    }
    
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if (visited[x][y].second == 3)
            continue;

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (board[nx][ny] == 0)
                continue;
            
            if (visited[nx][ny].second == GREEN)
            {
                if (visited[x][y].second == RED && visited[nx][ny].first == visited[x][y].first + 1)
                {
                    visited[nx][ny].first = visited[x][y].first + 1;
                    visited[nx][ny].second = 3;
                    flower += 1;
                }
            }

            else if (visited[nx][ny].second == RED)
            {
                if (visited[x][y].second == GREEN && visited[nx][ny].first == visited[x][y].first + 1)
                {
                    visited[nx][ny].first = visited[x][y].first + 1;
                    visited[nx][ny].second = 3;
                    flower += 1;
                }
            }

            else if (visited[nx][ny].second == 0 && visited[nx][ny].first == -1)
            {
                visited[nx][ny].first = visited[x][y].first + 1;
                visited[nx][ny].second = visited[x][y].second;
                q.push(make_pair(nx, ny));
            }
        }
    }
   
    return flower;
}

void combinations(int depth, int index, int green, int red)
{
    if (green == G && red == R)
    {
        answer = max(answer, calculate_flower());
        return;
    }

    if (depth == K)
        return;

    for (int i = index; i < K; i++)
    {
        if (selected[i]) continue;

        if (green < G)
        {
            selected[i] = true;
            a.push_back(v[i]);
            combinations(depth + 1, i, green + 1, red);
            selected[i] = false;
            a.pop_back();
        }

        if (red < R)
        {
            selected[i] = true;
            b.push_back(v[i]);
            combinations(depth + 1, i, green, red + 1);
            selected[i] = false;
            b.pop_back();
        }
    }
}

