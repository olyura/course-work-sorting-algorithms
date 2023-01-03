// Сортування підрахунком мовою C
#include <stdio.h>

// Алгоритм сортування підрахунком
void countingSort(int array[], int size) {

  // Ініціалізація вихідного масив такого розміру, як і вхідний.
  int output[size];
  
  // Пошук найбільшого елемента масиву
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Ініціалізація масиву з лічильниками розміром (max+1)
  int count[max+1];

  // Заповнення масиву з лічильниками значеннями 0
  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }

  // Підрахунок кожного елемента вхідного масиву у відповідному індексі масиву лічильників
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
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
  }

  // Перенос відсортованих значень у вхідний масив
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Вивід відсортованих даних
void printOutput(int array[], int size) {
  printf("Sorted data:\n");  
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);    
  }
  printf("\n");
}

// Перевірка розміру вхідного масиву
int sizeCheck() {
  int size;
  scanf("%d", &size);  
  if (size < 2) {
    printf("The number is too small, type a number from 2 to 10:\n");
    sizeCheck();
  } else if (size > 9) {
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
  printf("Enter the value of each key. Value must be a non-negative integer.\n");

  // Ініціалізація та заповнення вхідного масиву
  int array[size];

  for (int i = 0; i < size; i++) {
    printf("Enter key %d of %d value: ", i + 1, size);
    scanf("%d", &array[i]);    
  }

  countingSort(array, size);
  printOutput(array, size); 

  // Запобігання передчасному закриттю консолі
  system("pause"); 
}