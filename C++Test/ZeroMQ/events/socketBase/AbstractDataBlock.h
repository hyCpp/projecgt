#ifndef ABSTRACTDATABLOCK
#define ABSTRACTDATABLOCK

class AbstractDataBlock
{
public:
    AbstractDataBlock() {}
    virtual ~AbstractDataBlock() {}

    virtual size_t GetLength() = 0;
    virtual const void* GetData() = 0;

private:
    AbstractDataBlock(const AbstractDataBlock&);
    AbstractDataBlock& operator = (const AbstractDataBlock&);
};

#endif // ABSTRACTDATABLOCK

