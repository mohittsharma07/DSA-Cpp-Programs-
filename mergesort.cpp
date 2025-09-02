#include <iostream>
using namespace std;

void printArray(int A[],int n){
    for(int i = 0; i < n; i++){
        cout << A[i] << endl;
    }
    cout << endl;
}

void merge(int A[], int mid, int low, int high){

    int i, j, k, B[100];
     i = low;
     j = mid + 1;
     k = low; 

    while(i <= mid && j <= high){

        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{

            B[k] = A[j];
            j++;
            k++;
        }
    }

    while(i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }
    while(j <= high){
        B[k] = A[j];
        k++;
        j++;
    }

    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high){
    int mid;
    if(low < high){
        mid = (low + high) /2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main(){
    int A[] = {34,45,22,45,56,17,70};
    int n = 7;

    cout << " before sorting";
    printArray(A,n);

    mergesort(A,0,6);
    cout << " array after sorting";

    printArray(A,n);

    return 0;
}