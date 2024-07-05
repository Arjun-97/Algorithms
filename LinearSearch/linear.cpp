#include <iostream>

#define cin std::cin
#define cout std::cout

int linearSearch(int arr[], int n, int find) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == find) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n], find, ans;

    for(int i = 0; i < n; i++) {
        cout << "Enter an element: ";
        cin >> arr[i];
    }

    cout << "Enter an element to find: ";
    cin >> find;

    ans = linearSearch(arr, n, find);

    if(ans == -1) {
        cout << "Element not found";
    }
    else {
        cout << "Element found at index: " << ans + 1;
    }
}
