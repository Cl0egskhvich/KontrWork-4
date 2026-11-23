#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    const string listFile   = "list.txt";     // файл со списком
    const string outputFile = "output.txt";   // файл-приёмник

    // 1. Открываем файл со списком
    ifstream listIn(listFile);
    if (!listIn.is_open()) {
        cerr << "Не удалось открыть файл списка: " << listFile << endl;
        return 1;
    }

    // 2. Открываем файл-приёмник
    ofstream out(outputFile, ios::out | ios::trunc);
    if (!out.is_open()) {
        cerr << "Не удалось открыть выходной файл: " << outputFile << endl;
        return 1;
    }

    // 3. Читаем список и по очереди копируем содержимое
    string fileName;
    int copied = 0, skipped = 0;

    while (getline(listIn, fileName)) {
        if (fileName.empty()) continue;

        ifstream src(fileName, ios::binary);
        if (!src.is_open()) {
            cerr << "Пропущен (не открыт): " << fileName << endl;
            ++skipped;
            continue;
        }

        // Копируем содержимое побайтно (безопасно для любых файлов)
        out << src.rdbuf();

        cout << "Скопирован: " << fileName << endl;
        ++copied;

        src.close();
    }

    listIn.close();
    out.close();

    cout << "Готово. Скопировано файлов: " << copied
              << ", пропущено: " << skipped << endl;
    return 0;
}