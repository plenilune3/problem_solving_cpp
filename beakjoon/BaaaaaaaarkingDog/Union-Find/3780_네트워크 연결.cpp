#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 2e4 + 1;

int N;
int parent[MAX], length[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i <= N; i++)
        {
            parent[i] = i;
            length[i] = 0;
        }

        while (true)
        {
            int u, v;
            char cmd; cin >> cmd;

            if (cmd == 'O') break;

            if (cmd == 'E')
            {
                cin >> u;
                find_(u);
                cout << length[u] << "\n";
            }
            else if (cmd == 'I')
            {
                cin >> u >> v;
                union_(u, v);
            }
        }
    }

    return 0;
}

int find_(int u)
{
    if (parent[u] == u)
        return u;
    else
    {
        int temp = find_(parent[u]);
        length[u] += length[parent[u]];
        return parent[u] = temp;
    }
}

void union_(int u, int v)
{
    length[u] = abs(u - v) % 1000;
    parent[u] = v;
}

