#include <Create.h>

vector<string> split(string source, char separator) // Splits string by separator
{
    vector<string> res_vector;
    size_t symbol_index = 0;
    string curr_piece = "";
    while (symbol_index < source.size())
    {
        if (source[symbol_index] != separator)
        {
            curr_piece += source[symbol_index];
        }
        else
        {
            res_vector.push_back(curr_piece);
            curr_piece = "";
        }
        symbol_index++;
    }
    res_vector.push_back(curr_piece);
    return res_vector;
}

CIntN* Create_CINTN(string creation_parameters, CIntN_Factory factory)
{
    vector<string> parsed_params = split(creation_parameters, ' ');

    char obj_type = parsed_params[0][0];
    string filename = parsed_params[1];
    int dimension = stoi(parsed_params[2]);
    bool sign; (parsed_params[3][0] == 't')? sign = true : sign = false;
    string digits_string = parsed_params[4];

    if (obj_type == '0')
    {
        return factory.create_0(dimension, sign, digits_string, filename);
    }

    return factory.create_1(dimension, sign, digits_string, filename);
}
