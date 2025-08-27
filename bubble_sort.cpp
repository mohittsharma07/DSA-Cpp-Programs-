#include <iostream>
using namespace std;

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

void bubblesort(int a[], int n){
    int temp;
    for(int i = 0; i < n - 1; i++ ){

        for(int j = 0; j < n-1-i; j++){
            if(a[j] > a[j + 1]){

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main(){
    int a[] = {12,54,65,7,23,9};
    int n = 6;

    cout << "Array before sorting";

    printArray(a,n);
    bubblesort(a,n);

    cout << "Array after sorting";
    printArray(a,n);

    return 0;

}



