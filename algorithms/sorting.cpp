#include <bits/stdc++.h> 
using namespace std;

void selection_sort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int mini = i; 
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }  
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n) {
    for(int i = n-1; i>=0; i--) {
        int didSwap = 0;
        for(int j = 0; j<=i-1; j++){
            if(arr[j] > arr[j+1]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0){
        }
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    //selection_sort(arr, n);
    bubble_sort(arr, n);
    
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}