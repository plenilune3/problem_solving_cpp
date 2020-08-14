// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

struct count_nucleotide
{
    int count[4];
};


int main(int argc, char const *argv[])
{
    return 0;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> answer;
    int N = S.size();
    int M = P.size();
    
    count_nucleotide cn[N + 1];
    
    for (int i = 0; i < 4; i++)
        cn[0].count[i] = 0;
    
    for (int i = 1; i <= N; i++)
    {
        cn[i].count[0] = S[i - 1] == 'A' ? cn[i - 1].count[0] + 1 : cn[i - 1].count[0];
        cn[i].count[1] = S[i - 1] == 'C' ? cn[i - 1].count[1] + 1 : cn[i - 1].count[1];
        cn[i].count[2] = S[i - 1] == 'G' ? cn[i - 1].count[2] + 1 : cn[i - 1].count[2];
        cn[i].count[3] = S[i - 1] == 'T' ? cn[i - 1].count[3] + 1 : cn[i - 1].count[3];
    }
    
    for (int i = 0; i < M; i++)
    {
        int impact_factor = 0;
        
        for (int j = 0; j < 4; j++)
        {
            int count = cn[Q[i] + 1].count[j] - cn[P[i]].count[j];
            
            if (count != 0)
            {
                impact_factor = (j + 1);
                break;
            }
        }
        
        answer.push_back(impact_factor);
    }
    
    return answer;
}