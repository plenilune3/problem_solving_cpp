#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    char word[110];
    char alphabets[26] = {0};

    fgets(word, 110, stdin);

    for (int i = 0; word[i] != '\n' ; i++)
        alphabets[word[i] - 'a'] += 1;

    for (int i = 0; i < 26; i++)
        printf("%d ", alphabets[i]);

    return 0;
}
