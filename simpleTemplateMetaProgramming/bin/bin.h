#ifndef BIN_H
#define BIN_H

template <int n>          // normal recursion
struct Bin
{
    enum 
    {                     // parenthesis needed
        value = 10 * Bin<(n >> 1)>::value  + (n & 1)
    };
};

template <>               // end condition specialization
struct Bin<0>
{
    enum 
    { 
        value = 0
    };
};

#endif
