#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 11;

int N, population[MAX], answer = 100 * 100;
bool selected[MAX], visited[MAX];
vector< vector<int> > node(MAX);
vector<int> v;

void combinations(int depth);
int dfs(int x, bool b);

int main(int argc, char const *argv[])
{
    cin >> N;
    
    for (int i = 0; i < N; i++)
        cin >> population[i];
    
    for (int u = 0; u < N; u++)
    {
        int K; cin >> K;

        while (K--)
        {
            int v; cin >> v;

            node[u].push_back(v - 1);
            node[v - 1].push_back(u);
        }
    }

    combinations(0);

    if (answer != 100 * 100)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void combinations(int depth)
{
    if (depth == N)
    {
        fill_n(&visited[0], MAX, false);

        int count_a = 0, count_b = 0;
        int a = 0, b = 0;

        for (int i = 0; i < N; i++)
            if (visited[i] == false && selected[i])
            {
                count_a += 1;
                a += dfs(i, true);
            }
        
        for (int i = 0; i < N; i++)
            if (visited[i] == false && selected[i] == false)
            {
                count_b += 1;
                b += dfs(i, false);
            }
        
        if (count_a == 1 && count_b == 1)
            answer = min(answer, abs(a - b));

        return;
    }

    selected[depth] = true;
    combinations(depth + 1);

    selected[depth] = false;
    combinations(depth + 1);
}

int dfs(int x, bool b)
{
    visited[x] = true;
    int ret = population[x];

    for (vector<int>::iterator i = node[x].begin(); i != node[x].end(); i++)
    {
        int nx = (*i);

        if (visited[nx] || selected[nx] != b) continue;

        ret += dfs(nx, b);
    }

    return ret;
}