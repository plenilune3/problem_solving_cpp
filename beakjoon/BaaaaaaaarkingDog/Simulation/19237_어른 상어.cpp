#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 23;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

struct shark
{
    int num, x, y, dir;
    bool is_alive;
    int priority[5][5];
};

struct smell
{
    int num, time;
};

int N, M, K;
smell board[MAX][MAX];
shark s[MAX * MAX];

bool go(shark &a, int num);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> board[i][j].num;

            if (board[i][j].num != 0)
            {
                board[i][j].time = K;
                s[board[i][j].num].x = i, s[board[i][j].num].y = j;
            }
        }
    
    for (int i = 1; i <= M; i++)
    {
        s[i].num = i;
        s[i].is_alive = true;
        cin >> s[i].dir;
    }
    
    for (int k = 1; k <= M; k++)
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                cin >> s[k].priority[i][j];

    int now = 0, cnt = 0;

    while (true)
    {
        if (now > 1000)
        {
            now = -1;
            break;
        }

        if (cnt == M - 1)
            break;

        now += 1;
        
        for (int k = 1; k <= M; k++)
        {
            if (s[k].is_alive == false)
                continue;
            
            if (!go(s[k], 0)) go(s[k], s[k].num);
        }

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (board[i][j].num != 0)
                    board[i][j].time -= 1;
                
                if (board[i][j].time == 0)
                    board[i][j].num = 0;
            }
        
        for (int k = M; k >= 1; k--)
        {
            if (s[k].is_alive == false) continue;

            board[s[k].x][s[k].y].num = s[k].num;
            board[s[k].x][s[k].y].time = K;
        }

        for (int k = M; k >= 1; k--)
        {
            if (s[k].is_alive == false) continue;

            if (board[s[k].x][s[k].y].num != s[k].num)
            {
                s[k].is_alive = false;
                cnt += 1;
            }
        }
    }

    cout << now << "\n";

    return 0;
}

bool go(shark &a, int num)
{
    for (int i = 1; i <= 4; i++)
    {
        int nx = a.x + dx[a.priority[a.dir][i]], ny = a.y + dy[a.priority[a.dir][i]];

        if (nx < 1 || nx > N || ny < 1 || ny > N)
            continue;
       
        if (board[nx][ny].num == num)
        {
            a.dir = a.priority[a.dir][i];
            a.x = nx, a.y = ny;
            return true;
        }
    }

    return false;
}


