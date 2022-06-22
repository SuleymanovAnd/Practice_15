//
// Created by Андрей on 22.06.2022.
//
#include <iostream>


void search_largest_sum () {
    int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    std::cout << "Searching largest sum in array:\n";
    for (int i = 0; i < 9; i++) {
        std::cout << array[i] << " ";
    }

    std::cout << std::endl;

    int largest_sum = 0;
    int index_1 = 0;
    int index_2 = 0;

// проверяем сумму для диапазона элементов от размера массива до 2 элементов.
    for (int i = 9; i > 1; i--) { // диапазон i элементов
        for (int j = 0; j < 10 - i; j++) { // смещение диапазона от начала
            int sum = 0;
            for (int k = j; k < i + j; k++) { // прохождение по диапазону
                sum += array[k];
            }
            // наглядный вывод работы
            //std::cout << j << " / "<< (i-1)+j << " || " << sum << ". range = " << i <<std::endl;

            if (largest_sum < sum) {
                index_1 = j;
                index_2 = (i - 1) + j;
                largest_sum = sum;

                // std::cout << " larg = " << largest_sum << std::endl;
            }
        }
    }
        std::cout << "Largest sum = " << largest_sum << ". between index :" << index_1 << " & " << index_2 << std::endl;
}
