#include <iostream>
#include <string>

using namespace std;

int answer, N;
string format;

void make_license_plate(int depth, char last);

int main(int argc, char const *argv[])
{

    cin >> format;

    N = format.size();

    make_license_plate(0, 0);

    cout << answer << "\n";

    return 0;
}

void make_license_plate(int depth, char last)
{
    if (depth == N)
    {
        answer += 1;
        return;
    }

    if (format[depth] == 'c')
    {
        for (char c = 'a'; c <= 'z'; c++)
            if (c != last)
                make_license_plate(depth + 1, c);
    }
    else
    {
        for (char c = '0'; c <= '9'; c++)
            if (c != last)
                make_license_plate(depth + 1, c);
    }
}
