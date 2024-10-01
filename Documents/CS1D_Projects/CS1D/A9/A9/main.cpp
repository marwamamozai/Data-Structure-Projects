//main file 
#include <iostream>
#include <fstream>
#include <string>


// Youre doing the sub cypher 
// Function to encrypt data
std::string encrypt(const std::string& input) {
    std::string output = input;
    for (char& c : output) {
        if (isalpha(c)) {
            if (islower(c)) c = 'a' + (c - 'a' + 3) % 26;  
            else c = 'A' + (c - 'A' + 3) % 26;            
        }
    }
    return output;
}

// Function to decrypt data
std::string decrypt(const std::string& input) {
    std::string output = input;
    for (char& c : output) {
        if (isalpha(c)) {
            if (islower(c)) c = 'a' + (c - 'a' - 3 + 26) % 26; 
            else c = 'A' + (c - 'A' - 3 + 26) % 26;           
        }
    }
    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./main encrypt|decrypt <filename>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string filename = argv[2];
    std::string data, processedData;
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    // Read entire file content
    data.assign((std::istreambuf_iterator<char>(inFile)),
                 std::istreambuf_iterator<char>());
    inFile.close();

    // Encrypt or decrypt based on the mode
    if (mode == "encrypt") {
        processedData = encrypt(data);
        std::ofstream outFile("encrypted.txt");
        outFile << processedData;
        outFile.close();
    } else if (mode == "decrypt") {
        processedData = decrypt(data);
        std::ofstream outFile("decrypted.txt");
        outFile << processedData;
        outFile.close();
    } else {
        std::cerr << "Invalid mode. Use 'encrypt' or 'decrypt'.\n";
        return 1;
    }

    return 0;
}
