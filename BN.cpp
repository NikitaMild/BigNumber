#include <iostream>
#include <cstring>
#include "bignumber.h"
#include <iomanip>
#include <string>
#include <math.h>
#include <cstdlib>
#include <ctime>

BigNumber:: BigNumber (){
  length = 1;
  capacity = 1;
  array = new BASE[capacity];
  array[0] = 0;
}

BigNumber:: BigNumber (int newlength) {
    length = newlength;
    capacity = length + 1;
    array = new BASE [capacity];
    for(int i = 0; i < length; i++)
      array[i] = 0;
}

BigNumber:: ~BigNumber(){
    delete [] array;
    array = NULL;
    length = 0;
    capacity = 0;
}

BigNumber::BigNumber(char* string){
  this->ReadFromString(string);
}

BigNumber:: BigNumber(const BigNumber &NewNumber) {
    length = NewNumber.length;
    capacity = length + 1;
    array = new BASE[capacity];
    for(int i = 0; i < length; i++){
      array[i] = NewNumber.array[i];
    }
}

void BigNumber:: ReSize(int newlength) {
  delete [] array;
  length = newlength;
  capacity = length + 1;
  array = new BASE[capacity];
  for(int i = 0; i < length; i++)
    array[i] = 0;
  return;
}

void BigNumber:: RandomBigNumber(){
    //srand(time(NULL));
    for (int i = length - 1; i >= 0; --i){
      array[i] = 1 + rand();
    }
  return;
}

void BigNumber:: ReadFromString(char* str) {
  char STRING[strlen(str) + 1] = { 0 };
  strcat (STRING, str);
  int Length = strlen(STRING);
  if (Length % SIZE != 0){
    length = Length/SIZE + 1;
  }
  else {
    length = Length/SIZE;
  }
  capacity = length+1;
  array = new BASE [capacity];
  if (Length < SIZE) {
    array[0] = std::stoul (STRING,nullptr,16);
    return;
  }
  for(int i = Length - SIZE, j = 0 ; i >= 0 ; i -= SIZE, j++){
    array[j] = std::stoul (STRING + i,nullptr,16);
    STRING[i] = '\0';
    if (i < SIZE && strlen(STRING) > 0){
      j++;
      array[j] = std::stoul (STRING,nullptr,16);
      break;
    }
  }
  (*this).DelZero();
  return;
}

void BigNumber:: DelZero(){
for(int i = length - 1; i > 0; i--){
  if(array[i] == 0){
    --length;
  }
  else
    return;
}
return;
}

std::istream& operator >> (std::istream &in, BigNumber &InputNumber) {
  char WorkLine[1024];
  std::cout << "Please, input number:" << std::endl;
  std::cin >> WorkLine;
  int LEN = strlen(WorkLine);
  BigNumber temp(LEN);
  temp.ReadFromString(WorkLine);
  InputNumber = temp;
  return in;
}

std::ostream& operator << (std::ostream &out, const BigNumber &OutputNumber) {
  if(OutputNumber.length == 1){
    out.unsetf(std::ios::dec);
    out.setf(std::ios::hex | std::ios::uppercase);
    out << OutputNumber.array[OutputNumber.length - 1];
    out.unsetf(std::ios::hex | std::ios::uppercase);
    out.setf(std::ios::dec);
    return out;
  }
  else{
    out.unsetf(std::ios::dec);
    out.setf(std::ios::hex | std::ios::uppercase);
      out << OutputNumber.array[OutputNumber.length - 1];
      for(int i = OutputNumber.length - 2; i >= 0; i--)
        out << std::setw(SIZE) << std::setfill('0') << OutputNumber.array[i];
      out << std::endl;
    out.unsetf(std::ios::hex | std::ios::uppercase);
    out.setf(std::ios::dec);
    return out;
  }
}

