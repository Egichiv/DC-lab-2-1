#include <iostream>
#include <cstdint>

using std::cin;
using std::cout;

int partition(int32_t* array, int left, int right) {
    int v = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < v) {
            i++;
        }
        while (array[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        int32_t temp = array[i];
        array[i++] = array[j--];
        array[j + 1] = temp;
    }
    return j;
}

void quick_sort (int32_t* array, int left, int right) {
    if (left < right) {
        int pivot = partition (array, left, right);
        quick_sort (array, left, pivot);
        quick_sort (array, pivot + 1, right);
    }
}

int main() {
    int elements_number;
    int position;
    int32_t* array;

    int32_t A;
    int32_t B;
    int32_t C;
    int32_t a1;
    int32_t a2;

    cin >> elements_number;

    if (elements_number <= 1) {
        exit(1);
    }

    cin >> position >> A >> B >> C >> a1 >> a2;

    array = (int32_t*) calloc(elements_number, sizeof(int32_t));

    array[0] = a1;
    array[1] = a2;
    for (int count = 2; count < elements_number; count++) {
        array[count] = (A * array[count - 2]) + (B * array[count - 1]) + C;
    }

    quick_sort(array, 0,elements_number - 1);

    cout << array[position - 1];

    free(array);
    return 0;
}
