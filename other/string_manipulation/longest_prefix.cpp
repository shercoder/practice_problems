#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int n = 0;
  cin >> n;

  string word;
  map<string, int> holder;
  while(cin >> word) {
    for(int i = 0; i < word.length(); ++i) {
      holder[word.substr(0, i+1)]++;
      cout << word.substr(0, i+1) << endl;
    }
  }

  map<string, int>::iterator it = holder.begin();
  string prefix = it->first;
  int counter = it->second;
  it++;
  for(; it != holder.end(); ++it) {
    //cout << it->first << " => " << it->second << endl;
    if(it->second == counter && it->first.length() > prefix.length()) {
      prefix = it->first;
      counter = it->second;
    } else if(it->second > counter) {
      prefix = it->first;
      counter = it->second;
    }
  }

  cout << prefix << " -> " << counter << endl;
  return 0;
}
