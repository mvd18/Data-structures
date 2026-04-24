#pragma once 

#include <cstdlib>
#include <string> 

/**
 * @brief - ф-ия для того, чтобы менять местами элементы
 * 
 * @param i1 - первый элемент  
 * @param i2 - второй элемент
 */
template <typename T>
void swap(T& i1, T& i2){
    T temp = i1;
    i1 = i2;
    i2 = temp;
}

/**
 * @brief функция пузырьковой сортировки массива
 * @note BigO
 * 
 * Лучший случай: О(n) - если массив уже отсортирован
 * Средний/Худший случай: О(n^2) - либо случайно расположены элементы, либо в обратном порядке
 * 
 * @tparam T - тип данных
 * @param arr - указатель на массив
 * @param size - размер массива
 */
template <typename T>
void bubble(T* arr, size_t size){
    if (size <= 1) return;

    for (size_t i = 0; i < size; i++){
        for (size_t j = 0; j < size - i -1; j++ ){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}


/**
 * @brief Разделяет массив на два подмассива относительно опорного элемента
 * @note опорный элемент - самый правый элемент массива.
 * Элементы меньше опорного элемента - слева от него, больше - справа
 * 
 * @param *arr - указатель на массив
 * @param left - левый индекс массива
 * @param right правый индекс массива
 * @return size_t индекс опорного элемента
 */
template <typename T>
size_t partition(T* arr, size_t left, size_t right){
    size_t i = left;
    size_t pivot = right;

    for (size_t j = left; j < pivot; j++ ){
        if (arr[j] < arr[pivot]){
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[pivot]);
    return i;
}


/**
 * @brief Сортирует массив по возрастанию. Используется быстрая сортировка
 * @note BigO:  
 * 
 * В лучшем случае: O(n*log(n))
 * В среднем случае: O(n*log(n))
 * В худшем случае: O(n^2)
 * 
 * @param *arr - указатель на массив
 * @param left - левый индекс массива
 * @param right - правый индекс массива
 */
template <typename T>
void quick(T* arr, size_t left, size_t right){
    if (left >= right){
        return;
    }

    // Индекс опорного элемента
    size_t pivot = partition(arr, left, right);
    
    // Сортировка слева от опорного элемента
    if (pivot > left){
        quick(arr, left, pivot - 1);
    }

    // Сортировка справа от опорного элемента
    if (pivot < right){
        quick(arr, pivot + 1, right);
    }
}

/**
 * @brief Объединяет два подмассива [left; mid] и (mid, right] в отсортированном порядке
 * 
 * @param array массив 
 * @param left левый индекс массива
 * @param mid средний индекс массива
 * @param right правый индекс массива 
 */
template <typename T>
void merge(T* array, size_t left, size_t mid, size_t right ){
    size_t left_size = mid - left + 1;
    size_t right_size = right - mid;

    T* left_arr = new T[left_size];
    T* right_arr = new T[right_size];

    memcpy(left_arr, array + left, left_size * sizeof(T));
    memcpy(right_arr, array + mid + 1, right_size * sizeof(T));

    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < left_size && j < right_size){
        if ( left_arr[i] <= right_arr[j]){
            array[k] = left_arr[i];
            k++;
            i++;
        }
        else if ( left_arr[i] > right_arr[j]){
            array[k] = right_arr[j];
            k++;
            j++;
        }
    }


    if (i < left_size) {
        memcpy(array + k, left_arr + i, (left_size - i) * sizeof(T));
    } else {
        memcpy(array + k, right_arr + j, (right_size - j) * sizeof(T));
    }

    delete[] left_arr;
    delete[] right_arr;
}


/**
 * @brief Сортирует массив по возрастанию. Используется merge сортировка
 * @note BigO:  
 * 
 * В лучшем случае: O(n*log(n))
 * В среднем случае: O(n*log(n))
 * В худшем случае: O(n*logn(n))
 * 
 * @param array массив
 * @param left левый индекс массива
 * @param right правый индекс массива
 */
template <typename T>
void merge_sort(T*  array, size_t left, size_t right){
    if (left >= right){
        return;
    }

    size_t mid = (right + left)/2;
    merge_sort(array, left, mid);
    merge_sort(array, mid+1, right);
    merge(array, left, mid, right);

}