void BigNumber:: operator = (const BigNumber &EqualBigNumber){
  if(capacity >= EqualBigNumber.length){
    length = EqualBigNumber.length;
    for(int i = 0; i < EqualBigNumber.length; i++){
      array[i] = EqualBigNumber.array[i];
    }
    for(int i = EqualBigNumber.length; i < capacity; i++)
      array[i] = 0;
    (*this).DelZero();
    return;
  }
  else{
    delete [] array;
    length = EqualBigNumber.length;
    capacity = length + 1;
    array = new BASE[capacity];
    for(int i = 0; i < length; i++){
      array[i] = EqualBigNumber.array[i];
    }
    return;
  }
}


bool BigNumber::operator > (BigNumber const &TheNext){
    BigNumber t1;
    t1 = *this;
    BigNumber t2;
    t2 = TheNext;
    t1.DelZero();
    t2.DelZero();
    if(t1.length < t2.length){
        return false;
    }
    if(t1.length > t2.length){
        return true;
    }
    for(int i = t1.length - 1; i >= 0; --i){
      if(t1.array[i] != t2.array[i] ){
        return (t1.array[i] > t2.array[i]);
      }
    }
    return false;
}

bool BigNumber:: operator < (BigNumber const &TheNext){
  BigNumber t1;
  t1 = *this;
  BigNumber t2;
  t2 = TheNext;
  t1.DelZero();
  t2.DelZero();
  if(t1.length < t2.length){
      return true;
  }
  if(t1.length > t2.length){
      return false;
  }
  for(int i = t1.length - 1; i >= 0; --i){
    if(t1.array[i] != t2.array[i] ){
      return (t1.array[i] < t2.array[i]);
    }
  }
  return false;
}

bool BigNumber:: operator == (BigNumber const &TheNext){
  BigNumber t1;
  t1 = *this;
  BigNumber t2;
  t2 = TheNext;
  t1.DelZero();
  t2.DelZero();
  if(t1.length != t2.length){
      return false;
  }
  for(int i = t1.length - 1; i >= 0; --i){
    if(t1.array[i] != t2.array[i] ){
      return false;
    }
  }
  return true;
}


bool BigNumber:: operator >= (BigNumber const &TheNext){
  return (((*this) > TheNext) || ((*this) == TheNext));
}

BigNumber BigNumber:: operator + (BigNumber &SecondBigNumber){
  unsigned long sum, k = 0;
  if (SecondBigNumber.length > length){
    BigNumber Result(SecondBigNumber.length + 1);
    for (int i = 0; i < length; i++){
      sum = (array[i] + SecondBigNumber.array[i] + k) & mod;
      Result.array[i] = sum;
      k = (array[i] + SecondBigNumber.array[i] + k) / (mod + 1);
    }
    for (int i = length; i < SecondBigNumber.length; i++){
      sum = (SecondBigNumber.array[i] + k) & mod;
      Result.array[i] = sum;
      k = (SecondBigNumber.array[i] + k) / (mod + 1);
    }
    Result.array[SecondBigNumber.length] = k;
    Result.DelZero();
    return Result;
  }
  if (SecondBigNumber.length < length){
    BigNumber Result(length + 1);
    for(int i = 0; i < SecondBigNumber.length; i++){
      sum = (array[i] + SecondBigNumber.array[i] + k) & mod;
      Result.array[i] = sum;
      k = (array[i] + SecondBigNumber.array[i] + k) / (mod + 1);
    }
    for(int i = SecondBigNumber.length; i < length; i++){
      sum = (array[i] + k) & mod;
      Result.array[i] = sum;
      k = (array[i] + k) / (mod + 1);
    }
    Result.array[length] = k;
    Result.DelZero();
    return Result;
  }
  if (SecondBigNumber.length == length){
    BigNumber Result(SecondBigNumber.length + 1);
    for (int i = 0; i < SecondBigNumber.length; i++){
      sum = (array[i] + SecondBigNumber.array[i] + k) & mod;
      Result.array[i] = sum;
      k = (array[i] + SecondBigNumber.array[i] + k) / (mod + 1);
    }
    Result.array[SecondBigNumber.length] = k;
    Result.DelZero();
    return Result;
  }
}


