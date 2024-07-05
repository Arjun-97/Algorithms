#include <iostream>

#define cin std::cin
#define cout std::cout
#define endl std::endl

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
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

    bubbleSort(arr, n);

    cout << "Sorted array: " << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
