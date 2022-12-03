#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main () {
    std::vector<int> elves;

    std::ifstream input_file;
    input_file.open("input.txt");
    if (!input_file) {
        std::cout << "Unable to open file";
        return 1;
    }

    input_file.peek();
    std::vector<int> elf_coffer;
    while (!input_file.eof()) {

        std::string line;
        getline(input_file, line, '\n');

        if (line.length() == 0) {

            int elf_coffer_total = 0;
            for (int i : elf_coffer) {
                elf_coffer_total += i;
            }
            elves.push_back(elf_coffer_total);
            
            elf_coffer.clear();
            
            continue;
        }
        
        elf_coffer.push_back(std::stoi(line));
    }

    int largest_coffer = 0;
    for (int i : elves) {
        if (i > largest_coffer) {
            largest_coffer = i;
        }
    }

    std::cout << largest_coffer << std::endl;
    
    return 0;
}