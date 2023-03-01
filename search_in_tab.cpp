#include <iostream>
#include <string>
#include <ctime>
#include <utility>

template <typename T, typename FUN>
size_t part(T* arr, size_t size, FUN f) {
    int st = 0;
    T tmp;
    int plc = 0;

    for (int i = 0; i < size; i++) {
        T el = arr[i];
        if (f(el)) {
            tmp = arr[plc];
            arr[plc] = arr[i];
            arr[i] = tmp;
            plc++;
            st++;
        }
    }
    
    return st;
}

template <typename T>
void printTab(const T* t, size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << t[i] << " ";
        if (i == size-1) {
            std::cout << "]" << std::endl;
        }
    }
}

bool isEven(int e) { return e % 2 == 0; }
bool isOdd(int e) { return e % 2 != 0; }
bool inRange(std::string e) { return e >= "Bea" && e <= "Sue"; }
bool isSevenD(int e) { return e % 7 == 0; }

int main() {
    size_t ind = 0;
    int a1[] = { 1,2,3,4,5,6 };
    ind = part(a1, 6, isEven);
    std::cout << "ind = " << ind << " [ ";
    printTab(a1, 6);

    int a2[] = { 1,2,3,4,5,6 };
    ind = part(a2, std::size(a2), isOdd);
    std::cout << "ind = " << ind << " [ ";
    printTab(a2, std::size(a2));

    std::string a3[] = { "Ala", "Ula", "Ela", "Ola", "Maja"};
    std::string mn = "Bea";
    std::string mx = "Sue";
    ind = part(a3, std::size(a3), inRange);
    std::cout << "ind = " << ind << " [ ";
    printTab(a3, std::size(a3));

    constexpr size_t DIM = 500000;
    int* a4 = new int[DIM];
    srand(unsigned(time(0)));
    for (size_t i = 0; i < DIM; ++i) a4[i] = rand() % 21 + 1;
    ind = part(a4, DIM, isSevenD);
    std::cout << "ind = " << ind << std::endl;
    delete[] a4;
}
