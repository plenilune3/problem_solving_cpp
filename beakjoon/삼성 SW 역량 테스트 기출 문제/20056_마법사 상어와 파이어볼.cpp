#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

struct fireball
{
    int x, y, m, s, d;

    fireball(int _x, int _y, int _m, int _s, int _d) : x(_x), y(_y), m(_m), s(_s), d(_d) {}
};

int N, M, K;
queue<fireball> A[MAX][MAX];

void move();
void spread();
int sum_mass();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    while (M--)
    {
        int x, y, m, s, d; cin >> x >> y >> m >> s >> d;
        A[x - 1][y - 1].push(fireball(x - 1, y - 1, m, s, d));
    }

    while (K--)
    {
        move();
        spread();
    }

    int answer = sum_mass();
    cout << answer << "\n";

    return 0;
}

void move()
{
    queue<fireball> q;

    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            while (!A[x][y].empty())
            {
                q.push(A[x][y].front());
                A[x][y].pop();
            }

    while (!q.empty())
    {
        fireball fb = q.front();
        q.pop();

        int nx = (fb.x + dx[fb.d] * fb.s) % N;
        int ny = (fb.y + dy[fb.d] * fb.s) % N;
        
        if (nx < 0) nx = (nx + N) % N;
        if (ny < 0) ny = (ny + N) % N;

        A[nx][ny].push(fireball(nx, ny, fb.m, fb.s, fb.d));
    }
}

void spread()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
        {
            if (A[x][y].size() < 2)
                continue;
            
            int m = 0, s = 0, c = 0;
            bool odd = false, even = false;

            while (!A[x][y].empty())
            {
                fireball fb = A[x][y].front();
                A[x][y].pop();
                m += fb.m, s += fb.s, c += 1;
                fb.d % 2 ? odd = true : even = true;
            }

            if (m / 5 == 0)
                continue;

            for (int i = 0; i < 8; i += 2)
            {
                if ((!odd && !even) || (odd && even))
                    A[x][y].push(fireball(x, y, m / 5, s / c, i + 1));
                else
                    A[x][y].push(fireball(x, y, m / 5, s / c, i));
            }
        }
}

int sum_mass()
{
    int result = 0;
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            while (!A[x][y].empty())
            {
                fireball fb = A[x][y].front();
                A[x][y].pop();
                result += fb.m;
            }
    
    return result;
}