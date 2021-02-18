#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int idx = 0;
    
    while (true)
    {
        int answer = 0;
        int L, P, V; cin >> L >> P >> V;

        if (L == 0 && P == 0 && V == 0) break;

        int q = V / P, r = V % P;
        
        answer += L * q + min(L, r);

        cout << "Case " << ++idx << ": " << answer << "\n";
    }

    return 0;
}
