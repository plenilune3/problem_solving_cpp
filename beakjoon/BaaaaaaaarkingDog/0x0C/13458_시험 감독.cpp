#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, B, C;
    scanf("%d", &N);

    int* arr = new int[N]();

    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &B, &C);

    for (int i = 0; i < N; i++)
        if (arr[i] - B >= 0)
            arr[i] = arr[i] - B;
        else
            arr[i] = 0;
    
    long long answer = N;
    for (int i = 0; i < N; i++)
        answer += ceil((double)arr[i] / (double)C);

    printf("%lld\n", answer);
    return 0;
}
