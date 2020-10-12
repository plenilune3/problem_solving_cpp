#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 50;

int N, M, K, answer = INT_MAX;
int board[MAX][MAX];
bool selected[MAX * MAX];
vector< pair<int, int> > h, c, v;

void combinations(int depth, int index);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
                h.push_back(make_pair(i, j));
            else if (board[i][j] == 2)
                c.push_back(make_pair(i, j));
        }
    
    K = (int) c.size();

    combinations(0, 0);

    cout << answer << "\n";
    
    return 0;
}

void combinations(int depth, int index)
{
    if (depth == M)
    {
        int sum_distance = 0;

        for (vector< pair<int, int> >::iterator i = h.begin(); i != h.end(); i++)
        {
            int min_distace = MAX * MAX;

            for (vector< pair<int, int> >::iterator j = v.begin(); j != v.end(); j++)
            {
                int d = abs((*i).first - (*j).first) + abs((*i).second - (*j).second);
                min_distace = min(min_distace, d);
            }

            sum_distance += min_distace;
        }

        answer = min(answer, sum_distance);
        return;
    }

    for (int i = index; i < K; i++)
    {
        if (selected[i]) continue;

        selected[i] = true;
        v.push_back(c[i]);
        combinations(depth + 1, i);
        selected[i] = false;
        v.pop_back();
    }
}
