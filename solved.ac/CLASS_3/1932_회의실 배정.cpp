#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

struct meeting
{
    int left, right;

    bool operator< (const meeting &m) const
    {
        if (right != m.right) return right < m.right;
        else return left < m.left;
    }
};

int N;
meeting m[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> m[i].left >> m[i].right;
    
    sort(&m[0], &m[0] + N);

    int answer = 0;

    int min_right = m[0].right;
    answer += 1;

    for (int i = 1; i < N; i++)
        if (m[i].left >= min_right)
        {
            min_right = m[i].right;
            answer += 1;
        }
    
    cout << answer << "\n";

    return 0;
}
