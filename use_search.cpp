#include <iostream>
#include "search.h"
#include <clocale>
#include <vector>
#include <iomanip>
#include "module_array.h"

/*
https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2026/2026_part_1.md
*/

using namespace std;


int main(){

    random_device rd;
    mt19937 gen(rd());

    setlocale(LC_ALL, "ru_RU.UTF-8");

    vector<size_t> sizes = {100, 1000, 5000, 10'000, 50'000, 100'000};

    cout << fixed << setprecision(9);
    cout << "Размер  Время (сек)" << endl;

    for (size_t n : sizes) {
        int* arr = create_sort_arr(n, 0, 1'000'000);
        
        const int SEARCH_COUNT = 1000;
        
        auto t0 = steady_clock::now();
        uniform_int_distribution<size_t> dist(0, n - 1);
        for (int i = 0; i < SEARCH_COUNT; i++) {

            size_t random_index = dist(gen);
            int t = arr[random_index];
            binary_search(arr, n, t);
        }

    auto t1 = steady_clock::now();
    
    double time_sec = duration<double>(t1 - t0).count();

    cout << setw(6) << n << "  " << time_sec << " сек" << endl;

    delete[] arr;
    }
    
    cout << "Интерполяционный посик" << endl;

    for (size_t n : sizes) {      
        int* arr = create_sort_arr(n, 0, 1'000'000);

        const int SEARCH_COUNT = 1000;

        auto t0 = steady_clock::now();

        uniform_int_distribution<size_t> dist(0, n - 1);

        for (int i = 0; i < SEARCH_COUNT; i++) {
            size_t random_index = dist(gen);
            
            int t = arr[random_index];
            
            interpolation_search(arr, n, t);
        }
        
        auto t1 = steady_clock::now();
        double time_sec = duration<double>(t1 - t0).count();

        cout << setw(6) << n << "  " << time_sec << " сек" << endl;
        
        delete[] arr;
    }
    cout << "Линейный поиск" << endl;

    for (size_t n : sizes) {      
        int* arr = create_arr(n, 0, 1'000'000);

        const int SEARCH_COUNT = 1000;

        auto t0 = steady_clock::now();

        uniform_int_distribution<size_t> dist(0, n - 1);

        for (int i = 0; i < SEARCH_COUNT; i++) {
            size_t random_index = dist(gen);
            
            int t = arr[random_index];
            
            linear_search(arr, n, t);
        }
        
        auto t1 = steady_clock::now();
        double time_sec = duration<double>(t1 - t0).count();

        cout << setw(6) << n << "  " << time_sec << " сек" << endl;
        
        delete[] arr;
    }
    test_search();

    return 0;
}
