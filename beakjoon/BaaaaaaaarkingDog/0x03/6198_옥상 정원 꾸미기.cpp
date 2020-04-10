#include <iostream>
#include <stack>

using namespace std;


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    stack<long long> s;
    long long answer = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long height;
        cin >> height;

        while (!s.empty() && s.top() <= height)
            s.pop();

        answer += (long long) s.size();
        s.push(height);
    }

    cout << answer;

    return 0;
}
