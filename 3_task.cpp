//
// Created by Андрей on 23.06.2022.
//
#include <iostream>
#include <vector>
#include "overflow.h"

using namespace std;
void output_vector (vector <int> vec);
void input_in_end (vector <int>&vec, int n,int &vS);
void input_in_start (vector <int>&vec, int n,int &vS);
void input_between (vector <int>&vec, int n);

void five_in_ascending_order (){
    int vecSize = 1;
    vector <int> vec (vecSize);

    cout << "(-1) - show fifth ascending number\n(-2) - program completion\n";

    int n = 0;
   for (int i =0; n != -2;i++){
        cout << "input number:";
        cin >> n;
        while (overflow()) {cin >> n;}

        if (n == -1 ){
            if (vec.size() >=5 ){
                cout << vec [4]<< endl;
            } else {cout << "less than five numbers entered\n";}
        }

        else if (n <= vec[0]){ // если число наименьшее, ставим его в начало
            input_in_start (vec,n,vecSize);
       } else if (n > vec [vec.size()-1]){ // если число максимальное, то ставим его в конец
            input_in_end (vec,n,vecSize);
       }else { // иначе число где-то между
            input_between (vec,n);
       }
       //if (n!=-2 && n!= -1)output_vector (vec); // вывод вектора
    }
}

void input_in_start (vector <int>&vec, int n,int &vS){
    if (vS != 1) vec.resize (vec.size()+1); // увеличиваем размер вектора
    int temp = vec[0];
    for (int k =0; k < vec.size();k++) { // сдвигаем все числа вправо
        int temp2 = vec[k+1];
        vec[k+1] = temp;
        temp = temp2;
    }
    vec[0] = n; //  ставим наименьшее в начало
    vS++;
}

void output_vector (vector <int> vec){
    for (int i =0; i <vec.size (); i++){
        cout << vec[i] << " ";
    }
}
void input_in_end (vector <int>&vec, int n,int &vS){
    if (vS!=1) vec.resize (vec.size()+1);
    vec[vec.size()-1] = n;
    vS++;
}

void input_between (vector <int>&vec, int n){
    vec.resize (vec.size()+1);
    for (int j =0; j <vec.size();j++){
        if (n <= vec[j]) { //если число меньше очередного
            int temp = vec[j];
            for (int k = j+1; k < vec.size(); k++) { // сдвигаем все числа вправо
                int temp2 = vec[k];
                vec[k] = temp;
                temp = temp2;
                vec[j] = n;
            }
            break;
        }
    }
}