#include <iostream>

/*
https://github.com/ivtipm/Data-structures-and-algorithms/blob/main/current_plans/2026/2026_part_1.md
*/

//пространство имён std
using namespace std;

//функция вызываемая сама себя - рекурсивная
int recursion(int num){
    cout << num << " ";
    return recursion(num+1);
}
int main(){
    //вызов рекурсии
    recursion(1);
    return 0;
}

//отчёт в noteeee.excalidraw