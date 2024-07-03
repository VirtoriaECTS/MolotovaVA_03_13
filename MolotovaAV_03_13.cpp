// MolotovaAV_03_13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Sclad
{
public:
    string name;
    int count;
    double price;
    string date;

    class Sclad(string _name, int _count, double _price, string _date) {
        name = _name;
        count = _count;
        price = _price;
        date = _date;
    }

private:

};

void WriteFile(vector<Sclad> vector) {
    ofstream file("text.txt");
    if (file.is_open()) {
        for (int i = 0; i < vector.size(); i++) {
            file << "Название товара " << vector[i].name<<" \n";
            file << "Количество товара " << vector[i].count << " \n";
            file << "Стоимость товара " << vector[i].price << " \n";
            file << "Дата поставки товара " << vector[i].date << " \n";
            file << "\n";
        }

        file.close();
    }
}

void ReadFile() {
    ifstream file("text.txt");
    if (file.is_open()) {
        
        string line;
        while (getline(file, line)) {
            cout << line << "\n";
        }

        file.close();
    }
}

Sclad AddTovar() {
    string name;
    int count;
    double price;
    string date;

    cout << "Введите название товара\n";
    cin >> name;
    cout << "Введите количество товара\n";
    cin >> count;
    cout << "Введите цену товара\n";
    cin >> price;
    cout << "Введите дату поставки\n";
    cin >> date;

    Sclad sclad = Sclad(name, count, price, date);
    return sclad;
}

vector<Sclad> SortMax(vector<Sclad> vec) {
    sort(vec.begin(), vec.end(), [](const Sclad& a, const Sclad& b) {
        return a.count < b.count;
        });
    return vec;
}

vector<Sclad> SortMin(vector<Sclad> vec) {
    sort(vec.begin(), vec.end(), [](const Sclad& a, const Sclad& b) {
        return a.count > b.count;
        });
    return vec;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    vector<Sclad> sclads;
    string action;
    while (true) {
        cout << "1 - добавление товара\n2 - показать товары\n3 - сортировка по возрастанию (сортировка по количеству)\n4 - сортировка по убыванию (сортировка по количеству)\n5 - выход\n";
        cin >> action;
        if (action == "1") {
            sclads.push_back(AddTovar());
            WriteFile(sclads);
        }
        else if (action == "2") {
            ReadFile();
        }
        else if (action == "3") {
            sclads = SortMax(sclads);
            WriteFile(sclads);
            ReadFile();

        }
        else if (action == "4") {
            sclads = SortMin(sclads);
            WriteFile(sclads);
            ReadFile();
        }
        else if (action == "5") {
            break;
        }
    
    }
   

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
