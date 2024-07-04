#include <iostream>

#define cin std::cin
#define cout std::cout

int binarySearch(int arr[], int n, int find) {
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;

    while(start <= end) {
        if(find == arr[mid]) {
            return mid + 1;
        }
        else if(find < arr[mid]) {
            end = mid - 1;
            mid = (start + end) / 2;
        }
        else {
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    return -1;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n], find;

    for(int i = 0; i < n; i++) {
        cout << "Enter an element: ";
        cin >> arr[i];
    }

    cout << "Enter an element to search: ";
    cin >> find;

    int ans = binarySearch(arr, n, find);

    if(ans == -1) {
        cout << "Element not found";
    }
    else {
        cout << "Element found at position: " << ans;
    }
}
