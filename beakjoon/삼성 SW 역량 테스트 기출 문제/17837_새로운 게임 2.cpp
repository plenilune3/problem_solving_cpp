#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct piece
{
    int num, x, y, d;
};

const int MAX = 14;
const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

int N, K;
int color[MAX][MAX];
vector<int> board[MAX][MAX];
piece p[MAX * MAX];

bool move_piece(int num);
void change_dir(int &d);
piece make_piece(int num, int x, int y, int d);

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
                color[i][j] = 2;
            else
                cin >> color[i][j];
    
    for (int i = 1; i <= K; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;
        p[i] = make_piece(i, x, y, d);
        board[x][y].push_back(i);
    }

    int answer = 0;

    while (true)
    {
        if (answer > 1000)
            break;

        answer += 1;

        bool is_possible = true;

        for (int k = 1; k <= K; k++)
        {
            is_possible = move_piece(k);

            if (is_possible == false)
                break;
        }

        if (is_possible == false)
            break;
    }

    if (answer <= 1000)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

bool move_piece(int num)
{
    int x = p[num].x, y = p[num].y, d = p[num].d;
    int nx = x + dx[d], ny = y + dy[d];
    vector<int>::iterator iter;
    vector<int> v;

    for (vector<int>::iterator i = board[x][y].begin(); i != board[x][y].end(); i++)
        if ((*i) == num)
        {
            iter = i;
            break;
        }
    
    v.assign(iter, board[x][y].end());
    reverse(v.begin(), v.end());

    if (color[nx][ny] != 2)
    {
        if (color[nx][ny] == 1)
            reverse(v.begin(), v.end());
        
        while (!v.empty())
        {
            int n = v.back();
            v.pop_back();
            p[n].x = nx, p[n].y = ny;
            board[nx][ny].push_back(n);
        }

        board[x][y].erase(iter, board[x][y].end());
    }
    else
    {
        change_dir(d);
        p[num].d = d;
        nx = x + dx[d], ny = y + dy[d];

        if (color[nx][ny] != 2)
        {
            if (color[nx][ny] == 1)
                reverse(v.begin(), v.end());

            while (!v.empty())
            {
                int n = v.back();
                v.pop_back();
                p[n].x = nx, p[n].y = ny;
                board[nx][ny].push_back(n);
            }

            board[x][y].erase(iter, board[x][y].end());
        }
    }

    if (board[nx][ny].size() >= 4)
        return false;
    else
        return true;
}

void change_dir(int &d)
{
    if (d == 1) d = 2;
    else if (d == 2) d = 1;
    else if (d == 3) d = 4;
    else d = 3;
}

piece make_piece(int num, int x, int y, int d)
{
    piece p = { num, x, y, d };
    return p;
}