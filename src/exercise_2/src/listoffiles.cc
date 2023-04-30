#include <string>

#include "listoffiles.hh"

using namespace ds_ex;

Lof::Lof() 
{
    this->first = NULL;
    this->len   = 0;
}

Lof::~Lof()
{
    // free the memory of all nodes.
    Lof_node *curr = this->first;
    Lof_node *tmp  = NULL;
    while (curr) {
        tmp  = curr;
        curr = tmp->next;
        delete tmp;  
    }
}

Lof& Lof::insert_in_order(const int file_id)
{
    Lof_node *curr     = this->first;
    Lof_node *new_node = NULL;
    Lof_node *parent   = NULL;

    // Find the location where the next element should be stored.
    while (curr) {
        if (!curr->next || curr->file_id >= file_id) break;
        parent = curr;
        curr = curr->next;
    }
    // Ignore if the file_id already exists.
    if (curr) {
        if (curr->file_id == file_id) {
            return *this;
        }
    }

    // create a new node.
    new_node          = new Lof_node();
    new_node->file_id = file_id;
    new_node->next    = NULL;

    if (!this->first) {
        this->first = new_node;
    } else if (curr->file_id < file_id) {
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

bool Lof::find(int &dst, int k) const
{
    Lof_node *curr = this->first;
    int index = 0;
    while (index != k && curr) {
        curr = curr->next;
        ++index;
    }
    if (index == k && curr) {
        dst = curr->file_id;
        return true;
    } 

    return false;
}

int Lof::length() const 
{
    return this->len;
}