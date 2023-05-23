#include <cstdlib>
#include <iostream>
#include <clocale>
#include <cmath>
#include <ctime>
#include  <iomanip>
#include <conio.h>


using namespace std;

int Size = 3;  

class officePack
{
public:  
    void add(string Name1, string manufacturer1, int quantity1, float price1)  
    {
        Name = Name1;
        manufacturer = manufacturer1;
        quantity = quantity1;
        price = price1;
    }

    string Name;  
    string manufacturer;
    int quantity;
    float price;
};

officePack* initialize()  
{
    officePack* mon = new officePack[Size];  

    mon[0].add("Office", "Microsoft", 4, 870);   
    mon[1].add("SmartSute", "Lotus", 5, 1020);
    mon[2].add("StarOffice", "Sun", 4, 9);

    return mon;  
}

void editRow(officePack* mon)  
{
    int editIndex = 0;  
    officePack monToInsert;  

    cout << "Введите номер строки, которую хотите изменить ";
    cin >> editIndex;  
    editIndex--;  

    cout << "Введите данные о товаре:" << endl;

    cout << "Название продукта: ";
    cin >> monToInsert.Name;  

    cout << "Производитель: ";
    cin >> monToInsert.manufacturer;

    cout << "Количество составных частей: ";
    cin >> monToInsert.quantity;

    cout << "Цена ($): ";
    cin >> monToInsert.price;

    mon[editIndex] = monToInsert;  
}



officePack* insertRow(officePack* mon)  
{
    officePack monToInsert;  

    cout << "Введите данные о товаре:" << endl;

    cout << "Название продукта: ";
    cin >> monToInsert.Name;  

    cout << "Производитель: ";
    cin >> monToInsert.manufacturer;

    cout << "Количество составных частей: ";
    cin >> monToInsert.quantity;

    cout << "Цена ($): ";
    cin >> monToInsert.price;

    officePack* NewArray = new officePack[Size + 1];  

    for (int i = 0; i < Size; i++)  
    {
        NewArray[i] = mon[i];

    }

    NewArray[Size] = monToInsert;  

    delete[] mon;  

    Size++;  

    return NewArray;  
}


void  printRow(officePack mon)  
{
    cout << " | " << mon.Name << setw(15 - mon.Name.length())  
        << " |   " << setw(10) << mon.manufacturer                               
        << "   | " << setw(23) << mon.quantity
        << " | " << setw(8) << mon.price
        << " | " << endl;
    cout << " --------------------------------------------------------------------" << endl;
}

void  printnote()  
{
    
    cout << " |  Примечание: возможно бесплатно получить продукт StarOffice через|" << endl;
    cout << " |  Internet                                                        |" << endl;
    cout << " --------------------------------------------------------------------" << endl;

}
void  printHeader()  
{
    cout << " --------------------------------------------------------------------" << endl;
    cout << " |                             Офисные пакеты                       |" << endl;
    cout << " --------------------------------------------------------------------" << endl;
    cout << " | Название   | Производитель  | Количество сост. сачтей | Цена ($) |" << endl;
    cout << " --------------------------------------------------------------------" << endl;
}

void  printTable(officePack* mon)  
{
    system("CLS");  
    printHeader();  

    for (int i = 0; i < Size; i++)  
    {
        printRow(mon[i]);
    }
    printnote();
}


officePack* deleteRow(officePack* mon)  
{
    int DeleteIndex = 0;
    cout << "Введите номер строки, которую хотите удалить ";
    cin >> DeleteIndex;
    DeleteIndex--;  

    officePack* NewArray = new officePack[Size - 1];  

    for (int i = 0; i < Size; i++)  
    {
        if (i < DeleteIndex)  
        {
            NewArray[i] = mon[i];
        }
        else if (i > DeleteIndex)   
        {
            NewArray[i - 1] = mon[i];
        }
    }

    delete[] mon;  

    Size--;  

    return NewArray;  
}

int  main(int argc, const  char* argv[])
{

    setlocale(LC_ALL, "Russian");

    officePack* mon = initialize();  

    printTable(mon);  

    mon = insertRow(mon);  

    printTable(mon);

    editRow(mon);  

    printTable(mon);

    mon = deleteRow(mon);  

    printTable(mon);

    
    

    return 0;
}

