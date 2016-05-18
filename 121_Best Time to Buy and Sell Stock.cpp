Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.



int maxProfit(int* prices, int pricesSize) {
    int low=prices[0];
    int ans=0;
    for(int i=1;i<pricesSize;i++)
    {
        if(prices[i]<low)
        {
            low=prices[i];
        }
        else if(prices[i]-low>ans)
        {
            ans=prices[i]-low;
        }
    }
    return ans;
}