/**
Sort array in order by inserting keys to the right place.
@return 1 if success
*/
int
InsertionSort(
    int *arr,
    int size)
{
    int i, j, key;

    for (j = 1; j < size; j++) {
        key = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }

    return 1;
}
