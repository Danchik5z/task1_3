#include <iostream>
#include <vector>

using namespace std;


vector<int> solution(int** mas, int a, int b) {
    vector<int> row_number_maximum;
    int cur_max = **mas;
    for (int i = 0; i < a; i++) {
        int max_in_row = **(mas + i);
        for (int j = 0; j < b; j++) {
            int cur = *(*(mas + i) + j);
            if (cur > max_in_row) {
                max_in_row = cur;
            }
        }
        if (max_in_row > cur_max) {
            row_number_maximum.clear();
            cur_max = max_in_row;
            row_number_maximum.push_back(i);
        }
        else if (max_in_row == cur_max) 
        {
            row_number_maximum.push_back(i);
        }
    }
    return row_number_maximum;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Количесвтво строк: ";
    cin >> a;
    cout << "Количесвтво столбцов: ";
    cin >> b;
    int** mas = new int* [a];
    for (int i = 0; i < a; i++) {
        mas[i] = new int[b];
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            *(*(mas + i) + j) = rand() % 9 + 1;
            cout << *(*(mas + i) + j) << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int n : solution(mas, a, b))
    {
        cout << n << " ";
    }
    cout << endl;
    for (int i = 0; i < a; i++) {
        delete[]mas[i];
    }
    delete[]mas;
    return 0;
}