#include <iostream>
//The task is to find the min value between index 1(included) and index 7(not included)
int getMin(int* arr, int size, int left_index, int right_index, int* sqrt_memory) {
    int result = -1;
    int left = 0;
    int right = size - 1;
    while (true)
    {

    }

    return result;
}

int main() {
    //int arr[]{ 14, 16, 19, 30, 32, 33, 56, 69, 72 };
    int arr[]{ 1, 5, 2,   4, 6, 1,   4, 5, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int left_index = 1;//задача найти минимальный элемент между индексом 1 включительно и по правой границе индекс 7 не включительно
    int right_index = 7;

    const int block_length = 3;//we decided that one block has 3 elements //мы сами решили что пусть в одном блоке 3 элемента
    int blocks_quantity = size / block_length;//
    int* sqrt_memory = new int[blocks_quantity];

    int min = getMin(arr, size, left_index, right_index, sqrt_memory);
    std::cout << "SQRT decomposition" << min << ": " ;
    delete[] sqrt_memory;
}







/*
int count_array_size(int* arr, int size, int value) {
    int result = -1;
    int left = 0;
    int right = size - 1;
    while (true)
    {
        int middle = (left + right) / 2;
        if (value == arr[middle]) {

            while (value == arr[middle])
            {
                middle++;
            }
            return (size - 1) - (middle - 1);
        }
        if (value > arr[middle]) {
            if (middle == left)
            {
                middle++;
            }
            if (value > arr[middle] && middle == (size - 1))
            {
                return 0;
            }
            left = middle;
        }
        if (value < arr[middle]) {
            if (middle == 0)
            {
                return size;
            }
            right = middle;
        }
    }

    return result;
}

int main() {
    int arr[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int value = 100;
    int result = count_array_size(arr, size, value);
    std::cout << "Количество элементов больших, чем " << value << ": " << result;
}
*/