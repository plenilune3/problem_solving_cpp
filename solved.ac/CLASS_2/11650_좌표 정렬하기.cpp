#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N;
pair<int, int> p[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> p[i].first >> p[i].second;
    
    sort(p, p + N);

    for (int i = 0; i < N; i++)
        cout << p[i].first << " " << p[i].second << "\n";

    return 0;
}
