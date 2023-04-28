#include "listofwords.hh"

using namespace ds_ex;

Low &Low::insert_in_order(const std::string word)
{
    return *this;
}

bool Low::find(std::string &dst, int k) const
{
    return true;
}

bool Low::is_empty() const
{
    return (this->first == NULL)? true:false;
}