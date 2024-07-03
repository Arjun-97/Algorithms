#include <iostream>

#define cin std::cin
#define cout std::cout
#define endl std::endl

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

int partition(int arr[], int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++) {
		if(arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1;
}

void quickSort(int arr[], int p, int r) {
	if(p < r) {
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

int main() {
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int arr[n], p = 0, r = n - 1;
	for(int i = 0; i < n; i++) {
		cout << "Enter an element: ";
		cin >> arr[i];
	} 

	quickSort(arr, p, r);

	cout << "The sorted array is: " << endl;
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}
