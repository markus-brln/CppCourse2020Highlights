template <typename Data, template <typename> class Container>
Insertable<Data, Container>::Insertable(Container<Data> const &cont)
:
    Container<Data>(cont)               // call base class constructor
{
}
// constructor from base class Container obj
