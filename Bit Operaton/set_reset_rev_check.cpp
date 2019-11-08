#include<bits/stdc++.h>
using namespace std;

/*
    SetBit ( 10 , 5 )
        10   = 0000 0000 0000 0000 0000 0000 0000 1010
        y    = 0000 0000 0000 0000 0000 0000 0010 0000 (by doing 1 << 5 )
    10 | y   = 0000 0000 0000 0000 0000 0000 0010 1010

    ReSetBit ( 42 , 5 )
        42   = 0000 0000 0000 0000 0000 0000 0010 1010
        ~y   = 1111 1111 1111 1111 1111 1111 1101 1111
    10 & ~y  = 0000 0000 0000 0000 0000 0000 0001 1010

    ReverseBit( 10 , 5 )
        10   = 0000 0000 0000 0000 0000 0000 0000 1010
        y    = 0000 0000 0000 0000 0000 0000 0010 0000 (by doing 1 << 5 )
    10 ^ y   = 0000 0000 0000 0000 0000 0000 0010 1010

    CheckBit( 10 , 5)
        42   = 0000 0000 0000 0000 0000 0000 0010 1010
        y    = 0000 0000 0000 0000 0000 0000 0010 0000
    10  & y  = 0000 0000 0000 0000 0000 0000 0010 0000  return 1/0

*/

/// int SetBit(int val,int pos) {return val | (1<<pos) ;}
int SetBit(int val, int pos)
{
    int y = 1 << pos;
    return val | y;
}

/// int ReSet(int val,int pos ) {return val & ~(1<<pos);}
int ReSet(int val,int pos)
{
    int y = 1 << pos;
    y = ~y;
    return val & y;
}

/// int ReverseBit(int val,int pos) {return val ^ (1<<pos);}
int ReverseBit(int val,int pos)
{
    int y = 1 << pos;
    return val ^ y;
}

/// int CheckBit(int val,int pos) {return val & (1<<pos);}
int CheckBit(int val,int pos)
{
    int y = 1 << pos;
    return val & y;
}


int main()
{


    return 0;
}
