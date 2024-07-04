#include <iostream>

#define cin std::cin
#define cout std::cout

int kadane(int arr[], int n) {
	int max_sum = -99999999;
	int current_sum = 0;

	for(int i = 0; i < n; i++) {
		current_sum = current_sum + arr[i];

		if(max_sum < current_sum) {
			max_sum = current_sum;
		}
		if(current_sum < 0) {
			current_sum = 0;
		}
	}

	return max_sum;
}

int main() {
	int n;

	cout << "Enter number of elements: ";
	cin >> n;

	int arr[n];

	for(int i = 0; i < n; i++) {
		cout << "Enter an element: ";
		cin >> arr[i];
	}

	cout << "The largest sub array sum is: " << kadane(arr, n);
}
