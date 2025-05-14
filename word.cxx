#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include "sortlib.h"
using namespace std;

namespace app {
    bool CLOCK = false; // 是否计时
}

// 排序函数，但是直接操作原数组
void sort(vector<string>& arr, void (*sortFunc)(vector<string>&)) {
    if (app::CLOCK) {
        clock_t start = clock(), end;
        sortFunc(arr);
        end = clock();
        cout << "排序耗时：" << fixed << setprecision(3) << (double)(end - start) / CLOCKS_PER_SEC << "秒" << endl;
    }
    else {
        sortFunc(arr);
        cout << "排序完成，未记录耗时。" << endl;
    }
}

int main() {
    ifstream inFile("1000_random.txt");
    if (!inFile) {
        cerr << "读取文件时：文件打开失败..." << endl;
        return 6;
    }
    vector<string> words;
    string word;
    while (inFile >> word) {
        words.push_back(word);
    }
    inFile.close();
    cout << "读取到单词数量：" << words.size() << endl;

    // 排序
    LABEL: 
    cout << "请选择排序算法：" << endl;
    cout << "1. 插入排序" << endl;
    cout << "2. 快速排序" << endl;
    cout << "3. 希尔排序" << endl;
    cout << "4. 归并排序" << endl;
    cout << "5. 堆排序" << endl;
    cout << "6. 不排序并退出程序..." << endl;

    int choice;
    cin >> choice;

    if (choice == 6) {
        cout << "正常退出..." << endl;
    }

    switch (choice) {
        case 1:
            sort(words, sortlib::insertionSort);
            break;
        case 2:
            sort(words, sortlib::quickSort);
            break;
        case 3:
            sort(words, sortlib::shellSort);
            break;
        case 4:
            sort(words, sortlib::mergeSort);
            break;
        case 5:
            sort(words, sortlib::heapifySort);
            break;
        default:
            cout << "无效的选择，请重新输入。" << endl;
            goto LABEL;
    }

    // 保存
    ofstream outFile("sorted_words.txt");
    if (!outFile) {
        cerr << "写入文件时：文件打开失败..." << endl;
        return 9;
    }
    for (const auto& w : words) {
        outFile << w << endl;
    }
    outFile.close();
    cout << "排序完成，已保存到 sorted_words.txt" << endl;
    return 0;
}