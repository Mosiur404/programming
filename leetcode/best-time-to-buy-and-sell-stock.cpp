#include <iostream>
#include <algorithm>
#include <vector>
#define log(x) std::cout << x << std ::endl;
using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int minValue = INT_MAX;
    int profit = 0;
    int profitToday = 0;
    for (int i = 0; i < prices.size(); i++) {
      if (prices[i] < minValue) minValue = prices[i];
      profitToday = prices[i] - minValue;
      if (profit < profitToday) profit = profitToday;
    }
    return profit;
  }
};

int main(int argc, char const *argv[]) {
  vector<int> prices = {2, 4, 1};
  int result = Solution().maxProfit(prices);
  cout << "Result: " << result << endl;
  return 0;
}
