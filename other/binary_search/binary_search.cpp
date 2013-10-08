#include <iostream>

using namespace std;

int iterative_bs(int n);
int recursive_bs(int n, int low, int high);

int array[] = {2, 3, 5, 7, 8, 10, 14, 20};
const int SIZE = 8;

int main() {

  cout << iterative_bs(14) << endl;
  cout << iterative_bs(100) << endl;
  cout << recursive_bs(14, 0, SIZE) << endl;
  return 0;
}

int recursive_bs(int n, int low, int high) {
  if (high < low) return -1;

  int mid = (low+high)/2;
  if(array[mid] < n) 
    recursive_bs(n, mid+1, high);
  else if(array[mid] > n)
    recursive_bs(n, low, mid-1);
  else
    return array[mid];
}

int iterative_bs(int n) {
  int low = 0, high = SIZE;

  while(high > low) {
    int mid = (high+low)/2;
    if (array[mid] < n) {
      low = mid+1;
    } else if (array[mid] > n) {
      high = mid-1;
    } else {
      return array[mid];
    }
  }
  return -1;
}
