#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int N;
vector<int> a, b;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        a.push_back(num);
    }

    b.assign(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> c;
    unique_copy(b.begin(), b.end(), back_inserter(c));

    for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
        cout << lower_bound(c.begin(), c.end(), (*i)) - c.begin() << " ";
    cout << "\n";

    return 0;
}
