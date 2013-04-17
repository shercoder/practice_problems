#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class YahtzeeScore {
public:
  int maxPoints(vector<int> toss) {
    int total[7] = {0};
    for(int i = 0; i < 5; ++i) {
      total[toss[i]] += toss[i];
    }
    int max = *std::max_element(total, total+7);
    return max;
  }
};