#include "sortlib.h"
#include <vector>
#include <string>

// 所有排序方法均直接操作传入的数组
namespace sortlib {
    // 插入排序
    void insertionSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    void insertionSort(std::vector<std::string>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            std::string key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }

    // 快速排序
    void quickSort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;

        int pivot = arr[arr.size() / 2];
        std::vector<int> left, right;
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size() / 2) continue;
            if (arr[i] < pivot) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }

        quickSort(left);
        quickSort(right);

        arr.clear();
        arr.insert(arr.end(), left.begin(), left.end());
        arr.push_back(pivot);
        arr.insert(arr.end(), right.begin(), right.end());
    }

    void quickSort(std::vector<std::string>& arr) {
        if (arr.size() <= 1) return;

        std::string pivot = arr[arr.size() / 2];
        std::vector<std::string> left, right;
        for (int i = 0; i < arr.size(); i++) {
            if (i == arr.size() / 2) continue;
            if (arr[i] < pivot) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }

        quickSort(left);
        quickSort(right);

        arr.clear();
        arr.insert(arr.end(), left.begin(), left.end());
        arr.push_back(pivot);
        arr.insert(arr.end(), right.begin(), right.end());
    }

    // 希尔排序
    void shellSort(std::vector<int>& arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    void shellSort(std::vector<std::string>& arr) {
        int n = arr.size();
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                std::string temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }
                arr[j] = temp;
            }
        }
    }

    // 归并排序
    void mergeSort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;

        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        mergeSort(left);
        mergeSort(right);

        arr.clear();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr.push_back(left[i]);
                i++;
            } else {
                arr.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            arr.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            arr.push_back(right[j]);
            j++;
        }
    }

    void mergeSort(std::vector<std::string>& arr) {
        if (arr.size() <= 1) return;

        int mid = arr.size() / 2;
        std::vector<std::string> left(arr.begin(), arr.begin() + mid);
        std::vector<std::string> right(arr.begin() + mid, arr.end());

        mergeSort(left);
        mergeSort(right);

        arr.clear();
        int i = 0, j = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr.push_back(left[i]);
                i++;
            } else {
                arr.push_back(right[j]);
                j++;
            }
        }
        while (i < left.size()) {
            arr.push_back(left[i]);
            i++;
        }
        while (j < right.size()) {
            arr.push_back(right[j]);
            j++;
        }
    }

    // 堆排序
    static void heapify(std::vector<int>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapifySort(std::vector<int>& arr) {
        int n = arr.size();

        // 构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 逐步将堆顶元素移到数组末尾并调整堆
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    static void heapify(std::vector<std::string>& arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void heapifySort(std::vector<std::string>& arr) {
        int n = arr.size();

        // 构建最大堆
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // 逐步将堆顶元素移到数组末尾并调整堆
        for (int i = n - 1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
}
