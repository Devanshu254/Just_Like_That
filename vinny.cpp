#include <bits/stdc++.h>
using namespace std;

long long calculateProfit(long long type, vector<long long> &availableQuant, vector<long long> &neededQuant, vector<long long> &priceOfQuant, vector<long long> &spOfToy, long long remainingAmount, vector<vector<long long>> &memo)
{
    if (type < 0 || remainingAmount <= 0)
    {
        return 0;
    }

    if (memo[type][remainingAmount] != -1)
    {
        return memo[type][remainingAmount];
    }

    long long notTake = calculateProfit(type - 1, availableQuant, neededQuant, priceOfQuant, spOfToy, remainingAmount, memo);

    long long take = 0;
    if (availableQuant[type] >= neededQuant[type])
    {
        long long maxPossibleTake = availableQuant[type] / neededQuant[type];
        for (long long k = 0; k <= maxPossibleTake; ++k)
        {
            if (remainingAmount >= (k * neededQuant[type] * priceOfQuant[type]))
            {
                availableQuant[type] -= k * neededQuant[type];
                remainingAmount -= k * neededQuant[type] * priceOfQuant[type];
                take = max(take, k * spOfToy[type] + calculateProfit(type - 1, availableQuant, neededQuant, priceOfQuant, spOfToy, remainingAmount, memo));
                // Revert the changes after the recursive call
                availableQuant[type] += k * neededQuant[type];
                remainingAmount += k * neededQuant[type] * priceOfQuant[type];
            }
        }
    }

    memo[type][remainingAmount] = max(take, notTake);
    return memo[type][remainingAmount];
}

int main()
{
    long long totalAmount, toyTypes;
    cin >> totalAmount >> toyTypes;

    vector<long long> availableQuant(toyTypes);
    vector<long long> neededQuant(toyTypes);
    vector<long long> priceOfQuant(toyTypes);
    vector<long long> spOfToy(toyTypes);

    for (long long i = 0; i < toyTypes; i++)
    {
        cin >> availableQuant[i];
    }
    for (long long i = 0; i < toyTypes; i++)
    {
        cin >> neededQuant[i];
    }
    for (long long i = 0; i < toyTypes; i++)
    {
        cin >> priceOfQuant[i];
    }
    for (long long i = 0; i < toyTypes; i++)
    {
        cin >> spOfToy[i];
    }

    vector<vector<long long>> memo(toyTypes, vector<long long>(totalAmount + 1, -1));

    cout << calculateProfit(toyTypes - 1, availableQuant, neededQuant, priceOfQuant, spOfToy, totalAmount, memo);

    return 0;
}
