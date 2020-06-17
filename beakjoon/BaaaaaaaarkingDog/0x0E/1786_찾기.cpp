#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1000000;

string T, P;
int pi[MAX], length_T, length_P;
vector<int> answer;

void make_pi()
{
    int j = 0;
    for (int i = 1; i < length_P; i++)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        
        if (P[i] == P[j])
            pi[i] = ++j;
    }
}


int main(int argc, char const *argv[])
{
    getline(cin, T);
    getline(cin, P);

    length_P = P.size(), length_T = T.size();

    make_pi();

    for (int i = 0; i < length_P; i++)
        cout << pi[i] << " ";

    // cout << T << "\n";
    // cout << P << "\n";


    return 0;
}
