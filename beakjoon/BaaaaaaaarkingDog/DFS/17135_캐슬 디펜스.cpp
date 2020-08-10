#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 15;

class enemy
{
public:
    int d, x, y;

    enemy(int _d, int _x, int _y)
    {
        d = _d, x = _x, y = _y;
    }

    bool operator< (const enemy &t) const
    {
        if (d == t.d)
            return y > t.y;
        else
            return d > t.d;
    }
};

int N, M, D, answer;
bool board[MAX][MAX];
vector< pair<int, int> > archer;
bool selected[MAX];

int get_distance(pair<int, int>& a, pair<int, int>& b)
{
    int result = 0;

    if (a.first > b.first)
        result += a.first - b.first;
    else
        result += b.first - a.first;
    
    if (a.second > b.second)
        result += a.second - b.second;
    else
        result += b.second - a.second;
    
    return result;
}

int defense(bool board[MAX][MAX])
{
    int result = 0;

    while (true)
    {
        vector< pair<int, int> > e;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j])
                    e.push_back(make_pair(i, j));
        
        if (e.empty())
            break;
        
        vector< pair<int, int> >::iterator aiter;
        vector< pair<int, int> >::iterator eiter;
        for (aiter = archer.begin(); aiter != archer.end(); aiter++)
        {
            priority_queue<enemy> pq;

            for (eiter = e.begin(); eiter != e.end(); eiter++)
            {
                int dist = get_distance((*aiter), (*eiter));
                enemy c(dist, (*eiter).first, (*eiter).second);
                pq.push(c);
            }

            enemy t = pq.top();
            
            if (t.d <= D && board[t.x][t.y] == 1)
            {
                result += 1;
                board[t.x][t.y] = 0;
            }
        }

        for (int j = 0; j < M; j++)
        {
            bool temp[N];

            for (int i = 0; i < N; i++)
                temp[(i + 1) % N] = board[i][j];
            
            temp[0] = 0;
            
            for (int i = 0; i < N; i++)
                board[i][j] = temp[i];
        }
    }

    return result;
}

void combinations(int depth, int index)
{
    if (depth == 3)
    {
        bool board_copy[MAX][MAX];
        copy(&board[0][0], &board[0][0] + MAX * MAX, &board_copy[0][0]);
        answer = max(answer, defense(board_copy));
        return;
    }

    for (int i = index; i < M; i++)
        if (selected[i] == false) 
        {
            selected[i] = true;
            archer.push_back(make_pair(N, i));
            combinations(depth + 1, i);
            selected[i] = false;
            archer.pop_back();
        }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> D;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    combinations(0, 0);

    cout << answer << "\n";

    return 0;
}
