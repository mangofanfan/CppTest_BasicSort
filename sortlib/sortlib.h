#ifndef SORTLIB_H
#define SORTLIB_H

#include <vector>
#include <string>

namespace sortlib {
    void insertionSort(std::vector<int>& arr);
    void insertionSort(std::vector<std::string>& arr);

    void quickSort(std::vector<int>& arr);
    void quickSort(std::vector<std::string>& arr);

    void shellSort(std::vector<int>& arr);
    void shellSort(std::vector<std::string>& arr);

    void mergeSort(std::vector<int>& arr);
    void mergeSort(std::vector<std::string>& arr);

    void heapifySort(std::vector<int>& arr);
    void heapifySort(std::vector<std::string>& arr);
}

#endif // SORTLIB_H