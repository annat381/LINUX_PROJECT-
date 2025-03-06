#include <iostream>
#include <chrono>
#include <random>
#include<string>
#include <fstream>
using namespace std;
const int length=1000;
int a[length];
int counter=0;
ofstream out;
int rand_uns(int min, int max) {
unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
static std::default_random_engine e(seed);
std::uniform_int_distribution<int> d(min, max);
return d(e);
}
void write_to_array(int arr[], int length, string filename)
{
    out.open(filename);
    for (int i = 0; i<length; i++){
        out<<to_string(arr[i]);
        out<<" ";

    }
    out.close();
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        counter+=1;
        if (counter%100==0){
            string str=to_string(counter);
            str= str+ ".txt";
        write_to_array(a, length, str);

        }
    }
}
int main() {

    for (int i = length; i > 0; i--){
        a[i] = rand_uns(1000, 10000);
    }
    auto start = std::chrono::high_resolution_clock::now();
    insertionSort(a, length);
    auto end = std::chrono::high_resolution_clock::now();
    auto nsec = end - start;
    std::cout << "Insertion sort: "<< nsec.count() << " nsec." << std::endl;
    std::cout<<counter;
    return 0;
}
