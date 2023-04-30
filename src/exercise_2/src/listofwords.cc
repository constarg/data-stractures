#include "listofwords.hh"

using namespace ds_ex;

Low::Low() 
{
    this->first = NULL;
    this->len   = 0;
}

Low::~Low()
{
    // free the memory of all nodes.
    Low_node *curr = this->first;
    Low_node *tmp  = NULL;
    while (curr) {
        tmp = curr;
        curr = tmp->next;
        delete tmp->lof;
        delete tmp;
    }
}

Low &Low::insert_in_order(const std::string word, int file_id)
{
    Low_node *curr     = this->first;
    Low_node *parent   = NULL;
    Low_node *new_node = NULL;

    // Find the location where the next element should be stored.
    while (curr) {
        if (!curr->next || curr->word >= word) break;
        parent = curr;
        curr = curr->next;
    } 
    // if there is already this word, then just increase how many times it apears.
    if (curr) {
        if (curr->word == word) {
            ++curr->appear;
            // Insert the new file (if it is new)
            curr->lof->insert_in_order(file_id);
            return *this;
        }
    }

    // create a new node.
    new_node = new Low_node();
    new_node->word = word;
    new_node->next = NULL;
    // Create the associated list of file list.
    new_node->lof  = new ds_ex::Lof();
    // Store the file that contain this word in the lof.
    new_node->lof->insert_in_order(file_id);

    if (!this->first) {
        this->first = new_node;
    } else if (curr->word < word) {
        curr->next = new_node;
    } else {
        new_node->next = curr;
        if (curr == this->first) {
            this->first = new_node;
        } else {
            parent->next = new_node;
        }
    }

    // increase the number of elements.
    ++this->len;
    return *this;
}

bool Low::find(std::string &dst, int k) const
{
    Low_node *curr = this->first;
    int index = 0;
    while (index != k && curr) {
        curr = curr->next;
        ++index;
    }
    if (index == k && curr) {
        dst = curr->word;
        return true;
    } 

    return false;
}

int Low::length() const 
{
    return this->len;
}

int Low::get_appearance(const std::string word) const 
{
    // Find the word.
    Low_node *curr = this->first;
    while (curr) {
        if (curr->word == word) {
            // return how many times this word has appeared.
            return curr->appear;
        }
        curr = curr->next;
    }

    return 0;
}

int Low::get_number_of_files_appeared(const std::string word) const 
{
    Low_node *curr = this->first;
    // find the word.
    while (curr) {
        if (curr->word == word) {
            return curr->lof->length();
        }
        curr = curr->next;
    }

    return 0;
}

ds_ex::Lof *Low::get_lof(const std::string word) const
{
    Low_node *curr = this->first;
    // find the word.
    while (curr) {
        if (curr->word == word) {
            return curr->lof;
        }
        curr = curr->next;
    }
    return NULL;
}