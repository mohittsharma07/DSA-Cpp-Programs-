#include <iostream>
using namespace std;

void printarray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << endl;
    }
    cout << endl;
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(i <= high && a[i] <= pivot){
            i++;
        }
        while(j >= low && a[j] > pivot){
            j--;
        }
        if(i < j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    while(i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

void quicksort(int a[],int low,int high){
    if(low < high){
        int partitionindex = partition(a,low,high);
        quicksort(a,low,partitionindex-1);
        quicksort(a,partitionindex+1,high);
    }
}

int main(){
    int a[] = {3,5,2,13,12};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "before sorting";
    printarray(a,n);

    quicksort(a,0,n-1);

    cout << "array after sorting";
    printarray(a,n);

    return 0;
}
