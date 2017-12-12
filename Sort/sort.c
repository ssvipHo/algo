//
// Created by freepark on 2017/12/9.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define MAX 16

/**
 * 创建数组
 */
void createArray();

void insertionSort(int arr[]);

void shellSort(int *pInt);

int array[MAX];

int main() {
    createArray();
    // insertionSort(array);
    shellSort(array);
    for (int i = 0; i < MAX; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

void shellSort(int arr[]) {
    int temp = 0;
    int gap = 0;
    // 根据Sedgewick提出的(1, 5, 19, 41, 109,...) 取步长
    // 基数为9*pow(4, i) - 9*pow(2,i)+ 1 偶数位 2*pow(2, i+2) * (2*pow(2,i+2) - 3) + 1
    int *sedgewickTemp = (int *) malloc(MAX * sizeof(int));
    int k = 0, ki = 0, kj = 0;
    for (; k < MAX; k++) {
        if (k % 2 == 0) {
            temp = (int) (9 * (pow(4, ki) - pow(2, ki)) + 1);
            ki++;
        } else {
            temp = (int) (pow(2, kj + 2) * (pow(2, kj + 2) - 3) + 1);;
            kj++;
        }

        if (temp > MAX) {
            break;
        }

        sedgewickTemp[k] = temp;
    }

    int *sedgewick = (int *) malloc((k + 1) * sizeof(int));

    // 获取最后数组
    for (int i = 0; i < k; i++) {
        sedgewick[i] = sedgewickTemp[i];
    }

    free(sedgewickTemp);
    int j = 0;
    for (int i = 0; i < k; i++) {
        gap = sedgewick[i];
        // 每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m 的子序列，分别对各子表进行直接插入排序。
        // 仅增量因子为1 时，整个序列作为一个表来处理，表长度即为整个序列的长度
        for (i = gap; i < MAX; i++) {
            temp = arr[i];
            j = i - gap;
            for (; j >= 0 && arr[j] > temp; j -= gap) {
                arr[j + gap] = arr[j];
            }

            arr[j + gap] = temp;
        }
    }

    free(sedgewick);
}

/*
 * 算法思想：将数组中的所有元素依次跟前面已经排好的元素相比较，如果选择的元素比已排序的元素小，则交换，直到全部元素都比较过为止。
 */
void insertionSort(int *pInt) {
    int temp;
    for (int i = 0; i < MAX - 1; i++) {
        for (int j = i + 1; j > 0; j--) {
            if (*(pInt + j - 1) <= *(pInt + j)) {
                break;
            }

            temp = *(pInt + j);
            *(pInt + j) = *(pInt + j - 1);
            *(pInt + j - 1) = temp;
        }
    }
}

/**
 * create a array
 */
void createArray() {
    srand((unsigned int) time(0));
    for (int i = 0; i < MAX; i++) {
        array[i] = rand() % MAX;
        printf("%d ", array[i]);
    }
    puts(" ");
}
