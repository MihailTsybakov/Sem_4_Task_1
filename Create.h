#ifndef CREATE
#define CREATE
#include "CIntN.h"
#include <vector>
#include "factory.h"

vector<string> split(string source, char separator); // Splits string by separator

CIntN* Create_CINTN(string creation_parameters, CIntN_Factory);
#endif // CREATE
