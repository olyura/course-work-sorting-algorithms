#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <iostream>
#include <vector>

#include "data.h"

using namespace std;

// Допоміжні глобальні змінни для фіксації кількості порівнянь та обмініві
int radix_compare = 0;
int radix_exchange = 0;

// Функція пошуку найбільшого значення в масиві
int getMaxRadix(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// Алгоритм сортування підрахунком для кожного окремого розряду
void countingForRasixSort(int array[], int size, int place) {
  
  // Ініціалізація вихідного масиву (розмір + 1)
  int output[size + 1];

  // Пошук найбільшого елемента масиву
  int max = (array[0] / place) % 10;
  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }

  // Ініціалізація масиву з лічильниками розміром (max+1)
  int count[max + 1];

  // Заповнення масиву з лічильниками значеннями 0
  for (int i = 0; i < max; ++i) {
    count[i] = 0;
  }

  // Підрахунок кожного елемента вхідного масиву у відповідному індексі масиву лічильників
  for (int i = 0; i < size; i++) {
    count[(array[i] / place) % 10]++;
    radix_exchange++;
  }

  // Кумулятивна сума всіх попередніх значень в масиві лічильників
  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  // Пошук індекса кожного елемента вхідного масива в масиві лічильників
  // Розміщення елементів в вихідний масив, декремент лічильника
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
    radix_compare++;
  }
  
  // Перенос відсортованих значень у вхідний масив
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Алгоритм порозрядного сортування
void radixSort(int array[], int size) { 
  // Пошук найбільшого елементу
  int max = getMaxRadix(array, size);
  
  // Застосування сортування підрахунком для впорядкування за кожним розрядом
  for (int place = 1; max / place > 0; place *= 10)
    countingForRasixSort(array, size, place);
}

// Запуск функції сортування підрахунком
void runRadixSort(int demo = 0) {

  string rawArray;

  switch(demo) {
    case 1:
      cout << "Radix Sort - demo 1000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/radix1000asc.txt");
      break;
    case 2:
      cout << "Radix Sort - demo 1000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/radix1000desc.txt");
      break;
    case 3:
      cout << "Radix Sort - demo 1000 random" << endl;
      rawArray = randomArray(1000, 1000);
      break;
    case 4:
      cout << "Radix Sort - demo 10000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/radix10000asc.txt");
      break;
    case 5:
      cout << "Radix Sort - demo 10000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/radix10000desc.txt");
      break;
    case 6:
      cout << "Radix Sort - demo 10000 random" << endl;
      rawArray = randomArray(10000, 1000);
      break;
    case 7:
      cout << "Radix Sort - demo 100000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/radix100000asc.txt");
      break;
    case 8:
      cout << "Radix Sort - demo 100000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/radix100000desc.txt");
      break;
    case 9:
      cout << "Radix Sort - demo 100000 random" << endl;
      rawArray = randomArray(100000, 1000);
      break;
    default:
      rawArray = handArray();
  }

  vector<int> futurArray = arrayFromInputInt(rawArray);
  int arr[futurArray.size()];
  for (int i=0; i < futurArray.size(); i++) { 
    arr[i] = futurArray[i];
  }
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Radix Sort start" << endl;
  radixSort(arr, n);
  outputFile(arr, n);

  cout << "Compares = " << radix_compare << endl;
  cout << "Exchanges = " << radix_exchange << endl;
  radix_compare = 0;
  radix_exchange = 0;

  return;
}

#endif