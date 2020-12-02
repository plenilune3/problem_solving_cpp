#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct fire_ball
{
    int x, y, m, s, d;
};

int N, M, K;
queue<fire_ball> board[MAX][MAX];

void move();
void divide();
fire_ball make_fire_ball(int x, int y, int m, int s, int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    while (M--)
    {
        int x, y, m, s, d;
        cin >> x >> y >> m >> s >> d;
        board[x - 1][y - 1].push(make_fire_ball(x - 1, y - 1, m, s, d));
    }

    while (K--)
    {
        move();
        divide();
    }

    int answer = 0;

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            while (!board[x][y].empty())
            {
                answer += board[x][y].front().m;
                board[x][y].pop();
            }
    
    cout << answer << "\n";

    return 0;
}

void move()
{
    queue<fire_ball> q;

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            while (!board[x][y].empty())
            {
                q.push(board[x][y].front());
                board[x][y].pop();
            }
    
    while (!q.empty())
    {
        fire_ball fb = q.front();
        q.pop();

        int nx = (fb.x + dx[fb.d] * fb.s) % N;
        int ny = (fb.y + dy[fb.d] * fb.s) % N;

        if (nx < 0) nx = (nx + N) % N;
        if (ny < 0) ny = (ny + N) % N;

        board[nx][ny].push(make_fire_ball(nx, ny, fb.m, fb.s, fb.d));
    }
}

void divide()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
        {
            if (board[x][y].size() < 2)
                continue;

            int even_ = 0, odd_ = 0;
            int mass = 0, speed = 0, count_ = 0;

            while (!board[x][y].empty())
            {
                fire_ball fb = board[x][y].front();
                board[x][y].pop();

                count_ += 1;
                mass += fb.m, speed += fb.s;

                if (fb.d % 2) odd_ += 1;
                else even_ += 1;
            }

            mass = mass / 5;
            speed = speed / count_;

            if (mass == 0)
                continue;
            
            int temp = (even_ == count_ || odd_ == count_) ? 0 : 1;
            
            for (int i = temp; i < 8; i += 2)
                board[x][y].push(make_fire_ball(x, y, mass, speed, i));
        }
}

fire_ball make_fire_ball(int x, int y, int m, int s, int d)
{
    fire_ball fb = { x, y, m, s, d };
    return fb;
}