#include <iostream>
#include <algorithm> // Для sort()
#include <string> // Для ввода номеров пунктов
#include <fstream> // Для возможности работы с файлом

using namespace std;

int n; // Размерность матриц
string s; // ввод пункта меню с проверкой
char item;

void Init(int** m, const int n) // Инициализация матриц
{

    for (int i = 0; i < n; i++)
        m[i] = new int[n];
}

void Fill(int** m, const int n) // Заполнение матриц
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
}

void Output(int** m, const int n) // Вывод матрицы
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << m[i][j] << " ";
        cout << "\n";
    }
}

void Launch() // Ввод номера пункта
{
    getline(cin, s);
    item = s[0];
}

void Quit() // Выход из пунктов меню и при ошибках
{
    cout << "\nВыход: Нажмите цифру 0 и Enter для продолжения.\n";
    Launch();

    if (s.size() != 1)
    {
        cout << "\nВведённых символов слишком много или недостаточно. Напишите 0. Повторите попытку.";
        Quit();
    }
    else if (item != 48)
    {
        cout << "\nОшибка! Введённое число не равно нулю, повторите попытку.";
        Quit();
    }
}
void key1(int** A, int** B, int** C) // Консольный ввод
{
    cout << "Введите размер матриц:";
    cin >> n;

    if (n < 1)
    {
        cout << "Матрица данного размера не может быть создана! Измените размер!\n\n";
        key1;
    }
    else
    {
        system("cls"); // Очистка окна консоли
        cout << "Заполните матрицу А:" << endl;
        Init(A, n);
        Fill(A, n);

        system("cls");
        cout << "Заполните матрицу В:" << endl;
        Init(B, n);
        Fill(B, n);

        system("cls");
        cout << "Заполните матрицу С:" << endl;
        Init(C, n);
        Fill(C, n);
    }
}

void key2(int** A, int** B, int** C) // Файловый ввод
{
    ifstream file("Kurs.txt"); // Файл Kurs.txt открыт для считывания
    cout << "Открытие файла ";
    if (file.is_open())
    {
        cout << "прошло успешно." << endl;
        while (!file.eof())
        {
            file >> n;
            Init(A, n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    file >> A[i][j];

            Init(B, n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    file >> B[i][j];

            Init(C, n);
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    file >> C[i][j];

            cout << "Считывание файла прошло успешно!\n\n";
            break;
        }
    }
    else
    {
        cout << "не удалось. Произошла ошибка!\n\n";
    }

    file.close(); // Закрытие файла Kurs.txt
    Quit();
}

void key3(int** A, int** B, int** C) // Консольный вывод
{
    cout << "Выберите матрицу в которой следует изменить элемент, нажмите соответствующую клавишу:\n\n";
    cout << "1 - Вывести на экран матрицу А" << endl;
    cout << "2 - Вывести на экран матрицу В" << endl;
    cout << "3 - Вывести на экран матрицу С" << endl;

    Launch();

    system("cls");

    switch (item)
    {
        case 49:
        {
            cout << "Матрица А:\n";
            Output(A, n);
            Quit();
            break;
        }

        case 50:
        {
            cout << "Матрица В:\n";
            Output(B, n);
            Quit();
            break;
        }
        case 51:
        {
            cout << "Матрица С:\n";
            Output(C, n);
            Quit();
            break;
        }
        default:
        {
            cout << "Ошибка! Введённое число не соответствует ни одному из пунктов\n\n";
            Quit();
            break;
        }
    }
}

void key4(int** A, int** B, int** C) // Файловый вывод
{
    ofstream fout("Kurs.txt"); // файл Kurs.txt открыт для записи
    if (fout.is_open())
    {
        fout << n << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fout << A[i][j] << " ";
            }
            fout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fout << B[i][j] << " ";
            }
            fout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                fout << C[i][j] << " ";
            }
            fout << endl;
        }
        fout.close(); // Файл Kurs.txt закрыт
        cout << "Матрицы успешно записаны в файл " << endl;
    }
    else
    {
        cout << "Ошибка открытия файла " << endl;
    }
    Quit();
}

