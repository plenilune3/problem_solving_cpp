#include <cstdio>
#include <cstring>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++)
    {
        char str[1000003];
        scanf("%s", str);
        int length = strlen(str);

        list<char> password;
        list<char>::iterator cursor = password.end();

        for (int i = 0; i < length; i++)
        {
            if (str[i] == '<')
            {
                if (cursor != password.begin())
                    cursor--;
            }
            else if (str[i] == '>')
            {
                if (cursor != password.end())
                    cursor++;
            }
            else if (str[i] == '-')
            {
                if (cursor != password.begin())
                {
                    cursor--;
                    cursor = password.erase(cursor);
                }
            }
            else
                password.insert(cursor, str[i]);
        }

        for(cursor = password.begin(); cursor != password.end(); cursor++)
            printf("%c", *cursor);
        printf("\n");
    }

    return 0;
}
