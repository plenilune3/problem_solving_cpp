#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int M = 1e5;
const int N = 1e5;

int m, n, l, answer;
int hunter[M];
pair<int, int> animal[N];

bool hunting_animal(pair<int, int> a);
int get_distance(pair<int, int> a, int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> m >> n >> l;

    for (int i = 0; i < m; i++)
        cin >> hunter[i];
    
    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        animal[i] = make_pair(x, y);
    }

    sort(&hunter[0], &hunter[0] + m);
    
    for (int i = 0; i < n; i++)
    {
        if (animal[i].second > l)
            continue;

        answer += hunting_animal(animal[i]);
    }
    
    cout << answer << "\n";

    return 0;
}

int get_distance(pair<int, int> a, int x)
{
    return a.first > x ? (a.first - x) + a.second : (x - a.first) + a.second;
}

bool hunting_animal(pair<int, int> a)
{
    int left = 0, right = m - 1;
    int lower = a.first + a.second - l, upper = a.first - a.second + l; 

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (hunter[mid] >= lower && hunter[mid] <= upper)
            return true;
        
        if (hunter[mid] <= lower)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}
