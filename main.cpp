#include "CIntN.h"
#include "Create.h"
#include "Autotest.h"

int main(int argc, char* argv[])
{
    if (!autotest())
    {
        cout << "Autotest Failed!" << endl;
        exit(-1);
    }
    cout << "Autotest passed" << endl;

    string input_filename = "Input.txt";
    ifstream input_file(input_filename);

    if (!input_file.is_open())
    {
        cout << "Error: cannot open " << input_filename << endl;
        exit(-1);
    }

    vector<string> psvector; // parameter strings vector
    string tmp_string;

    while (getline(input_file, tmp_string))
    {
        psvector.push_back(tmp_string);
    }

    CIntN** arr = new CIntN*[psvector.size()];
    CIntN_Factory factory;

    for (size_t i = 0; i < psvector.size(); ++i)
    {
        arr[i] = Create_CINTN(psvector[i], factory);
    }

    // Outputting
    for (size_t i = 0; i < psvector.size(); ++i)
    {
        arr[i]->output((arr[i]->out_file()).c_str());
        delete arr[i];
    }

    input_file.close();
    delete[] arr;
    return 0;
}
