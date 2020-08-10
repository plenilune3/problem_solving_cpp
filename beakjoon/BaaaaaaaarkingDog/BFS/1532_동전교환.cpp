#include <iostream>

using namespace std;

struct coin
{
    int G, S, B;
};

int ExchangeCoin(coin now, coin target);
bool CanBuyNoteBook(coin &now, coin &target);
int ExchangeSilverToGold(coin &now, coin &target);
int ExchangeBronzeToSilver(coin &now, coin &target);
int ExchangeSilverToBronze(coin &now, coin &target);
int ExchangeGoldToSilver(coin &now, coin &target);

int main(void)
{
    coin init, target;

    cin >> init.G >> init.S >> init.B;
    cin >> target.G >> target.S >> target.B;

    cout << ExchangeCoin(init, target) << "\n";
}

int ExchangeCoin(coin now, coin target)
{
    int cnt = 0;

    cnt += ExchangeBronzeToSilver(now, target);
    cnt += ExchangeSilverToGold(now, target);

    if (CanBuyNoteBook(now, target))
        return cnt;
    
    cnt += ExchangeSilverToBronze(now, target);
    cnt += ExchangeGoldToSilver(now, target);

    if (!CanBuyNoteBook(now, target))
        return -1;
    else
        return cnt;
}

bool CanBuyNoteBook(coin &now, coin &target)
{
    return now.G >= target.G && now.S >= target.S && now.B >= target.B;
}

int ExchangeBronzeToSilver(coin &now, coin &target)
{
    int cnt = 0;
    
    if (now.S < target.S)
    {
        int requiredCoin = target.S - now.S;

        if (target.B / 11 >= requiredCoin)
        {
            now.S += requiredCoin;
            target.B -= (requiredCoin * 11);
            return requiredCoin;
        }
    }

    while (now.S < target.S)
    {

    }

    return 0;
}

int ExchangeSilverToGold(coin &now, coin &target)
{
    if (now.G < target.G)
    {
        int requiredCoin = target.G - now.G;

        if (target.S / 11 >= requiredCoin)
        {
            now.G += requiredCoin;
            target.S -= (requiredCoin * 11);
            return requiredCoin;
        }
    }

    return 0;
}

int ExchangeSilverToBronze(coin &now, coin &target)
{
    if (now.B < target.B)
    {
        int requiredCoin = target.B - now.B;
        int exchangableCoin = now.S - target.S;

        if (exchangableCoin * 9 >= requiredCoin)
        {
            int exchangedCoin = requiredCoin / 9;

            if (requiredCoin % 9 != 0)
                exchangedCoin += 1;
            
            now.B += exchangedCoin * 9;
            now.S -= exchangedCoin;
            return exchangedCoin;
        }
    }

    return 0;
}

int ExchangeGoldToSilver(coin &now, coin &target)
{
    if (now.S < target.S)
    {
        int requiredCoin = target.S - now.S;
        int exchangableCoin = now.G - target.G;

        if (exchangableCoin * 9 >= requiredCoin)
        {
            int exchangedCoin = requiredCoin / 9;

            if (requiredCoin % 9 != 0)
                exchangedCoin += 1;
            
            now.S += exchangedCoin * 9;
            now.G -= exchangedCoin;
            return exchangedCoin;
        }
    }

    return 0;
}