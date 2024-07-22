"""
121: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

description: 
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
"""

def best_time_to_buy_and_sell_stock(prices):
    """
    T.C: O(n)
    S.C: O(1)
    """
    
    # 2 ptr solution
    left, right = 0, 1  # left = buy, right = sell
    
    # result variables
    max_profit = 0
    max_profit_left = None
    max_profit_right = None
    
    while(right < len(prices)):
        # profitable ?
        if (prices[left] < prices[right]):
            profit = prices[right] - prices[left]
            
            # check if the profit is greater and update max_profit
            if profit > max_profit:
                max_profit = max(max_profit, profit)
                max_profit_left = left
                max_profit_right = right
        else:
            left = right
        
        # regardless of profitable increment right pointer
        right += 1
    
    return max_profit, max_profit_left, max_profit_right


if __name__ == "__main__":
    # input
    prices = [7, 1, 5, 3, 6, 4]
    max_profit, max_profit_left, max_profit_right = best_time_to_buy_and_sell_stock(prices)
    print(f'max profit: {max_profit}')
    print(f'buy at: {max_profit_left}')
    print(f'sell at: {max_profit_right}')
    