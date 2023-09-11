#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "data.h"

using namespace std;

// Допоміжні глобальні змінни для фіксації кількості порівнянь та обмініві
int bucket_compare = 0;
int bucket_exchange = 0;

#define NBUCKET 10  // Кількість комірок
#define INTERVAL 10  // Ємність кожної комірки

struct Node {
  int data;
  struct Node *next;
};

void bucketSort(int arr[], int size);
struct Node *insertionSort(struct Node *list);
int getBucketIndex(int value);

// Алгоритм блочного сортування
void bucketSort(int arr[], int size) {
  int i, j;
  struct Node **buckets;

  // Створення комірок та розподілення пам'яті
  buckets = (struct Node **)malloc(sizeof(struct Node *) * NBUCKET);

  // Ініціалізація порожніх комірок
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = NULL;
  }

  // Наповнення комірок відповідними елементами
  for (i = 0; i < size; ++i) {
    struct Node *current;
    int pos = getBucketIndex(arr[i]);
    current = (struct Node *)malloc(sizeof(struct Node));
    current->data = arr[i];
    current->next = buckets[pos];
    buckets[pos] = current;
    bucket_exchange++;
  }

  // Сортування елементів кожної комірки методом включення
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = insertionSort(buckets[i]);
  }

  // Перенос відсортованих елементів в основний масив
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

  // Очистка комірок
  for (i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      struct Node *tmp;
      tmp = node;
      node = node->next;
      free(tmp);
    }
  }
  free(buckets);
  return;
}

// Алгоритм сортування включенням
struct Node *insertionSort(struct Node *list) {
  struct Node *k, *nodeList;
  if (list == 0 || list->next == 0) {
    return list;
  }

  nodeList = list;
  k = list->next;
  nodeList->next = 0;
  while (k != 0) {
    struct Node *ptr;
    if (nodeList->data > k->data) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = nodeList;
      nodeList = tmp;
      continue;
    }

    bucket_exchange++;

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      bucket_compare++;
      if (ptr->next->data > k->data) {
        break;
      }
    }

    if (ptr->next != 0) {
      struct Node *tmp;
      tmp = k;
      k = k->next;
      tmp->next = ptr->next;
      ptr->next = tmp;
      continue;
    } else {
      ptr->next = k;
      k = k->next;
      ptr->next->next = 0;
      continue;
    }
  }
  return nodeList;
}

// Визначення індексу комірки
int getBucketIndex(int value) {
  return value / INTERVAL;
}

// Запуск функції сортування підрахунком
void runBucketSort(int demo = 0) {

  string rawArray;

  switch(demo) {
    case 1:
      cout << "Bucket Sort - demo 1000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/bucket1000asc.txt");
      break;
    case 2:
      cout << "Bucket Sort - demo 1000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/bucket1000desc.txt");
      break;
    case 3:
      cout << "Bucket Sort - demo 1000 random" << endl;
      rawArray = randomArray(1000, 100);
      break;
    case 4:
      cout << "Bucket Sort - demo 10000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/bucket10000asc.txt");
      break;
    case 5:
      cout << "Bucket Sort - demo 10000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/bucket10000desc.txt");
      break;
    case 6:
      cout << "Bucket Sort - demo 10000 random" << endl;
      rawArray = randomArray(10000, 100);
      break;
    case 7:
      cout << "Bucket Sort - demo 100000 ASC" << endl;
      rawArray = arrayFromFile("testArrays/bucket100000asc.txt");
      break;
    case 8:
      cout << "Bucket Sort - demo 100000 DESC" << endl;
      rawArray = arrayFromFile("testArrays/bucket100000desc.txt");
      break;
    case 9:
      cout << "Bucket Sort - demo 100000 random" << endl;
      rawArray = randomArray(100000, 100);
      break;
    default:
      rawArray = handArray();
  }

  vector<int> futureArray = arrayFromInputInt(rawArray);
  int arr[futureArray.size()];
  for (int i=0; i < futureArray.size(); i++) { 
    arr[i] = futureArray[i];
  }
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Bucket Sort start" << endl;
  bucketSort(arr, n);
  outputFile(arr, n);

  cout << "Compares = " << bucket_compare << endl;
  cout << "Exchanges = " << bucket_exchange << endl;
  bucket_compare = 0;
  bucket_exchange = 0;

  return;
}

#endif