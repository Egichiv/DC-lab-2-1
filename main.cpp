#include <iostream>
#include <cstdint>

using std::cin;
using std::cout;

void k_statistic (int32_t* array, int left, int right, int position) {
    int32_t v = array[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {

        while (array[i] < v) {
            i++;
        }

        while (array[j] > v) {
            j--;
        }

        if (i <= j) {
            int32_t temp = array[i];
            array[i++] = array[j--];
            array[j + 1] = temp;
        }
    }

    if ((j > left) && (position <= j)) {
        k_statistic(array, left, j, position);
    }

    if ((i < right) && (position >= j)) {
        k_statistic(array, j + 1, right, position);
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

    cin >> elements_number >> position;

    array = (int32_t*) calloc(elements_number, sizeof(int32_t));

    cin >> A >> B >> C >> a1;

    array[0] = a1;

    if (elements_number == 1) {
        cout << array[0];
        return 0;
    }

    cin >> a2;
    array[1] = a2;

    for (int count = 2; count < elements_number; count++) {
        array[count] = (A * array[count - 2]) + (B * array[count - 1]) + C;
    }

    k_statistic(array, 0, elements_number - 1, position - 1);
    cout << array[position - 1];

    free(array);
    return 0;
}
