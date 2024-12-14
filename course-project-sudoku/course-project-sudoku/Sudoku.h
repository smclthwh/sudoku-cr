#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>

using namespace std;

class Sudoku {
private:
    vector<vector<int>> grid; // Поточна сітка Sudoku
    vector<vector<int>> solution; // Повністю розв'язана сітка
    vector<vector<bool>> initialGrid; // Чи є число початковим

    bool isValid(int row, int col, int num); // Перевірка, чи можна вставити число
    bool fillGrid(); // Рекурсивне заповнення сітки
    void generatePuzzle(int difficulty); // Генерація головоломки
    bool generateSolvedSudoku(); // Генерація повного розв'язання

public:
    Sudoku(int difficulty); // Конструктор з рівнем складності

    void displayGrid(); // Відображення Sudoku
    void displaySolution(); // Відображення розв'язання
    bool insertNumber(int row, int col, int num); // Вставка числа
    bool removeNumber(int row, int col); // Видалення числа
};

#endif // SUDOKU_H