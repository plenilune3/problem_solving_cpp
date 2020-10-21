#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int a = min(abs(x - w), abs(y - h));
    int b = min(abs(x - 0), abs(y - 0));
    int answer = min(a, b);

    cout << answer << "\n";

    return 0;
}
