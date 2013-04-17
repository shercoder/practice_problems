#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

map<string, int> terms;

bool comp(const string& lhs, const string& rhs)
{
  return terms[lhs] > terms[rhs];
}


int main() {
  int N = 0;
  cin >> N;
  cin.get();

  string term;
  vector<string> just_strings;
  
  for(int i = 0; i < N; ++i) {
    cin >> term;
    if(!terms[term]++) {
      just_strings.push_back(term);
    }
  }

  stable_sort(just_strings.begin(), just_strings.end());
  stable_sort(just_strings.begin(), just_strings.end(), comp);


  int frequent = 0;
  cin >> frequent;

  //vector<string>::iterator it = just_strings.begin();

  for(int i = 0; i < frequent; ++i) {
    cout << just_strings[i] << endl;
  }

  
  return 0;
}

// template<typename A, typename B>
// pair<B,A> flip_pair(const pair<A,B> &p)
// {
//     return pair<B,A>(p.second, p.first);
// }

// template<typename A, typename B>
// map<B,A> flip_map(const map<A,B> &src)
// {
//     map<B,A> dst;
//     std::transform(src.begin(), src.end(), inserter(dst, dst.begin()), flip_pair<A,B>);
//     return dst;
// }

// map<int, string> values = flip_map(terms);
// map<int, string>::reverse_iterator it = values.rbegin();
// for(; it != values.rend(); ++it) {
//   if (f_counter < frequent) {
//     cout << it->second << endl;
//     ++f_counter;
//   }
// }