template <typename Data, template <typename> class Container>
Insertable<Data, Container>::Insertable(
    Insertable<Data, Container> const &containerObj)
:
    Container<Data>(containerObj)       // call base class constructor
{
}
// copy constructor