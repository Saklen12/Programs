#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileEncryptor {
private:
    string filename;
    int encryptionKey;

    
    char encryptChar(char ch) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            return (ch - base + encryptionKey) % 26 + base;
        }
        return ch;
    }

   
    char decryptChar(char ch) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            return (ch - base - encryptionKey + 26) % 26 + base;
        }
        return ch;
    }

public:
    
    FileEncryptor(string fname, int key) {
        filename = fname;
        encryptionKey = key;
    }

    
    void encryptAndWrite(string message) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        for (char ch : message) {
            file << encryptChar(ch);
        }

        file.close();
        cout << "Message successfully encrypted and stored in " << filename << endl;
    }

    
    string readAndDecrypt() {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file for reading." << endl;
            return "";
        }

        string decryptedMessage;
        char ch;
        while (file.get(ch)) {
            decryptedMessage += decryptChar(ch);
        }

        file.close();
        return decryptedMessage;
    }

    
    void displayFileContents() {
        string message = readAndDecrypt();
        cout << "Decrypted Message: " << message << endl;
    }
};


int main() {
    FileEncryptor fe("data.txt", 3); 

    int choice;
    string message;

    do {
        cout << "\n=== File Encryptor Menu ===\n";
        cout << "1. Encrypt and Write Message\n";
        cout << "2. Read and Decrypt Message\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter a message to encrypt: ";
                getline(cin, message);
                fe.encryptAndWrite(message);
                break;
            case 2:
                cout << "Reading and decrypting file...\n";
                fe.displayFileContents();
                break;
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
