#ifndef SORT
#define SORT
#include "stringProcessor.h"
void swap(char** a, char** b)
{
     char* tmp = *a;
    *a = *b;
    *b = tmp;

}
inline void quick_sort_rec(char** arr, int left, int right)
{
    int i = left;
    int j = right;
    char* pivot = arr[(left + right) / 2];

    while (i <= j)
    {
        while (std::strcmp(arr[i], pivot) < 0)  // arr[i] < pivot
            ++i;

        while (std::strcmp(arr[j], pivot) > 0)  // arr[j] > pivot
            --j;

        if (i <= j)
        {
            char* tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            ++i;
            --j;
        }
    }

    if (left < j)
        quick_sort_rec(arr, left, j);
    if (i < right)
        quick_sort_rec(arr, i, right);
}
void quick_sort(char** arr, size_t length)
{
   if (length > 1)
        quick_sort_rec(arr, 0, static_cast<int>(length - 1));
}
#endif // !SORT