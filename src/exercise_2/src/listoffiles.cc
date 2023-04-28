#include <string>

#include "listoffiles.hh"

using namespace ds_ex;

Lof& Lof::insert_in_order(const uint8_t word)
{
    return *this;
}

bool Lof::find(uint8_t &dst, int k) const
{
    return true;
}

bool Lof::is_empty() const
{
    return (this->first == NULL)? true:false;
}