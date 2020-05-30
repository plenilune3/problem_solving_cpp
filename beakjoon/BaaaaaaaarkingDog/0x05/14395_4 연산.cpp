#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct state
{
    long long n;
    int depth;
    string path;
};

state bfs(long long s, long long t)
{
    set<long long> visited;
    queue<state> q;
    state init = { s, 0, "" }; 
    q.push(init);
    visited.insert(s);

    while (!q.empty())
    {
        state c = q.front();
        q.pop();

        if (c.n == t)
            return c;
        
        string op[] = { "*", "+", "-", "/" };
        long long a[] = { c.n * c.n, c.n + c.n, c.n - c.n, c.n / c.n };

        for (int i = 0; i < 4; i++)
        {
            if (visited.find(a[i]) == visited.end() && a[i] >= 1)
            {
                state nc = { a[i], c.depth + 1, c.path + op[i]};
                visited.insert(a[i]);
                q.push(nc);
            }
        }
    }

    state r = { s, -1, "" };
    return r;
}

int main(int argc, char const *argv[])
{
    long long s, t;
    cin >> s >> t;

    state result = bfs(s, t);

    if (result.depth == -1)
        cout << -1 << "\n";
    else if (result.depth == 0)
        cout << 0 << "\n";
    else
        cout << result.path << "\n";

    return 0;
}
