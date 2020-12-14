#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 1e5 + 1;

int N;
double F[MAX];

long long count_();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> F[i];
    
    sort(&F[0], &F[0] + N);
    
    cout << count_() << "\n";
    
    return 0;
}

long long count_()
{
    long long result = 0;
    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        double temp = F[i] * 0.9;

        while (!q.empty() && q.front() < temp)
            q.pop();
        
        result += (long long) q.size();
        q.push(F[i]);
    }

    return result;
}

