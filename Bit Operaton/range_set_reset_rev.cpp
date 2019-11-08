#include<bits/stdc++.h>
using namespace std;

/*
    SetBit ( 10 , 3 , 6 )
        10   = 0000 0000 0000 0000 0000 0000 0000 1010
        y    = 0000 0000 0000 0000 0000 0000 0001 0000
        y--  = 0000 0000 0000 0000 0000 0000 0000 1111
        y    = 0000 0000 0000 0000 0000 0000 0111 1000 (left shift by pos1)

    10 | y   = 0000 0000 0000 0000 0000 0000 0111 1010


    RangeReSetBit( 46 , 2, 6 )
        46   = 0000 0000 0000 0000 0000 0000 0010 1110
        y    = 0000 0000 0000 0000 0000 0000 0010 0000
        y--  = 0000 0000 0000 0000 0000 0000 0001 1111
        y    = 0000 0000 0000 0000 0000 0000 0111 1100 (left shift by pos1)
       ~y    = 1111 1111 1111 1111 1111 1111 1000 0011

    46 & y   = 0000 0000 0000 0000 0000 0000 0000 0010

    SetBit ( 10 , 3 , 6 )
        10   = 0000 0000 0000 0000 0000 0000 0000 1010
        y    = 0000 0000 0000 0000 0000 0000 0001 0000
        y--  = 0000 0000 0000 0000 0000 0000 0000 1111
        y    = 0000 0000 0000 0000 0000 0000 0111 1000 (left shift by pos1)

    10 ^ y   = 0000 0000 0000 0000 0000 0000 0111 0010
*/

int RangeSetBit(int val, int pos1,int pos2)
{
    int numOfBit = pos2-pos1+1;
    int y = 1 << numOfBit;
    y--;
    y = y << pos1;
    return val | y;
}

int RangeResetBit(int val,int pos1,int pos2)
{
    int numOfBit = pos2-pos1+1;
    int y = 1 << numOfBit;
    y--;
    y = y << pos1;
    y = ~y;
    return val & y;
}

int RangeReverseBit(int val,int pos1,int pos2)
{
    int numOfBit = pos2-pos1+1;
    int y = 1 << numOfBit;
    y--;
    y = y << pos1;
    return val ^ y;
}

int main()
{



    return 0;
}
