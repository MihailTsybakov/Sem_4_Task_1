

#ifndef FACTORY
#define FACTORY

#include "CIntN1.h"
#include "CIntN0.h"

class CIntN_Factory
{
public:
    CIntN* create_0(int dimension, bool sign, string digits_string, string output_file);
    CIntN* create_1(int dimension, bool sign, string digits_string, string output_file);
};


#endif // FACTORY