void key5(int** A, int** B, int** C) // Изменение элементов матрицы
{
    cout << "Выберите матрицу в которой следует изменить элемент, нажмите соответствующую клавишу:\n\n";
    cout << "1 - А\n";
    cout << "2 - В\n";
    cout << "3 - С\n";

    Launch();

    system("cls");
    cout << "Введите номер строки и номер столбца через пробел:\n";
    int row, col;
    cin >> row >> col;
    row--;
    col--;

    if (row < 0 || row >= n || col < 0 || col >= n)
        cout << "Ошибка!\n";
    else
    {
        cout << "Введите новый элемент:\n";
        switch (int(item))
        {
            case 49:
            {
                cin >> A[row][col];
                break;
            }
            case 50:
            {
                cin >> B[row][col];
                break;
            }
            case 51:
            {
                cin >> C[row][col];
                break;
            }
            default:
            {
                cout << "Выбран неверный пункт!\n";
                break;
            }
        }
    }
}

void key6(int** A, int** B) // Индивидуальное задание
{ //Объявялем новые массивы для сумм элементов столбцов матицы Б
    auto* B1 = new double[n];
    int sum_B = 0;
    int sum =0;
    //Заполняем массив суммой элементов столбцов матицы Б
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            sum_B += B[i][j];
        }
        B1[j] = sum_B ;
        sum_B = 0;
    }


    //Сравниваем элементы матриц и сумму
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "A[i][j] = " << A[i][j] << " B1[j] = " << B1[j] << endl;
            if (A[i][j] > B1[j]) {
                sum += 1;
            }
        }
    }
    cout << sum;

    cout << "Нажмите любую клавишу для продолжения.\n\n";
    Quit();
}

void menu() // Основное меню
{
    system("cls");
    cout << "1 - Консольный ввод матриц" << endl;
    cout << "2 - Файловый ввод матриц" << endl;
    cout << "3 - Консольный вывод матриц" << endl;
    cout << "4 - Файловый вывод матриц" << endl;
    cout << "5 - Изменение элементов" << endl;
    cout << "6 - Индивидуальное задание" << endl;
    cout << "7 - Выход из программы" << endl << endl;
    cout << "Выберите нужный пункт, нажав на клавишу от 1 до 7 и клавишу Enter: ";
}

int main()
{
    setlocale(LC_ALL, "rus"); // Подключение русского языка

    bool cycle = 1;

    menu();
    Launch();

    int** A = new int* [n], ** B = new int* [n], ** C = new int* [n]; // Объявление двумерных массивов/матриц

    while (cycle)
    {
        if (s.size() != 1)
        {
            system("cls");
            cout << "Введённое число должно соответствовать одному из пунктов. Использование чисел больше 7 или букв недопустимо.\n";
            cout << "Повторите попытку.\n";
            Quit();
            s.clear();
            item = ' ';
        }
        else
            switch (int(item))
            {
                case 49: // Консольный ввод
                {
                    system("cls");
                    key1(A, B, C);
                    item = ' ';
                    break;
                }
                case 50: // Файловый ввод
                {
                    system("cls");
                    key2(A, B, C);
                    item = ' ';
                    break;
                }
                case 51: // Консольный вывод
                {
                    system("cls");
                    key3(A, B, C);
                    item = ' ';
                    break;
                }
                case 52: // Файловый вывод
                {
                    system("cls");
                    key4(A, B, C);
                    item = ' ';
                    break;
                }
                case 53: // Изменение элементов матрицы
                {
                    system("cls");
                    key5(A, B, C);
                    system("cls");
                    menu();
                    Launch();
                    item = ' ';
                    break;
                }
                case 54: // Индивидуальное задание
                {
                    system("cls");
                    key6(A, B);
                    item = ' ';
                    break;
                }
                case 55: // Выход из программы
                {
                    cycle = 0;
                    break;
                }
                default: // Случай при нажатии неверной клавиши
                    system("cls");
                    cout << "Нажата клавиша не из диапазона 1-7.\n";
                    Quit();
                    item = ' ';
                    break;
            }

        menu();

        if (item == ' ') // Считывание введённых клавиш
            Launch();

        system("cls");
    }

    // Удаление указателей матриц
    for (int i = 0; i < n; i++)
        delete[] A[i];
    for (int i = 0; i < n; i++)
        delete[] B[i];
    for (int i = 0; i < n; i++)
        delete[] C[i];

    delete[] A;
    delete[] B;
    delete[] C;

    cout << "Программа завершена!\n";
    return 0;
}