#ifndef CINT1
#define CINT1

#include "CIntN.h"

class CIntN1 : public CIntN
{
public:
    using CIntN::CIntN;
    using CIntN::operator=;
    CIntN1(const CIntN& to_copy) : CIntN(to_copy){}
    ~CIntN1();

    int output(const char* FileName) override;
};

#endif // CINT1
