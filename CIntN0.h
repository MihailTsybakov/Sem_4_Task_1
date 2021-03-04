#ifndef CINT0
#define CINT0

#include "CIntN.h"

class CIntN0 : public CIntN
{
public:
    using CIntN::CIntN;
    using CIntN::operator=;
    CIntN0(const CIntN& to_copy) : CIntN(to_copy){}
    ~CIntN0();

    int output(const char* FileName) override;

    friend CIntN0 operator+(const CIntN& first, const CIntN& second);
    friend CIntN0 operator-(const CIntN& first, const CIntN& second);
};
#endif // CINT0
