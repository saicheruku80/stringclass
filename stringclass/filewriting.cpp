#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    fstream fio;
    fio.open("sample.txt", ios::out);  // Open file for writing
    if (!fio.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    cout << "Enter lines of text (Ctrl+D to end input):" << endl;
    while (getline(cin, line)) {  // Correct usage of getline
        fio << line << endl;  // Write line to file
    }

    fio.close();
    return 0;
}
