#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int student[MAX+1];
bool visited[MAX+1];
bool cycle[MAX+1];
int n, cnt;

void dfs(int s)
{
    visited[s] = true;

    int ns = student[s];

    if (visited[ns] == false)
        dfs(ns);
    else if (cycle[ns] == false)
    {
        for(int i = ns; i != s; i = student[i])
            cnt++;
        cnt++;
    }

    cycle[s] = true;
}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        fill_n(visited, MAX+1, false);
        fill_n(cycle, MAX+1, false);

        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> student[i];

        cnt = 0;
        for (int i = 1; i <= n; i++)
            if (visited[i] == false)
                dfs(i);

        cout << n - cnt << "\n";
    }

    return 0;
}
