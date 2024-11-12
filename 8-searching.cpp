#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }
    return -1;
}

int main() {
    int n, target;
    
    cout << "Enter the number of elements in sorted array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " sorted elements: "<<endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the element to search: ";
    cin >> target;

    int linearResult = linearSearch(arr, n, target);
    if (linearResult != -1) {
        cout << "Element found at index " << linearResult << " using Linear Search.\n";
    } else {
        cout << "Element not found using Linear Search.\n";
    }

    int binaryResult = binarySearch(arr, n, target);
    if (binaryResult != -1) {
        cout << "Element found at index " << binaryResult << " using Binary Search.\n";
    } else {
        cout << "Element not found using Binary Search.\n";
    }

    return 0;
}
