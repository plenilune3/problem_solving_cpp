#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 501;

int N, M;
int ranking[MAX];
int in_degree[MAX];
bool adj[MAX][MAX];

vector<int> find_order();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        fill_n(&adj[0][0], MAX * MAX, false);
        fill_n(&in_degree[0], MAX, 0);
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> ranking[i];
        
        for (int i = 1; i <= N; i++)
            for (int j = i + 1; j <= N; j++)
            {
                adj[ranking[i]][ranking[j]] = true;
                in_degree[ranking[j]] += 1;
            }

        cin >> M;

        while (M--)
        {
            int u, v; cin >> u >> v;

            if (adj[u][v])
            {
                adj[u][v] = false;
                in_degree[v] -= 1;
                adj[v][u] = true;
                in_degree[u] += 1;
            }
            else
            {
                adj[u][v] = true;
                in_degree[v] += 1;
                adj[v][u] = false;
                in_degree[u] -= 1;
            }
    }

        vector<int> result = find_order();

        if (result[0] == -1)
            cout << "IMPOSSIBLE" << "\n";
        else if (result[0] == -2)
            cout << "?" << "\n";
        else
        {
            for (vector<int>::iterator iter = result.begin(); iter != result.end(); iter++)
                cout << (*iter) << " ";
            cout << "\n";
        }
    }

    return 0;
}

vector<int> find_order()
{
    vector<int> result;
    queue<int> q;

    for (int u = 1; u <= N; u++)
        if (in_degree[u] == 0)
            q.push(u);
    
    for (int i = 1; i <= N; i++)
    {
        if (q.empty())
            return vector<int> (1, -1);
        
        if (q.size() > 1)
            return vector<int> (1, -2);
        
        int u = q.front(); q.pop();

        result.push_back(u);

        for (int v = 1; v <= N; v++)
        {
            if (!adj[u][v])
                continue;
            
            if (--in_degree[v] == 0)
                q.push(v);
        }
    }

    return result;
}

