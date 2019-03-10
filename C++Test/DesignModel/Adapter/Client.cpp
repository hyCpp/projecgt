#include"Adapter.h"
#include"Adaptee.h"
#include"ClassAdapter.h"

int main()
{
    Target *pTarget = new Adapter();
    pTarget->Request();

    Adaptee *pAdaptee = new Adaptee();
    pAdaptee->SpecificRequest(10);

    Target *pClassAdapter = new ClassAdapter();
    pClassAdapter->Request();
}
