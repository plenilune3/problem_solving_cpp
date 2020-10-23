#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

struct point
{
    int x, y;

    bool operator< (const point &p) const
    {
        if (y != p.y) return y < p.y;
        else return x < p.x;
    }
};

int N;
point p[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> p[i].x >> p[i].y;
    
    sort(p, p + N);

    for (int i = 0; i < N; i++)
        cout << p[i].x << " " << p[i].y << "\n";

    return 0;
}
