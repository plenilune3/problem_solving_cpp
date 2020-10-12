#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int U = (1 << 0), R = (1 << 1), D = (1 << 2), L = (1 << 3);

int N, M, K, answer = MAX * MAX;
int board[MAX][MAX];
int watched[MAX][MAX];
vector< vector<int> > cameras(6);
vector< pair<int, int> > v;

void init();
void watch(int x, int y, int k, int w);
void backtracking(int depth);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1) board[i][j] = 6;
            else cin >> board[i][j];

            if (board[i][j] >= 1 && board[i][j] <= 5) v.push_back(make_pair(i, j));
            else if (board[i][j] == 6) watched[i][j] = 1;
        }
    
    K = (int) v.size();
    
    init();
    backtracking(0);

    cout << answer << "\n";

    return 0;
}

void backtracking(int depth)
{
    if (depth == K)
    {
        int unwatched = 0;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (watched[i][j] == 0)
                    unwatched += 1;
        
        answer = min(answer, unwatched);
        return;
    }

    int x = v[depth].first, y = v[depth].second;
    int num = board[x][y];

    for (vector<int>::iterator i = cameras[num].begin(); i != cameras[num].end(); i++)
    {
        watch(x, y, (*i), 1);
        backtracking(depth + 1);
        watch(x, y, (*i), -1);
    }
}

void watch(int x, int y, int k, int w)
{
    watched[x][y] += w;

    for (int i = 0; i < 4; i++)
        if (k & (1 << i))
        {
            int nx = x + dx[i], ny = y + dy[i];

            while (board[nx][ny] != 6)
            {
                watched[nx][ny] += w;
                nx += dx[i], ny += dy[i];
            }
        }
}

void init()
{
    cameras[1].push_back(R);
    cameras[1].push_back(D);
    cameras[1].push_back(L);
    cameras[1].push_back(U);

    cameras[2].push_back(L|R);
    cameras[2].push_back(U|D);

    cameras[3].push_back(U|R);
    cameras[3].push_back(R|D);
    cameras[3].push_back(D|L);
    cameras[3].push_back(L|U);

    cameras[4].push_back(L|U|R);
    cameras[4].push_back(U|R|D);
    cameras[4].push_back(R|D|L);
    cameras[4].push_back(D|L|U);

    cameras[5].push_back(U|R|D|L);
}