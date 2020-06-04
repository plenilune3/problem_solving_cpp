#include <iostream>
#include <vector>

using namespace std;

const int MAX = 102;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int T, N, answer;
int board[MAX][MAX];
vector< pair<int, int> > starting;
vector< pair<int, int> > worm_hole[6];

int hit(int type, int dir)
{
    if (type == 1)
    {
        if (dir == 0) return 1;
        else if (dir == 1) return 3;
        else if (dir == 2) return 0;
        else return 2;
    }
    else if (type == 2)
    {
        if (dir == 0) return 3;
        else if (dir == 1) return 0;
        else if (dir == 2) return 1;
        else return 2;
    }
    else if (type == 3)
    {
        if (dir == 0) return 2;
        else if (dir == 1) return 0;
        else if (dir == 2) return 3;
        else return 1;
    }
    else if (type == 4)
    {
        if (dir == 0) return 1;
        else if (dir == 1) return 2;
        else if (dir == 2) return 3;
        else return 0;
    }
    else
    {
        if (dir == 0) return 1;
        else if (dir == 1) return 0;
        else if (dir == 2) return 3;
        else return 2;
    }
}

pair<int, int> into_the_wormhole(pair<int, int> w)
{
    int num = board[w.first][w.second] - 5;
    int nx, ny;

    for (int i = 0; i < 2; i++)
        if (worm_hole[num][i].first != w.first || worm_hole[num][i].second != w.second)
            nx = worm_hole[num][i].first, ny = worm_hole[num][i].second;

    return make_pair(nx, ny);
}

void play(pair<int, int> s, int dir)
{
    int cnt = 0;
    pair<int, int> t = s;
    int nx = s.first, ny = s.second, ndir = dir;

    while(true)
    {
        nx += dx[ndir], ny += dy[ndir];

        if (board[nx][ny] == -1)
        {
            answer = max(answer, cnt);
            break;
        }

        if (nx == t.first && ny == t.second)
        {
            answer = max(answer, cnt);
            break;
        }

        if (board[nx][ny] >= 1 && board[nx][ny] <= 5)
        {
            ndir = hit(board[nx][ny], ndir);
            cnt += 1;
        }
        else if (board[nx][ny] >= 6 && board[nx][ny] <= 10)
        {
            pair<int, int> n = into_the_wormhole(make_pair(nx, ny));
            nx = n.first, ny = n.second;
        }
    }

}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        fill_n(&board[0][0], MAX * MAX, 0);
        starting.clear();
        answer = 0;

        for (int i = 0; i < 6; i++)
            worm_hole[i].clear();

        cin >> N;

        for (int i = 0; i < N + 2; i++)
            for (int j = 0; j < N + 2; j++)
            {
                if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
                    board[i][j] = 5;
                else
                {
                    cin >> board[i][j];

                    if (board[i][j] == 0)
                        starting.push_back(make_pair(i, j));
                    else if (board[i][j] >= 6 && board[i][j] <= 10)
                        worm_hole[board[i][j] - 5].push_back(make_pair(i, j));
                }
            }
        
        for (vector< pair<int, int> >::iterator i = starting.begin(); i != starting.end(); i++)
            for (int j = 0; j < 4; j++)
                play((*i), j);
        
        cout << "#" << test_case << " " << answer << "\n";
    }

    return 0;
}
