template <typename Data, template <typename> class Container>
std::ostream &operator<<(std::ostream &out, Insertable<Data, Container> const &cont)
{
    for (Data const &elem : cont)
        out << elem << ' ';

    return out;
}
// for Insertable's of any type (assumes that Data itself is insertable)