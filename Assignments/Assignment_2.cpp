#include<iostream>
using namespace std;

long int myProfit (int prices[], int noOfDays)
{
    int maxVal = 0, minVal = 105, profit=0;

    if (noOfDays == 1)
        return 0; //No profit in buying and selling on same day as has same price
    /*
    Time Complexity = O(n^2)
    Space Complexity = O(n)



    for (int i=0; i<noOfDays; i++)
    {
        for (int j=i+1; j<noOfDays; j++)
        {
            profit = prices[j] - prices[i];
            if (profit > maxVal)
                maxVal = profit;
        }
    }
    */

    /*
    Time Complexity = O(n)
    Space Complexity = O(n)

    */
    for (int i=0; i<noOfDays; i++)
    {
        if(prices[i] < minVal)
        {
            minVal = prices[i];
            maxVal = 0;
        }

        if(prices[i] > maxVal)
        {
            maxVal = prices[i];
        }
    }

    if (maxVal == 0)
        return maxVal;
    else
        return maxVal-minVal;


    return maxVal;
}

int main()
{
    int noOfDays, prices[111];;
    scanf("%d", &noOfDays);

    for (int i=0; i<noOfDays; i++)
        cin >> prices[i];


    printf("%d", myProfit(prices, noOfDays));

    return 0;
}




