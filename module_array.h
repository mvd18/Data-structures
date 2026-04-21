#pragma once
#include <cstddef>
#include <string>
#include <chrono>
#include <random>
#include <fstream>

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
    auto delta = duration_cast<milliseconds>(t1-t0);
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
 * @brief шаблонная ф-ия создания монотонно возрастающего массива (не исп. сортировку здесь, т. к. это уменьшит эффективность кода и время выполнения)

 * 
 * @tparam T - тип данных
 * @param size - размер массива 
 * @param min - мин. значение 
 * @param max - макс. значение
 * @return T* arr - указатель на массив 
 */
template <typename T>
T* create_sort_arr(size_t size, T min, T max){
    random_device rd;
    mt19937 gen(rd()); 

    uniform_int_distribution<>rang(min, max);

    T* arr = new T[size];

    arr[0] = rang(gen);
    for (size_t i = 1; i < size; i++){
        arr[i] = arr[i-1]+rang(gen);
    }

    return arr;
}


/**
 * @brief шаблонная ф-ия - создания массива
 * 
 * @tparam T - тип данных
 * @param size - размер массива
 * @param min - мин. значение
 * @param max - макс. значение
 * @return T* arr - указатель на массив
 */
template <typename T>
T* create_arr(size_t size, T min, T max){
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> rang(min, max);

    T* arr = new T[size];

    for(size_t i = 0; i < size; i++){
        //rang - объект
        arr[i] = rang(gen);
    }

}

/**
 * @brief проверка массива на отсортированность
 * 
 * @tparam T - тип данных
 * @param T* arr - указатель на массив 
 * @param size - размер массива
 * @return true - если размер массива 0 или 1 и если arr[i] < arr[i-1]
 * @return false - если arr[i] > arr[i-1] 
 */
template <typename T>
bool check_sort_arr(const T* arr, size_t size){
    if (size <= 1) return true;

    for (size_t i = 0; i < size - 1; i++){
        if (arr[i] > arr[i+1]) return false;
    }

    return true;

}

/**
 * @brief функция записи в файл
 * 
 * @tparam T - тип данных
 * @param arr - указатель на массив
 * @param size - размер массива
 * @param filename - имя файла
 * @param append - флаг 
 */
template <typename T>
void write_arr_in_file(const T* arr, size_t size, const string& filename, bool append = false) {
    // проверка массива
    if (arr == nullptr) {
        throw invalid_argument("Массив не инициализирован");
    }

     ofstream file;
     if (append) {
        file.open(filename, ios::app);
     } else {
        file.open(filename);
     }

     if (!file.is_open()) {
        throw runtime_error("Не удалось открыть файл для записи: " + filename);
     }
     // записываем размер массива
     file << size << endl; 

     // Записываем элементы
    for (int i = 0; i < n; ++i) {
        // Для целых чисел выводим без форматирования
        if constexpr (is_integral_v<T>) {
            file << arr[i];
        } else {
            // Для вещественных - с 4 знаками
            file << fixed << setprecision(4) << arr[i];
        }
        // Разделитель
        if (i < n - 1) {
            file << " ";
        }
    }

    file.close();
    cout << "Массив успешно записан в файл: " << filename << endl;
}
