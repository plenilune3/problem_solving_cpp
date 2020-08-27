#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000;

int N, M, T;
int A[MAX], B[MAX];

vector<int> make_prefix_sum(int N, int arr[MAX]);
long long find_answer(vector<int> &v1, vector<int> &v2);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cin >> M;

    for (int i = 0; i < M; i++)
        cin >> B[i];
    
    vector<int> v1 = make_prefix_sum(N, A);
    vector<int> v2 = make_prefix_sum(M, B);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long answer = find_answer(v1, v2);

    cout << answer << "\n";

    return 0;
}

long long find_answer(vector<int> &v1, vector<int> &v2)
{
    long long answer = 0;
    vector<int>::iterator left, right;
    left = v1.begin(), right = v2.end() - 1;

    while (true)
    {
        if (left >= v1.end() || right < v2.begin())
            break;
        
        int left_value = (*left), right_value = (*right);

        if (left_value + right_value == T)
        {
            long long left_cnt = 0, right_cnt = 0;

            while (left < v1.end() && (*left) == left_value)
                left_cnt += 1, left++;
            
            while (right >= v2.begin() && (*right) == right_value)
                right_cnt += 1, right--;
            
            answer += left_cnt * right_cnt;
        }

        else if (left_value + right_value < T) left++;

        else right--;
    }

    return answer;
}

vector<int> make_prefix_sum(int length, int arr[MAX])
{
    int P[length + 1] = { 0 };
    vector<int> v;

    for (int i = 1; i <= length; i++)
        P[i] = P[i - 1] + arr[i - 1];
    
    for (int i = 0; i < length; i++)
        for (int j = i; j < length; j++)
            v.push_back(P[j + 1] - P[i]);
    
    return v;
}
