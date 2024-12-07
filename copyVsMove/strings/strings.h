#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <iosfwd>

class Strings
{
    size_t d_size = 0;
    std::string *d_str = 0;
    bool d_copy = true;
                                                // function pointer to  
    std::string *(Strings::*d_enlargeFunc)();   // enlarge by copy/move

    public:
        struct POD
        {
            size_t      size;
            std::string *str;
        };

        Strings();

        Strings(int argc, char **argv);
        Strings(char **environLike);
        Strings(std::istream &in);
        Strings(size_t nIterate, bool copy);    // demonstrate copy/move

        ~Strings();

        size_t size() const;
        void swap(Strings &other);          // swap data members
        POD release();                      // make Strings object reusable
        std::string const &at(size_t idx) const;    // for const-objects
        std::string &at(size_t idx);                // for non-const objects
        void add(std::string const &next);          // add another element
        void iterate(char **environLike);
    private:
        std::string &safeAt(size_t idx) const;      // private backdoor
        std::string *storageArea();
        void destroy();      
        void fill(char *ntbs[]);                // fill prepared d_str
        static size_t count(char *environLike[]);   // # elements in env.like
        std::string *enlargeByCopy();           // increase size by 1
        std::string *enlargeByMove();           // same, just without copying
        std::string *rawStrings(size_t amount); // allocate new memory

        
};

inline size_t Strings::size() const         // potentially dangerous practice:
{                                           // inline accessors
    return d_size;
}

inline std::string const &Strings::at(size_t idx) const
{
    return safeAt(idx);
}

inline std::string &Strings::at(size_t idx)
{
    return safeAt(idx);
}

        
#endif
