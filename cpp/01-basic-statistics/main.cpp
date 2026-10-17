#include <iostream>
int main() {
    int n;
    if (!(std::cin >> n)) return 1;

    int count = 0;
    long long sum = 0;
    int mn, mx;

    for (int i = 0; i < n; ++i) {
        int v;
        std::cin >> v;
        if (!std::cin) return 1;

        if(count == 0){
            mn = v;
            mx = v;
        }else{
            if(v < mn) mn = v;
            if(v > mx) mx = v;
        }
        sum += v;
        count ++;
    }

    std::cout << "count=" << count << "\n";
    std::cout << "sum=" << sum << "\n";
    std::cout << "min=" << mn << "\n";
    std::cout << "max=" << mx << "\n";

    return 0;
}
