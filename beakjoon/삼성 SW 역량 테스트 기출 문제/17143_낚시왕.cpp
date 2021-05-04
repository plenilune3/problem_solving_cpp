#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 101;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, 1, -1 };

struct shark 
{
    int x, y, s, d, z;

    shark(int _x, int _y, int _s, int _d, int _z) : x(_x), y(_y), s(_s), d(_d), z(_z) {}

    bool operator< (const shark s) const
    {
        return z < s.z;
    }
};

int R, C, M, A[MAX][MAX];
vector<shark> v;

int catch_shark(int y, vector<shark> &v);
int find_shark(int y);
void move_sharks(vector<shark> &v);
void move_shark(shark &s);
int change_dir(int dir);
void eat_shark(vector<shark> &v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> R >> C >> M;

    for (int k = 1; k <= M; k++)
    {
        int x, y, s, d, z; cin >> x >> y >> s >> d >> z;
        A[x - 1][y - 1] = z;

        if (d == 1 || d == 2)
            s = s % (R * 2 - 2);
        else
            s = s % (C * 2 - 2);

        v.push_back(shark(x - 1, y - 1, s, d, z));
    }

    int fisher_man = 0;
    int answer = 0;

    while (fisher_man < C)
    {
        answer += catch_shark(fisher_man++, v);
        move_sharks(v);
        eat_shark(v);
    }

    cout << answer << "\n";

    return 0;
}

int catch_shark(int y, vector<shark> &v)
{
    int z = find_shark(y);

    if (z == 0)
        return 0;
    
    for (vector<shark>::iterator i = v.begin(); i != v.end(); i++)
        if ((*i).z == z)
        {
            A[(*i).x][(*i).y] = 0;
            v.erase(i);
            break;
        }
    
    return z;
}

int find_shark(int y)
{
    for (int x = 0; x < R; x++)
        if (A[x][y] != 0)
            return A[x][y];
    
    return 0;
}

void move_sharks(vector<shark> &v)
{
    for (int x = 0; x < R; x++)
        for (int y = 0; y < C; y++)
            A[x][y] = 0;

    sort(v.begin(), v.end());

    for (vector<shark>::iterator i = v.begin(); i != v.end(); i++)
        move_shark(*i);

    for (vector<shark>::iterator i = v.begin(); i != v.end(); i++)
        A[(*i).x][(*i).y] = (*i).z;
}

void move_shark(shark &s)
{
    for (int i = 0; i < s.s; i++)
    {
        int nx = s.x + dx[s.d], ny = s.y + dy[s.d];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
        {
            s.d = change_dir(s.d);
            nx = s.x + dx[s.d], ny = s.y + dy[s.d];
        }

        s.x = nx, s.y = ny;
    }
}

void eat_shark(vector<shark> &v)
{
    vector<shark>::iterator it = v.begin();

    while (it != v.end())
    {
        int x = (*it).x, y = (*it).y, z = (*it).z;

        if (A[x][y] != z)
            it = v.erase(it);
        else
            it++;
    }
}

int change_dir(int dir)
{
    if (dir == 1) return 2;
    else if (dir == 2) return 1;
    else if (dir == 3) return 4;
    else return 3;
}