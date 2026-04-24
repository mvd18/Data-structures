#include "sort.h"
#include "module_array.h"
#include <cassert>

/*
https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2026/2026_part_1.md
*/

using namespace std;

/**
 * @brief ф-ия для выполнения сортировки пузырьком count раз
 * 
 * @param size размер массива
 * @param min мин. значение
 * @param max макс. значение
 * @param count кол-во повторений цикла
 */
void run_bubble_iterations(size_t size, int min, int max, int count) {
    for (int i = 0; i < count; ++i) {
        int* arr = create_arr(size, min, max);
        bubble(arr, size);
        delete[] arr;
    }
}

/**
 * @brief ф-ия для выполнения сортировки слиянием count раз
 * 
 * @param size размер массива
 * @param min мин. значение
 * @param max макс. значение
 * @param count кол-во повторений
 */
void run_merge_iterations(size_t size, int min, int max, int count) {
    for (int i = 0; i < count; ++i) {
        int* arr = create_arr<int>(size, min, max);
        
        // merge_sort принимает (массив, левый_индекс, правый_индекс)
        merge_sort(arr, 0, size - 1); 
        
        delete[] arr;
    }
}


/**
 * @brief ф-ия для запуска быстрой сортировки count раз 
 * 
 * @param size размер массива
 * @param min мин. значени 
 * @param max макс. значение
 * @param count кол-во повторений цикла 
 */
void run_quick_iterations(size_t size, int min, int max, int count) {
    for (int i = 0; i < count; ++i) {
        int* arr = create_arr(size, min, max);
        quick(arr, 0, size-1);
        delete[] arr;
    }
}


int main(){
    setlocale(LC_ALL, "ru_RU.UTF-8");
    
    vector<size_t> sizes = {100, 1000, 5000, 10'000, 15'000};
    const int SORT = 100;
    
    cout << fixed << setprecision(6);
    cout << "Сортировка пузырьком" << endl;
    cout << "Размер  Время (сек)\n";
    
    for (size_t n : sizes) {
        long long total_ms = timer_code(
            run_bubble_iterations,
            "bubble.txt", 
            n, 0, 1'000'000, SORT  
                  
        );
        
        //мс в секунды, делим на SORT для среднего времени
        double avg_time_sec = (total_ms / 1000.0) / SORT;
        
        cout << setw(6) << n << "  " << avg_time_sec << " сек\n";
    }

    cout << "\n Быстрая сортировка" << endl;
    cout << "Размер  Время (сек)\n";

        for (size_t n : sizes) {
        long long total_ms = timer_code(
            run_quick_iterations,
            "quick.txt", 
            n, 0, 1'000'000, SORT  
                  
        );
        
        //мс в секунды, делим на SORT для среднего времени
        double avg_time_sec = (total_ms / 1000.0) / SORT;
        
        cout << setw(6) << n << "  " << avg_time_sec << " сек\n";
    }

    cout << "\n Cортировка слиянием" << endl;
    cout << "Размер  Время (сек)\n";

    for (size_t n : sizes) {
    long long total_ms = timer_code(
        run_merge_iterations,  
        "merge.txt",       
        n, 0, 1'000'000, SORT 
    );
    
    double avg_time_sec = (total_ms / 1000.0) / SORT;
    cout << setw(8) << n << "  " << avg_time_sec << " сек\n";
    }

    //тесты сортировки пузырьком 
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bubble(arr, 10);
    assert(check_sort_arr(arr, 6));

    int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble(arr2, 10);
    assert(check_sort_arr(arr2, 6));

    int arr3[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    bubble(arr3, 10);
    assert(check_sort_arr(arr3, 10));
    
    //тесты квик сортировка
    int arrq2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    quick(arrq2, 0, 9);
    assert(check_sort_arr(arrq2, 6));

    int arrq3[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    quick(arrq3, 0, 9);
    assert(check_sort_arr(arrq3, 6));

    int arrq[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    quick(arrq, 0, 9);
    assert(check_sort_arr(arrq, 10));

    //тесты сортировка слиянием
    int arrm2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    merge_sort(arrm2, 0, 9);
    assert(check_sort_arr(arrm2, 6));

    int arrm3[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    merge_sort(arrm3, 0, 9);
    assert(check_sort_arr(arrm3, 6));

    int arrm[10] = {1, 2, 3, 4, 5, 10, 9, 8, 7, 6};
    merge_sort(arrm, 0, 9);
    assert(check_sort_arr(arrm, 10));

    return 0;
}