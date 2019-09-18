// C++ program for implementation of Bubble sort  
#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort  
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code  
int main()
{
    int arr[] = {56, 70, 78, 11, 75, 2, 28, 45, 26, 25,
                 94, 61, 16, 37, 87, 12, 5, 62, 76, 36,
                 50, 6, 77, 59, 79, 33, 43, 53, 74, 84,
                 64, 47, 55, 96, 48, 85, 81, 65, 22, 92,
                 89, 73, 3, 63, 1, 42, 52, 10, 20, 31};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, n);
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}  