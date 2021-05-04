#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;

int K, M, P;
int in_degree[MAX];
int strahler_order[MAX];

int find_strahler_order(int N, vector< vector<int> > &node);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        vector< vector<int> > node(MAX);

        fill_n(&in_degree[0], MAX, 0);
        fill_n(&strahler_order[0], MAX, 0);

        cin >> K >> M >> P;

        while (P--)
        {
            int u, v; cin >> u >> v;

            node[u].push_back(v);
            in_degree[v] += 1;
        }

        int answer = find_strahler_order(M, node);

        cout << K << " " << answer << "\n";
    }

    return 0;
}

int find_strahler_order(int N, vector< vector<int> > &node)
{
    int strahler = 0;
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0)
        {
            q.push(i);
            strahler_order[i] = 1;
            strahler = max(strahler, strahler_order[i]);
        }
    
    for (int i = 0; i <= N; i++)
    {
        if (q.empty())
            return strahler;

        int u = q.front();
        q.pop();

        for (vector<int>::iterator j = node[u].begin(); j != node[u].end(); j++)
        {
            int v = (*j);

            if (--in_degree[v] == 0)
            {
                q.push(v);
                strahler_order[v] = max(strahler_order[v], strahler_order[u]);
            }
            else
                strahler_order[v] = max(strahler_order[v], strahler_order[u] + 1);
            
            strahler = max(strahler, strahler_order[v]);
        }
    }

    return strahler;
}
