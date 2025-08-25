#include <iostream>
using namespace std;

void linearSearch(int a[], int n, int size){
    int temp = -1;

    for(int i=0; i<5; i++){
        if(a[i] == n) {
            cout << "Element found at location" << i+1 <<endl;
            temp = 0;
            break;
            
        }
    }

    if(temp == -1){
        cout << " No Element found" << endl;
    }
}

int main() {
    int arr[5];
    cout << " Please enter 5 elements of the array " << endl;
    for(int i = 0; i < 5; i++){
        cin >> arr[i];
    }
    cout << "Please enter an element to search" << endl;
    int num;
    cin >> num;

    linearSearch(arr,num,5);

    return 0;
}






