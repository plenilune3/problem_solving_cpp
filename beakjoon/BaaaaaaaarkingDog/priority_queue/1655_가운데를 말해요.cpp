#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int left = 0, right = 0;

    while (N--)
    {
        int num; cin >> num;

        if (left == right) 
            max_heap.push(num), left += 1;
        else 
            min_heap.push(num), right += 1;

        while (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
        {
            int a = max_heap.top(); max_heap.pop();
            int b = min_heap.top(); min_heap.pop();
            min_heap.push(a);
            max_heap.push(b);
        }

        cout << max_heap.top() << "\n";
    }

    return 0;
}
