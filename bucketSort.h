#ifndef BUCKETSORT_H
#define BUCKETSORT_H

#include <iostream>
#include <iomanip>
#include <vector>

#include "data.h"

using namespace std;

#define NBUCKET 10  // Кількість комірок
#define INTERVAL 10  // Ємність кожної комірки

struct Node {
  int data;
  struct Node *next;
};

void bucketSort(int arr[], int size);
struct Node *insertionSort(struct Node *list);
/* void printOutput(int arr[], int size); */
/* void printBuckets(struct Node *list); */
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
  }

  // Демонстрація комірок та їх вмісту, не обов'язково
  /* for (i = 0; i < NBUCKET; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  } */

  // Сортування елементів кожної комірки методом включення
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = insertionSort(buckets[i]);
  }

  // Демонстрація вмісту комірок після сортування, не обов'язково
  /* cout << "-------------" << endl;
  cout << "Buckets after sorting" << endl;
  for (i = 0; i < NBUCKET; i++) {
    cout << "Bucket[" << i << "] : ";
    printBuckets(buckets[i]);
    cout << endl;
  } */

  // Перенос відсортованих елементів в основний масив
  for (j = 0, i = 0; i < NBUCKET; ++i) {
    struct Node *node;
    node = buckets[i];
    while (node) {
      arr[j++] = node->data;
      node = node->next;
    }
  }

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

    for (ptr = nodeList; ptr->next != 0; ptr = ptr->next) {
      if (ptr->next->data > k->data)
        break;
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

// Вивід відсортованих даних
/* void printOutput(int ar[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d ", ar[i]);
  }
  cout << endl;
} */

// Перебор вмісту комірки
/* void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    cout << setw(3) << cur->data;
    cur = cur->next;
  }
} */

// Запуск функції сортування підрахунком
void runBucketSort(int demo = 0) {

  string rawArray;

  switch(demo) {
    case 1:
      cout << "Bucket Sort - demo 1000 ASC" << endl;
      rawArray = bucket1000asc();
      break;
    case 2:
      cout << "Bucket Sort - demo 1000 DESC" << endl;
      rawArray = bucket1000desc();
      break;
    case 3:
      cout << "Bucket Sort - demo 1000 random" << endl;
      rawArray = randomArray(1000, 100);
      break;
    case 4:
      cout << "Bucket Sort - demo 10000 ASC" << endl;
      rawArray = bucket10000asc();
      break;
    case 5:
      cout << "Bucket Sort - demo 10000 DESC" << endl;
      rawArray = bucket10000desc();
      break;
    case 6:
      cout << "Bucket Sort - demo 10000 random" << endl;
      rawArray = randomArray(10000, 100);
      break;
    case 7:
      cout << "Bucket Sort - demo 100000 ASC" << endl;
      rawArray = bucket100000asc();
      break;
    case 8:
      cout << "Bucket Sort - demo 100000 DESC" << endl;
      rawArray = bucket100000desc();
      break;
    case 9:
      cout << "Bucket Sort - demo 100000 random" << endl;
      rawArray = randomArray(100000, 100);
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

  cout << "Bucket Sort start" << endl;
  bucketSort(arr, n);
  outputFile(arr, n);

  return;

  //reverse
  /* int revArr[n];
  for (int i = 0; i < n; i++) {
    revArr[i] = arr[n - 1 - i];
  }
  outputFile(revArr, n) */;
  //

}

#endif