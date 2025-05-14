#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <ctime>
#include "sortlib.h"
using namespace std;

// 可修改的参数
namespace app {
    int ARR_SIZE = 100;
    int INT_MAX = 10000;
    bool CLOCK = false;
}

// 格式化打印数组
void printArray(const vector<int>& arr) {
    for (int j = 0; j < app::ARR_SIZE;) {
        for (int i = 0; i < 20; i++) {
            cout << setw(8) << arr[j + i];
        }
        cout << endl;
        j += 20;
    }
}

// 排序并打印并计时
void sort(vector<int> arr, void (*sortFunc)(vector<int>&)) {
    if (app::CLOCK) {
        clock_t start = clock(), end;
        sortFunc(arr);
        end = clock();
        printArray(arr);
        cout << "排序耗时：" << fixed << setprecision(3) << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    }
    else {
        sortFunc(arr);
        printArray(arr);
        cout << "排序完成，未记录耗时。" << endl;
    }
}

// 主函数
int main(){
    cout << "部分参数于main.cxx的顶部定义 | 你可以修改之后重新编译并运行程序。" << endl;
    cout << "当前配置：数组大小 = " << app::ARR_SIZE << "，是否计时 = " << (app::CLOCK ? "是" : "否") << endl;
    cout << "开始生成随机数..." << endl;
    default_random_engine randint;
    uniform_int_distribution<int> dist(1, app::INT_MAX);
    vector<int> arr(app::ARR_SIZE);
    for (int i = 0; i < app::ARR_SIZE; i++) {
        arr[i] = dist(randint);
    }
    printArray(arr);
    cout << "随机数生成完毕，开始排序..." << endl;

    while (true) {
        cout << "请选择排序算法：" << endl;
        cout << "1. 插入排序" << endl;
        cout << "2. 快速排序" << endl;
        cout << "3. 希尔排序" << endl;
        cout << "4. 归并排序" << endl;
        cout << "5. 堆排序" << endl;
        cout << "6. 退出" << endl;

        int choice;
        cin >> choice;

        if (choice == 6) {
            break;
        }

        switch (choice) {
            case 1:
                sort(arr, sortlib::insertionSort);
                break;
            case 2:
                sort(arr, sortlib::quickSort);
                break;
            case 3:
                sort(arr, sortlib::shellSort);
                break;
            case 4:
                sort(arr, sortlib::mergeSort);
                break;
            case 5:
                sort(arr, sortlib::heapifySort);
                break;
            default:
                cout << "无效的选择，请重新输入。" << endl;
                continue;
        }
    }
    cout << "正常退出..." << endl;
    return 0;
}
