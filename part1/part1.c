#include <stdio.h>
#include <stdlib.h>

#define NOT_POW_2 -1
#define INVALID 0


int calculate_exp(int x) {
    if (x % 2)
        return NOT_POW_2;
    if (x == 2)
        return 1;
    int result = calculate_exp(x / 2);
    if (result == NOT_POW_2)
        return NOT_POW_2;
    return 1 + result;
}

int get_size(int *size) {
    printf("Enter size of input:\n");

    if (((scanf("%d", size)) != 1) || *size <= 0) {
        return INVALID;
    }
    return 1;
}

int fill_arr(int arr[], int n) {
    printf("Enter numbers:\n");
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", arr + i) != 1) {
            return INVALID;
        }
    }
    return 1;
}

int main() {
    int size;
    int temp_exp;
    int exp_sum = 0;

    //get size value
    if (get_size(&size) == INVALID) {
        //invalid size message
        printf("Invalid size\n");
        return INVALID;
    }

    //allocate an int array of the proper size
    int *arr = (int *) malloc(sizeof(int) * size);
    if (arr == NULL)
        return INVALID;

    //fill array and check if the input is valid
    if (fill_arr(arr, size) == INVALID) {
        //print invalid input message
        printf("Invalid number\n");
        free(arr);
        return INVALID;
    }

    //find numbers that are power of 2 & calculate total exponent sum
    for (int i = 0; i < size; ++i) {
        if (arr[i] == 1)
            temp_exp = 0;
        else if (arr[i] <= 0 || arr[i] % 2 != 0)
            continue;

        else {
            temp_exp = calculate_exp(arr[i]);
            if (temp_exp == NOT_POW_2)
                continue;
        }
        printf("The number %d is a power of 2: %d = 2^%d\n", arr[i], arr[i], temp_exp);
        exp_sum += temp_exp;

    }
    printf("Total exponent sum is %d\n", exp_sum);
    free(arr);
    return 0;

}

