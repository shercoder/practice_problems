#include <iostream>

using namespace std;

bool is_anagram(string first, string second) {
  int sz1 = first.size();
  int sz2 = second.size();
  if (sz1 != sz2) return false;
  if (sz1 == 0 && sz2 == 0) return true;

  int r[26] = {0};
  for (int i = 0; i < sz1; ++i) {
    r[first[i] - 'a']++;
    r[second[i] - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    if (r[i] == 1) return false;
  }
  return true;
}

int main(int argc, char const* argv[]) {
  if (argc != 3) { 
    cout << "Usage: " << argv[0] << " <first_string> <second_string>" << endl;
    return 1;
  }

  string first(argv[1]);
  string second(argv[2]);
  cout << first << " " << second << endl;

  cout << first << " and " << second << " are" << (is_anagram(first, second) ? " " : " not ") << "anagrams" << endl;


  return 0;
}
