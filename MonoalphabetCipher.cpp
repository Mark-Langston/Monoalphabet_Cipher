#include <iostream>
#include <fstream>
#include <string>

// Function to encrypt the text
void encrypt_text(std::string& text) {
    for (char& c : text) {
        if (std::isalpha(c)) {
            // Convert to uppercase and apply letter substitution
            c = std::toupper(c);
            c = 'Z' - (c - 'A');
        }
    }
}

int main() {
    // Ask the user if they want to create a new file and encrypt it
    std::cout << "Do you want to create a new file and encrypt it? [if you enter n, you can decrypt a file instead] (y/n): ";
    char choice;
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        // Encrypt text and save to encrypted.txt

        // Get user input for the text to encrypt
        std::string input_text;
        std::cout << "Enter the text to encrypt: ";
        std::cin.ignore(); // Clear input buffer
        std::getline(std::cin, input_text);

        // Encrypt the input text
        encrypt_text(input_text);

        // Save the encrypted text to a file named "encrypted.txt"
        std::ofstream out_file("encrypted.txt");
        if (out_file.is_open()) {
            out_file << input_text;
            out_file.close();

            // Print a success message and the encrypted text to the console
            std::cout << "File has been encrypted and saved as encrypted.txt\n";
            std::cout << "Encrypted Text:\n" << input_text << std::endl;
        }
        else {
            // Print an error message if unable to open the file for writing
            std::cerr << "Error: Unable to open file for writing!\n";
        }
    }
    else if (choice == 'n' || choice == 'N') {
        // Decrypt text from a file

        // Get the file name from the user
        std::string file_name;
        std::cout << "Enter the file name to decrypt: ";
        std::cin >> file_name;

        // Open the file for reading
        std::ifstream in_file(file_name);
        if (in_file.is_open()) {
            // Read the encrypted text from the file
            std::string encrypted_text;
            std::getline(in_file, encrypted_text);
            in_file.close();

            // Decrypt the text
            encrypt_text(encrypted_text);

            // Print the decrypted text to the console
            std::cout << "Decrypted Text:\n" << encrypted_text << std::endl;
        }
        else {
            // Print an error message if unable to open the file for reading
            std::cerr << "Error: Unable to open file for reading\n";
        }
    }
    else {
        // Print an error message for an invalid choice
        std::cerr << "Invalid choice. Please enter 'y' to encrypt or 'n' to decrypt.\n";
    }

    return 0;
}