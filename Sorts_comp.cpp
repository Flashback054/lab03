#include "Sorts_comp.h"

// --------- SORTS WITH COMPARISIONS -----------

void selectionSort_comp(int a[], int n, long long& comp)
{

    for (int i = 0; (++comp && i < n); i++)
    {

        int min_idx = i;

        for (int j = i + 1; (++comp && j < n); j++)
        {

            if (++comp && a[min_idx] > a[j])

                min_idx = j;
        }

        HoanVi(a[min_idx], a[i]);
    }
}

void insertionSort_comp(int* arr, int n, long long& compare)
{

    int key = 0;

    int j = 0;

    for (int i = 1; ++compare && i < n; i++)
    {

        key = arr[i];

        j = i - 1;

        while ((++compare && j >= 0) && (++compare && arr[j] > key))
        {

            swap(arr[j + 1], arr[j]);

            j = j - 1;
        }
    }
}

void bubbleSort_comp(int* arr, int n, long long& compare)
{

    for (int i = 0; ++compare && i < n; i++)
    {

        for (int j = 0; ++compare && j < n - 1; j++)
        {

            if (++compare && arr[j] > arr[j + 1])
            {

                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void heapify_comp(int* arr, int n, int pos, long long& compare)
{

    int largest = pos;

    int left = 2 * pos + 1;
    int right = 2 * pos + 2;


    if ((++compare && left < n) && (++compare && arr[left] > arr[largest]))
    {

        largest = left;

    }

    if ((++compare && right < n) && (++compare && arr[right] > arr[largest]))
    {

        largest = right;

    }

    if (++compare && largest != pos) {
        swap(arr[largest], arr[pos]);
        heapify_comp(arr, n, largest,compare);
    }
}

void heapSort_comp(int* arr, int n, long long& compare)
{

    for (int i = n / 2 - 1; ++compare && i >= 0; i--)
    {

        heapify_comp(arr, n, i, compare);
    }

    for (int i = n - 1; ++compare && i > 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify_comp(arr, i, 0, compare);
    }
}

void merge_comp(int* arr, int p, int q, int r, long long& comparisons)

{

    int n1 = q - p + 1;

    int n2 = r - q;

    int* arr_n1 = new int[n1];

    int* arr_n2 = new int[n2];

    for (int i = 0; (++comparisons, i < n1); i++)

        arr_n1[i] = arr[p + i];

    for (int i = 0; (++comparisons, i < n2); i++)

        arr_n2[i] = arr[q + 1 + i];

    int i = 0, j = 0, k = p;

    while ((++comparisons && i < n1) && (++comparisons && j < n2))

    {

        if (++comparisons && arr_n1[i] <= arr_n2[j])

        {

            arr[k] = arr_n1[i];

            ++i;
        }

        else

        {

            arr[k] = arr_n2[j];

            ++j;
        }

        ++k;
    }

    while (comparisons && i < n1)

    {

        arr[k] = arr_n1[i];

        ++i;

        ++k;
    }

    while (++comparisons && j < n2)

    {

        arr[k] = arr_n2[j];

        ++j;

        ++k;
    }
}

void mergeSort_comp(int* arr, int l, int r, long long& comparisons)

{

    if (++comparisons && l < r)

    {

        // chia nua mang

        // lap lai toi khi mang duoc chia nho chi chua 1 ptu

        // <-> subarr nay da dc sx

        int mid = (r + l) / 2;

        mergeSort_comp(arr, l, mid, comparisons);

        mergeSort_comp(arr, mid + 1, r, comparisons);

        // merge the sorted arr

        merge_comp(arr, l, mid, r, comparisons);
    }
}

// function overloading:
void mergeSort_comp(int* arr, int n, long long& comparisions)
{
    mergeSort_comp(arr, 0, n - 1, comparisions);
}

// QUICK sort with comparisons


void quickSort_comp(int* arr, int left, int right,long long &comparisions)
{
    if (++comparisions && left < right)
    {
        int pivot = arr[(left + right) / 2];
        int i = left;
        int j = right;

        while (++comparisions && i < j) {
            while (++comparisions && arr[i] < pivot)
                i++;
            while (++comparisions && arr[j] > pivot)
                j--;

            if (++comparisions && i <= j)
            {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        if (++comparisions && j > left)
            quickSort_comp(arr, left, j,comparisions);
        if (++comparisions && i < right)
            quickSort_comp(arr, i, right,comparisions);
    }
}

// function overloading:
void quickSort_comp(int* arr, int n, long long& comparisions)
{
    quickSort_comp(arr, 0, n - 1, comparisions);
}

// Radix sort
int get_max_element_comp(int* arr, int n, long long& comparisons)

{

    int max_element = arr[0];

    for (int i = 1; (++comparisons, i < n); i++)

    {

        ++comparisons;

        max_element = max(max_element, arr[i]);
    }

    return max_element;
}

void countingSortForRadix_comp(int* arr, int n, int place, long long& comparisons)
{

    const int num_digit = 10;

    int* count = new int[num_digit] {0};

    int* output = new int[n];

    for (int i = 0; (++comparisons, i < n); i++)

    {

        ++count[(arr[i] / place) % 10];
    }

    for (int i = 1; (++comparisons, i < num_digit); i++)

        count[i] += count[i - 1];

    // place element in sorted order

    for (int i = n - 1; (++comparisons, i >= 0); i--)

    {

        output[count[(arr[i] / place) % 10] - 1] = arr[i];

        --count[(arr[i] / place) % 10];
    }

    for (int i = 0; (++comparisons, i < n); i++)

        arr[i] = output[i];

    delete[] count;

    delete[] output;
}

void radixSort_comp(int* arr, int n, long long& comparisons)

{

    int max_element = get_max_element_comp(arr, n, comparisons);

    for (int i = 1; (++comparisons, max_element / i > 0); i *= 10)

    {

        countingSortForRadix_comp(arr, n, i, comparisons);
    }
}

void shakerSort_comp(int a[], int n, long long& comp)
{
    int i, j, k;
    for (i = 0; ++comp && i < n;)
    {
        bool swap = false;
        for (j = i + 1; ++comp && j < n; j++)
        {
            if (++comp&& a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
                swap = true;
            }
        }
        if (++comp && swap == false) // array is already in order
            return;

        n--;
        swap = false;
        for (k = n - 1; ++comp && k > i; k--)
        {
            if (++comp&& a[k] < a[k - 1])
            {
                HoanVi(a[k], a[k - 1]);
                swap = true;
            }
        }
        if (++comp && swap == false) // array is already in order
            return;
        i++;
    }
}
void shellSort_comp(int a[], int n, long long& comp)
{
    int gap, i, j, temp;
    for (gap = n / 2; ++comp && gap > 0; gap /= 2)
    {
        for (i = gap; ++comp && i < n; i++)
        {
            temp = a[i];
            for (j = i; (++comp && j >= gap) && (++comp && a[j - gap] > temp); j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}
void countingSort_comp(int a[], int n, long long& comp)
{
    int* output = new int[n];
    int max = a[0];

    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[i] > max)
            max = a[i];
    }

    int* count = new int[max + 1];
    for (int i = 0; ++comp && i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; ++comp && i < n; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; ++comp && i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comp && i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; ++comp && i < n; i++)
    {
        a[i] = output[i];
    }

    delete[] count;
    delete[] output;
}
void flashSort_comp(int a[], int n, long long& comp)
{
    int minVal = a[0];
    int maxIndex = 0;
    int m = int(0.45 * n);
    int* bucket = new int[m];
    for (int i = 0; ++comp && i < m; i++)
        bucket[i] = 0;
    for (int i = 1; ++comp && i < n; i++)
    {
        if (++comp && a[i] < minVal)
            minVal = a[i];
        if (++comp && a[i] > a[maxIndex])
            maxIndex = i;
    }
    if (++comp && a[maxIndex] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[maxIndex] - minVal);
    for (int i = 0; ++comp && i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++bucket[k];
    }
    for (int i = 1; ++comp && i < m; i++)
        bucket[i] += bucket[i - 1];
    HoanVi(a[maxIndex], a[0]);
    int moves = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (++comp && moves < n - 1)
    {
        while (++comp && j > bucket[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (++comp && k < 0)
            break;
        while (++comp && j != bucket[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --bucket[k]];
            a[t] = flash;
            flash = hold;
            ++moves;
        }
    }
    delete[] bucket;
    insertionSort_comp(a, n, comp);
}
