#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        min_heap.push(num);
    }

    int answer = 0;

    while (--N)
    {
        int a = min_heap.top(); min_heap.pop();
        int b = min_heap.top(); min_heap.pop();

        answer += a + b;
        min_heap.push(a + b);
    }

    cout << answer << "\n";

    return 0;
}
