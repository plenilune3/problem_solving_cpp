#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 15;
const int dx[] = { 0, 0, 0, -1, 1 };
const int dy[] = { 0, 1, -1, 0, 0 };

struct piece
{
    int idx, x, y, d;

    piece() : idx(0), x(0), y(0), d(0) {}
    piece(int _idx, int _x, int _y, int _d) : idx(_idx), x(_x), y(_y), d(_d) {}
};

int N, K, A[MAX][MAX];
vector<int> B[MAX][MAX];
piece P[MAX * MAX];

int move_piece(piece p);
vector<int>::iterator choose_pieces(int idx, int x, int y);
void move(vector<int> &c, int nx, int ny);
int change_dir(int dir);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < N + 2; j++)
            if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
                A[i][j] = 2;
            else
                cin >> A[i][j];
    
    for (int i = 1; i <= K; i++)
    {
        int x, y, d; cin >> x >> y >> d;
        P[i] = piece(i, x, y, d);
        B[x][y].push_back(i);
    }

    int answer = 0;

    while (true)
    {
        bool possible = true;
        
        if (answer > 1000)
            break;
        
        answer += 1;

        for (int k = 1; k <= K; k++)
        {
            int result = move_piece(P[k]);

            if (result >= 4)
            {
                possible = false;
                break;
            }
        }

        if (possible == false)
            break;
    }

    if (answer <= 1000)
        cout << answer << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

int move_piece(piece p)
{
    int idx = p.idx, x = p.x, y = p.y, d = p.d;
    int nx = x + dx[d], ny = y + dy[d];
    vector<int> v;

    vector<int>::iterator it = choose_pieces(idx, x, y);
    v.assign(it, B[x][y].end());
    reverse(v.begin(), v.end());

    if (A[nx][ny] != 2)
    {
        move(v, nx, ny);
        B[x][y].erase(it, B[x][y].end());
    }
    else
    {
        P[idx].d = change_dir(d);
        d = P[idx].d;
        nx = x + dx[d], ny = y + dy[d];

        if (A[nx][ny] != 2)
        {
            move(v, nx, ny);
            B[x][y].erase(it, B[x][y].end());
        }
    }

    return B[nx][ny].size();
}

vector<int>::iterator choose_pieces(int idx, int x, int y)
{
    for (vector<int>::iterator i = B[x][y].begin(); i != B[x][y].end(); i++)
        if (idx == (*i))
            return i;
}

void move(vector<int> &v, int nx, int ny)
{
    if (A[nx][ny] == 1)
        reverse(v.begin(), v.end());
    
    while (!v.empty())
    {
        int idx = v.back();
        v.pop_back();
        P[idx].x = nx, P[idx].y = ny;
        B[nx][ny].push_back(idx);
    }
}

int change_dir(int dir)
{
    if (dir == 1) return 2;
    else if (dir == 2) return 1;
    else if (dir == 3) return 4;
    else return 3;
}