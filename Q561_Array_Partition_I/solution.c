/****  Begin Quick Sort  ****/
// divid the array
int partition(int * array, int low, int high) {
  int x = array[high];
  int i = low - 1;
  int j, temp;

  for (j = low; j < high; j++) {
    if (array[j] < x) {
      i += 1;
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  temp = array[high];
  array[high] = array[i+1];
  array[i+1] = temp;

  return i+1;
}

// quick sort main method
void quickSort(int * array, int low, int high) {
  if (low < high) {
    int q = partition(array, low, high);
    quickSort(array, low, q-1);
    quickSort(array, q+1, high);
  }
}
/****  End Quick Sort  ****/

int arrayPairSum(int* nums, int numsSize) {
    int sum = 0;
    int i;
    // sort the arry first
    quickSort(nums, 0, numsSize-1);
    for (i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            sum += nums[i];
        }
    }
    return sum;
}
