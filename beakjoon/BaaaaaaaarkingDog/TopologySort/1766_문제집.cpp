#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32001;

int N, M;
int in_degree[MAX];
vector< vector<int> > node(MAX);

vector<int> find_order();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        node[u].push_back(v);
        in_degree[v] += 1;
    }

    vector<int> answer = find_order();

    for (vector<int>::iterator iter= answer.begin(); iter != answer.end(); iter++)
        cout << (*iter) << " ";
    cout << "\n";

    return 0;
}

vector<int> find_order()
{
    vector<int> result;
    priority_queue<int> pq;

    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0)
            pq.push(-i);
    
    for (int i = 1; i <= N; i++)
    {
        int u = -pq.top(); pq.pop();

        result.push_back(u);

        for (vector<int>::iterator iter = node[u].begin(); iter != node[u].end(); iter++)
        {
            int v = (*iter);

            if (--in_degree[v] == 0)
                pq.push(-v);
        }
    }

    return result;
}

