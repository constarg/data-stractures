#ifndef LINKED_LIST_OF_WORDS
#define LINKED_LIST_OF_WORDS

#include <string>
#include <stdint.h>

#include "listoffiles.hh"

namespace ds_ex {
    class Low;
    
    /**
     * Node of the list of word
    */
    class Low_node 
    {
        friend Low;
        private:
            std::string word;    // The word
            int appear;          // This variable represent the times a word apeard
            ds_ex::Lof *lof;     // The list of files.
            Low_node *next;      // a pointer to the next element.
    };

    /**
     * The class below represents the list of words. This list 
     * used to store a word that was found in a file.
    */
    class Low
    {
        private:
            Low_node *first; // The first node of the linkedlist.
            int len;         // The length of the linkedlist.         
        public:
            // constructor.
            Low();
            // destructor.
            ~Low();
            /**
             * Insert the next file id in the right index, in order.
             * @param word The word to store in the list.
             * @param file_id The file that contain the word.
             * @return The instance in whitch the oparation was made
             */ 
            Low &insert_in_order(const std::string word, int file_id);
            /**
             * Find the k file id.
             * @param dst Where the data are stored.
             * @param k The file id to find.
             * @return true if the id exists in the list, otherwise false.
             */
            bool find(std::string &dst, int k) const;
            /**
             * @return the length of the list
            */
            int length() const;
            /**
             * @param word The word of interest.
             * @return How many times a word has appeared.
            */
            int get_appearance(const std::string word) const;
            /**
             * @param word The word of interest.
             * @return The number of files that the word appeared.
            */
            int get_number_of_files_appeared(const std::string word) const;
            /**
             * @param word The word of interest.
             * @return A pointer to an array that contains the file ids of 
             * the files that contains the word @word.
            */
            ds_ex::Lof *get_lof(const std::string word) const;
    };
}



#endif