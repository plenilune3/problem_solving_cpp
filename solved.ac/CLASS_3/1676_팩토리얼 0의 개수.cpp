#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int N; cin >> N;

    int A = 0, B = 0;

    for (int i = 2; i <= N; i *= 2)
        A += N / i;
    
    for (int i = 5; i <= N; i *= 5)
        B += N / i;
    
    cout << min(A, B) << "\n";

    return 0;
}
