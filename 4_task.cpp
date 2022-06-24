//
// Created by Андрей on 23.06.2022.
//
#include <iostream>
#include <vector>
using namespace std;
void mergeSort (vector <int> &vec, int start, int end);

void mergeSort(vector<int> &vec, int start, int end) {

    if (end - start < 2) { // если массив меньше 2х элементов, они считаются отсортированными.

        return;
    }
    if (end - start == 2) { // если массив в 2 элемента, проверяем их и сортируем.
        if (abs(vec[start]) > abs(vec[start + 1])) {
            int temp = vec[start + 1];
            vec[start + 1] = vec[start];
            vec[start] = temp;

            return;
        }
    }
        mergeSort (vec,start,start +(end-start)/2); // рекурсивно делим массив и смотрим левую часть
        mergeSort (vec,start+((end-start)/2),end); // рекурсивно делим массив и смотрим левую часть

        // складываем наши части в новый массив
        vector <int> sum;
        int start1 = start;
        int end1 = start + (end-start)/2;
        int start2 = end1;

        while (sum.size()< end - start){// перекидываем элементы, пока массив sum не станет равным начальному
            if (start1 >= end1 || (start2 < end && abs(vec[start2]) <= abs(vec[start1]))){ // если начало первой части вышло за границы части
                sum.push_back (vec[start2]);                 // или начало второй части вышло за границы части
                ++start2;                                    // и элемент второй половины меньше или равен элементу первой
                // ставим меньший элемент в суммарный вектор и сдвигаем индекс.
            } else { // иначе меньший элемент в первой части ставим в сум вектор и сдвигаем индекс этой части.
                sum.push_back (vec[start1]);
                ++start1;
            }
        }

        for (int i = start; i<end;i++){
            vec [i] = sum [i-start];
        }
}


void modulo_sort (){

    vector <int> vec  = {-34,300,-1,-20,-100,-50, -5, 1, 10, 15};
    cout << "Source array: ";
    for (int i =0; i < vec.size(); i++){
        cout << vec [i] << " ";
    }
    cout << endl;

    mergeSort(vec,0,vec.size());
    cout << "Sorted array (mergeSort): ";
    for (int i =0; i < vec.size(); i++){
        cout << vec [i] << " ";
    }
}