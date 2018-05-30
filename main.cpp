#include <iostream>
#include "bignumber.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

int main() {

/*
int T = 1000, M = 1000;
unsigned int n , m;
BigNumber A;
BigNumber B;
BigNumber K;
BigNumber F;
BigNumber Z;
divBig C;
  srand(time(NULL));
  do{
    n = 1 + rand() % M;
    m = 1 + rand() % M;
    A.ReSize(n);
    B.ReSize(m);
    A.RandomBigNumber();
    B.RandomBigNumber();
    C = A/B;
} while((A == (B * C.res) + C.rem) && (A - C.rem == B * C.res) && (C.rem < B) && (--T));
  if (T) {
    std::cout << "T: " << T << std::endl;
    std::cout << "A: " << A << std::endl;
    std::cout << "B: " << B << std::endl;
    std::cout << "C.res: " << C.res << std::endl;
    std::cout << "C.rem: " << C.rem << std::endl;
    std::cout << "(B * C.res) + C.rem: " << (B * C.res) + C.rem << std::endl;
    std::cout << "A - C.rem: " << A - C.rem << std::endl;
    std::cout << "B * C.res: " << B * C.res << std::endl;
  }
*/

/*
char* ppower = "1B02761F9C6B100F64E1B27A78330195DA1F6902CDEAF4C71C71C7";
BigNumber P(ppower);
BigNumber S(ppower);
BigNumber KEK;
BigNumber RR;
divBig KK;

  RR.ReSize(100);
  RR.RandomBigNumber();
  KEK = RR.BigPower(P,S);
  KK = RR/P;
  if (KEK == KK.rem) {
    std::cout << "test complete" << std::endl;
  }
  else{
  std::cout << "RR: " << std::hex << RR << std::endl;
  std::cout << "KEK: " << std::hex << KEK << std::endl;
  }
*/

/*
  int R = 1;
  int E = 10000;
  clock_t time1;
  srand(time(NULL));
  while(R){
  BigNumber One;
  BigNumber Two;
  BigNumber Res;
  One.ReSize(E);
  Two.ReSize(E);
  One.RandomBigNumber();
  Two.RandomBigNumber();
  time1 = clock();
  Res = One * Two;
  time1 = clock() - time1;
  --R;
  }
  //time1 = clock() - time1;
  float Time1 = ((float)time1) / CLOCKS_PER_SEC;
  std::cout << "time A*B: " << Time1 << std::endl;

  int T = 1; //M = 1000;
  int M = 10000;
  int n = 0;
  int m = 0;
  clock_t times;
  srand(time(NULL));
  while(T){
    BigNumber One;
    BigNumber Two;
    BigNumber Res;
    BigNumber Result;
  //  srand(time(NULL));
//    n = 1 + rand() % M;
  //  m = 1 + rand() % M;
    One.ReSize(M);
    Two.ReSize(M);
    One.RandomBigNumber();
    Two.RandomBigNumber();
    //std::cout << "this: " << One << std::endl;
    //std::cout << "Two: " << Two << std::endl;
    times = clock();
    Res = One.Karacuba(Two);
    times = clock() - times;
    --T;
    /*Result = One * Two;
    if (Res == Result){
      --T;
    }
    else {
      std::cout << "T: " << T << std::endl;
      std::cout << "Res: " << Res << std::endl;
      std::cout << "Result: " << Result << std::endl;
      break;
    }
  }
  float Times = (float(times)) / CLOCKS_PER_SEC;
  std::cout << "time Karacuba: " << Times  << std::endl;
  std::cout << "Карацуба быстрее в: " << Time1 / Times << " раз, чем обычное умножение" << std::endl;
*/

/*
  int T = 1000;
  int M = 1000;
  int n = 0;
  int m = 0;
  BigNumber S;//(ppower);
  BigNumber RR;//(str);
  divBig KK;
  BigNumber KEK;
  srand(time(NULL));
  while(T){
    n = 1 + rand() % M;
    m = 2 + rand() % (2*n);
    S.ReSize(n);
    RR.ReSize(m);
    S.RandomBigNumber();
    RR.RandomBigNumber();
    int k = n;
    char* tt = "1";
    BigNumber b(tt);
    b = b.PowOnBase(2*k);
    divBig Z;
    Z = b/S;
    KEK = RR.Barett(S,Z.res);
    KK = RR/S;
    if (KEK == KK.rem) {
      --T;
    //  std::cout << "T: " << T << std::endl;
      continue;
      //std::cout << "test complete" << std::endl;
    }
    else{
      std::cout << "T: " << T << std::endl;
      std::cout << "S: " << S << std::endl;
      std::cout << "RR: " << RR << std::endl;
      std::cout << "KEK: " << KEK << std::endl;
      std::cout << "KK: " << KK.rem << std::endl;
      break;
    }
  }
*/

/*
  int T = 1000;
  int M = 1000;
  int n = 0;
  int m = 0;
  BigNumber S;
  BigNumber RR;
  divBig KK;
  BigNumber KEK;
  //srand(time(NULL));
  //n = 1 + rand() %M;
  //m = 2*n;
  S.ReSize(1000);
  RR.ReSize(2000);
  S.RandomBigNumber();
  RR.RandomBigNumber();
  int k = 1000;
  char* tt = "1";
  BigNumber b(tt);
  b = b.PowOnBase(2*k);
  divBig Z;
  Z = b/S;
  clock_t times = 0;
  float Time;
  srand(time(NULL));
  times = clock();
  while(T){
    KEK = RR.Barett(S,Z.res);
    --T;
  }
  times = clock() - times;
  Time = (float(times)) / CLOCKS_PER_SEC;
  std::cout << "time Barett: " << Time << std::endl;


  int R = 1000;
  divBig Res;
  clock_t time1 = 0;
  time1 = clock();
  while(R){
/*  n = 1 + rand() %M;
  m = 2*n;
  S.ReSize(n);
  RR.ReSize(m);
  S.RandomBigNumber();
  RR.RandomBigNumber();
  Res = RR/S;
  --R;
  }
  time1 = clock() - time1;
  float Time1 = ((float)time1) / CLOCKS_PER_SEC;
  std::cout << "time A/B: " << Time1 << std::endl;
  std::cout << "Баретт быстрее в: " << Time1 / Time << " раз, чем обычное деление" << std::endl;
*/


char* kek="1B02761F9C6B100F64E1B27A78330195DA1F6902CDEAF4C71C71C7";
int t = 100;
bool flag = false;
BigNumber R(kek);
srand(time(NULL));
  flag = R.TMR(t);
  if(flag==true){
    std::cout << "simple number: " << R << std::endl;
  }
  else{
    std::cout << "YOU LOOSE" << std::endl;
  }

/*
char* kek="1B02761F9C6B100F64E1B27A78330195DA1F6902CDEAF4C71C71C7";
int t = 20;
bool flag = false;
//BigNumber R(kek);
BigNumber test(50);
srand(time(NULL));
while(flag==false){
  test.RandomBigNumber();
  flag = test.TMR(t);
  if(flag==true){
    std::cout << "simple number: " << test << std::endl;
  }
}
*/
}
