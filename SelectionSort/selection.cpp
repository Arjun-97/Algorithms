#include <iostream>

#define cout std::cout
#define cin std::cin
#define endl std::endl

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
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

    selectionSort(arr, n);

    cout << "Sorted array: " << endl;

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
