#include <iostream>
#include <queue>
#include <stack>

using namespace std;

const int MAX = 15;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };

struct piece
{
    int id, x, y, d; 
};

int N, K;
int board[MAX][MAX];
queue<int> q[MAX][MAX];
piece pieces[11];

void move_(int id, int x, int y, int d);
void white_(int x, int y, int nx, int ny);
void red_(int x, int y, int nx, int ny);
int reverse_dir(int d);
bool is_finished();
piece make_piece(int id, int x, int y, int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
        {
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
                board[i][j] = 2;
            else
                cin >> board[i][j];
        }

    for (int i = 1; i <= K; i++)
    {
        pieces[i].id = i;
        cin >> pieces[i].x >> pieces[i].y >> pieces[i].d;
        pieces[i].d -= 1;
        q[pieces[i].x][pieces[i].y].push(pieces[i].id);
    }


    int answer = 0;
    bool possible = true;

    while (true)
    {
        if (is_finished()) break;

        if (answer >= 1000)
        {
            possible = false;
            break;
        }

        for (int id = 1; id <= K; id++)
        {
            int x = pieces[id].x, y = pieces[id].y, d = pieces[id].d;

            if (id != q[x][y].front()) continue;

            move_(id, x, y, d);
        }

        answer += 1;
    }

    if (possible)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void move_(int id, int x, int y, int d)
{
    int nx = x + dx[d], ny = y + dy[d];

    if (board[nx][ny] == 0) white_(x, y, nx, ny);

    if (board[nx][ny] == 1) red_(x, y, nx, ny);

    if (board[nx][ny] == 2)
    {
        pieces[id].d = d = reverse_dir(d);
        nx = x + dx[d], ny = y + dy[d];

        if (board[nx][ny] == 0) white_(x, y, nx, ny);
        else if (board[nx][ny] == 1) red_(x, y, nx, ny);
    }
}

void white_(int x, int y, int nx, int ny)
{
    while (!q[x][y].empty())
    {
        int k = q[x][y].front();
        pieces[k].x = nx, pieces[k].y = ny;
        q[nx][ny].push(k);
        q[x][y].pop();
    }
}

void red_(int x, int y, int nx, int ny)
{
    stack<int> s;

    while (!q[x][y].empty())
    {
        s.push(q[x][y].front());
        q[x][y].pop();
    }

    while (!s.empty())
    {
        int k = s.top();
        pieces[k].x = nx, pieces[k].y = ny;
        q[nx][ny].push(k);
        s.pop();
    }
}

int reverse_dir(int d)
{
    if (d == 0) return 1;
    else if (d == 1) return 0;
    else if (d == 2) return 3;
    else return 2;
}

bool is_finished()
{
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (q[i][j].size() >= 4)
                return true;
    
    return false;
}

piece make_piece(int id, int x, int y, int d)
{
    piece p = { id, x, y, d };
    return p;
}
