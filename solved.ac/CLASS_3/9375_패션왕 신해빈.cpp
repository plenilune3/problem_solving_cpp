#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        map<string, int> clothes;

        int N; cin >> N;

        for (int i = 0; i < N; i++)
        {
            string name, type;
            cin >> name >> type;
            clothes[type] += 1;
        }

        int answer = 1;

        for (map<string, int>::iterator i = clothes.begin(); i != clothes.end(); i++)
            answer *= (*i).second + 1;
        
        cout << answer - 1 << "\n";
    }

    return 0;
}
