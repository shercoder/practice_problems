/**
 Design an algorithm and write code to remove the duplicate characters in a string
 without using any additional buffer. NOTE: One or two additional variables are fine.
 An extra copy of the array is not.
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void remove_dup_char(char *str) {
  if (str == NULL) return;
  int len = strlen(str);
  if (len < 2) return;

  int checker = 0;
  
  for (int i = 0; i < len; ++i) {
    int val = str[i] - (int)'a';
    if ((checker & (1<<val)) > 0) {
      memmove(str+i, str+i+1, len-i+1); 
      len = strlen(str);
      --i;
    }
    checker |= (1<<val);
  }
}

int main() {
  //char str[] = "aaaa"; //"pardeepsinghh";
  //char str[] = "aaaabbb"; //"pardeepsinghh";
  char str[] = "pardeepsinghh";
  printf("before => %s\n", str);
  remove_dup_char(str);
  printf("after => %s\n", str);
  return 0;
}
