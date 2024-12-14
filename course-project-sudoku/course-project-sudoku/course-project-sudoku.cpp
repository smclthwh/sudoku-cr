#include <iostream>
#include "Sudoku.h"

using namespace std;

int main() {
    char restart = 'y';

    do {
        cout << "Welcome to Sudoku Generator and Solver!\n";
        cout << "Select difficulty level:\n";
        cout << "1. Easy\n2. Medium\n3. Hard\n";

        int level;
        cin >> level;

        while (cin.fail() || level < 1 || level > 3) {
            cout << "Invalid difficulty level. Enter a number from 1 to 3: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> level;
        }

        Sudoku sudoku(level);
        bool gameSolved = false;
        char choice;

        do {
            if (!gameSolved) {
                cout << "\nCurrent Sudoku:\n";
                sudoku.displayGrid();
                cout << "\nOptions:\n";
                cout << "1. Solve\n";
                cout << "2. Insert Number\n";
                cout << "3. Remove Number\n";
                cout << "4. Exit\n";

                cin >> choice;

                while (cin.fail() || (choice != '1' && choice != '2' && choice != '3' && choice != '4')) {
                    cout << "Invalid choice. Enter a number from 1 to 4: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> choice;
                }

                if (choice == '1') {
                    sudoku.displaySolution();
                    gameSolved = true;
                }
                else if (choice == '2') {
                    int row, col, num;
                    cout << "Enter row (1-9): ";
                    cin >> row;

                    while (cin.fail() || row < 1 || row > 9) {
                        cout << "Invalid row. Please enter a number from 1 to 9: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> row;
                    }

                    cout << "Enter column (1-9): ";
                    cin >> col;

                    while (cin.fail() || col < 1 || col > 9) {
                        cout << "Invalid column. Enter a number from 1 to 9: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> col;
                    }

                    cout << "Enter number (1-9): ";
                    cin >> num;

                    while (cin.fail() || num < 1 || num > 9) {
                        cout << "Invalid number. Please enter a number from 1 to 9: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> num;
                    }

                    if (!sudoku.insertNumber(row - 1, col - 1, num)) {
                        cout << "Could not insert number.\n";
                    }
                }
                else if (choice == '3') {
                    int row, col;
                    cout << "Enter row (1-9): ";
                    cin >> row;

                    while (cin.fail() || row < 1 || row > 9) {
                        cout << "Invalid row. Please enter a number from 1 to 9: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> row;
                    }

                    cout << "Enter column (1-9): ";
                    cin >> col;

                    while (cin.fail() || col < 1 || col > 9) {
                        cout << "Invalid column. Enter a number from 1 to 9: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cin >> col;
                    }

                    if (!sudoku.removeNumber(row - 1, col - 1)) {
                        cout << "Could not delete number.\n";
                    }
                }
                else if (choice == '4') {
                    restart = 'n';
                    break;
                }
            }
            else {
                cout << "\nOptions:\n";
                cout << "1. Try again\n";
                cout << "2. Exit\n";

                cin >> choice;

                while (cin.fail() || (choice != '1' && choice != '2')) {
                    cout << "Invalid choice. Enter 1 or 2: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin >> choice;
                }

                if (choice == '1') {
                    restart = 'y';
                    break;
                }
                else if (choice == '2') {
                    restart = 'n';
                    break;
                }
            }
        } while (restart == 'y');

    } while (restart == 'y');

    cout << "Goodbye!\n";
    return 0;
}
