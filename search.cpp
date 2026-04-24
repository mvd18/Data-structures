#include "search.h"
#include <cassert>


bool test_search(){
    //поиск элемента в середине массива
    int arr1[6] = {1, 3, 5, 7, 9, 11};
    int res1 = binary_search(arr1, 6, 7);
    assert(res1 == 3);

    //поиск первого элемента
    int res2 = binary_search(arr1, 6, 1);
    assert(res2 == 0);

    //поиск последнего элемента
    int res3 = binary_search(arr1, 6, 11);
    assert(res3 == 5);

    //элемент не найден
    int res4 = binary_search(arr1, 6, 0);
    assert(res4 == -1);

    //тип double
    double arr3[4] = {1.5, 2.5, 3.5, 4.5};
    int res5 = binary_search(arr3, 4, 3.5);
    assert(res5 == 2);

    //тип char
    char arr4[5] = {'a', 'b', 'c', 'd', 'e'};
    int res6 = binary_search(arr4, 5, 'd');
    assert(res6 == 3);

    //поиск элемента в середине
    int arri1[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int res_i1 = interpolation_search(arri1, 10, 50);
    assert(res_i1 == 4);

    //поиск первого элемента
    int res_i2 = interpolation_search(arri1, 10, 10);
    assert(res_i2 == 0);

    //поиск последнего элемента 
    int res_i3 = interpolation_search(arri1, 10, 100);
    assert(res_i3 == 9);

    //элемент не найден
    int res_i4 = interpolation_search(arr1, 10, 5);
    assert(res_i4 == -1);

    //неравномерно распределенные данные
    int arri2[10] = {1, 2, 10, 20, 50, 100, 200, 500, 850, 1000};
    int res_i5 = interpolation_search(arri2, 10, 100);
    assert(res_i5 == 5);

    return true;


}