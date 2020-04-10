#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        if (str[1] == 'u')
        {
            int operand;
            cin >> operand;

            q.push(operand);
        }
        else if (str[1] == 'o')
        {
            if (q.empty())
                cout << -1 << "\n";
            else
            {
                int t = q.front();
                cout << t << "\n";
                q.pop();
            }
        }
        else if (str[1] == 'i')
            cout << q.size() << "\n";
        else if (str[1] == 'm')
            cout << (int) q.empty() << "\n";
        else if (str[1] == 'r')
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        else if (str[1] == 'a')
            if (q.empty())
                cout << -1 << "\n";
            else
                cout << q.back() << "\n";
    }

    return 0;
}
