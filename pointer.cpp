#include <stdio.h>

void make_string( char **str ) {
  *str = "hello world";
}

int main() {
  char* str;
  make_string( &str );
  printf("%s\n", str);
  return 0;
}
