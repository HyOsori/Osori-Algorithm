
#define SWAP(X, Y) {X=X^Y; Y=X^Y; X=X^Y;}

/* insertion_sort.cc */
extern int InsertionSort(int *, int);

/* merge_sort.cc */
extern int MergeSort(int *, int);
extern void TopDownMergeSort(int*, int, int, int*);
extern void Merge(int*, int, int, int, int*);
extern void CopyArray(int *, int *, int, int);

/* quick_sort.cc */
extern void QuickSort(int *, int);
extern void LomutoQuickSort(int *, int, int);
extern int Partition(int *, int, int);

/* counting_sort.cc */
extern int FindLargest(int *, int);
extern void CountingSort(int *, int);
