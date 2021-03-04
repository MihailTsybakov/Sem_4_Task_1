#include "factory.h"

CIntN* CIntN_Factory::create_0(int dimension, bool sign, string digits_string, string output_file)
{
    return new CIntN0(dimension, sign, digits_string, output_file);
}

CIntN* CIntN_Factory::create_1(int dimension, bool sign, string digits_string, string output_file)
{
    return new CIntN1(dimension, sign, digits_string, output_file);
}
