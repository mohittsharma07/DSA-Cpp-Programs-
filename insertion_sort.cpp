#include <iostream>
using namespace std;

void printarray(int a[],int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

void insertionsort(int a[], int n){
    for(int i = 1; i < n; i++){
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            
            j--;
        }
        a[j + 1] = key;

        cout << "After pass" << i << endl;
        printarray(a,n);

    }
}

int main(){
    int a[] = {16,31,13,45,80,55};
    int n = 6;

    cout << " Array before sorting ";
    printarray(a,n);

    insertionsort(a,n);

    cout << " Array after sorting";
    printarray(a,n);

    return 0;
}