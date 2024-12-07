#include "main.ih"


int main()
{
    cout << Type<int>::located << ' ' << 
        Type<int, double>::located << ' ' << 
        Type<int, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int>::located << ' ' << 
        Type<int, double, int, int, int>::located << 
        '\n';
}
// checks at which idx first type (Needle) passed to Type
// is found in others (Haystack)
// should display 0 0 1 2 2 2