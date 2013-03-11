#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

template<typename A, typename B>
pair<B,A> flip_pair(const pair<A,B> &p)
{
    return pair<B,A>(p.second, p.first);
}

template<typename A, typename B>
map<B,A> flip_map(const map<A,B> &src)
{
    map<B,A> dst;
    std::transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<A,B>);
    return dst;
}

int main() {
  int N = 0;
  cin >> N;
  cin.get();

  string term;
  map<string, int> terms;
  for(int i = 0; i < N; ++i) {
    cin >> term;
    terms[term]++;
  }

  map<string, int>::iterator itr = terms.begin();
  for(; itr != terms.end(); ++itr) {
    cout << itr->first << " => " << itr->second << endl;
  }
  cout << "=========================================" << endl;

  int frequent = 0;
  int f_counter = 0;
  cin >> frequent;

  map<int, string> values = flip_map(terms);
  map<int, string>::reverse_iterator it = values.rbegin();
  for(; it != values.rend(); ++it) {
    if (f_counter < frequent) {
      cout << it->second << endl;
      ++f_counter;
    }
  }
  return 0;
}