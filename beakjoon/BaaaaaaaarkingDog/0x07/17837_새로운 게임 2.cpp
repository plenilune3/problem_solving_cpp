#include <iostream>
#include <vector>

using namespace std;

const int MAX = 14;

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

struct piece
{
    int num, d;
};

int N, K;
int board[MAX][MAX];
vector<piece> p[MAX][MAX];

void white(int r, int c, int nr, int nc, int num, vector<piece>::iterator ptr)
{
    vector<piece> np;
    np.assign(ptr, p[r][c].end());
    p[r][c].erase(ptr, p[r][c].end());

    vector<piece>::iterator iter;
    for (iter = np.begin(); iter != np.end(); iter++)
        p[nr][nc].push_back((*iter));
}

void red(int r, int c, int nr, int nc, int num, vector<piece>::iterator ptr)
{
    vector<piece> np;
    np.assign(ptr, p[r][c].end());
    p[r][c].erase(ptr, p[r][c].end());

    while (!np.empty())
    {
        piece t = np.back();
        np.pop_back();

        p[nr][nc].push_back(t);
    }
}

void move_piece(int r, int c, int num)
{
    vector<piece>::iterator ptr;
    vector<piece>::iterator iter;

    for (iter = p[r][c].begin(); iter != p[r][c].end(); iter++)
        if ((*iter).num == num)
        {
            ptr = iter;
            break;
        }
    
    int nr = r + dx[(*ptr).d];
    int nc = c + dy[(*ptr).d];

    if (board[nr][nc] == 0)
        white(r, c, nr, nc, num, ptr);

    else if (board[nr][nc] == 1)
        red(r, c, nr, nc, num, ptr);

    else if (board[nr][nc] == 2)
    {
        if ((*ptr).d == 1)
            (*ptr).d = 2;
        else if ((*ptr).d == 2)
            (*ptr).d = 1;
        else if ((*ptr).d == 3)
            (*ptr).d = 4;
        else if ((*ptr).d == 4)
            (*ptr).d = 3;
        
        int nnr = r + dx[(*ptr).d];
        int nnc = c + dy[(*ptr).d];

        if (board[nnr][nnc] == 0)
            white(r, c, nnr, nnc, num, ptr);
        else if (board[nnr][nnc] == 1)
            red(r, c, nnr, nnc, num, ptr);
    }
}

pair<int, int> find_piece(int k)
{
    pair<int, int> result;

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
        {
            if (p[r][c].empty())
                continue;

            vector<piece>::iterator iter;
            for (iter = p[r][c].begin(); iter != p[r][c].end(); iter++)
                if ((*iter).num == k)
                    result = make_pair(r, c);
        }
    
    return result;
}

bool is_possible()
{
    bool possible = true;

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            if (p[r][c].size() >= 4)
            {
                possible = false;
                break;
            }
    
    return possible;
}

int main(int argc, char const *argv[])
{
    cin >> N >> K;

    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= N + 1; j++)
        {
            if (i == 0 || j == 0 || i == N + 1 || j == N + 1)
                board[i][j] = 2;
            else
                cin >> board[i][j];
        }
    
    for (int k = 1; k <= K; k++)
    {
        int r, c, d;

        cin >> r >> c >> d;
        piece t = { k, d };
        p[r][c].push_back(t);
    }

    int cnt = 0;

    while (true)
    {
        cnt += 1;

        bool possible = false;

        for (int k = 1; k <= K; k++)
        {
            pair<int, int> c = find_piece(k);
            move_piece(c.first, c.second, k);

            if (is_possible() == false)
            {
                possible  = true;
                break;
            }

            if (possible)
                break;
        }

        if (possible)
            break;
        
        if (cnt > 1000)
            break;
    }

    if (cnt > 1000)
        cout << -1 << "\n";
    else 
        cout << cnt << "\n";

    return 0;
}


