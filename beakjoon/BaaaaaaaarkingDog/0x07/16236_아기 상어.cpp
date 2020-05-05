#include <iostream>
#include <queue>

using namespace std;

// struct shark
// {
//     int x, y, size, cnt, time;
// };

// struct coordinate
// {
//     int x, y, depth;
// };

class shark
{
public:
    int x, y, size = 2, cnt = 0, time = 0;

    void set_coordinate(int i, int j)
    {
        x = i;
        y = j;
    }

    void eat_fish()
    {
        cnt += 1;

        if (cnt == size)
            cnt = 0, size += 1;
    }

    void add_time(int t)
    {
        time += t;
    }
};

class coordinate
{
public:
    int d, x, y;

    coordinate(int _d, int _x, int _y)
    {
        d = _d, x = _x, y = _y;
    }

    bool operator < (const coordinate &t) const
    {
        if (d == t.d)
            if (x == t.x)
                return y > t.y;
            else
                return x > t.x;
        else
            return d > t.d;
    }
};

const int MAX = 20;
const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

int fish[MAX][MAX];
bool visited[MAX][MAX];
int N;
shark baby;

bool bfs()
{
    fill_n(&visited[0][0], MAX*MAX, false);
    
    priority_queue<coordinate> pq;
    coordinate init(0, baby.x, baby.y);
    visited[baby.x][baby.y] = true;
    pq.push(init);

    while(!pq.empty())
    {
        coordinate c = pq.top();
        pq.pop();

        if (fish[c.x][c.y] > 0 && fish[c.x][c.y] < baby.size) 
        {
            baby.set_coordinate(c.x, c.y);
            baby.add_time(c.d);
            baby.eat_fish();
            fish[c.x][c.y] = 0;

            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
                continue;
            
            if (fish[nx][ny] <= baby.size)
            {
                visited[nx][ny] = true;
                coordinate nc(c.d + 1, nx, ny);
                pq.push(nc);
            }
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> fish[i][j];

            if (fish[i][j] == 9)
            {
                baby.set_coordinate(i, j);
                fish[i][j] = 0;
            }
        }
    
    while (true)
    {
        bool possible = bfs();

        if (possible == false)
            break;
    }

    cout << baby.time << "\n";

    return 0;
}


// int bfs()
// {
//     fill_n(&visited[0][0], MAX*MAX, false);
//     deque<coordinate> dq;
//     coordinate init = { baby.x, baby.y, 0 };
//     visited[baby.x][baby.y] = true;
//     dq.push_back(init);
//     int end = N * N;
//     coordinate n = {MAX, MAX, 0};

//     while (!dq.empty())
//     {
//         coordinate c = dq.front();
//         dq.pop_front();

//         if (c.depth == end)
//             break;

//         if (fish[c.x][c.y] > 0 && fish[c.x][c.y] < baby.size)
//         {
//             end = c.depth + 1;

//             if (c.x < n.x)
//                 n = c;
//             else if (c.x == n.x && c.y < n.y)
//                 n = c;
//         }
        
//         for (int i = 0; i < 4; i++)
//         {
//             int nx = c.x + dx[i];
//             int ny = c.y + dy[i];

//             if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny])
//                 continue;
            
//             if (fish[nx][ny] <= baby.size)
//             {
//                 visited[nx][ny] = true;
//                 coordinate nc = {nx, ny, c.depth + 1};
//                 dq.push_back(nc);
//             }
//         }
//     }

//     if (n.depth == 0)
//         return -1;
//     else
//     {
//         fish[n.x][n.y] = 0;
//         baby.x = n.x;
//         baby.y = n.y;
//         baby.cnt += 1;
//         baby.time += n.depth;

//         if (baby.cnt == baby.size)
//         {
//             baby.cnt = 0;
//             baby.size += 1;
//         }

//         return n.depth;
//     }
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     cin >> N;

//     for (int i = 0; i < N; i++)
//         for (int j = 0; j < N; j++)
//         {
//             cin >> fish[i][j];

//             if (fish[i][j] == 9)
//             {
//                 baby.x = i, baby.y = j, baby.size = 2, baby.cnt = 0, baby.time = 0;
//                 fish[i][j] = 0;
//             }
//         }
    
//     int answer = 0;
    
//     while (true)
//     {
//         int time = bfs();

//         if (time == -1)
//             break;
        
//         answer += time;
//     }

//     cout << answer << "\n";

//     return 0;
// }

