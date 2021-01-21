#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2e5 + 1;

struct node
{
    int left, right;
};

int N;
long long K;
node nodes[MAX];

int dfs(int d, long long r, int u);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int u = 1; u <= N; u++)
        cin >> nodes[u].left >> nodes[u].right;

    cin >> K;

    cout << dfs(0, K, 1) << "\n";

    return 0;
}

int dfs(int d, long long r, int u)
{
    if (nodes[u].left == -1 && nodes[u].right == -1)
        return u;
    
    else if (nodes[u].right == -1)
        return dfs(d + 1, r, nodes[u].left);
    
    else if (nodes[u].left == -1)
        return dfs(d + 1, r, nodes[u].right);

    else
    {
        if (r % 2 != 0)
            return dfs(d + 1, r / 2 + 1, nodes[u].left);
        else
            return dfs(d + 1, r / 2, nodes[u].right);
    }
}
