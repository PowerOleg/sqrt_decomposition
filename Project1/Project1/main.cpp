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
    for (int block_number = 1; block_number <= blocks_quantity; block_number++)
    {
       int min_of_block = get_min_of_block(arr, block_number, block_length);
       sqrt_memory[block_number] = min_of_block;
    }
}

int get_min(int* arr, int size, int left_index, int right_index, int* sqrt_memory)
{
    int left_up = 1;//the block number that touched by left_index
    int right_down = 3;//the block number that touched by right_index
    


    return 0;
}

int main()
{
    //int arr[]{ 14, 16, 19, 30, 32, 33, 56, 69, 72 };
    int arr[]{ 1, 5, 2,   4, 6, 1,   4, 5, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int left_index = 1;//������ ����� ����������� ������� ����� �������� 1 ������������ � �� ������ ������� ������ 7 �� ������������
    int right_index = 7;

    const int block_length = 3;//we decided that one block has 3 elements beacuse 3 is the sqrt of 9//�� ���� ������ ��� ����� � ����� ����� 3 �������� �� 3 ��� ������ �� 9
    int blocks_quantity = size / block_length;//blocks quantity of 9 elements is 3 blocks
    int* sqrt_memory = new int[blocks_quantity];
    preprocessing(arr, sqrt_memory, blocks_quantity, block_length);

    
    int min = get_min(arr, size, left_index, right_index, sqrt_memory);

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
    std::cout << "���������� ��������� �������, ��� " << value << ": " << result;
}
*/