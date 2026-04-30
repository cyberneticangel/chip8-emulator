/* file_reader.cpp */

#include <fstream>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
    // Check if user gave us a file name
    char *program_name = argv[0];
    if(argc < 2) {
        cout << "Usage: " << program_name << " rom.ch8" << endl;
    }
    // Open the file
    char *rom_file = argv[1];
    ifstream file(rom_file, ios::binary);

    // Check if file opened successfully
    if(!file.is_open()) {
        cout << "Failed to open file " << rom_file << endl;
        return 1; // To be replaced by error handling
    }
    // Get file size and file content
    istream &end_pos = file.seekg(0, ios::end); // seekg() docs - https://en.cppreference.com/cpp/io/basic_istream/seekg
    int file_size = file.tellg(); // tellg() docs - 
    istream &begin_pos = file.seekg(0, ios::beg); // why do we not store them? food for thought

    // Create a vector of that size
    vector<unsigned char> rom_data(file_size); // unsigned char 0-255 bytes, vector is actually an object and (file_size) calls the constructor 

    // Read into vector
    file.read((char*)rom_data.data(), file_size); // return to this later
    cout << "Read " << rom_data.size() << " bytes" << endl;

    // Print the first 16 bytes as hex
    int count = min(16, (int)rom_data.size()); // what does min() do?
    for(int i = 0; i < count; i++) {
        cout << hex << (int)rom_data[i] << endl; // access index of our rom_data vector
    }
    cout << endl; // flushes the output buffer
    return 0;

}