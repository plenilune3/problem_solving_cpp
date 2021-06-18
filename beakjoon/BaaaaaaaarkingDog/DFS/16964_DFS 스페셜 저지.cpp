#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 1;

int N;
vector< vector<int> > node(MAX, vector<int> ());

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 1; i <= N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

	return 0;
}
