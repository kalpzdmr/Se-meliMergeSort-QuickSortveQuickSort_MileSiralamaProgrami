#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int arr[], int p, int r) {
    if (p < r) {
        int q = (p+r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

int partition(int arr[], int p, int r) {
    int pivot = arr[r];
    int i = (p - 1);

    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int pivot = partition(arr, p, r);
        quickSort(arr, p, pivot - 1);
        quickSort(arr, pivot + 1, r);
    }
}

int ort_pivot(int arr[], int p, int r) {
    int top = 0;
    for (int i = p; i <= r; i++) {
        top += arr[i];
    }
    int ort = top / (r - p + 1);

    int closest = arr[p];
    for (int i = p; i <= r; i++) {
        if (abs(arr[i] - ort) < abs(closest - ort)) {
            closest = arr[i];
        }
    }
    return closest;
}

int partition_M(int arr[], int p, int r) {
    int pivot = ort_pivot(arr, p, r);
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

void quickSort_M(int arr[], int p, int r) {
    if (p < r) {
        int pivot = partition_M(arr, p, r);
        quickSort_M(arr, p, pivot - 1);
        quickSort_M(arr, pivot + 1, r);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
    	printf("%d\n", arr[i]);
    }
}

int main() {
    int n, choice;

	scanf("%d", &choice);
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    switch (choice) {
        case 0:
            mergeSort(arr, 0, n - 1);
            printf("MergeSort\n");
            break;
        case 1:
            quickSort(arr, 0, n - 1);
            printf("QuickSort\n");
            break;
        case 2:
            quickSort_M(arr, 0, n - 1);
            printf("QuickSort_M\n");
            break;
    }
    
    printArray(arr, n);
    return 0;
}
