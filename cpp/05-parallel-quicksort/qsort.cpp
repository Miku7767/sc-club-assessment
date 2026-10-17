#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <atomic>

std::atomic<int> active_threads(0);
const int MAX_THREADS = 4;
const int SERIAL_THRESHOLD = 4;

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void insertion_sort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void parallel_qsort(std::vector<int>& arr, int left, int right) {
    if (right - left + 1 <= SERIAL_THRESHOLD) {
        insertion_sort(arr, left, right);
        return;
    }

    int mid = partition(arr, left, right);

    bool can_spawn = false;
    if (active_threads.load() < MAX_THREADS) {
        active_threads.fetch_add(1);
        can_spawn = true;
    }

    if (can_spawn) {
        std::thread left_thread(parallel_qsort, std::ref(arr), left, mid - 1);
        parallel_qsort(arr, mid + 1, right);
        left_thread.join();
        active_threads.fetch_sub(1);
    } else {
        parallel_qsort(arr, left, mid - 1);
        parallel_qsort(arr, mid + 1, right);
    }
}

int main() {
    std::ifstream fin("data.txt");
    std::vector<int> arr;
    int num;
    while (fin >> num) {
        arr.push_back(num);
    }
    fin.close();

    int n = arr.size();
    parallel_qsort(arr, 0, n - 1);

    std::cout << "排序后结果：" << std::endl;
    for (int x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    bool is_sorted = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted) {
        std::cout << "✅ 正确性验证通过：数组完全有序" << std::endl;
    } else {
        std::cout << "❌ 验证失败：数组存在逆序" << std::endl;
    }

    return 0;
}
