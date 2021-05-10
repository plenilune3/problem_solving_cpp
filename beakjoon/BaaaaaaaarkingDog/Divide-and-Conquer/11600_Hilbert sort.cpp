#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
vector< pair<int, string> > answer;

int xy2d(int length, int x, int y);
void rotate_(int length, int *x, int *y, int rx, int ry);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> S;

    int length = S + 1;

    while (N--)
    {
        int x, y; string a; cin >> x >> y >> a;
        answer.push_back(make_pair(xy2d(length, y, s), a));
    }

    sort(answer.begin(), answer.end());

    for (vector< pair<int, string> >::iterator i = answer.begin(); i != answer.end(); i++)
        cout << (*i).first << " " << (*i).second << "\n";

    return 0;
}

int xy2d (int n, int x, int y) {
    int rx, ry, s, d=0;
    for (s=n/2; s>0; s/=2) {
        rx = (x & s) > 0;
        ry = (y & s) > 0;
        d += s * s * ((3 * rx) ^ ry);
        rotate_(n, &x, &y, rx, ry);
    }
    return d;
}

void rotate_(int n, int *x, int *y, int rx, int ry) {
    if (ry == 0) {
        if (rx == 1) {
            *x = n-1 - *x;
            *y = n-1 - *y;
        }

        int t  = *x;
        *x = *y;
        *y = t;
    }
}