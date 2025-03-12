#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
std::ofstream out;
int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}

void shakerSort(int* arr, int n) {
    int left = 0;
    int right = n - 1;
    int lastSwap;
    int counter = 0;
    while (left < right) {
        counter += 1;
        if ((counter % 10) == 0){
        std::string str = std::to_string(counter);
        str = str + ".txt";
        out.open(str);
        for (int i = 0; i < n; i++){
        out << arr[i] << std::endl;
        }
        out.close();
        }
        lastSwap = left;

        //справа
        for (int i = left; i < right; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                lastSwap = i;
            }
        }
        right = lastSwap;

        //налево
        for (int i = right; i > left; --i) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                lastSwap = i;
            }
        }
        left = lastSwap;

    }
}

int main() {
    int n;

    std::cout << "Number of elements: ";
    std::cin >> n;

    //память под массив
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand_uns(-100, 100);
        std::cout << arr[i] << std::endl;;
    }

    shakerSort(arr, n);

    out.open("final_file.txt");
    for (int i = 0; i < n; i++) {
        out << arr[i] << std::endl;
    }
    out.close();
    std::cout << std::endl;

    delete[] arr;

    return 0;
}
