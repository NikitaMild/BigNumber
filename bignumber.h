#include <iostream>
#define BASE unsigned short
#define SIZE (sizeof(BASE)*2)
#define mod ((1 << (sizeof(unsigned short)*8)) - 1)

struct divBase;
struct divBig;

class BigNumber{
  private:
    BASE capacity; //емкость массива;
    BASE length;  //мощность массива;
    BASE *array;  //указатель на массив;

  public:
    BigNumber();
    BigNumber(int);
    BigNumber(const BigNumber&);
    ~BigNumber();
    void ReSize(int);
    void RandomBigNumber();
    BigNumber(char*);
    void ReadFromString(char*);
    void DelZero();
    friend std::istream & operator >> (std::istream&, BigNumber&);
    friend std::ostream & operator << (std::ostream&, const BigNumber&);
    void operator = (const BigNumber&);
    bool operator < (BigNumber const &);
    bool operator > (BigNumber const &);
    bool operator == (BigNumber const &);
    bool operator >= (BigNumber const &);
    BigNumber operator + (BigNumber&);
    BigNumber operator - (BigNumber&);
    BigNumber mulBase (BASE&);
    BigNumber operator * (BigNumber const &) const;
    divBase DivBase (BASE&);
    void  add_null(int);
    divBig operator / (BigNumber&);
    BigNumber BigPower (BigNumber const &, BigNumber&) const;
    BigNumber PowOnBase(int);
    BigNumber Karacuba (BigNumber const &);
    BigNumber FakeDiv(int k);
    BigNumber FakeMoD(int k);
    BigNumber Barett(BigNumber const &, BigNumber &);
    int CountDeg();
    bool TMR(int &);
    int countS(BigNumber);
    BigNumber powerS(int);
};

struct divBase{
  BASE r;   //остаток при делении на базу;
  BigNumber Result;   //результат деления большого числа на базу;
};

struct divBig{
  BigNumber res;  //результат деления большого на большое;
  BigNumber rem;  //остаток при делении большого на большое;
};
