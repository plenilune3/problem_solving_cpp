#include <iostream>

using namespace std;

// struct pipe
// {
//     int x, y, d;
// };

const int MAX = 17;
// const int dx[] = {0, 1, 1};
// const int dy[] = {1, 1, 0};

bool visited[MAX][MAX];
int N, answer;

void dfs(int x, int y, int d)
{
    if (x == N && y == N)
    {
        answer += 1;
        return;
    }

    if (d != 0 && x + 1 <= N && visited[x + 1][y] == false)
        dfs(x + 1, y, 1);
    
    if (d != 1 && y + 1 <= N && visited[x][y + 1] == false)
        dfs(x, y + 1, 0);
    
    if (x + 1 <= N && y + 1 <= N && visited[x + 1][y + 1] == false && visited[x][y + 1] == false && visited[x + 1][y] == false)
        dfs(x + 1, y + 1, 2);
}

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> visited[i][j];
    
    dfs(1, 2, 0);

    cout << answer << "\n";
    
    return 0;
}


// void backtracking(int depth, pipe p)
// {
//     if (p.x == N && p.y == N)
//     {
//         answer += 1;
//         return;
//     }

//     for (int i = 0; i < 3; i++)
//     {
//         int nx = p.x + dx[i];
//         int ny = p.y + dy[i];

//         if (nx < 1 || nx > N || ny < 1 || ny > N || visited[nx][ny])
//             continue;
        
//         if ((p.d == 0 && i == 2) || (p.d == 2 && i == 0))
//             continue;
        
//         pipe t = {nx, ny, i};

//         if (i == 1)
//         {
//             if (visited[p.x + 1][p.y] || visited[p.x][p.y + 1])
//                 continue;

//             visited[nx][ny] = true;
//             visited[p.x + 1][p.y] = true;
//             visited[p.x][p.y + 1] = true;
//             backtracking(depth + 1, t);
//             visited[nx][ny] = false;
//             visited[p.x + 1][p.y] = false;
//             visited[p.x][p.y + 1] = false;
//         }
//         else
//         {
//             visited[nx][ny] = true;
//             backtracking(depth + 1, t);
//             visited[nx][ny] = false;
//         }
//     }
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL), cout.tie(NULL);

//     cin >> N;

//     for (int i = 0; i < N + 2; i++)
//         for (int j = 0; j < N + 2; j++)
//         {
//             if (i == 0 || i == N + 1 || j == 0 || j == N + 1)
//                 visited[i][j] = false;
//             else
//                 cin >> visited[i][j];
//         }
    
//     visited[1][1] = true;
//     visited[1][2] = true;
//     pipe p = {1, 2, 0};
//     backtracking(0, p);

//     cout << answer << "\n";

//     return 0;
// }
