#include <iostream>
using namespace std;

int main() {
	int N,Key,i,comp=0,swap=0;
	cout << "Enter number of elements to store in the array: ";
	cin >> N;
	int arr[N];
	for(int n = 0; n < N; n++) {
		cout << "Element - " << n << ": ";
		cin >> arr[n];
	}
	cout << "Elements in the array are: ";
	for(int n = 0; n < N; n++) {
		cout << arr[n] << "   ";
	}
	cout << "\nOn applying insertion sort: ";
	for(int j = 1; j < N; j++) {
		Key = arr[j];
		i = j - 1;
		while(i >= 0 && arr[i] < Key) {
			if(arr[i] < Key) { comp++; }
			arr[i + 1] = arr[i];
			i = i - 1;
		}
		arr[i+1] = Key;
		swap ++;
	}
	for(int n = 0; n < N; n++) {
		cout << arr[n] << "   ";
	}
	cout << "\n" << comp << "\n" << swap;
}
