#include <iostream>
using namespace std;

void printarray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

void selectionsort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int minindex = i;

        for(int j = i + 1; j < n; j++){
            if(a[j] < a[minindex]) {
                minindex = j;
            }
        }

        int temp = a[i];
        a[i] = a[minindex];
        a[minindex] = temp;
    }

}

int main(){
    int a[] = {44,54,3,55,23};
    int n = 5;

    cout << " array before sorting";
    printarray(a,n);

    selectionsort(a,n);
    cout << "array after sorting";

    printarray(a,n);

    return 0;

}