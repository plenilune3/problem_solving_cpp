#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int N = 10;

bool A[N][N];
bool visited[N][N];
int paper[6] = {0, 5, 5, 5, 5, 5};
vector< pair<int, int> > v;
int length, answer = INT_MAX;

bool is_possible(int x, int y, int s)
{
    bool possible = true;

    if (x + s > N || y + s > N || paper[s] == 0 || visited[x][y])
        possible = false;
    else
    {
        for (int i = x; i < x + s; i++)
        {
            for (int j = y; j < y + s; j++)
                if (A[i][j] == false || visited[i][j])
                {
                    possible = false;
                    break;
                }
            if (possible == false)
                break;
        }
    }

    return possible;
}

void attach(int x, int y, int s)
{
    for (int i = x; i < x + s; i++)
        for (int j = y; j < y + s; j++)
        {
            A[i][j] = false, visited[i][j] = true;
        }

}

void detach(int x, int y, int s)
{
    for (int i = x; i < x + s; i++)
        for (int j = y; j < y + s; j++)
        {
            A[i][j] = true, visited[i][j] = false;
        }
}

void backtracking(int depth)
{
    // cout << "\n";

    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //         cout << A[i][j] << " ";
    //     cout << "\n";
    // }
    
    if (depth == length)
    {
        bool finished = true;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (A[i][j])
                {
                    finished = false;
                    break;
                }

        if (finished)
        {
            int result = 25 - (paper[1] + paper[2] + paper[3] + paper[4] + paper[5]);
            cout << result << "\n";
            answer = min(answer, result);
        }

        return;
    }

    for (int i = depth; i < length; i++)
    {
        int x = v[i].first;
        int y = v[i].second;

        if (visited[x][y])
            continue;

        for (int s = 1; s <= 5; s++)
        {
            if (paper[s] == 0)
                continue;

            if (is_possible(x, y, s))
            {
                attach(x, y, s);
                paper[s] -= 1;
                backtracking(depth + 1);
                paper[s] += 1;
                detach(x, y, s);
            }
        }
    }
}


int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];

            if (A[i][j])
                v.push_back(make_pair(i, j));
        }
    
    length = v.size();
    backtracking(0);
    
    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
