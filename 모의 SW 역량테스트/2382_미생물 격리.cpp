#include <iostream>

using namespace std;

const int MAX = 102;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

struct cluster
{
    int x, y, k, d;
};

struct cell
{
    int num, k;
};

cluster c[1001];
cell board[MAX][MAX];
int N, M, K;

int hit(int dir)
{
    if (dir == 1)
        return 2;
    else if (dir == 2)
        return 1;
    else if (dir == 3)
        return 4;
    else
        return 3;
}

void move(cluster &c)
{
    int nx = c.x + dx[c.d], ny = c.y + dy[c.d];

    if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1)
    {
        c.k /= 2;
        c.d = hit(c.d);
    }

    c.x = nx, c.y = ny;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N >> M >> K;

        for (int i = 1; i <= K; i++)
            cin >> c[i].x >> c[i].y >> c[i].k >> c[i].d;
        
        while(M--)
        {
            cell init = { 0, 0 };
            fill_n(&board[0][0], MAX * MAX, init);

            for (int i = 1; i <= K; i++)
            {
                if (c[i].k == 0)
                    continue;
                
                move(c[i]);

                if (board[c[i].x][c[i].y].num == 0)
                {
                    board[c[i].x][c[i].y].num = i;
                    board[c[i].x][c[i].y].k = c[i].k;
                }
                else
                {
                    if (board[c[i].x][c[i].y].k > c[i].k)
                    {
                        c[board[c[i].x][c[i].y].num].k += c[i].k;

                        c[i].k = c[i].d = 0;
                    }
                    else if (board[c[i].x][c[i].y].k < c[i].k)
                    {
                        int temp = c[board[c[i].x][c[i].y].num].k;

                        c[board[c[i].x][c[i].y].num].k = 0;
                        c[board[c[i].x][c[i].y].num].d = 0;

                        board[c[i].x][c[i].y].num = i;
                        board[c[i].x][c[i].y].k = c[i].k;
                        
                        c[i].k += temp;
                    }
                }
            }
        }

        int answer = 0;
        for (int i = 1; i <= K; i++)
            answer += c[i].k;
        
        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}

