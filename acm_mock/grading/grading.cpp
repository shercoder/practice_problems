/*
Pardeep Singh and Oriah Oulrich
Time: 4:23PM
*/
#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

float get_c(float x1, float y1, float x2, float y2) {
  float x = pow(fabs(x2-x1), 2);
  float y = pow(fabs(y2-y1), 2);
  return sqrt(x+y);
}

int main() {
  int N = 0;
  cin >> N;

  float start_x, start_y;
  float x1, y1, x2, y2;
  float sum = 0;

  scanf("%f %f", &x1, &y1); 
  start_x = x1, start_y = y1;

  while(N) {
    scanf("%f %f", &x2, &y2); 
    float s = get_c(x1, y1, x2, y2);
    sum += s;
    x1 = x2;
    y1 = y2;
    --N;
  }
  sum += get_c(x1, y1, start_x, start_y);
  cout << sum << endl;
  return 0;
}
