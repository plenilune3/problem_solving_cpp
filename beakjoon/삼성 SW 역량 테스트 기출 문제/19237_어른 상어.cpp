#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 21;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

struct shark
{
    int idx, x, y, d, p[5][5];

    shark() : idx(0) {};
    shark(int _idx, int _x, int _y, int _d) : idx(_idx), x(_x), y(_y), d(_d) {};

    bool operator<(const shark s) const
    {
        return idx > s.idx;
    }
};

struct smell
{
    int idx, t;

    smell() : idx(0), t(0) {};
    smell(int _idx, int _t) : idx(_idx), t(_t) {};
};

int N, M, K;
vector<shark> v;
int A[MAX][MAX];
smell B[MAX][MAX];

void spread(vector<shark> &v, int K);
void time_(int N, smell B[MAX][MAX]);
void move(int N, int A[MAX][MAX], smell B[MAX][MAX], vector<shark> &v);
int erase_shark(int A[MAX][MAX], vector<shark> &v);
int calculate_dir(shark s, smell B[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];

            if (A[i][j] == 0)
                continue;

            v.push_back(shark(A[i][j], i, j, 0));
        }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for (int i = 0; i < M; i++)
        cin >> v[i].d;
    
    for (int x = 0; x < M; x++)
        for (int i = 1; i <= 4; i++)
            for (int j = 1; j <= 4; j++)
                cin >> v[x].p[i][j];

    int answer = 0;

    spread(v, K);

    while (M != 1)
    {
        if (answer > 1000)
            break;

        answer += 1;
        move(N, A, B, v);
        M -= erase_shark(A, v);
        time_(N, B);
        spread(v, K);
    }

    if (answer > 1000)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}

void spread(vector<shark> &v, int K)
{
    for (vector<shark>::iterator i = v.begin(); i != v.end(); i++)
    {
        int idx = (*i).idx, x = (*i).x, y = (*i).y;
        B[x][y].idx = idx, B[x][y].t = K;
    }
}

void time_(int N, smell B[MAX][MAX])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (B[i][j].idx == 0)
                continue;
            
            B[i][j].t -= 1;

            if (B[i][j].t == 0)
                B[i][j].idx = 0;
        }
}

void move(int N, int A[MAX][MAX], smell B[MAX][MAX], vector<shark> &v)
{
    sort(v.begin(), v.end());

    for (vector<shark>::iterator i = v.begin(); i != v.end(); i++)
    {
        int d = calculate_dir((*i), B);

        A[(*i).x][(*i).y] = 0;
        (*i).x += dx[d], (*i).y += dy[d];
        (*i).d = d;
        A[(*i).x][(*i).y] = (*i).idx;
    }
}

int erase_shark(int A[MAX][MAX], vector<shark> &v)
{
    int result = 0;
    vector<shark>::iterator it = v.begin();

    while (it != v.end())
    {
        int idx = (*it).idx, x = (*it).x, y = (*it).y;

        if (A[x][y] != idx)
        {
            it = v.erase(it);
            result += 1;
        }
        else
            it++;
    }

    return result;
}

int calculate_dir(shark s, smell B[MAX][MAX])
{
    int dir = 0;

    for (int d = 1; d <= 4; d++)
    {
        int nx = s.x + dx[s.p[s.d][d]], ny = s.y + dy[s.p[s.d][d]];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (B[nx][ny].idx != 0)
            continue;
        
        dir = s.p[s.d][d];
        break;
    }

    if (dir != 0)
        return dir;
    
    for (int d = 1; d <= 4; d++)
    {
        int nx = s.x + dx[s.p[s.d][d]], ny = s.y + dy[s.p[s.d][d]];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        if (B[nx][ny].idx != s.idx)
            continue;
        
        dir = s.p[s.d][d];
        break;
    }

    return dir;
}