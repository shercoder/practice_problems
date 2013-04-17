#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef std::pair<string, int> Pair;

struct compare
{
  bool operator() (const Pair& a, const Pair& b) const {
    return a.second > b.second;
  }
};

int main(int argc, char const *argv[])
{
  string line;
  string token;
  std::map<string, int> m;
  while(cin >> token) {
    m[token]++;
  }

  std::vector<Pair> v(m.begin(), m.end());
  std::sort(v.begin(), v.end(), compare());

  std::vector<Pair>::iterator i = v.begin();
  for(; i != v.end(); ++i) {
    cout << i->second << ": " << i->first << endl;
  }
  return 0;
}