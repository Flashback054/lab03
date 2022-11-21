#include "Sorts.h"

// ------- NORMAL SORT --------

// SELECTION SORT

void selectionSort(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {

        int min_idx = i;

        for (int j = i + 1; j < n; j++)
        {

            if (a[min_idx] > a[j])

                min_idx = j;
        }

        HoanVi(a[min_idx], a[i]);
    }
}

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        int key = a[i];
        while (a[k] > key && k >= 0)
        {
            a[k + 1] = a[k];
            k--;
        }
        a[k + 1] = key;
    }
}

// BUBBLE SORT

void bubbleSort(int* arr, int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {

            if (arr[j] > arr[j + 1])
            {

                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// HEAP SORT

void heapify(int* arr, int n, int pos)
{

    int largest = pos;

    int left = 2 * pos + 1;
    int right = 2 * pos + 2;


    if (left < n && arr[left] > arr[largest])
    {

        largest = left;

    }

    if (right < n && arr[right] > arr[largest] )
    {

        largest = right;

    }

    if (largest != pos) {
        swap(arr[largest], arr[pos]);
        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
    {

        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

// MERGE sort

void merge(int* arr, int p, int q, int r)

{

    int n1 = q - p + 1;

    int n2 = r - q;

    int* arr_n1 = new int[n1];

    int* arr_n2 = new int[n2];

    for (int i = 0; i < n1; i++)

        arr_n1[i] = arr[p + i];

    for (int i = 0; i < n2; i++)

        arr_n2[i] = arr[q + 1 + i];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)

    {

        if (arr_n1[i] <= arr_n2[j])

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

    while (i < n1)

    {

        arr[k] = arr_n1[i];

        ++i;

        ++k;
    }

    while (j < n2)

    {

        arr[k] = arr_n2[j];

        ++j;

        ++k;
    }
}

void mergeSort(int* arr, int l, int r)
{

    if (l < r)

    {

        // chia nua mang

        // lap lai toi khi mang duoc chia nho chi chua 1 ptu

        // <-> subarr nay da dc sx

        int mid = (r + l) / 2;

        mergeSort(arr, l, mid);

        mergeSort(arr, mid + 1, r);

        // merge the sorted arr

        merge(arr, l, mid, r);
    }
}

// function overloading
void mergeSort(int* arr, int n) {
    mergeSort(arr, 0, n - 1);
}

// QUICK sort

int patrition(int* arr, int low, int high)

{

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)

    {

        if (arr[j] <= pivot)

        {

            ++i;

            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(int* arr, int low, int high)

{

    if (low < high)

    {

        // divide arr -> smaller than pivot on the left and

        // larger than pivot on the right

        int pi = patrition(arr, low, high);

        // cout << pi << endl;

        // recursive call on the left and right of pivot

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

void quickSort(int* arr, int n) {
    quickSort(arr, 0, n - 1);
}

// RADIX sort

int get_max_element(int* arr, int n)

{

    int max_element = arr[0];

    for (int i = 1; i < n; i++)

        max_element = max(max_element, arr[i]);

    return max_element;
}

void countingSortForRadix(int* arr, int n, int place)
{

    const int num_digit = 10;

    int* count = new int[num_digit] {0};

    int* output = new int[n];

    for (int i = 0; i < n; i++)

    {

        ++count[(arr[i] / place) % 10];
    }

    for (int i = 1; i < num_digit; i++)

        count[i] += count[i - 1];

    // place element in sorted order

    for (int i = n - 1; i >= 0; i--)

    {

        output[count[(arr[i] / place) % 10] - 1] = arr[i];

        --count[(arr[i] / place) % 10];
    }

    for (int i = 0; i < n; i++)

        arr[i] = output[i];

    delete[] count;

    delete[] output;
}

void radixSort(int* arr, int n)

{

    int max_element = get_max_element(arr, n);

    for (int i = 1; max_element / i > 0; i *= 10)

    {
        countingSortForRadix(arr, n, i);
    }
}

void shakerSort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n;)
    {
        bool swap = false;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[j - 1])
            {
                HoanVi(a[j], a[j - 1]);
                swap = true;
            }
        }
        if (swap == false) // array is already in order
            return;

        n--;
        swap = false;
        for (k = n - 1; k > i; k--)
        {
            if (a[k] < a[k - 1])
            {
                HoanVi(a[k], a[k - 1]);
                swap = true;
            }
        }
        if (swap == false) // array is already in order
            return;
        i++;
    }
}

void shellSort(int a[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = a[i];
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
            {
                a[j] = a[j - gap];
            }
            a[j] = temp;
        }
    }
}

void countingSort(int a[], int n)
{
    int* output = new int[n];
    int max = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    int* count = new int[max + 1];
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }

    delete[] count;
    delete[] output;
}

void flashSort(int a[], int n)
{
    int minVal = a[0];
    int maxIndex = 0;
    int m = int(0.45 * n);
    int* bucket = new int[m];
    for (int i = 0; i < m; i++)
        bucket[i] = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < minVal)
            minVal = a[i];
        if (a[i] > a[maxIndex])
            maxIndex = i;
    }
    if (a[maxIndex] == minVal)
        return;
    double c1 = (double)(m - 1) / (a[maxIndex] - minVal);
    for (int i = 0; i < n; i++)
    {
        int k = int(c1 * (a[i] - minVal));
        ++bucket[k];
    }
    for (int i = 1; i < m; i++)
        bucket[i] += bucket[i - 1];
    HoanVi(a[maxIndex], a[0]);
    int moves = 0;
    int j = 0;
    int k = m - 1;
    int t = 0;
    int flash;
    while (moves < n - 1)
    {
        while (j > bucket[k] - 1)
        {
            j++;
            k = int(c1 * (a[j] - minVal));
        }
        flash = a[j];
        if (k < 0)
            break;
        while (j != bucket[k])
        {
            k = int(c1 * (flash - minVal));
            int hold = a[t = --bucket[k]];
            a[t] = flash;
            flash = hold;
            ++moves;
        }
    }
    delete[] bucket;
    insertionSort(a, n);
}

