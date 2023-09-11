#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include <iostream>
#include <vector>

#include "data.h"

using namespace std;

// Допоміжні глобальні змінни для фіксації кількості порівнянь та обмініві
int counting_compare = 0;
int counting_exchange = 0;

// Сортування підрахунком
void countingSort(int array[], int size) {

  // Ініціалізація вихідного масиву
  int output[size];
  
  // Пошук найбільшого елемента масиву
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
      //counting_compare++;
  }

  // Ініціалізація масиву з лічильниками розміром (max+1)
  int count[max + 1];

  // Заповнення масиву з лічильниками значеннями 0
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Підрахунок кожного елемента вхідного масиву у відповідному індексі масиву лічильників
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
    counting_exchange++;
  }

  // Кумулятивна сума всіх попередніх значень в масиві лічильників
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Пошук індекса кожного елемента вхідного масива в масиві лічильників
  // Розміщення елементів в вихідний масив, декремент лічильника
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
    counting_compare++;
  }

  // Перенос відсортованих значень у вхідний масив
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Запуск функції сортування підрахунком
void runCountingSort(int demo = 0) {

  string rawArray;

  switch(demo) {
    case 1:
      cout << "Counting Sort - demo 1000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/counting1000asc.txt");
      break;
    case 2:
      cout << "Counting Sort - demo 1000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/counting1000desc.txt");
      break;
    case 3:
      cout << "Counting Sort - demo 1000 random" << endl;
      rawArray = randomArray(1000, 10);
      break;
    case 4:
      cout << "Counting Sort - demo 10000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/counting10000asc.txt");
      break;
    case 5:
      cout << "Counting Sort - demo 10000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/counting10000desc.txt");
      break;
    case 6:
      cout << "Counting Sort - demo 10000 random" << endl;
      rawArray = randomArray(10000, 10);
      break;
    case 7:
      cout << "Counting Sort - demo 100000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/counting100000asc.txt");
      break;
    case 8:
      cout << "Counting Sort - demo 100000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/counting100000desc.txt");
      break;
    case 9:
      cout << "Counting Sort - demo 100000 random" << endl;
      rawArray = randomArray(100000, 10);
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

  cout << "Counting Sort start" << endl;
  countingSort(arr, n);
  outputFile(arr, n);

  cout << "Compares = " << counting_compare << endl;
  cout << "Exchanges = " << counting_exchange << endl;
  counting_compare = 0;
  counting_exchange = 0;

  return;
}

#endif