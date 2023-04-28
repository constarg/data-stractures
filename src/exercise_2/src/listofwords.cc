#include "listofwords.hh"

using namespace ds_ex;

// TODO - constructor

Low &Low::insert_in_order(const std::string word, uint8_t file_id)
{
    Low_node *curr     = this->first;
    Low_node *new_node = NULL;

    while (curr->word < word && curr->next);
    // if there is already this word, then just increase how many times it apears.
    if (curr->next && curr->word == word) {
        ++curr->apear;
        // Store the file that contain this word in the lof.
        curr->low->insert_in_order(file_id);
    }

    // create a new node.
    new_node = new Low_node();
    new_node->word = word;
    new_node->next = NULL;
    // Create the associated list of file list.
    new_node->low = new ds_ex::Lof();
    // Store the file that contain this word in the lof.
    new_node->low->insert_in_order(file_id);

    if (!curr->next) {
        // If the new node stored at the end;
        curr->next = new_node;
    } else {
        // If the new node must stored in an other index
        new_node->next = curr->next;
        curr->next = new_node;
    }

    return *this;


    return *this;
}

bool Low::find(std::string &dst, int k) const
{
    Low_node *curr = this->first;
    int index = 0;
    while (index++ != k);
    if (index == k) {
        dst = curr->word;
        return true;
    } 

    return false;
}

bool Low::is_empty() const
{
    return (this->first == NULL)? true:false;
}

// TODO - destructor.