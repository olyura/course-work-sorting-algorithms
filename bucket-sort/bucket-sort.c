// Блочне сортування мовою C
#include <stdio.h>
#include <stdlib.h>

#define NBUCKET 10  // Кількість комірок
#define INTERVAL 10  // Ємність кожної комірки

struct Node {
  int data;
  struct Node *next;
};

void bucketSort(int arr[], int size);
struct Node *insertionSort(struct Node *list);
void printOutput(int arr[], int size);
void printBuckets(struct Node *list);
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
  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
  }

  // Сортування елементів кожної комірки методом включення
  for (i = 0; i < NBUCKET; ++i) {
    buckets[i] = insertionSort(buckets[i]);
  }

  // Демонстрація вмісту комірок після сортування, не обов'язково
  printf("-------------\n");
  printf("Buckets after sorting\n");
  for (i = 0; i < NBUCKET; i++) {
    printf("Bucket[%d]: ", i);
    printBuckets(buckets[i]);
    printf("\n");
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
void printOutput(int ar[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// Перебор вмісту комірки
void printBuckets(struct Node *list) {
  struct Node *cur = list;
  while (cur) {
    printf("%d ", cur->data);
    cur = cur->next;
  }
}

// Перевірка розміру вхідного масиву
int sizeCheck() {
  int size;
  scanf("%d", &size);  
  if (size < 2) {
    printf("The number is too small, type a number from 2 to 10:\n");
    sizeCheck();
  } else if (size > 10) {
    printf("The number is too big, type a number from 2 to 10:\n");
    sizeCheck();
  } else {
    return size;  
  }
}

// Головна функція
int main(void) {

  // Ініціалізація та перевірка розміру вхідного масиву
  int size;

  printf("Enter the size of an array from 2 to 10: \n");
  size = sizeCheck();
  printf("The size or your input array is %d.\n", size);
  printf("Enter the value of each key. Value must be a non-negative integer smaller than 100.\n");

  // Ініціалізація та заповнення вхідного масиву
  int array[size];

  for (int i = 0; i < size; i++) {
    printf("Enter key %d of %d value: ", i + 1, size);
    scanf("%d", &array[i]);    
  }

  bucketSort(array, size);
  printf("-------------\n");
  printf("Sorted array: ");
  printOutput(array, size);

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}