#include <iostream>

using namespace std;

struct fish
{
    int idx, d;

    fish() : idx(0), d(0) {};
    fish(int _idx, int _d) : idx(_idx), d(_d) {};
};

const int MAX = 4;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int answer, sum_init;
fish A[MAX][MAX];

void feed_shark(int x, int y, int result);
void move_fish(fish A[MAX][MAX]);
pair<int, int> find_fish(int k);
bool is_possible(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int x = 0; x < MAX; x++)
        for (int y = 0; y < MAX; y++)
        {
            cin >> A[x][y].idx >> A[x][y].d;
            A[x][y].d -= 1;
        }
    
    int result = A[0][0].idx;
    A[0][0].idx = 17;
    feed_shark(0, 0, result);

    cout << answer << "\n";

    return 0;
}

void feed_shark(int x, int y, int result)
{
    int d = A[x][y].d;
    move_fish(A);

    if (!is_possible(x, y))
    {
        answer = max(answer, result);
        return;
    }

    fish B[MAX][MAX];
    copy(&A[0][0], &A[0][0] + MAX * MAX, &B[0][0]);

    for (int k = 1; k < 4; k++)
    {
        int nx = x + dx[d] * k, ny = y + dy[d] * k;

        if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
            continue;
        
        if (A[nx][ny].idx == 0)
            continue;
        
        int temp = A[nx][ny].idx;
        A[nx][ny].idx = 17;
        A[x][y].idx = 0;
        feed_shark(nx, ny, result + temp);
        copy(&B[0][0], &B[0][0] + MAX * MAX, &A[0][0]);
    }
}

void move_fish(fish A[MAX][MAX])
{
    for (int k = 1; k <= 16; k++)
    {
        pair<int, int> c = find_fish(k);
        int x = c.first, y = c.second;

        if (x == -1 && y == -1)
            continue;

        for (int d = 0; d < 8; d++)
        {
            int nx = x + dx[(A[x][y].d + d) % 8], ny = y + dy[(A[x][y].d + d) % 8];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) 
                continue;
            
            if (A[nx][ny].idx == 17)
                continue;
            
            A[x][y].d = (A[x][y].d + d) % 8;
            swap(A[x][y], A[nx][ny]);
            break;
        }
    }
}

pair<int, int> find_fish(int k)
{
    for (int x = 0; x < MAX; x++)
        for (int y = 0; y < MAX; y++)
            if (A[x][y].idx == k)
                return make_pair(x, y);

    return make_pair(-1, -1);
}

bool is_possible(int x, int y)
{
    int d = A[x][y].d;

    for (int k = 1; k < 4; k++)
    {
        int nx = x + dx[d] * k, ny = y + dy[d] * k;

        if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
            continue;
        
        if (A[nx][ny].idx == 0)
            continue;
        
        return true;
    }

    return false;
}