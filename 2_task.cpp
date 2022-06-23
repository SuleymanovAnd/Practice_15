//
// Created by Андрей on 22.06.2022.
//
#include <iostream>
using namespace std;



void search_for_syllables (){

    // судя по примеру массив отсортированный по возрастанию.
 cout << "Finde syllables in arrow:\n";
 int array [] = {2, 7, 11, 15};

 for (int i = 0; i < 4; i++){
     cout << array [i] << " ";
 }

 cout << endl;
 int sumNum = 9;
cout << "for number " << sumNum << endl<<endl;

 int indexMax = 3;
 int indexMin = 0;
 while ( indexMin < indexMax) {
     if (array[indexMin] + array [indexMax] == sumNum) {
        cout << "Number " << array[indexMin] << " + number " << array [indexMax] << " = " << sumNum;
        break;
     } else if (array[indexMin] + array [indexMax] > sumNum) {--indexMax;
     } else if (array[indexMin] + array [indexMax] < sumNum) { ++indexMin;
     } else {cout << "array does not contain required numbers!";}
 }
}

