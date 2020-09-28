#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;
const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int kdx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int kdy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int N, W, H, answer;
char board[MAX][MAX];
bool visited[15];
int count_[MAX][MAX];
vector< pair<int, int> > v;

void backtracking(int depth, int index);
void king(int x, int y, int v);
void queen(int x, int y, int v);
void rook(int x, int y, int v);
void bishop(int x, int y, int v);
void knight(int x, int y, int v);
void count_attack(int x, int y, char c, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string start, end;

    while (cin >> start)
    {
        fill_n(&count_[0][0], MAX * MAX, false);
        v.clear();
        answer = 16;
        cin >> W >> H;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
            {
                cin >> board[i][j];

                if (board[i][j] != 'E')
                {
                    count_attack(i, j, board[i][j], 1);
                    v.push_back(make_pair(i, j));
                }
            }
        
        N = (int) v.size();
        
        cin >> end;

        backtracking(0, 0);

        cout <<  "Minimum Number of Pieces to be removed: " << answer << "\n";
    }

    return 0;
}

bool is_possible()
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (board[i][j] != 'E' && count_[i][j] != 0)
                return false;
    
    return true;
}

void backtracking(int depth, int index)
{
    if (is_possible())
    {
        answer = min(depth, answer);
        return;
    }

    for (int i = index; i < N; i++)
    {
        if (visited[i]) continue;

        int x = v[i].first, y = v[i].second;
        char c = board[x][y];

        visited[i] = true;
        count_attack(x, y, c, -1);
        board[x][y] = 'E';
        backtracking(depth + 1, i);
        visited[i] = false;
        count_attack(x, y, c, 1);
        board[x][y] = c;
    }
}

void attack(int x, int y, int d, int v)
{
    x += dx[d], y += dy[d];
    
    while (true)
    {
        if (x < 0 || x >= H || y < 0 || y >= W)
            break;
        
        count_[x][y] += v;
        x += dx[d], y += dy[d];
    }
}

void king(int x, int y, int v)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        
        count_[nx][ny] += v;
    }
}

void queen(int x, int y, int v)
{
    for (int i = 0; i < 8; i++)
        attack(x, y, i, v);
}

void rook(int x, int y, int v)
{
    for (int i = 0; i <= 6; i += 2)
        attack(x, y, i, v);
}

void bishop(int x, int y, int v)
{
    for (int i = 1; i <= 7; i += 2)
        attack(x, y, i, v);
}

void kningt(int x, int y, int v)
{
    for (int i = 0; i < 8; i++)
    {
        int nx = x + kdx[i], ny = y + kdy[i];

        if (nx < 0 || nx >= H || ny < 0 || ny >= W)
            continue;
        
        count_[nx][ny] += v;
    }
}

void count_attack(int x, int y, char c, int v)
{
    if (c == 'K') king(x, y, v);
    else if (c == 'Q') queen(x, y, v);
    else if (c == 'R') rook(x, y, v);
    else if (c == 'B') bishop(x, y, v);
    else if (c == 'N') kningt(x, y, v);
}

