template <typename Data, template <typename> class Container>
Insertable<Data, Container>::Insertable(Data const &data)
:
    Container<Data>({data})             // initializer list to constructor
{
}
// constructor from single Data-type object