BigNumber BigNumber:: operator - (BigNumber &SecondBigNumber){
  unsigned long sum, k = 0;
  BigNumber Result(length);
  for (int i = 0; i < SecondBigNumber.length; i++){
    sum = (array[i] - (SecondBigNumber.array[i] + k)) & mod;
    Result.array[i] = sum;
    k = (mod - (array[i] - SecondBigNumber.array[i] - k)) / (mod + 1);
  }
  for (int i = SecondBigNumber.length; i < length; i++){
    sum = (array[i] - k) & mod;
    Result.array[i] = sum;
    k = (mod - (array[i] - k)) / (mod + 1);
  }
  Result.DelZero();
  return Result;
}


BigNumber BigNumber:: mulBase(BASE &base){
  unsigned long sum, k = 0;
  if (!base){
    BigNumber Result(1);
    return Result;
  }
  BigNumber Result(length + 1);
  for (int i = 0; i < length; i++){
    sum = ((unsigned long)array[i] * base + k) & mod;
    Result.array[i] = sum;
    k = ((unsigned long)array[i] * base + k) / (mod+1);
  }
  Result.array[length] = k;
  Result.DelZero();
  return Result;
}


BigNumber BigNumber:: operator * (BigNumber const &SecondBigNumber) const{
  unsigned long  t = 0;
  unsigned short k = 0;
  BigNumber Result(length + SecondBigNumber.length);
  for(int j = 0; j < SecondBigNumber.length; j++){
    if(!SecondBigNumber.array[j]) continue; //Result.array[j] = 0;
      //else {
      if(SecondBigNumber.array[j] != 0){
        k = 0;
        for(int i = 0; i < length; i++){
          t = (unsigned long)(array[i]) * SecondBigNumber.array[j] + Result.array[i+j] + k;
          Result.array[i+j] = t % (mod + 1);
          k = t / (mod + 1);
        }
        Result.array[length+j] = k;
      }
  }
  Result.DelZero();
  return Result;
}


void BigNumber:: add_null(int count_null)
{
    BigNumber temp;
    temp = *this;
    delete [] array;
    length = temp.length + count_null;
    capacity = length + 1;
    array = new BASE[capacity];
    for(int i = 0; i < temp.length; ++i)
      array[i] = temp.array[i];
	for(int i = temp.length; i < length; ++i)
	{
		array[i] = 0;
	}
}

divBase BigNumber:: DivBase(BASE &base){
  divBase Division;
  unsigned long t = 0;
  Division.r = 0;
  BigNumber temp(length);
  Division.Result = temp;
  for(int i = length - 1; i >= 0; i--){
    t = (unsigned long)(array[i]) + (unsigned long)(Division.r) * (mod+1);
    Division.Result.array[i] = t / base;
    Division.r = t % base;
  }
  Division.Result.DelZero();
  return Division;
}

