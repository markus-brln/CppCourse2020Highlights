#include "strings.ih"

void Strings::add(string const &next)
{
                                        // call function that pointer points
    string *tmp = (*this.*d_enlargeFunc)(); // to, move/copy all strings

    tmp[d_size] = next;                 // store next

    delete[] d_str;                     // return old memory

    d_str = tmp;                        // update d_str and d_size
    ++d_size;
}
