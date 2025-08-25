#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target){
    int b = 0;
    int e = n-1;

    while(b <= e){
        int mid = (b + e)/2;

        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid] < target){
            b = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return -1;
}

int main(){
    int arr[10]={24,36,39,47,78,87,92,112,156,180};

    int n = 10;
    int target;

    cout << "Enter element to search";
    cin >> target;

    int result = binarySearch(arr,n,target);
    if(result != -1){
        cout << "Element found at position" << result + 1 << endl;
    }
    else{
        cout << "Element not found" << endl;
    }
    return 0;
}