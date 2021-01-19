#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 1;

int N, W[MAX], prev_[MAX];
int dp[MAX][2];
bool visited[MAX];
vector<int> path;
vector< vector<int> > node(MAX);
vector< vector<int> > tree(MAX);

void make_tree(int u, int p);
void make_path(int u, bool is_visited);
int calculate_(int u, bool is_selected);
int get_max(int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&dp[0][0], MAX * 2, -1);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> W[i];
    
    for (int i = 1; i <= N - 1; i++)
    {
        int u, v; cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    make_tree(1, 0);

    int answer = get_max(1);

    cout << answer << "\n";

    make_path(1, visited[1]);
    sort(path.begin(), path.end());

    for (vector<int>::iterator i = path.begin(); i != path.end(); i++)
        cout << (*i) << " ";
    cout << "\n";

    return 0;
}

int calculate_(int u, bool is_selected)
{
    int &ret = dp[u][is_selected];

    if (ret != -1) return ret;

    ret = is_selected ? W[u] : 0;

    for (vector<int>::iterator i = tree[u].begin(); i != tree[u].end(); i++)
    {
        int v = (*i);

        if (is_selected)
            ret += calculate_(v, 0);
        else
            ret += get_max(v);
    }

    return ret;
}

void make_path(int u, bool is_visited)
{
    if (is_visited)
        path.push_back(u);

    for (vector<int>::iterator i = tree[u].begin(); i != tree[u].end(); i++)
    {
        int v = (*i);

        if (is_visited)
            make_path(v, 0);
        else
            make_path(v, visited[v]);
    }
}

int get_max(int u)
{
    int result = 0;
    int x = calculate_(u, 1), y = calculate_(u, 0);

    if (x > y)
    {
        visited[u] = true;
        result = x;
    }
    else
        result = y;
    
    return result;
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