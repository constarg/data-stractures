#ifndef LINKED_LIST_OF_FILES
#define LINKED_LIST_OF_FILES


namespace ds_ex {
    class Lof;

    /**
     * Node of the list of files
    */
    class Lof_node {
        friend Lof;
        private:
            int file_id;   // The number of the file.
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
            int len;         // The length of the linkedlist.    
        public:
            // constructor.
            Lof();
            // destructor.
            ~Lof();
            /**
             * Insert the next file id in the right index, in order.
             * @param file_id The file id to store in the list.
             * @return The instance in whitch the oparation was made
             */ 
            Lof &insert_in_order(const int file_id);
            /**
             * Find the k file id.
             * @param dst Where the data are stored.
             * @param k The file id to find.
             * @return true if the id exists in the list, otherwise false.
             */
            bool find(int &dst, int k) const;
            /**
             * @return the length of the list
            */
            int length() const;
    };
    
}



#endif