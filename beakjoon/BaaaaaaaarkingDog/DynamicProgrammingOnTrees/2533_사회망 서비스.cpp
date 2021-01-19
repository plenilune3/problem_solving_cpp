#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e6 + 1;

int N, dp[MAX][2];
vector< vector<int> > node(MAX);
vector< vector<int> > tree(MAX);

void make_tree(int u, int p);
int count_earlyadopter(int u, bool is_ealryadopter);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&dp[0][0], MAX * 2, -1);

    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int u, v; cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    make_tree(1, 0);

    int answer = min(count_earlyadopter(1, 0), count_earlyadopter(1, 1));
    cout << answer << "\n";

    return 0;
}

int count_earlyadopter(int u, bool is_ealryadopter)
{
    if (dp[u][is_ealryadopter] != -1)
        return dp[u][is_ealryadopter];
    
    dp[u][is_ealryadopter] = (is_ealryadopter) ? 1 : 0;

    for (vector<int>::iterator i = tree[u].begin(); i != tree[u].end(); i++)
    {
        int v = (*i);

        if (is_ealryadopter)
            dp[u][is_ealryadopter] += min(count_earlyadopter(v, 0), count_earlyadopter(v, 1));
        else
            dp[u][is_ealryadopter] += count_earlyadopter(v, 1);
    }

    return dp[u][is_ealryadopter];
}

void make_tree(int u, int p)
{
    for (vector<int>::iterator i = node[u].begin(); i != node[u].end(); i++)
    {
        int v = (*i);

        if (v == p) continue;

        tree[u].push_back(v);
        make_tree(v, u);
    }
}
