#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;

    if (n % 2 == 0)
        cout << n << " — чётное" << endl;
    else
        cout << n << " — нечётное" << endl;

    return 0;
}