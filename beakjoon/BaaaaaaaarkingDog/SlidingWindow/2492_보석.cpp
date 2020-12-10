#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 2;

int N, M, T, K;
vector< pair<int, int> > v;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> T >> K;

    while (T--)
    {
        int X, Y; cin >> X >> Y;
        v.push_back(make_pair(X, Y));
    }

    sort(v.begin(), v.end());

    for (vector< pair<int, int> >::iterator i = v.begin(); i != v.end(); i++)
        cout << (*i).first << " " << (*i).second << "\n";
    
    return 0;
}