divBig BigNumber:: operator / (BigNumber &SecondBigNumber){
  divBig Division;
  BigNumber u = *this;
  BigNumber v = SecondBigNumber;
  BigNumber V;
  if(v > u){
    Division.res.array[0] = 0;
    Division.rem = u;
    return Division;
  }
  if(SecondBigNumber.length == 1) {
    BASE base;
    divBase tmp;
    base = v.array[0];
    tmp = u.DivBase(base);
    Division.res = tmp.Result;
    Division.rem.array[0] = tmp.r;
    return Division;
  }
  int m = u.length - v.length;
  int n = v.length;
  //----------------------
  BigNumber Result(m+1);   //Result of Division;
  //-----------------------
unsigned int long Q;
unsigned int long R;
int i, k;
int j = 0;
unsigned int long b = (1 << sizeof(unsigned short)*8);
unsigned int short d = b / (v.array[n-1] + 1);
u = u.mulBase(d);
if(d == 1 || u.length - length == 0){
  u.add_null(1);
}
v = v.mulBase(d);
for(j = m; j >= 0; --j){
  Q = ((u.array[j+n] * b + u.array[j+n-1]) / v.array[n-1]);
  R = ((u.array[j+n] * b + u.array[j+n-1]) % v.array[n-1]);
  while(R < b && (Q == b || (Q * v.array[n-2] > (b * R + u.array[j+n-2])))){
    --Q;
    R += v.array[n-1];
  }
  BigNumber U(v.length+1);
  for (i = 0,k = j; k < (j+n+1); ++i,++k){
    U.array[i] = u.array[k];
  }
  U.DelZero();

  Result.array[j] = Q;
  BASE q = Q;
  V = v.mulBase(q);
  if(U >= V)
  {
    U = U - V;
  }
  else{
    U = V - U;
    v.add_null(1);
    U = v - U;
    Result.array[j] -= 1;
    v.DelZero();
  }
  for (i = 0,k = j; k < (j+n+1); ++i,++k)
  {
    u.array[k] = U.array[i];
  }

}
Result.DelZero();
Division.res = Result;
BigNumber numb(v.length+1);
for(int i = 0; i < v.length; i++){
  numb.array[i] = u.array[i];
}
divBase kk = numb.DivBase(d);
kk.Result.DelZero();
Division.rem = kk.Result;
return Division;
}



BigNumber BigNumber:: BigPower (BigNumber const &PowerBigNumber, BigNumber &ModulBigNumber) const {
  divBig RES;
  divBig TEM;
  BigNumber result; //z
  BigNumber temp;   //q
  temp = (*this);
  if(PowerBigNumber.array[0] & 1){
    result = (*this);
  }
  else{
    result.array[0] = 0x1;
  }
  for(int j = 1; j < 16; ++j){
    TEM = (temp * temp) / ModulBigNumber;
    temp = TEM.rem;
    if((PowerBigNumber.array[0] >> j) & 1){
      RES = (result * temp) / ModulBigNumber;
      result = RES.rem;
    }
  }
  for(int i = 1; i < PowerBigNumber.length; ++i){
    for(int j = 0; j < 16; ++j){
      TEM = (temp * temp) / ModulBigNumber;
      temp = TEM.rem;
      if((PowerBigNumber.array[i] >> j) & 1){
        RES = (result * temp) / ModulBigNumber;
        result = RES.rem;
      }
    }
  }
  result.DelZero();
  return result;
}

BigNumber BigNumber:: PowOnBase(int n){
  BigNumber Result(n+length);
  for(int i = Result.length - 1, j = length - 1; j >= 0; --i,--j){
    Result.array[i] = array[j];
  }
  for(int i = Result.length - length - 1; i >= 0; --i){
    Result.array[i] = 0;
  }
  return Result;
}

BigNumber BigNumber:: Karacuba (BigNumber const &SecondBigNumber){
  int n = 0;
  int n2 = 0;
  if(*this >= SecondBigNumber){
    if (length & 1 != 0){
      n2 = length + 1;
      n = (length>>1) + 1;
    }
    else {
      n2 = length;
      n = length>>1;
    }
  }
  else{
    if (SecondBigNumber.length & 1 != 0){
      n2 = SecondBigNumber.length + 1;
      n = (SecondBigNumber.length>>1) + 1;
    }
    else {
      n2 = SecondBigNumber.length;
      n = SecondBigNumber.length>>1;
    }
  }
  if(n >= 50){
    BigNumber U0(n);
    BigNumber V0(n);
    BigNumber U1(n);
    BigNumber V1(n);
    for(int i = 0; i < n && i < length; i++){
      U0.array[i] = array[i];
    }
    for(int i = 0; i < n && i < SecondBigNumber.length; i++){
      V0.array[i] = SecondBigNumber.array[i];
    }
    for(int i = n, j = 0; j < U1.length && i < length; i++, j++){
      U1.array[j] = array[i];
    }
    for(int i = n, j = 0; j < V1.length && i < SecondBigNumber.length; i++, j++){
      V1.array[j] = SecondBigNumber.array[i];
    }
    BigNumber A;
    BigNumber B;
    BigNumber C;
    BigNumber Result;
    BigNumber T;
    A = U1.Karacuba(V1);
    B = U0.Karacuba(V0);
    C = (U1+U0).Karacuba(V1+V0);
    T = (C - A - B).PowOnBase(n);
    A = A.PowOnBase(n2);
    Result = A + T + B;
    Result.DelZero();
    return Result;
  }
  BigNumber Result = (*this)*SecondBigNumber;
  return Result;
}

