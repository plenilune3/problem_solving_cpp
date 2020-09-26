#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;

int N, M;
int in_degree[MAX];
vector< vector< pair<int, int> > > node(MAX);

vector< vector<int> > count_part();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    while (M--)
    {
        int u, v, w; cin >> u >> v >> w;
        node[v].push_back(make_pair(u, w));
        in_degree[u] += 1;
    }

    vector< vector<int> > parts = count_part();

    for (int i = 1; i <= N; i++)
        if (parts[N][i])
            cout << i << " " << parts[N][i] << "\n";

    return 0;
}

vector< vector<int> > count_part()
{
    vector< vector<int> > parts(MAX, vector<int> (MAX, 0));
    queue<int> q;

    for (int u = 1; u <= N; u++)
        if (in_degree[u] == 0)
        {
            parts[u][u] = 1;
            q.push(u);
        }
    
    for (int i = 1; i <= N; i++)
    {
        int u = q.front(); q.pop();

        for (vector< pair<int, int> >::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        {
            int v = (*iter).first, w = (*iter).second;

            for (int j = 1; j <= N; j++)
                parts[v][j] += parts[u][j] * w;
            
            if (--in_degree[v] == 0)
                q.push(v);
        }
    }

    return parts;
}


