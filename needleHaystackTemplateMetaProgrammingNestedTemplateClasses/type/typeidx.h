#ifndef TYPEIDX_H
#define TYPEIDX_H

// NOTE: comments about recursion (see ex. 20) mostly ommitted,
// since focus is on nested template classes


template <typename ...Outer>            // establish Type's context
template <typename Needle>              // normal specialization as in ex. 20
                                        // with Type<Outer...>:: we get access
struct Type<Outer...>::TypeIdx<Needle>  // to the private struct
{
    enum 
    { 
        located = 0                     // not found, recursion ends
    };
};

template <typename ...Outer>
template <typename Needle, typename ...Haystack>     
struct Type<Outer...>::TypeIdx<Needle, Needle, Haystack...>
{
    enum  
    { 
        located = 1                     // found, recursion ends
    };
};

template <typename ...Outer>
template <typename Needle, typename Next, typename ...Haystack>
struct Type<Outer...>::TypeIdx<Needle, Next, Haystack...>
{
    enum                                // same recursion as in ex. 20
    { 
        idx = TypeIdx<Needle, Haystack...>::located 
    };
    enum 
    { 
        located = idx == 0 ? 0 : 1 + idx 
    };
    
};

#endif