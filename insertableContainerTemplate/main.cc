#include "main.ih"


int main()
{
    deque<string> ds = {"kilo", "lima", "mike"};

    vector<int> vi {1, 2, 3, 4, 5};

    Insertable<int, vector> iv;         // we changed the order of the 
    Insertable<int, vector> iv2(vi);    // template args here to make it
    Insertable<int, vector> iv3(4);     // more compatible with the book
    Insertable<int, vector> iv4(iv2);

    cout << iv2 << '\n' <<
            iv3 << '\n' <<
            iv4 << '\n';

    iv3.push_back(123);
    cout << iv3 << '\n';

    Insertable<string, deque> sd(ds);   // same here
    sd.push_back("november");

    cout << "sd has " << sd.size() << " elements and contains:\n"
            << sd << '\n';
}