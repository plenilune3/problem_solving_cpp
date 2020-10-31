#include <iostream>
#include <map>

using namespace std;

const int MAX = 1e5 + 1;

int N, M;

string findById[MAX];
map<string, int> findByName;
// map<int, string> findById;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string name; cin >> name;
        findByName[name] = i;
        findById[i] = name;
    }

    while (M--)
    {
        string query; cin >> query;

        if (isalpha(query[0]))
            cout << findByName[query] << "\n";
        else
        {
            int id = 0;

            for (string::iterator i = query.begin(); i != query.end(); i++)
                id = id * 10 + ((*i) - '0');
            
            cout << findById[id] << "\n";
        }
    }

    return 0;
}
