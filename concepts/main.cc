#include <string>
#include <iostream>
#include <vector>
#include <concepts>                 // use predefined concepts

using namespace std;


template <typename Type, typename RetType>
concept RefIdx =
    requires(Type someContainer)
    {
        { someContainer[0] } -> std::same_as<RetType&>;
    };
// concept to verify that certain operations return a 
// type defined by the type that is used as template argument


template <typename Type, typename RetType>
    requires RefIdx<Type, RetType>      // op idx of Type must return
RetType fun(Type cont)                  // ref to RetType
{
    return cont[0];
}
// demo function

int main()
{
    vector<string> hoi { "hoi" };

                                        // specify template args of fun call
    cout << fun<vector<string>, string>(hoi) << '\n';
}
