#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1e4 + 1;

int N, M;
vector<int> A, B;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x; cin >> x;

        if (x < 0) A.push_back(x);
        else if (x > 0) B.push_back(x);
    }

    sort(A.begin(), A.end(), less<int>());
    sort(B.begin(), B.end(), greater<int>());

    long long answer = 0;
    int length_A = (int) A.size();
    int length_B = (int) B.size();

    for (int i = 0; i < length_A; i++)
        if (i % M == 0)
            answer += abs(A[i]) * 2;
            
    for (int i = 0; i < length_B; i++)
        if (i % M == 0)
            answer += abs(B[i]) * 2;
    
    if (length_A != 0 && length_B != 0)
        answer -= max(abs(A[0]), abs(B[0]));
    else if (length_A != 0)
        answer -= abs(A[0]);
    else if (length_B != 0)
        answer -= abs(B[0]);
    
    cout << answer << "\n";
            
    return 0;
}
