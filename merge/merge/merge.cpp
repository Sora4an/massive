#include <iostream>

template <typename T>
// заполняем массив элементами с клавиатуры
void FormArray(T* arr, int n) {
    std::cout << "Enter array   ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
}

template <typename T>
// выводим массив в консоль
void PrintArray(T* arr, int start, int fin) {
    for (int i = start; i < fin; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

template <typename T>
// соединяем  две отсортированные части массива
void Merge(T* arr, int start, int mid, int fin) {
    // заводим 2 указателя (1 для первой части массива и 1 для второй)
    int count1 = 0, count2 = 0;
    // заводим временный массив merged для соединения 2х частей
    T* merged = new T[fin - start + 1];
    // идем двумя указателями (первый указатель по первой части массива, второй - второй части)
    while (start + count1 < mid && mid + count2 < fin) {
        // если текущий элемент первой части меньше текущего элемента второй,
        // то записываем его в результирующий массив и сдвигаем первый указатель на 1 вперед
        // иначе записываем в результирующий массив текущий элемент второй части
        if (arr[start + count1] < arr[mid + count2]) {
            merged[count1 + count2] = arr[start + count1];
            count1++;
        }
        else {
            merged[count1 + count2] = arr[mid + count2];
            count2++;
        }
    }
    // для случая, когда мы дошли до конца одной части, но не дошли до конца другой,
    // дописываем в результирующий массив оставшиеся элементы не закончившейся части
    if (mid + count2 < fin) {
        while (mid + count2 < fin) {
            merged[count1 + count2] = arr[mid + count2];
            count2++;
        }
    }
    else if (start + count1 < mid) {
        while (start + count1 < mid) {
            merged[count1 + count2] = arr[start + count1];
            count1++;
        }
    }

    // копируем значения из результирующего массива на соответствующие позиции в исходном
    for (int i = 0; i < count1 + count2; i++) {
        arr[start + i] = merged[i];
    }
    delete[] merged;
}

template <typename T>
void MergeSort(T* arr, int start, int fin) {
    // пока не дойдем до массива размером 1
    if (fin <= start + 1) {
        return;
    }
    // выбираем средний элемент
    int mid = (start + fin) / 2;
    // рекурсивно запускаем функцию сортировки для левой и правой частей массива
    MergeSort(arr, start, mid);
    MergeSort(arr, mid, fin);
    // соединяем полученные отсортированные внутри себя части на выходе из рекурсии
    Merge(arr, start, mid, fin);
}

int main() {
    int len = 0;
    std::cout << "Enter the length of the array:  ";
    std::cin >> len;
    auto* arr = new double[len];
    FormArray(arr, len);
    std::cout << "Initial array:\n";
    PrintArray(arr, 0, len);
    MergeSort(arr, 0, len);
    std::cout << "Sorted array:\n";
    PrintArray(arr, 0, len);
    delete[] arr;
}
