//#define SWAP(X, Y) {X=X^Y; Y=X^Y; X=X^Y;}

void swap(int*, int*);

void QuickSort(int *, int);
void LomutoQuickSort(int *, int, int);
int Partition(int *, int, int);

void
QuickSort(
    int *arr,
    int size)
{
    LomutoQuickSort(arr, 0, size - 1);
}

void
LomutoQuickSort(
    int *arr,
    int low,
    int high)
{
    if (low < high) {
        int p = Partition(arr, low, high);
        LomutoQuickSort(arr, low, p-1);
        LomutoQuickSort(arr, p+1, high);
    }
}

int
Partition(
    int *arr,
    int low,
    int high)
{
    int pivot;
    int i, j;

    pivot = arr[low];
    i = low;
    for (j = low+1; j <= high; j++) {
        if(arr[j] <= pivot) {
            i = i + 1;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[low], &arr[i]);

    return i;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
