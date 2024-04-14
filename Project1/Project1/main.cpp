#include <iostream>
//The task is to find the min value between index 1(included) and index 7(not included)

int get_min_of_block(int* arr, int block_number, const int block_length)
{
    int min = 2140000000;//TODO
    int size = block_number * block_length;
    for (int i = (block_number - 1) * block_length; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

void preprocessing(int* arr, int* sqrt_memory, int blocks_quantity, const int block_length)
{
    for (int block_number = 1; block_number <= blocks_quantity; block_number++)//blocks stats from 1 just to convert for example from 1 block to 3 index 
    {
       int min_of_block = get_min_of_block(arr, block_number, block_length);
       sqrt_memory[block_number - 1] = min_of_block;
    }
}

int get_min(int* arr, int size, int left_index, int right_index, int* sqrt_memory, int blocks_quantity)
{
    int min = 2140000000;//TODO
    int left_up = 2;//номер левого блока который полностью покрывается интвервалом//the block number from the left which inside the range//need to calculate but I'm too lazy//TODO
    int right_down = 2;//номер правого блока который покрывается те внутри интервала//the block number from the right which inside the range//need to calculate but I'm too lazy//TODO
    for (int i = left_index; i < (left_up - 1) * blocks_quantity; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    for (int i = left_up; i <= right_down; i++)//remember block number starts from 1 and ends with 3
    {
        if (sqrt_memory[i - 1] < min)
        {
            min = sqrt_memory[i - 1];
        }
    }
    for (int i = right_down * blocks_quantity; i < right_index; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    //int arr[]{ 14, 16, 19, 30, 32, 33, 56, 69, 72 };
    int arr[]{ 1, 5, 2,   4, 6, 1,   4, 5, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int left_index = 1;//задача найти минимальный элемент между индексом 1 включительно и по правой границе индекс 7 не включительно
    int right_index = 7;

    const int block_length = 3;//we decided that one block has 3 elements beacuse 3 is the sqrt of 9//мы сами решили что пусть в одном блоке 3 элемента тк 3 это корень из 9
    int blocks_quantity = size / block_length;//blocks quantity of 9 elements is 3 blocks
    int* sqrt_memory = new int[blocks_quantity];
    preprocessing(arr, sqrt_memory, blocks_quantity, block_length);

    
    int min = get_min(arr, size, left_index, right_index, sqrt_memory, blocks_quantity);
    std::cout << "SQRT decomposition" << std::endl;
    std::cout << "In the range from " << left_index << " to " << right_index << " min is " << min;
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