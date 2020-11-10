#include <iostream>
#include <set>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int N; cin >> N;
        multiset<int> ms;

        while (N--)
        {
            char c; int num;
            cin >> c >> num;

            if (c == 'I')
                ms.insert(num);
            
            else if (c == 'D' && !ms.empty())
            {
                if (num == 1)
                    ms.erase(--ms.end());
                else
                    ms.erase(ms.begin());
            }
        }

        if (!ms.empty())
            cout << *(ms.rbegin()) << " " << *(ms.begin()) << "\n";
        else
            cout << "EMPTY" << "\n";

    }

    return 0;
}