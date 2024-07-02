#include <iostream>
using namespace std;

void merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1], R[n2 + 1];

  for (int i = 0; i < n1; i++) {
    L[i] = A[p + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = A[q + 1 + j];
  }

  L[n1] = 99999999;
  R[n2] = 99999999;

  int i = 0;
  int j = 0;
  for (int k = p; k <= r; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } 
    else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int p, int r) {
  if (p < r) {
    int q = (p + r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);
    merge(A, p, q, r);
  }
}

int main() {
  int p = 0, r = 6;
  int arr[7] = {77, 22, 33, 44, 11, 55, 66};
  mergeSort(arr, p, r);
  for (int i = 0; i <= r; i++) {
    cout << arr[i] << endl;
  }
  return 0;
}
