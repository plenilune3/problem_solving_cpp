#include <iostream>
#include <map>

using namespace std;

const int MAX = 1e5 + 1;

int N, M;
map<string, string> user;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    while (N--)
    {
        string id, password;
        cin >> id >> password;
        user[id] = password;
    }

    while (M--)
    {
        string id; cin >> id;
        cout << user[id] << "\n";
    }

    return 0;
}
