#pragma once
#include <cstddef>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;


/**
 * @brief шаблонная функция возврата времени работы, переданной ф-ии
 * 
 * @tparam Func - тип данных ф-ии
 * @tparam Args - тип данных аргументов ф-ии
 * @param func - функция
 * @param arg - аргументы, переданной ф-ии
 * @param filename - имя файла для записи времени
 * @return long long time_ms - возвращаем время в миллисекнудах
 */
template <typename Func, typename... Args>
long long timer_code(Func func, Args... arg, const string& filename = "data.txt"){
    //начальное время
    //now() - возвращаем время в наносекундах
    auto t0 = steady_clock::now();

    //переданная функция
    //передача просто arg - приведёт к ошибке, мы передадим не все аргументы 
    func(arg...);

    //конечное время
    auto t1 = steady_clock::now();

    //duration_cast - явно конвертируем в миллисекунды
    auto delta = duration_cast<milliseconds>t1-t0;
    //.count()- возвращает числовое кол-во 
    long long time_ms = delta.count();

    //ofstream - класс из <fstream> для вывода в файл (output file stream) 
    //append - флаг открытия, для записи в конец файла, не стирая содержимое
    ofstream file(filename, ios::app);
    //если файл открыт
    if (file.is_open()){
        file << time_ms << "\n";
        //закрытие файла
        file.close();
    }

    return time_ms;

}



/**
 * @brief создание монотонно возрастающего массива (не исп. сортировку здесь, т. к. это уменьшит эффективность кода и время выполнения)
 * 
 * @param size - размер массива
 * @param min - мин. значение 
 * @param max - макс. значение
 * @return int* - указатель на массив 
 */
int* create_sort_arr(size_t size, int min, int max);


/**
 * @brief создание массива состоящего из целых чисел
 * 
 * @param size - размер массива 
 * @param min - минимальное 
 * @param max - максимальное
 * @return int* - указатель на созданный массив
 */
int* create_arr(size_t size, int min, int max);

/**
 * @brief проверка массива на отсортированность
 * 
 * @param arr - передаём массив
 */
void check_sort_arr(int arr);