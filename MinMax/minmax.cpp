#include <iostream>
#include <tuple>
using namespace std;

tuple<int,int> minMax(int arr[], int i, int j, int max, int min) {
	int max1, min1;
	if(i == j) {
		max = arr[i];
		min = arr[i];
	}
	else if(i == j-1) {
		if(arr[i] < arr[j]) {
			max = arr[j];
			min = arr[i];
		}
		else {
			max = arr[i];
			min = arr[j];
		}
	}
	else {
		int mid = (i+j)/2;
		tie(min,max) = minMax(arr,i,mid,max,min);
		tie(min1,max1) = minMax(arr,mid+1,j,max1,min1);
		if(max < max1) {
			max = max1;
		}
		if(min > min1) {
			min = min1;
		}
	}
	return make_tuple(min,max);
}

int main() {
	int max,min,a,b;
	int n;
	cout << "Enter number of elements: ";
	cin >> n;
	int arr[n+1];
	for(int i = 1; i <= n; i++) {
		cout << "Element-" << i << ": ";
		cin >> arr[i];
	}
	tie(a,b) = minMax(arr,1,n,max,min);
	cout << "Minimum element: " << a << endl;
	cout << "Maximum element: " << b << endl;
}
