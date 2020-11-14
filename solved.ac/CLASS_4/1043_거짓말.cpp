#include <iostream>
#include <vector>

using namespace std;

const int MAX = 51;

class union_find
{
private:
    vector<int> parent;
public:
    union_find(int N) { parent = vector<int> (N + 1, -1); }

    int find(int u)
    {
        if (parent[u] < 0) return u;

        int v = find(parent[u]);
        parent[u] = v;

        return v;
    }

    void merge(int u, int v)
    {
        u = find(u), v = find(v);

        if (u == v) return;

        if (u > v) swap(u, v);

        parent[u] += parent[v];
        parent[v] = u;
    }
};

int N, M, T, answer;
vector< vector<int> > party;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> N >> M;

    union_find *g = new union_find(N);
    vector<int> truth;

    cin >> T;

    while (T--)
    {
        int v; cin >> v;
        truth.push_back(v);
        g->merge(0, v);
    }

    while (M--)
    {
        cin >> T;

        vector<int> temp;

        for (int i = 0; i < T; i++)
        {
            int u; cin >> u;
            temp.push_back(u);
        }

        for (int i = 1; i < T; i++)
            g->merge(temp[i - 1], temp[i]);
        
        party.push_back(temp);
    }

    for (vector< vector<int> >::iterator i = party.begin(); i != party.end(); i++)
    {
        bool possible = true;
        vector<int> people = (*i);

        for (vector<int>::iterator j = people.begin(); j != people.end(); j++)
        {
            int u = g->find((*j));

            if (u == 0)
            {
                possible = false;
                break;
            }
        }

        if (possible)
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}