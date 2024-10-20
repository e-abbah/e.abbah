#include <iostream>
#include <string>
using namespace std;

char encrypt(char e, int b) {
    char letter = e; // Default to returning the original character

    if (isalpha(e)) {
        e = tolower(e);
        int position = e - 'a'; // 0-25 range

        position = (position + b) % 26; // Shift and wrap around
        letter = 'a' + position; // Convert back to char
    }
    return letter;
}

char decrypt(char e, int b) {
    char letter = e; 

    if (isalpha(e)) {
        e = tolower(e);
        int position = e - 'a'; // 0-25 range

        position = (position - b + 26) % 26; // Shift back and wrap around
        letter = 'a' + position; // Convert back to char
    }
    return letter;
}

int main() {
    int choice;
    int b;

    cout << "Do you want to encrypt or decrypt?\nEnter 1 to Encrypt or Enter 2 to Decrypt: ";
    cin >> choice;

    // Ask for the shift value
    cout << "Enter shift value: ";
    cin >> b;

    cin.ignore(); // Clear the newline left in the input buffer

    string input;

    switch (choice) {
        case 1:
            cout << "Enter text: ";
            getline(cin, input); // Read a full line

            cout << "Encrypted text: ";
            for (char e : input) {
                cout << encrypt(e, b);
            }
            cout << endl;
            break;

        case 2:
            cout << "Enter text: ";
            getline(cin, input); // Read a full line

            cout << "Decrypted text: ";
            for (char e : input) {
                cout << decrypt(e, b);
            }
            cout << endl;
            break;

        default:
            cout << "Enter a valid option\n";
            break;
    }

    return 0;
}
