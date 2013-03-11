#include <iostream>
#include <functional>
#include <algorithm>
// #include <queue>

using namespace std;

int main() {
  int N = 0;
  cin >> N;
  cin.get();

  int topfour[4] = {0,0,0,0};

  int next = 0;
  int size = 0;
  for(int i = 0; i < N; ++i) {
    cin >> next;
    if(size < 4){
      topfour[size] = next;
      ++size;
      sort(topfour, topfour+size, greater<int>());
    } else {
      if(topfour[3] < next) {
        topfour[3] = next;
        sort(topfour, topfour+4, greater<int>());
      }
    }
  }

  for(int i = 0; i < 4; ++i) {
    cout << topfour[i] << endl;
  }

  return 0;
}


  // priority_queue<int, vector<int>, greater<int> > topfour;

  // int next = 0;
  // int size = 0;
  // for(int i = 0; i < N; ++i) {
  //   cin >> next;
  //   if(size < 4){
  //     topfour.push(next);
  //     ++size;
  //   } else {
  //     if(topfour.top() < next) {
  //       topfour.pop();
  //       topfour.push(next);
  //     }
  //   }
  // }

  // while(!topfour.empty()) {
  //   cout << topfour.top() << endl;
  //   topfour.pop();
  // }
