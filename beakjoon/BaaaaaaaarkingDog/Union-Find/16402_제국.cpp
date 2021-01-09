#include <iostream>
#include <map>
#include <set>
#include <regex>

using namespace std;

const int MAX = 501;

int N, M;
int parent[MAX];
map<string, int> kingdom_num;
map<int, string> kingdom_name;

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i <= MAX; i++)
        parent[i] = i;

    regex p("Kingdom of ([\\w]+)");
    regex w("Kingdom of ([\\w]+),Kingdom of ([\\w]+),([0-9]+)");
    smatch match;

    cin >> N >> M; cin.ignore();

    for (int i = 1; i <= N; i++)
    {
        string name;
        getline(cin, name);
        regex_match(name, match, p);
        kingdom_num[match[1].str()] = i;
        kingdom_name[i] = match[1].str();
    }
   
    while (M--)
    {
        string result;
        getline(cin, result);
        regex_match(result, match, w);

        int u = kingdom_num[match[1].str()];
        int v = kingdom_num[match[2].str()];

        string winner = match[3].str();

        if (winner == "2")
            swap(u, v);

        union_(u, v);
    }

    set<string> answer;

    for (int i = 1; i <= N; i++)
        answer.insert(kingdom_name[find_(i)]);

    cout << answer.size() << "\n";

    for (set<string>::iterator i = answer.begin(); i != answer.end(); i++)
        cout << "Kingdom of " << (*i) << "\n";

    return 0;
}

int find_(int u)
{
    if (parent[u] == u)
        return u;
    else
    {
        int v = find_(parent[u]);
        return parent[u] = v;
    }
}

void union_(int u, int v)
{
    int pu = find_(u), pv = find_(v);

    if (pu == pv)
    {
        parent[u] = u;
        parent[v] = u;
    }
    else
        parent[pv] = pu;
}
