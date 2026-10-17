#include <iostream>

int main() {
    const int CAPACITY = 8;
    int window[8] = {};
    int kept = 0;
    int count = 0;

    if (!(std::cin >> count)) return 1;

    int write_pos = 0;
    for (int i = 0; i < count; ++i) {
        int value = 0;
        if (!(std::cin >> value)) return 1;
        window[write_pos % CAPACITY] = value;
        write_pos++;

        if (kept < CAPACITY) {
            ++kept;
        }
    }

    int last_idx = (write_pos - 1) % CAPACITY;
    int last = window[last_idx];

    int oldest_idx;
    if (kept < CAPACITY) {
        oldest_idx = 0;
    } else {
        oldest_idx = write_pos % CAPACITY;
    }
    int oldest = window[oldest_idx];

    long long sum = 0;
    for (int k = 0; k < kept; ++k) {
        int idx = (oldest_idx + k) % CAPACITY;
        sum += window[idx];
    }

    std::cout << "kept=" << kept << "\n";
    std::cout << "oldest=" << oldest << "\n";
    std::cout << "last=" << last << "\n";
    std::cout << "sum=" << sum << "\n";

    (void)CAPACITY;
    return 0;
}
