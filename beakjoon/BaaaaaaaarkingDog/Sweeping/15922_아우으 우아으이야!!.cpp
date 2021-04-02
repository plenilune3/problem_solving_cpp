#include <iostream>

using namespace std;

struct line
{
    int left, right;

    line() : left(0), right(0) {};
    line(int _left, int _right) : left(_left), right(_right) {};
};

const int MAX = 1e5 + 1;

int N;
line L[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> L[i].left >> L[i].right;
    
    int answer = 0;
    int l = -1e9, r = -1e9;

    for (int i = 0; i < N; i++)
    {
        if (L[i].left < r)
            r = max(r, L[i].right);
        else
        {
            answer += r - l;
            l = L[i].left;
            r = L[i].right;
        }
    }
    answer += r - l;
    cout << answer << "\n";

    return 0;
}
