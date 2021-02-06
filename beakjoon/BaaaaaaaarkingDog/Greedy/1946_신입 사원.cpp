#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N;
pair<int, int> A[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> A[i].first >> A[i].second;
        
        sort(&A[0], &A[0] + N);
       
        int answer = 1;
        int standard = A[0].second;

        for (int i = 1; i < N; i++)
        {
            if (A[i].second < standard)
            {
                answer += 1;
                standard = A[i].second;
            }
        }
        
        cout << answer << "\n";
    }

    return 0;
}
