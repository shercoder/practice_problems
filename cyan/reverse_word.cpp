#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

void reverse_func(char *str) {
    char * end = str;
    char tmp;
    if (str) {
        while (*end) {
            ++end;
        }
        --end;
        while (str < end) {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}

// inplace O(n) in time and O(1) space
void reverse_string(char *str, int len) {
  for (int i = 0; i < len/2; ++i) {
    str[i] ^= str[len-i-1];
    str[len-i-1] ^= str[i];
    str[i] ^= str[len-i-1];
  }
}

void reverse_words(char *str) {
  int len = strlen(str);
  reverse_string(str, len);

  int next = 0;
  for(int i = 0; i < len; ++i) {
    if (str[i] == ' ') {
      reverse_string(&str[next], i-next);
      next = i+1;
    }
  }

  // take care of the last word
  reverse_string(&str[next], len-next);
}


int main() {
    char str[] = "pardeep singh";
    char *pch = strtok(str," ");
    string reverse;
    while(pch != NULL) {
        int len = strlen(pch);
        for(int i = len-1; i >= 0; --i) { 
            reverse += pch[i];
        }
        reverse += " ";
        pch = strtok(NULL, " ");
    }
    cout << reverse << endl;

    char name[] = "pardeep singh";
    reverse_func(name);
    cout << name << endl;

    char str1[] = "pardeep singh";
    reverse_words(str1);
    cout << "str1 ==> " << str1 << endl;
    return 0;
}
