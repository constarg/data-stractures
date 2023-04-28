#include <string>

#include "listoffiles.hh"

using namespace ds_ex;

// TODO - constructor

Lof& Lof::insert_in_order(const uint8_t file_id)
{
    Lof_node *curr     = this->first;
    Lof_node *new_node = NULL;

    while (curr->file_id < file_id && curr->next);

    // create a new node.
    new_node = new Lof_node();
    new_node->file_id = file_id;
    new_node->next = NULL;

    if (!curr->next) {
        // If the new node stored at the end;
        curr->next = new_node;
    } else {
        // If the new node must stored in an other index
        new_node->next = curr->next;
        curr->next = new_node;
    }

    return *this;
}

bool Lof::find(uint8_t &dst, int k) const
{
    Lof_node *curr = this->first;
    int index = 0;
    while (index++ < k) curr = curr->next;
    if (index == k) {
        dst = curr->file_id;
        return true;
    }

    return false;
}

bool Lof::is_empty() const
{
    return (this->first == NULL)? true:false;
}

// TODO - destructor.