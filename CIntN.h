/*

В каждой задаче должен быть сделан базовый класс, решающий задачу. Пусть он называется CData.
В каждом классе должна быть создана [чисто] виртуальная функция
вывода данных класса в файл вида
virtual int output(const char *FileName=NULL)=0;
От данного класса CData надо породить два класса CData0 и CData1,
в первом из которых переопределена функция
int output(const char *FileName);
как функция вывода данных класса в файл в одну строку, а во втором данная функция определена как функция вывода данных класса в
столбец (т.е. по одному элементу данных в одну строку).
В файле с исходными данными в каждой строке задаются данные
для одного экземпляра класса, порожденного от CData. Данные задачи
задаются в каждой строке в виде:
I FileName Data
где I = 0 или = 1, FileName — имя выходного файла, Data — все данные
одного объекта, разделенные пробелами.
Для каждой строки исходного файла надо создать класс CData0,
если I == 0, либо надо создать класс CData1, если I == 1. Созданный
класс надо заполнить данными из введенной строки. Имя выходного
файла следует занести в соответствующее поле созданного класса.
Все созданные классы надо поместить в массив указателей на базовый класс CData **arr;.
Каждый новый объект должен создаваться функцией вида
CData *CreateData(const char *str, CFabricData **f );.
где f — массив фабрик для создания I-го дочернего класса от CData.
Далее надо в цикле для каждого объекта из массива arr вызвать
функцию output().

*/

/// ***********************************************************************************
/*

3. Определить класс CIntN для работы с целыми знаковыми числами,
состоящими lо N десятичных цифр, где N задается в конструкторе. В
классе должны быть определены необходимые конструкторы, деструктор, операторы присваивания, сложения, вычитания.
Написать функцию и конструктор сохранения переменной данного
типа в файл и загрузки из файла.
В отдельном файле должен быть написан тест на данный класс

*/
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
using namespace std;

#ifndef CINTN
#define CINTN
class CIntN
{
protected:
    int dimension;
    bool sign; // True = "+"
    int* digits; // Digits array
    string pure_plus(const CIntN& num_1, const CIntN& num_2);
    string pure_minus(const CIntN& num_1, const CIntN& num_2);
    string output_file;
public:
    CIntN();
    virtual ~CIntN();
    CIntN(int dimension, bool sign, string digits_string, string output_file);
    CIntN(const CIntN& to_copy);
    CIntN& operator=(const CIntN& equals_to);
    void print() const noexcept;
    operator int() const noexcept;
    int getabs() const noexcept;
    string out_file() const noexcept;

    virtual int output(const char* FileName) = 0;
};

class CIntN0 : public CIntN
{
public:
    using CIntN::CIntN;
    ~CIntN0();

    int output(const char* FileName) override;

    CIntN0 operator+(const CIntN0& addition);
    CIntN0 operator-(const CIntN0& subtraction);
};

class CIntN1 : public CIntN
{
public:
    using CIntN::CIntN;
    ~CIntN1();

    int output(const char* FileName) override;

    CIntN1 operator-(const CIntN1& subtraction);
    CIntN1 operator+(const CIntN1& addition);
};

class CIntN_Factory
{
public:
    CIntN* create_0(int dimension, bool sign, string digits_string, string output_file);
    CIntN* create_1(int dimension, bool sign, string digits_string, string output_file);
};


#endif  //CINTN
