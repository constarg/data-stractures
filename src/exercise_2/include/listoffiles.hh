#ifndef LINKED_LIST_OF_FILES
#define LINKED_LIST_OF_FILES

#include <stdint.h>

namespace ds_ex {
    class Lof;

    /**
     * Node of the list of files
    */
    class Lof_node {
        friend Lof;
        private:
            uint8_t file_id;   // The number of the file.
            Lof_node *next; // The next node.
    };      

    /**
     * The class below represents the list of files. This list 
     * used to store a number whitch is the file that contain
     * a certain word.
    */
    class Lof {
        private:
            Lof_node *first; // The first node of the linkedlist.            
        public:
            /**
             * Insert the next file id in the right index, in order.
             * @param file_id The file id to store in the list.
             * @return The instance in whitch the oparation was made
             */ 
            Lof &insert_in_order(const uint8_t file_id);
            /**
             * Find the k file id.
             * @param dst Where the data are stored.
             * @param k The file id to find.
             * @return true if the id exists in the list, otherwise false.
             */
            bool find(uint8_t &dst, int k) const;
            /**
             * Check if the list is empty
             * @param true if the list is empty, otherwise false.
             */
            bool is_empty() const;
    };
    
}



#endif