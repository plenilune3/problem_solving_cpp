#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int U = 1, R = 1 << 1, D = 1 << 2, L = 1 << 3;
vector<int> direction[6];

void init()
{
    direction[1].push_back(U);
    direction[1].push_back(R);
    direction[1].push_back(D);
    direction[1].push_back(L);

    direction[2].push_back(U|D);
    direction[2].push_back(R|L);

    direction[3].push_back(U|R);
    direction[3].push_back(R|D);
    direction[3].push_back(D|L);
    direction[3].push_back(L|U);

    direction[4].push_back(L|U|R);
    direction[4].push_back(U|R|D);
    direction[4].push_back(R|D|L);
    direction[4].push_back(D|L|U);

    direction[5].push_back(U|R|D|L);
}

struct cctv
{
    int x, y, id;
};

int N, M, answer = MAX*MAX;
int office[MAX][MAX];
int watch[MAX][MAX];
vector<cctv> v;

void monitor(int x, int y, int i, int d)
{
    for (int k = 0; k < 4; k++)
        if (i & (1 << k))
        {
            int nx = x;
            int ny = y;
            while (office[nx][ny] != 6)
            {
                watch[nx][ny] += d;
                nx += dx[k], ny += dy[k];
            }
        }
}

void backtracking(int depth, int length)
{
    if (depth == length)
    {
        int area = 0;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (watch[i][j] == 0)
                    area += 1;
        
        answer = min(answer, area);

        return;
    }

    int x = v[depth].x;
    int y = v[depth].y;
    int id = v[depth].id;

    for (int i : direction[id])
    {
        monitor(x, y, i, 1);
        backtracking(depth + 1, length);
        monitor(x, y, i, -1);
    }
}

int main(int argc, char const *argv[])
{
    init();
    cin >> N >> M;

    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || j == 0 || i == N+1 || j == M+1)
                office[i][j] = 6;
            else
            {
                cin >> office[i][j];

                if (office[i][j] == 6)
                    watch[i][j] = 1;

                else if (office[i][j] != 0)
                {
                    cctv t = {i, j, office[i][j]};
                    v.push_back(t);
                }
            }
        }

    int length = v.size();

    backtracking(0, length);

    cout << answer << "\n";

    return 0;
}


// struct cctv
// {
//     int t, d, x, y;
// };

// int N, M, answer = MAX*MAX;
// int endpoint;
// int office[MAX][MAX];
// bool watch[MAX][MAX];

// void watcher(int x, int y, int d)
// {
//     int dx[] = {0, -1, 0, 1};
//     int dy[] = {1, 0, -1, 0};

//     while (true)
//     {
//         x = x + dx[d];
//         y = y + dy[d];

//         if (x < 0 || x >= N || y < 0 || y >= M || office[x][y] == 6)
//             break;
        
//         watch[x][y] = true;
//     }
// }

// void monitor(cctv t)
// {

//     if (t.t == 1)
//         watcher(t.x, t.y, t.d);

//     else if (t.t == 2)
//     {
//         int a = t.d % 2;
//         int b = (a + 2) % 4;

//         watcher(t.x, t.y, a);
//         watcher(t.x, t.y, b);
//     }

//     else if (t.t == 3)
//     {
//         int a = t.d;
//         int b = (a + 3) % 4;

//         watcher(t.x, t.y, a);
//         watcher(t.x, t.y, b);
//     }

//     else if (t.t == 4)
//     {
//         int a = t.d;
//         int b = (a + 2) % 4;
//         int c = (a + 3) % 4;

//         watcher(t.x, t.y, a);
//         watcher(t.x, t.y, b);
//         watcher(t.x, t.y, c);
//     }

//     else
//     {
//         for (int i = 0; i < 4; i++)
//             watcher(t.x, t.y, (t.d + i) % 4);
//     }
// }


// void dfs(int depth, vector<cctv> v)
// {
//     if (depth == endpoint)
//     {
//         bool nwatch[MAX][MAX];
//         memcpy(nwatch, watch, sizeof(watch));

//         vector<cctv>::iterator iter;
//         for (iter = v.begin(); iter != v.end(); iter++)
//             monitor((*iter));

//         int cnt = 0;
//         for (int i = 0; i < N; i++)
//             for (int j = 0; j < M; j++)
//                 if (watch[i][j] == false)
//                     cnt += 1;
        
//         memcpy(watch, nwatch, sizeof(nwatch));
        
//         answer = min(answer, cnt);
//         return;
//     }

//     for (int i = 0; i < 4; i++)
//     {
//         vector<cctv> nv;
//         nv.assign(v.begin(), v.end());
//         nv[depth].d = (v[depth].d + i) % 4;
//         dfs(depth + 1, nv);
//     }
// }

// int main(int argc, char const *argv[])
// {
//     vector<cctv> c;
//     cin >> N >> M;

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < M; j++)
//         {
//             cin >> office[i][j];

//             if (office[i][j] != 0 && office[i][j] != 6)
//             {
//                 cctv t = {office[i][j], 0, i, j};
//                 c.push_back(t);
//             }

//             if (office[i][j] != 0)
//                 watch[i][j] = true;
//         }
    
//     endpoint = c.size();

//     dfs(0, c);

//     cout << answer << "\n";

//     return 0;
// }

