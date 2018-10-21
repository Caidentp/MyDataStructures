#include "singlylinkedlist.h"

const char* IndexError::what() const throw()
{
    return "List index out of range.";
}
