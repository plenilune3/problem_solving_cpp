#include <iostream>
#include <deque>

using namespace std;

const int MAX = 5e6 + 1;

int N, L;
int A[MAX], answer[MAX];

void find_(int A[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    find_(A);

    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}

void find_(int A[MAX])
{
    deque< pair<int, int> > window;

    for (int i = 0; i < N; i++)
    {
        while (!window.empty() && window.front().first <= i - L)
            window.pop_front();
        
        while (!window.empty() && window.back().second > A[i])
            window.pop_back();
        
        window.push_back(make_pair(i, A[i]));
        answer[i] = window.front().second;
    }
}

