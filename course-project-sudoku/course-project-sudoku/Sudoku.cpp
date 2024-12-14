#include "Sudoku.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm> // Для random_shuffle

using namespace std;

// Конструктор
Sudoku::Sudoku(int difficulty) {
    grid.assign(9, vector<int>(9, 0));
    solution.assign(9, vector<int>(9, 0));
    initialGrid.assign(9, vector<bool>(9, false));

    srand(time(0)); // Ініціалізація генератора випадкових чисел
    generateSolvedSudoku(); // Генерація заповненої сітки
    generatePuzzle(difficulty); // Видалення чисел для створення головоломки
}

// Відображення Sudoku
void Sudoku::displayGrid() {
    cout << " -------------------------\n";
    for (int i = 0; i < 9; ++i) {
        cout << " | ";
        for (int j = 0; j < 9; ++j) {
            if (grid[i][j] == 0)
                cout << "  ";
            else
                cout << grid[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0)
            cout << " -------------------------\n";
    }
}

// Відображення розв'язку
void Sudoku::displaySolution() {
    cout << " -------------------------\n";
    for (int i = 0; i < 9; ++i) {
        cout << " | ";
        for (int j = 0; j < 9; ++j) {
            cout << solution[i][j] << " ";
            if ((j + 1) % 3 == 0)
                cout << "| ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0)
            cout << " -------------------------\n";
    }
}

// Вставка числа
bool Sudoku::insertNumber(int row, int col, int num) {
    if (row < 0 || row >= 9 || col < 0 || col >= 9 || num < 1 || num > 9)
        return false;

    if (initialGrid[row][col]) {
        cout << "Cannot modify initial numbers.\n";
        return false;
    }

    if (isValid(row, col, num)) {
        grid[row][col] = num;
        return true;
    }
    else {
        cout << "Invalid move. Number conflicts with Sudoku rules.\n";
        return false;
    }
}

// Видалення числа
bool Sudoku::removeNumber(int row, int col) {
    if (row < 0 || row >= 9 || col < 0 || col >= 9)
        return false;

    if (initialGrid[row][col]) {
        cout << "Cannot remove initial numbers.\n";
        return false;
    }

    grid[row][col] = 0;
    return true;
}

// Генерація заповненої Sudoku
bool Sudoku::generateSolvedSudoku() {
    fillGrid(); // Рекурсивне заповнення
    solution = grid; // Зберігаємо розв'язок
    return true;
}

// Рекурсивне заповнення сітки
bool Sudoku::fillGrid() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (grid[row][col] == 0) {
                vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                random_shuffle(nums.begin(), nums.end()); // Перемішуємо числа
                for (int num : nums) {
                    if (isValid(row, col, num)) {
                        grid[row][col] = num;
                        if (fillGrid())
                            return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Перевірка коректності вставки числа
bool Sudoku::isValid(int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == num || grid[i][col] == num)
            return false;
        if (grid[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == num)
            return false;
    }
    return true;
}

// Генерація головоломки
void Sudoku::generatePuzzle(int difficulty) {
    grid = solution; // Починаємо з повністю заповненої сітки
    int cellsToRemove = (difficulty == 1) ? 30 : (difficulty == 2) ? 40 : 50;

    while (cellsToRemove > 0) {
        int row = rand() % 9;
        int col = rand() % 9;
        if (grid[row][col] != 0) {
            grid[row][col] = 0;
            initialGrid[row][col] = false; // Видаляємо число
            --cellsToRemove;
        }
    }

    // Позначаємо всі невидалені числа як початкові
    for (int row = 0; row < 9; ++row)
        for (int col = 0; col < 9; ++col)
            if (grid[row][col] != 0)
                initialGrid[row][col] = true;
}