#pragma once
#include <cstdlib>

/**
 * @brief ф-ия линейного поиска 
 * 
 * @tparam T - шаблонный тип данных
 * @param *arr - указатель на массив  
 * @param size - размер массива
 * @param num - искомое число
 * @return size_t i - возвр.  индекс искомого элемента
 */
template <typename T>
//const - данные, на которые указывает указатель, не должны изменяться внутри ф-ии 
size_t linear_search(const T* arr, size_t size, T&num){
    for (size_t i = 0; i < size; i++){
        if (arr[i] == num) return i; 
    }

    //-1 - потому что тип данных size_t, указываем, что элемент не найден
    return -1;

}

/**
 * @brief ф-ия бинарного поиска
 * 
 * @tparam T - шаблонный тип данных
 * @param *arr - указатель на массив
 * @param size - размер массива
 * @param target - искомое число 
 * @return size_t middle - индекс искомого элемента
 */
template <typename T>
size_t binary_search(const T* arr, size_t size, T target){
    size_t left = 0;
    size_t right = size - 1;

    while (left <= right){
        size_t middle = left + (right - left)/2;
        if (arr[middle] == target){
            return middle;
        }

        if (arr[middle] < target){
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        return -1;
    }

} 

/**
 * @brief ф-ия интерполяционного поиска
 * 
 * @tparam T - тип данных 
 * @param *arr - указатель на массив 
 * @param size - размер массива  
 * @param target - искомое число
 * @return size_t i - индекс искомого элемента 
 */
template <typename T>
size_t interpolation_search(const T* arr, size_t size, T target){
    size_t left = 0;
    size_t right = 0;

    while (left <= right && target >= arr[left] && target <= arr[right]){
        if (arr[right] == arr[left]){
            if (arr[left] == target){
                return left;
            } 
            return -1;
        }
        size_t ind = (left + ((target - arr[left])*(right - left)))/arr[right] - arr[left];

        if (ind < left || ind > right){
            return -1;
        }

        if (arr[ind] == target){
            return ind;
        }
        
        if (arr[ind] < target){
            left = ind + 1;
        } else {
            right = ind - 1; 
        }
   
    }
    return -1;
}

