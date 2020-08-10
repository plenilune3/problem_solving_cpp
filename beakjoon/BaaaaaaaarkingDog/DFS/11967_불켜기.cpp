#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 101;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;

vector< pair<int, int> > barn[MAX][MAX];
bool visited[MAX][MAX];
bool light[MAX][MAX];

void dfs(int x, int y)
{
    visited[x][y] = true;

    vector< pair<int, int> >::iterator iter;
    for (iter = barn[x][y].begin(); iter != barn[x][y].end(); iter++)
    {
        int cx = (*iter).first;
        int cy = (*iter).second;
        light[cx][cy] = true;

        if (visited[cx][cy] == true)
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            
            if (visited[nx][ny] == true)
                dfs(cx, cy);
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 1 || nx > N || ny < 1 || ny > N)
            continue;
        
        if (light[nx][ny] == true && visited[nx][ny] == false)
            dfs(nx, ny);
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        barn[x][y].push_back(make_pair(a, b));
    }

    light[1][1] = true;
    dfs(1, 1);

    int answer = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (light[i][j])
                answer++;

    cout << answer << "\n";

    return 0;
}



// const int MAX = 101;
// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};
// int N, M;

// vector< pair<int, int> > barn[MAX][MAX];
// bool light[MAX][MAX] = { false };
// bool visited[MAX][MAX] = { false };
// bool visited_before[MAX][MAX] = { false };

// bool bfs(pair<int, int> s)
// {
//     queue< pair<int, int> > q;
//     visited[s.first][s.second] = true;
//     light[s.first][s.second] = true;
//     q.push(s);
//     bool possible = false;

//     while(!q.empty())
//     {
//         pair<int, int> c = q.front();
//         q.pop();

//         int x = c.first;
//         int y = c.second;

//         if (visited_before[x][y] == false && !barn[x][y].empty())
//         {
//             vector< pair<int, int> >::iterator iter;

//             for(iter = barn[x][y].begin(); iter != barn[x][y].end(); iter++)
//                 light[(*iter).first][(*iter).second] = true;
            
//             visited_before[x][y] = true;
//             possible = true;
//         }

//         for (int i = 0; i < 4; i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];

//             if (nx < 1 || nx > N || ny < 1 || ny > N)
//                 continue;
            
//             if (visited[nx][ny] == false && light[nx][ny] == true)
//             {
//                 visited[nx][ny] = true;
//                 q.push({nx, ny});
//             }
//         }
//     }

//     return possible;
// }


// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> N >> M;

//     for (int i = 0; i < M; i++)
//     {
//         int x, y, a, b;
//         cin >> x >> y >> a >> b;
//         barn[x][y].push_back(make_pair(a, b));
//     }

//     while (true)
//     {
//         fill_n(&visited[0][0], MAX*MAX, false);
//         bool possible = bfs(make_pair(1, 1));

//         if (!possible)
//             break;
//     }

//     int answer = 0;
//     for (int i = 1; i <= N; i++)
//         for (int j = 1; j <= N; j++)
//             if (light[i][j])
//                 answer++;

//     cout << answer << "\n";

// }
