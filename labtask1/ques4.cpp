#include <iostream>
using namespace std;


int findMax(int* arr, int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int findMin(int* arr, int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    

    int* ptr = new int[n];
    
    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> ptr[i];
    }
    

    int maximum = findMax(ptr, n);
    int minimum = findMin(ptr, n);
    
    cout << "Maximum element is: " << maximum << endl;
    cout << "Minimum element is: " << minimum << endl;
    
    
    delete[] ptr;
    return 0;
}