#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[3];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 0; i < 3; i++)
        cin >> dp[i];
    
    N -= 1;

    while (N--)
    {
        int RGB[3];

        for (int i = 0; i < 3; i++)
            cin >> RGB[i];
        
        for (int i = 0; i < 3; i++)
            RGB[i] = min(RGB[i] + dp[(i + 1) % 3], RGB[i] + dp[(i + 2) % 3]);
        
        copy(&RGB[0], &RGB[0] + 3, &dp[0]);
    }

    cout << *min_element(&dp[0], &dp[0] + 3) << "\n";

    return 0;
}
