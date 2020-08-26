#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int MAX = 4000001;

vector<int> find_primes(int n);

int main(int argc, char const *argv[])
{
    int N, answer = 0;
    cin >> N;

    vector<int> primes = find_primes(N);

    vector<int>::iterator left, right;
    left = right = primes.begin();
    int sum = 0;

    while (true)
    {
        if (sum >= N)
            sum -= (*left++);
        else if (right == primes.end())
            break;
        else
            sum += (*right++);

        if (sum == N)
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}

vector<int> find_primes(int num)
{
    vector<int> primes;
    bool is_prime[num + 1];
    fill_n(&is_prime[0], num + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < sqrt(num) + 1; i++)
    {
        if (is_prime[i] == false)
            continue;
        
        for (int j = i + i; j <= num; j += i)
            is_prime[j] = false;
    }

    for (int i = 0; i <= num; i++)
        if (is_prime[i])
            primes.push_back(i);
    
    return primes;
}

