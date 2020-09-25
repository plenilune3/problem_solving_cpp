#include <iostream>
#include <climits>

using namespace std;

const int MAX = 1e6 + 1;

int N;
int pre_min[3], pre_max[3], cur_min[3], cur_max[3];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int min_num = INT_MAX, max_num = 0;
    int score[3];

    for (int i = 0; i < 3; i++)
    {
        cin >> score[i];
        cur_min[i] = cur_max[i] = score[i];
    }

    for (int i = 1; i < N; i++)
    {
        int score[3];

        for (int j = 0; j < 3; j++)
            cin >> score[j];
        
        for (int k = 0; k < 3; k++)
        {
            pre_min[k] = cur_min[k];
            pre_max[k] = cur_max[k];
            cur_min[k] = INT_MAX;
            cur_max[k] = 0;
        }

        for (int j = 0; j < 3; j++)
        {
            cur_min[j] = min(cur_min[j], pre_min[j] + score[j]);
            if (j - 1 >= 0) cur_min[j] = min(cur_min[j], pre_min[j - 1] + score[j]);
            if (j + 1 <= 2) cur_min[j] = min(cur_min[j], pre_min[j + 1] + score[j]);

            cur_max[j] = max(cur_max[j], pre_max[j] + score[j]);
            if (j - 1 >= 0) cur_max[j] = max(cur_max[j], pre_max[j - 1] + score[j]);
            if (j + 1 <= 2) cur_max[j] = max(cur_max[j], pre_max[j + 1] + score[j]);
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        max_num = max(max_num, cur_max[i]);
        min_num = min(min_num, cur_min[i]);
    }

    cout << max_num << " " << min_num << "\n"; 

    return 0;
}