BigNumber BigNumber:: FakeDiv(int k){
  int q = length - k;
  BigNumber Result(q);
  for(int i = length - 1, j = q - 1; j >= 0; --i, --j){
    Result.array[j] = array[i];
  }
  return Result;
}

BigNumber BigNumber:: FakeMoD(int k){
  if(k >= length){
    return *this;
  }
  length = k;
  return *this;
}

BigNumber BigNumber:: Barett(BigNumber const &BigModule, BigNumber &Z){
  BigNumber temp = BigModule;
  int k = BigModule.length;
  if(temp > *this){
    return *this;
  }
  if(temp == *this){
    BigNumber Result;
    return Result;
  }
  if (length > 2*k){
    divBig result = (*this)/temp;
    return result.rem;
  }
  BigNumber b;
  BigNumber Q = (*this).FakeDiv(k-1);
  b.ReSize(1);
  b.array[0] = 0x1;
  b = b.PowOnBase(k+1);
  Q = Q * Z;
  Q = Q.FakeDiv(k+1);
  BigNumber R;
  BigNumber r1 = *this;
  r1 = r1.FakeMoD(k+1);
  BigNumber r2 = Q * BigModule;
  r2 = r2.FakeMoD(k+1);
  if(r1 >= r2){
    R = r1 - r2;
  }
  else{
    R = b + r1 - r2;
  }
  while(R >= BigModule){
    R = R - temp;
  }
  return R;
}

int BigNumber:: countS(BigNumber testing){
  int S = 0;
  int i = 0;
  for(i; i < testing.length; i++){
    if(testing.array[i] == 0){
      ++S;
    }
    else{
      break;
    }
  }
  S = S*16;
  for(int j = 0; j < 16; ++j){
    std::cout << std::hex << testing.array[i] << std::endl;
    if((testing.array[i] >> j) & 1){
      return S;
    }
    else{
      ++S;
    }
  }
}

BigNumber BigNumber:: powerS(int s){
  int len = (s+15) >> 4;
  BigNumber temp(len);
  for(int i = 0; i < len - 1; ++i){
    temp.array[i] = 0;
  }
  temp.array[len-1] = 1 << (s & 15);
  return temp;
}

bool BigNumber:: TMR(int &t){
  BigNumber testing = *this;
  BigNumber zero;
  BigNumber one;
  one.array[0] = 0x1;
  BigNumber two;
  two.array[0] = 0x2;
  BigNumber three;
  three.array[0] = 0x3;
  divBig m;
  int s = 0;
  BigNumber R;
  BigNumber PowS = one;
  BigNumber temp = testing - one;

  if(testing.array[0] & 1 ){
    s = countS(temp);
    PowS = PowS.powerS(s);
    m = testing/PowS;
    R = m.res;
    int j = 0;
    for(int i = 0; i < t; ++i){
      BigNumber a;
      j = 1 + rand() % testing.length;
      a.ReSize(j);
      a.RandomBigNumber();
      while(a > testing){
        a = a - testing;
      }
      if(a == testing){
        a = a - two;
      }
      BigNumber B;
      B = a.BigPower(R,testing);
      if(B == one || B == temp){
        continue;
      }
      else{
        j = 1;
        while(j < s){
          if(B == temp){
            break;
          }
          m = (B*B)/testing;
          B = m.rem;
          if(B == one){
            return false;
          }
          ++j;
        }
      }
      if(B == temp){
        continue;
      }
      else{
        return false;
      }
    }
  }
  else{
    return false;
  }
  return true;
}
