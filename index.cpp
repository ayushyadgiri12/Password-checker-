#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to check password strength
string checkStrength(const string& pwd) {
    int score = 0;
    bool hasUpper = false, hasLower = false;
    bool hasDigit = false, hasSymbol = false;

    // Rule 1: Minimum length
    if (pwd.length() >= 8) score++;

    // Rule 2-5: Character type checks
    for (char c : pwd) {
        if (isupper(c))  hasUpper  = true;
        if (islower(c))  hasLower  = true;
        if (isdigit(c))  hasDigit  = true;
        if (ispunct(c))  hasSymbol = true;
    }

    if (hasUpper)  score++;
    if (hasLower)  score++;
    if (hasDigit)  score++;
    if (hasSymbol) score++;

    // Return strength category
    if (score <= 2) return "Weak";
    if (score == 3) return "Moderate";
    if (score == 4) return "Strong";
    return "Very Strong";
}

// Function to display detailed analysis
void showAnalysis(const string& pwd) {
    cout << "\n  Analysis:" << endl;
    cout << "  " << (pwd.length() >= 8 ? "[+]" : "[-]") << " Length >= 8 characters" << endl;

    bool hasUpper = false, hasLower = false;
    bool hasDigit = false, hasSymbol = false;

    for (char c : pwd) {
        if (isupper(c)) hasUpper = true;
        if (islower(c)) hasLower = true;
        if (isdigit(c)) hasDigit = true;
        if (ispunct(c)) hasSymbol = true;
    }

    cout << "  " << (hasUpper  ? "[+]" : "[-]") << " Contains uppercase letter" << endl;
    cout << "  " << (hasLower  ? "[+]" : "[-]") << " Contains lowercase letter" << endl;
    cout << "  " << (hasDigit  ? "[+]" : "[-]") << " Contains digit"            << endl;
    cout << "  " << (hasSymbol ? "[+]" : "[-]") << " Contains special character" << endl;
}

int main() {
    int choice;
    string password;

    do {
        // Display menu
        cout << "\n  ========================================" << endl;
        cout << "       Password Strength Checker          " << endl;
        cout << "  ========================================" << endl;
        cout << "  1. Check Password Strength"               << endl;
        cout << "  2. Exit"                                  << endl;
        cout << "  ----------------------------------------" << endl;
        cout << "  Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\n  Enter your password: ";
            cin >> password;

            showAnalysis(password);

            string strength = checkStrength(password);
            cout << "\n  Password Strength: " << strength << endl;

        } else if (choice != 2) {
            cout << "\n  Invalid choice! Please enter 1 or 2." << endl;
        }

    } while (choice != 2);

    cout << "\n  Goodbye!" << endl;
    return 0;
}