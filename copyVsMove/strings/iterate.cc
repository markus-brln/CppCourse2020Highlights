#include "strings.ih"


void Strings::iterate(char **environLike)
{
    for (char **begin = environLike; *begin != 0; ++begin)
    {
        string next = *begin;
        add(next);                          // add all env vars to Strings obj
    }
}