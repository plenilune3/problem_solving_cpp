#include <iostream>

using namespace std;

const int MAX = 501;

int H, W;
int height[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> H >> W;

    for (int i = 0; i < W; i++)
        cin >> height[i];
    
    int answer = 0;
    
    for (int i = 1; i < W - 1; i++)
    {
        int max_left_height = 0, max_right_height = 0;

        for (int j = 0; j < i; j++)
            max_left_height = max(max_left_height, height[j]);
        
        for (int j = i + 1; j < W; j++)
            max_right_height = max(max_right_height, height[j]);
        
        int max_height = min(max_left_height, max_right_height);

        if (height[i] <= max_height)
            answer += max_height - height[i];
    }

    cout << answer << "\n";

    return 0;
}
