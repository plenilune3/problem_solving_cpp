#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct enermy
{
    int x, y, d;

    bool operator< (const enermy &e) const
    {
        if (d != e.d) return d > e.d;
        else return y > e.y;
    }
};

const int MAX = 15;

int N, M, D, answer = 0;
bool board[MAX][MAX];
vector< pair<int, int> > v;
bool selected[MAX];

void choose_archer(int depth, int index);
int play(bool board[MAX][MAX]);
void move(bool board[MAX][MAX]);
vector<enermy> get_enermies(bool board[MAX][MAX]);
enermy make_enermy(int x, int y, int d);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> D;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    choose_archer(0, 0);

    cout << answer << "\n";
    
    return 0;
}

void choose_archer(int depth, int index)
{
    if (depth == 3)
    {
        bool board_c[MAX][MAX];
        copy(&board[0][0], &board[0][0] + MAX * MAX, &board_c[0][0]);
        answer = max(answer, play(board_c));
        return;
    }

    for (int i = index; i < M; i++)
    {
        if (selected[i]) continue;

        selected[i] = true;
        v.push_back(make_pair(N, i));
        choose_archer(depth + 1, i);
        selected[i] = false;
        v.pop_back();
    }
}

int play(bool board[MAX][MAX])
{
    int counter = 0;

    while (true)
    {
        vector<enermy> enermies = get_enermies(board);

        if (enermies.empty())
            break;

        for (vector<enermy>::iterator i = enermies.begin(); i != enermies.end(); i++)
        {
            int x = (*i).x, y = (*i).y, d = (*i).d;

            if (board[x][y] && d <= D)
            {
                counter += 1;
                board[x][y] = 0;
            }
        }

        move(board);
    }

    return counter;
}

void move(bool board[MAX][MAX])
{
    bool board_c[MAX][MAX];

    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            board_c[(x + 1) % N][y] = board[x][y];
    
    for (int y = 0; y < M; y++)
        board_c[0][y] = 0;
    
    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}

vector<enermy> get_enermies(bool board[MAX][MAX])
{
    vector<enermy> c;
    priority_queue<enermy> pq[3];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0)
                continue;

            for (int k = 0; k < 3; k++)
            {
                int dist = abs(v[k].first - i) + abs(v[k].second - j);
                pq[k].push(make_enermy(i, j, dist));
            }
        }
    
    for (int i = 0; i < 3; i++)
        if (!pq[i].empty())
            c.push_back(pq[i].top());
    
    return c;
}

enermy make_enermy(int x, int y, int d)
{
    enermy e = { x, y, d };
    return e;
}

