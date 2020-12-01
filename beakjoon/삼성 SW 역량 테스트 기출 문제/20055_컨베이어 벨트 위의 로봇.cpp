#include <iostream>

using namespace std;

const int MAX = 201;

int N, K, A[MAX], counter;
bool R[MAX];

void rotate_();
void move_();
void put_();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < 2 * N; i++)
        cin >> A[i];
    
    int answer = 0;

    while (true)
    {
        answer += 1;

        rotate_();
        move_();
        put_();

        if (counter >= K)
            break;
    }

    cout << answer << "\n";
    
    return 0;
}

void rotate_()
{
    int A_temp = A[2 * N - 1];

    for (int i = 2 * N - 1; i >= 1; i--)
    {
        A[i] = A[i - 1];
        R[i] = R[i - 1];
    }

    R[N - 1] = false;
    R[0] = false;
    A[0] = A_temp;
}

void move_()
{
    for (int i = N - 2; i >= 0; i--)
    {
        if (R[i] == false || R[i + 1] || A[i + 1] == 0)
            continue;
        
        A[i + 1] -= 1;

        if (A[i + 1] == 0)
            counter += 1;

        R[i] = false, R[i + 1] = true;

        if (i + 1 == N - 1)
            R[i + 1] = false;
    }
}

void put_()
{
    if (A[0] == 0 || R[0])
        return;
    
    R[0] = true, A[0] -= 1;

    if (A[0] == 0)
        counter += 1;
}