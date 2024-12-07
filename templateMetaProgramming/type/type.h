template <typename ...NeedleAndHaystack>
struct Type
{
};
// just expects param pack, general declaration
// (does not even have a 'located' enum value since 
// no type would be given at all)


template <typename Needle>              // specialization 1
struct Type<Needle>
{
    enum 
    { 
        located = 0                     // recursion ends
    };
};
// only 1 arg -> instantiated with only 1 type either in main()
// or in recursive instance (see enum in specialization 3)

                                        // specialization 2
template <typename Needle, typename ...Haystack>     
struct Type<Needle, Needle, Haystack...>
{
    enum 
    { 
        located = 1                     // recursion ends
    };
};
// 2 Needles next to each other received -> located!


                                        // specialization 3
template <typename Needle, typename Next, typename ...Haystack>
struct Type<Needle, Next, Haystack...>
{
    enum                                // recursive part, Haystack empty,
    {                                   // then specialization 1 called,
        idx = Type<Needle, Haystack...>::located    // else spec 2 or 3
    };
    enum                                // Needle found somewhere in
    {                                   // recursion? add 1 to idx
        located = idx == 0 ? 0 : 1 + idx
    };
    
};
// called if Needle != Next, but still types on the Haystack left