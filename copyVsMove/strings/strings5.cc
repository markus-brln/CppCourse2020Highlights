#include "strings.ih"
#include <iostream>

extern char **environ;


Strings::Strings(size_t nIterate, bool copy = true)
:
    d_size(0),
    d_str(0), 
    d_copy(copy)                            // to be copied/moved
{
                                            // set the member pointer to 
    if (d_copy)                             // enlarge function
        d_enlargeFunc = &Strings::enlargeByCopy;
    else
        d_enlargeFunc = &Strings::enlargeByMove;
    

                                            // fill with env n times
    for (size_t idx = 0; idx < nIterate; ++idx)
    {
        iterate(environ);                   // iterate over env variables, add

        delete[] d_str;                     // reset for next iteration
        d_str = 0;
        d_size = 0;
    }
    iterate(environ);                       // fill one last time
                                            // show first and last element
    cout << at(0) << '\n' << at(d_size - 1) << '\n';
}