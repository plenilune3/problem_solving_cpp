#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> q;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        q.push(i);
    
    for (int i = 0; i < N - 1; i++)
    {
       q.pop();
       int t = q.front();
       q.pop();
       q.push(t);
    }

    cout << q.front() << "\n";

    return 0;
}

// #include <stdio.h>

// int findStartPoint(int n) {
//     int result = 1;
//     while(result < n)
//         result *= 2;
    
//     return result/2;
// }

// int main(){
    
//     int N;
    
//     scanf("%d", &N);
    
//     if(N == 1) {
//         printf("1\n");
//     } else {
//         int start = findStartPoint(N);
//         printf("%d\n", (N - start) * 2);
//     }

// }
