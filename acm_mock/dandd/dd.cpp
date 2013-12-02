/*
Pardeep Singh and Oriah Oulrich
Time: 4:57PM
*/
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main() {
//  map<int, int> contenders;

  int N = 0;
  cin >> N;

  int grades[N];
  for (int i = 0; i < N; ++i) cin >> grades[i];

  int comps[N];
  for (int i = 0; i < N; ++i) comps[i] = 0;

  int index = 0;
  for (int i = 1; i < N; ++i) {
    comps[index] += 1;
    if (grades[index] > grades[i]) {
      index = i;
    }
  } 
  
  index = 0;
  for (int i = 1; i < N; ++i) {
    if (comps[index] < comps[i]) index = i;   
  }
  cout << index+1 << endl;

/*  int c = 0;
  cin >> c;
  contenders[1] = 0;

  int next = 0;
  int index = 1;
  for (int i = 1; i < N; ++i) {
    cin >> next;
    cout << next << endl;
    if (c <= next) contenders[i]++;
    else {
      contenders[i]++;
      c = next;
    }
  }

  map<int, int>::iterator it = contenders.begin();
  c = it->first;
  int c_val = it->second;
  it++;
  for(; it != contenders.end(); ++it) { 
    if (it->second > c_val) {
      c_val = it->second;
      c = it->first;
    }
  }
  cout << c << endl;
  */
  return 0;
}
