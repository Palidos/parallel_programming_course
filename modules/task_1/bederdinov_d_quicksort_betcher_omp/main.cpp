// Copyright 2019 Bederdinov Daniil
#define len 80
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <omp.h>

void CreateArray(int arr[], int length) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = std::rand() % len;
    }
}

void QuickSort(int *arr, int size) {
    int i = 0, j = size - 1;
    int pivot = arr[size / 2];

    do {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
        QuickSort(arr, j + 1);
    if (i < size)
        QuickSort(&arr[i], size - i);
}

int main(int argc, char *argv[]) {
    int array[len];
    CreateArray(array, len);
    std::cout << std::endl;
    std::cout << "array before sort:" << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    QuickSort(array, len);
    std::cout << "array after sort:" << std::endl;
    for (int i = 0; i < len; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
