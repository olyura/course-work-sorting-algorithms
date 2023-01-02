// Сортування підрахунком
#include <stdio.h>

void countingSort(int array[], int size) {
  
  // Знаходимо найбільший елемент масиву
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  // Створюємо вихідний масив такого розміру, як і вхідний.
  int output[size];

  // Створюємо масив лічильника розміром (max+1)
  int count[max+1];

  // Initialize count array with all zeros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Find the index of each element of the original array in count array, and
  // place the elements in output array
  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an output array
void printOutput(int array[], int size) {  
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);    
  }
  printf("\n");
}

// Input array size cheker
int sizeCheck() {
  int size;
  scanf("%d", &size);
  if (size < 2) {
    printf("The number is too small, plase type a number from 2 to 9:\n");
    sizeCheck();
  } else if (size > 9) {
    printf("The number is too big, plase type a number from 2 to 9:\n");
    sizeCheck();
  }
  return size;  
}

// Driver code
int main(void) {
  int size;
 
  printf("333Enter the size of an array forom 2 to 9: \n");
  size = sizeCheck();
  printf("The size or your input array is %d.\n", size);

  // Creating input array
  int array[size];

  for (int i = 0; i < size; i++) {
    printf("Enter key %d of %d value: ", i + 1, size);
    scanf("%d", &array[i]);    
  }

  countingSort(array, size);
  printOutput(array, size); 

  system("pause"); //prevent console from closing automatically 

}