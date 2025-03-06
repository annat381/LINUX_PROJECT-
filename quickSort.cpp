/*»Ќ—“–” ÷»я:
    1. ƒл€ смены длины массива мен€ть const int length
    2. Ћучше ничего не трогать
    3. ƒл€ смены частоты записи массива мен€ть const int denominator
—пасибо.*/

#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
#include <string>
#include <random>
using namespace std;


int rand_uns(int min, int max)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}


ofstream out;

int counter = 0;
const int length = 10000;
const int denominator = 100;
int arr[length];

//-------------------------------------------

void write_array_to_file(int arr[], int length, string filename)
{
    out.open(filename);

    for (int i = 0; i < length; i++)
    {
        out << to_string(arr[i]);
        out << " ";
    }

    out.close();
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Place for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If current element is smaller than or equal to pivot
            i++;
            swap(arr[i], arr[j]); // Swap elements
        }
    }
    swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
    return i + 1; // Return the partition index

    //counter += 1;


}

void quickSort(int arr_[], int low, int high) {
    if (low < high) {
        int pi = partition(arr_, low, high); // Partitioning index

        // Recursively sort elements before and after partition
        quickSort(arr_, low, pi - 1);
        quickSort(arr_, pi + 1, high);

        counter += 1;

        if (counter % denominator == 0)
        {
            string str = to_string(counter);
            str = str + ".txt";

            write_array_to_file(arr, length, str);
        }
    }
}

//-------------------------------------------




int main()
{


    for (int i = 0; i < length; i++)
    {
        arr[i] = rand_uns(0, 10000);
    }

    //cout << arr[0] << endl << endl;

    quickSort(arr, 0, length);

    //cout << arr[0];

    write_array_to_file(arr, length, "final.cpp");

    //cout << endl << endl << counter;
}
