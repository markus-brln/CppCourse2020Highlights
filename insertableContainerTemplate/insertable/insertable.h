#ifndef INCLUDED_INSERTABLE_
#define INCLUDED_INSERTABLE_

#include <ostream>                          // opinsert.f

namespace InsertableName
{

template <typename Data, template <typename> class Container>
struct Insertable: public Container<Data>   // use Container's members
{
    Insertable() = default;                 // uses default of Container
    Insertable(Insertable const &other);    // 1.f
    Insertable(Insertable &&other);         // not required from main()
    Insertable(Data const &dataObj);        // 3.f
    Insertable(Container<Data> const &cont);// 4.f
};

#include "insertable1.f"
#include "insertable3.f"
#include "insertable4.f"
#include "opinsert.f"

}   // namespace Insertable ends
#endif
