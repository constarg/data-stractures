#ifndef LINKED_LIST_OF_WORDS
#define LINKED_LIST_OF_WORDS

#include <string>
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
            int apear;      // This variable represent the times a word apeard
            ds_ex::Lof *low;       // The list of files.
            Low_node *next; // a pointer to the next element.
    };

    /**
     * The class below represents the list of words. This list 
     * used to store a word that was found in a file.
    */
    class Low
    {
        private:
            Low_node *first; // The first node of the linkedlist.            
        public:
            /**
             * Insert the next file id in the right index, in order.
             * @param word The word to store in the list.
             * @return The instance in whitch the oparation was made
             */ 
            Low &insert_in_order(const std::string word);
            /**
             * Find the k file id.
             * @param dst Where the data are stored.
             * @param k The file id to find.
             * @return true if the id exists in the list, otherwise false.
             */
            bool find(std::string &dst, int k) const;
            /**
             * Check if the list is empty
             * @param true if the list is empty, otherwise false.
             */
            bool is_empty() const;
    };
}



#endif