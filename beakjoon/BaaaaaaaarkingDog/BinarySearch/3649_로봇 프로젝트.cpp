#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e6 + 1;

int N;
int hole;
int lego[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while (cin >> hole)
    {
        hole *= 1e7;
        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> lego[i];
        
        sort(&lego[0], &lego[0] + N);

        int left = 0, right = N - 1;
        bool possible = false;

        while (left < right)
        {
            int sum_lego = lego[left] + lego[right];

            if (sum_lego == hole)
            {
                possible = true;
                break;
            }
            else if (sum_lego < hole)
                left += 1;
            else
                right -= 1;
        }

        if (possible)
            cout << "yes " << lego[left] << " " << lego[right] << "\n";
        else
            cout << "danger" << "\n";
    }

    return 0;
}
