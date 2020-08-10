#include <iostream>

using namespace std;

const int MAX = 100;

int C, P;
int h[MAX];

int play(int p)
{
    int result = 0;

    if (p == 1)
    {
        for (int i = 0; i < C; i++)
            result += 1;

        for (int i = 0; i < C - 3; i++)
            if (h[i] == h[i+1] && h[i+1] == h[i+2] && h[i+2] == h[i+3])
                result += 1;
    }

    else if (p == 2)
    {
        for (int i = 0; i < C - 1; i++)
            if (h[i] == h[i+1])
                result += 1;
    }

    else if (p == 3)
    {
        for (int i = 0; i < C - 1; i++)
            if (h[i] == (h[i+1] + 1))
                result += 1;
        
        for (int i = 0; i < C - 2; i++)
            if (h[i] == h[i+1] && (h[i+1] + 1) == h[i+2])
                result += 1;
    }

    else if (p == 4)
    {
        for (int i = 0; i < C - 1; i++)
            if ((h[i] + 1) == h[i+1])
                result += 1;
        
        for (int i = 0; i < C - 2; i++)
            if (h[i] == (h[i+1] + 1) && h[i+1] == h[i+2])
                result += 1;
    }

    else if (p == 5)
    {
        for (int i = 0; i < C - 2; i++)
        {
            if (h[i] == h[i+1] && h[i+1] == h[i+2])
                result += 1;
            if (h[i] == h[i+2] && h[i+1] == (h[i+2] - 1))
                result += 1;
        }
         
        for (int i = 0; i < C - 1; i++)
        {
            if (h[i] == (h[i+1] + 1))
                result += 1;
            if ((h[i] + 1) == h[i+1])
                result += 1;
        }
    }

    else if (p == 6)
    {
        for (int i = 0; i < C - 2; i++)
        {
            if (h[i] == h[i+1] && h[i+1] == h[i+2])
                result += 1;
            if ((h[i] + 1) == h[i+1] && h[i+1] == h[i+2])
                result += 1;
        }

        for (int i = 0; i < C - 1; i++)
        {
            if (h[i] == h[i+1])
                result += 1;
            if (h[i] == (h[i+1] + 2))
                result += 1;
        }
    }

    else
    {
        for (int i = 0; i < C - 2; i++)
        {
            if (h[i] == h[i+1] && h[i+1] == h[i+2])
                result += 1;
            if (h[i] == h[i+1] && h[i+1] == (h[i+2] + 1))
                result += 1;
        }

        for (int i = 0; i < C - 1; i++)
        {
            if (h[i] == h[i+1])
                result += 1;
            if ((h[i] + 2) == h[i+1])
                result += 1;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> C >> P;

    for (int i = 0; i < C; i++)
        cin >> h[i];
    
    cout << play(P) << "\n";

    return 0;
}
