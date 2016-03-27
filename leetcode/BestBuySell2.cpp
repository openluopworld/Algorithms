
/*
 * Problem: Best Time to Buy and Sell Stock II
 * 
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. 
 * You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times).
 * However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */
#include<stdio.h>

/*
 * Find every rising line, buy at the start point and sell at the end point
 */
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
	int buy = 0;
	if ( pricesSize >= 2) {
		for ( int i = 0; i < pricesSize-1; i++ ) {
			if ( prices[i] < prices[i+1]) {
				buy = prices[i++];
				while ( i < pricesSize-1 && prices[i] < prices[i+1]) {
					i++;
				}
				profit += prices[i] - buy;
			}
		}
	}
	return profit;
}

int main () {
	int prices[] = {2, 1, 2, 1, 2, 1, 2};
	printf("%d", maxProfit(prices, 7));
	return 0;
}