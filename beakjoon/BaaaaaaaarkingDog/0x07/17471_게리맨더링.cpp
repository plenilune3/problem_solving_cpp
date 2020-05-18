#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 12;

int N, answer = INT_MAX;
int ward[MAX];
bool A[MAX][MAX];
bool selected[MAX];
vector<int> a;
vector<int> b;

int differnce(int a, int b)
{
    int result;
    
    if (a > b)
        result = a - b;
    else
        result = b - a;
    
    return result;
}

void combinations(int depth)
{
    if (depth == N + 1)
    {
        int length_a = a.size();
        int length_b = b.size();

        if (length_a == N || length_b == N)
            return;
        
        int sum_a = 0;
        for (int i = 0; i < length_a; i++)
            sum_a += ward[a[i]];
        
        int sum_b = 0;
        for (int i = 0; i < length_b; i++)
            sum_b += ward[b[i]];
        
        if (length_a == 1)
        {
            for (int i = 0; i < length_b; i++)
            {
                bool possible = false;

                for (int j = 0; j < length_b; j++)
                    if (A[b[i]][b[j]])
                        possible = true;
                
                if (possible == false)
                    return;
            }

            answer = min(answer, differnce(sum_a, sum_b));
            return;
        }

        if (length_b == 1)
        {
            for (int i = 0; i < length_a; i++)
            {
                bool possible = false;

                for (int j = 0; j < length_a; j++)
                    if (A[a[i]][a[j]])
                        possible = true;
                
                if (possible == false)
                    return;
            }

            answer = min(answer, differnce(sum_a, sum_b));
        }

        for (int i = 0; i < length_a; i++)
        {
            bool possible = false;

            for (int j = 0; j < length_a; j++)
                if (A[a[i]][a[j]])
                    possible = true;
            
            if (possible == false)
                return;
        }

        for (int i = 0; i < length_b; i++)
        {
            bool possible = false;

            for (int j = 0; j < length_b; j++)
                if (A[b[i]][b[j]])
                    possible = true;
            
            if (possible == false)
                return;
        }

        answer = min(answer, differnce(sum_a, sum_b));
        return;
    }

    selected[depth] = true;
    a.push_back(depth);
    combinations(depth + 1);
    selected[depth] = false;
    a.pop_back();

    b.push_back(depth);
    combinations(depth + 1);
    b.pop_back();
}


int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> ward[i];
    
    for (int i = 1; i <= N; i++)
    {
        int cnt;
        cin >> cnt;

        while (cnt--)
        {
            int j;
            cin >> j;

            A[i][j] = true;
            A[j][i] = true;
        }
    }

    combinations(1);

    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}
