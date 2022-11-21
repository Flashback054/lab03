#include "DataGenerator.h"
#include "Sorts.h"
#include "Sorts_comp.h"
#include <map>
#include <iomanip>

typedef void (*normal_sort)(int*, int);
typedef void (*sort_comp)(int*, int, long long&);


map<string, normal_sort> normal_sorts{
    pair<string, normal_sort>("selection-sort",selectionSort),
    pair<string, normal_sort>("insertion-sort", insertionSort),
    pair<string, normal_sort>("bubble-sort",bubbleSort),
    pair<string, normal_sort>("heap-sort",heapSort),
    pair<string, normal_sort>("merge-sort",mergeSort),
    pair<string, normal_sort>("quick-sort",quickSort),
    pair<string, normal_sort>("radix-sort",radixSort),
    pair<string, normal_sort>("shaker-sort", shakerSort),
    pair<string, normal_sort>("shell-sort", shellSort),
    pair<string, normal_sort>("counting-sort", countingSort),
    pair<string, normal_sort>("flash-sort", flashSort)
};

map<string, sort_comp> sorts_comp{
    pair<string, sort_comp>("selection-sort",selectionSort_comp),
    pair<string, sort_comp>("insertion-sort", insertionSort_comp),
    pair<string, sort_comp>("bubble-sort",bubbleSort_comp),
    pair<string, sort_comp>("heap-sort",heapSort_comp),
    pair<string, sort_comp>("merge-sort",mergeSort_comp),
    pair<string, sort_comp>("quick-sort",quickSort_comp),
    pair<string, sort_comp>("radix-sort",radixSort_comp),
    pair<string, sort_comp>("shaker-sort", shakerSort_comp),
    pair<string, sort_comp>("shell-sort", shellSort_comp),
    pair<string, sort_comp>("counting-sort", countingSort_comp),
    pair<string, sort_comp>("flash-sort", flashSort_comp)
};


double calculateRuntime(string sort_name,int* a, int n) {
    void (*sort_function)(int*, int) = normal_sorts[sort_name];
    auto t = clock();
    sort_function(a, n);
    t = clock() - t;
    return double(t);
}


long long countComparisions(string sort_name, int* a, int n)
{
    long long comp_count = 0;
    sorts_comp[sort_name](a, n, comp_count);
    return comp_count;
}

void printArr(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}


string sort_names[11] = {
"selection-sort",
"insertion-sort",
"bubble-sort",
"heap-sort",
"merge-sort",
"quick-sort",
"radix-sort",
"shaker-sort",
"shell-sort",
"counting-sort",
"flash-sort"
};

int data_size[6] = { 10000, 30000, 50000, 100000, 300000, 500000 };

// ham chi dung de print experiment result
void printTable(int data_type) {
    cout << "------- DATA TYPE: " << data_type << "-------\n\n";
    // chay experiment cho 6 data size
    for (int sizeIndex = 0; sizeIndex < 6; sizeIndex++) {
        
        int n = data_size[sizeIndex];
        int* a = new int[n];
        cout << "---DATA SIZE: " << n << "---\n\n";

        // chay 11 sort
        for (int sortIndex = 0; sortIndex < 11; sortIndex++) {
            string sort_name = sort_names[sortIndex];
            // tinh runtime
            GenerateData(a, n, data_type);
            double runtime = calculateRuntime(sort_name,a,n);

            GenerateData(a, n, data_type);
            long long comparisions = countComparisions(sort_name, a, n);
            
            //in ket qua:
            cout << sort_name << ":\n";
            cout << "Runtime: " << runtime << "ms\n";
            cout << "Comparisions: " << comparisions << "\n\n";
        }
        delete[] a;
    }
    
}


int main()
{
    int data_order[4] = { 0,1,2,3 };
    // 0: random, 1: sorted, 2: reversed, 3: nearly-sorted, 
    // input data order

    // print experiment table cho data_order 0:random (test thoi)
    printTable(0);

    return 0;
}