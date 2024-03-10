#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Структура для хранения информации о телевизоре
struct TV {
    string brand;
    float size;
    float price;
};

int main() {
    setlocale(LC_ALL, "RU");
    // Создание и запись информации в бинарный файл
    ofstream file("tv_data.bin",ios::binary);

    // Пример данных о телевизорах для записи
    TV tv1 = { "Samsung", 40.0, 500.0 };
    TV tv2 = { "Samsung", 32.0, 400.0 };
    TV tv3 = { "Samsung", 42.0, 600.0 };

    // Запись данных в файл
    file.write((char*)&tv1, sizeof(tv1));
    file.write((char*)&tv2, sizeof(tv2));
    file.write((char*)&tv3, sizeof(tv3));

    file.close();

    // Поиск и печать информации о телевизорах фирмы "Samsung" размером более 32 дюймов
    ifstream read_file("tv_data.bin",ios::binary);
    int count = 0;
    TV tv_read;
    while (read_file.read((char*)&tv_read, sizeof(tv_read))) {
        if (tv_read.brand == "Samsung" and tv_read.size > 32.0) {
            count += 1;
            cout << "Фирма: " << tv_read.brand << endl;
            cout << "Размер: " << tv_read.size << endl;
            cout << "Стоимость: " << tv_read.price << endl;
            cout << endl;
        }
    }

    read_file.close();
    cout << "Количество телевизоров размером более 32: " << count << endl;
    return 0;
}