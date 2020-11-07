#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct number
{
    int a, b;

    bool operator< (const number &n) const
    {
        if (b != n.b) return b > n.b;
        else return a > n.a;
    }
};

number make_number(int a, int b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    priority_queue<number> pq;

    cin >> N;

    while (N--)
    {
        int num; cin >> num;

        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top().a << "\n";
                pq.pop();
            }
            else
                cout << 0 << "\n";
        }
        else
            pq.push(make_number(num, abs(num)));
    }

    return 0;
}

number make_number(int a, int b)
{
    number n = { a, b };
    return n;
}
