#include "main.ih"


size_t normal_recursive_bin(size_t num)
{
    if (num == 0)
        return 0;
                                        // shift by 1 to right
    return 10 * normal_recursive_bin(num >> 1) + (num & 1);  // paren suggested
}

int main()
{
    cout << Bin<5>::value << '\n' <<
            Bin<27>::value << '\n';

    cout << normal_recursive_bin(5) << '\n' << 
            normal_recursive_bin(27) << '\n';
}