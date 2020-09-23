#include <iostream>
#include <vector>

using namespace std;

const int MAX = 5e5 + 1;

int N, answer;
vector< vector<int> > node(MAX);
bool visited[MAX];

void find_height(int depth, int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v; cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    find_height(0, 1);

    if (answer % 2 == 0)
        cout << "No" << "\n";
    else
        cout << "Yes" << "\n";

    return 0;
}

void find_height(int depth, int x)
{
    bool is_leaf = true;
    visited[x] = true;

    for (vector<int>::iterator iter = node[x].begin(); iter != node[x].end(); iter++)
    {
        int nx = (*iter);

        if (visited[nx])
            continue;
        
        is_leaf = false;
        find_height(depth + 1, nx);
    }

    if (is_leaf)
        answer += depth;
}


