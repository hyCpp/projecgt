#include"Aggregate.h"
#include "Iterator.h"
#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"
#include "stdio.h"

int main()
{
    ConcreteAggregate* pName = new ConcreteAggregate();
    pName->Push("Rose");
    pName->Push("jack");
    pName->Push("Alice");

    Iterator* iter = pName->CreateIterator();
    for (iter->First(); !iter->IsEnd(); iter->Next()) {
        printf("%s is ok\n", iter->GetValue().c_str());
    }

    std::vector<std::string>::iterator it;
}
