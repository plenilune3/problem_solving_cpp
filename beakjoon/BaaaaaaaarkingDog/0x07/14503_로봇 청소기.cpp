#include <iostream>
#include <queue>

using namespace std;

const int MAX = 50;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool room[MAX][MAX];
bool visited[MAX][MAX];
int N, M;

int cleaning(int r, int c, int d)
{
    int cnt = 1;
    visited[r][c] = true;

    while (true)
    {
        bool clean = false;

        for (int i = 0; i < 4; i++)
        {
            int nd = (d + 3) % 4;
            int nx = r + dx[nd];
            int ny = c + dy[nd];
            d = nd;

            if (room[nx][ny] == false && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                cnt++;
                r = nx, c = ny;
                clean =true;
                break;
            }
        }

        if (clean == false)
        {
            int nx = r - dx[d];
            int ny = c - dy[d];
            
            if (room[nx][ny] == true)
                return cnt;
            else
            {
                r = nx;
                c = ny;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> room[i][j];

    int answer = cleaning(r, c, d);

    cout << answer << "\n";

    return 0;
}


// struct robot
// {
//     int x;
//     int y;
//     int d;
// };


// const int MAX = 50;

// int dx[] = {0, -1, 0, 1};
// int dy[] = {-1, 0, 1, 0};
// int bdx[] = {1, 0, -1, 0};
// int bdy[] = {0, -1, 0, 1};

// bool room[MAX][MAX];
// bool visited[MAX][MAX];
// int N, M;

// int cleaning(int r, int c, int d)
// {
//     int cnt = 1;
//     robot init = {r, c, d};
//     queue< robot > q;
//     visited[r][c] = true;
//     q.push(init);

//     while (!q.empty())
//     {
//         robot c = q.front();
//         q.pop();

//         int td = c.d;
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = c.x + dx[td];
//             int ny = c.y + dy[td];
//             int nd = (td - 1 < 0) ? 3 : td - 1;

//             if (visited[nx][ny] == false && room[nx][ny] == false)
//             {
//                 visited[nx][ny] = true;
//                 cnt++;
//                 robot r = {nx, ny, nd};
//                 q.push(r);
//                 break;
//             }
//             else
//                 td = nd;
//         }

//         if (q.empty())
//         {
//             int nx = c.x + bdx[c.d];
//             int ny = c.y + bdy[c.d];

//             if (room[nx][ny] == false)
//             {
//                 if (visited[nx][ny] == false)
//                 {
//                     visited[nx][ny] = true;
//                     cnt++;
//                 }
//                 robot r = {nx, ny, c.d};
//                 q.push(r);
//             }
//         }
//     }

//     return cnt;
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int r, c, d;

//     cin >> N >> M;
//     cin >> r >> c >> d;

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < M; j++)
//             cin >> room[i][j];

//     int answer = cleaning(r, c, d);
    
//     cout << answer << "\n"; 

//     return 0;
// }
