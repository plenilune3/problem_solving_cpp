#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v(2, 0);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    v[0] = 0, v[1] = 1;
    int a = v[0], b = v[1];

    while (a + b <= 1000000000)
    {
        int temp = a + b;
        v.push_back(temp);
        a = b;
        b = temp;
    }

    int T; cin >> T;

    while (T--)
    {
        int x; cin >> x;
        vector<int> answer;

        while (x)
        {
            vector<int>::iterator it = lower_bound(v.begin(), v.end(), x);

            if (x == *it)
            {
                x -= *it;
                answer.push_back(*it);
            }
            else
            {
                x -= *(it - 1);
                answer.push_back(*(it - 1));
            }
        }

        reverse(answer.begin(), answer.end());

        for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++)
            cout << (*i) << " ";
        cout << "\n";
    }

    return 0;
}
