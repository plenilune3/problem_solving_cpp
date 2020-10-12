#include <iostream>

using namespace std;

int K, answer;
bool gear[4][8];

void rotate(bool gear[8], int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < 4; i++)
    {
        string g; cin >> g;

        for (int j = 0; j < 8; j++)
            gear[i][j] = g[j] - '0';
    }

    cin >> K;

    while (K--)
    {
        int num, dir; cin >> num >> dir;

        int gear_dir[4];
        fill_n(&gear_dir[0], 4, 0);

        num -= 1;
        gear_dir[num] = dir;

        for (int i = num + 1; i < 4; i++)
            if (gear[i - 1][2] != gear[i][6])
                gear_dir[i] = -gear_dir[i - 1];
        
        for (int i = num - 1; i >= 0; i--)
            if (gear[i + 1][6] != gear[i][2])
                gear_dir[i] = -gear_dir[i + 1];
       
        for (int i = 0; i < 4; i++)
            if (gear_dir[i])
                rotate(gear[i], gear_dir[i]);
    }

    for (int i = 0; i < 4; i++)
        if (gear[i][0])
            answer += (1 << i);
    
    cout << answer << "\n";
        
    return 0;
}

void rotate(bool gear[8], int d)
{
    bool gear_c[8];

    for (int i = 0; i < 8; i++)
        if (d == 1) gear_c[(i + 1) % 8] = gear[i];
        else gear_c[i] = gear[(i + 1) % 8];
    
    copy(&gear_c[0], &gear_c[0] + 8, &gear[0]);
}
