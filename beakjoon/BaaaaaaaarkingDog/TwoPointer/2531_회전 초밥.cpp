#include <iostream>

using namespace std;

const int MAX_N = 30001;
const int MAX_D = 3001;

int N, D, K, C;
int sushi[MAX_N];
int count_sushi[MAX_D];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cin.tie(NULL);

    cin >> N >> D >> K >> C;

    for (int i = 0; i < N; i++)
        cin >> sushi[i];
    
    int cnt = 0;

    for (int i = 0; i < K; i++)
    {
        if (count_sushi[sushi[i]] == 0)
            cnt += 1;
        count_sushi[sushi[i]] += 1;
    }

    int max_cnt = cnt;

    for (int left = 0; left < N; left++)
    {
        int right = (left + K) % N;

        count_sushi[sushi[left]] -= 1;

        if (count_sushi[sushi[left]] == 0)
            cnt -= 1;
        
        if (count_sushi[sushi[right]] == 0)
            cnt += 1;

        count_sushi[sushi[(right)]] += 1;

        if (count_sushi[C] == 0)
            max_cnt = max(max_cnt, cnt + 1);
        else 
            max_cnt = max(max_cnt, cnt);
   }

    cout << max_cnt << "\n";

    return 0;
}
