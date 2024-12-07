#ifndef TYPE_H
#define TYPE_H

// the support class TypeIdx must be a private,
//    nested class (it may be a struct) of the class Type.
//  - the interface of the class Type may only contain the
//    declaration of the support class TypeIdx.


template <typename ...Outer>            // outer context, parameter pack of
struct Type                             // Needle+Haystack
{
    private:
        template <typename ...Inner>    // inner context
        struct TypeIdx;                 // only declaration of nested class

    public:
        enum
        {                               // use TypeIdx to compute the desired
            located = TypeIdx<Outer...>::located    // value
        };
};

#include "typeidx.h"                    // specializations of nested class


#endif