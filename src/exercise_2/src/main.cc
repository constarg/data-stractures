#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <bits/stdc++.h>

#include "listofwords.hh"


static int order_of_files[] = {26, 94, 22, 40, 43, 24, 87, 44, 
                               31, 45, 6 , 49, 14, 53, 58, 33, 
                               74, 13, 19, 93, 55, 71, 39, 29, 
                               10, 80, 86, 77, 79, 82,  9, 92, 
                               17, 96, 50,  2, 65, 90, 89, 11, 
                               57, 51, 68, 83, 66, 54, 27, 95, 
                               48, 81, 70, 25,  4, 60, 21, 76, 
                               75, 61, 15, 37, 30, 62, 34, 56, 
                               88, 59,  1, 32,  3, 73, 78, 42, 
                               16, 36,  7, 47, 12, 67, 85, 64, 
                               28, 52, 84, 98, 69, 41, 63, 72, 
                               46, 20, 18,100, 97, 99, 23, 38, 
                               35, 91,  8,  5};


static void read_words_of(const std::string file_name, ds_ex::Low *low, int file_id)
{
    std::string path = "./input/"+file_name+".txt";
    std::ifstream file;
    std::string curr_word;
    file.open(path, std::ios::in);
    if (file.is_open()) {
        while (getline(file, curr_word, ' ')) {
            low->insert_in_order(curr_word, file_id);
        }
        file.close();
    }
}

int main(int argc, char *argv[])
{
    // Create a new List of words.
    ds_ex::Low *low = new ds_ex::Low();
    int presentage = 0;
    std::string user_input;
    ds_ex::Lof *lof;
    int curr_file;

    std::cout << "Retriving words..." << std::endl;

    for (int file_id : order_of_files) {
        // read each file with the order given in the order_of_files array.
        read_words_of(std::to_string(file_id), low, file_id);
        ++presentage;
        std::cout << "\33[2K\rProgress - " << presentage << "%" << std::flush;
    }
    std::cout << std::endl;
    std::cout << "Total words: " << low->length() << std::endl;

    // Request for a word from the user.
    while (!std::cin.eof()) {
        std::cout << "Next word: ";
        std::cin  >> user_input;
        std::transform(user_input.begin(), user_input.end(), user_input.begin(), ::toupper);
        std::cout << "The word '" << user_input      << "' appears " 
                  << low->get_appearance(user_input) << " times in "
                  << low->get_number_of_files_appeared(user_input) 
                  << " Documents." << "These documents are:" << std::endl;
        lof = low->get_lof(user_input);
        if (!lof) continue;
        for (int i = 0; i < lof->length(); i++) {
            if (lof->find(curr_file, i)) {
                std::cout << curr_file << ",";
            }
        }
        std::cout << std::endl;
    }

    delete low;
    return 0;
}