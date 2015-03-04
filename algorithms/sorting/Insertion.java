public int[] insertionSortIncreaseOrder(int[] A, int N) {
  for (int j = 1; j < N; j++) {
    int key = A[j];
    int i = j-1;
    while(i >= 0 && A[i] > key) {
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = key;
  }
  return A;
}

public int[] insertionSortDecreaseOrder(int[] A, int N) {
  for (int j = 1; j < N; j++) {
    int key = A[j];
    int i = j-1;
    while(i >= 0 && A[i] < key) { // Difference is that we just have to check A[i] is less than the key
      A[i+1] = A[i];
      i--;
    }
    A[i+1] = key;
  }
  return A;
}
