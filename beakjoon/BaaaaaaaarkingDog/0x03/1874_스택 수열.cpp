#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> s;
    string answer;
    int num_max = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        if (k > num_max)
        {
            for (int i = num_max + 1; i <= k; i++)
            {
                s.push(i);
                answer += "+\n";
            }
        }
        else
        {
            if (s.top() != k)
            {
                cout << "NO" << "\n";
                return 0;
            }

        }

        s.pop();
        answer += "-\n";

        if (num_max < k)
            num_max = k;
    }

    cout << answer << "\n";

    return 0;
}
