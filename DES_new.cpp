#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
void doPC1(_Bool*, unsigned char*, _Bool*);
void doPC2(_Bool*, unsigned char*, _Bool*);
void doIP(_Bool*, unsigned char*, _Bool*, _Bool*);
void printVector(_Bool*, unsigned char);
void partitionRL_(_Bool*, unsigned char, _Bool*, _Bool*);
void joinRL_(_Bool*, unsigned char, _Bool*, _Bool*);
void shift2Left(_Bool*, unsigned char, _Bool*);
void functionE(_Bool*, unsigned char*, _Bool*);
void XOR(_Bool*, _Bool*, unsigned char, _Bool*);
void functionS(_Bool*, unsigned char[][4][16], _Bool*);
void char2_Bool(unsigned char, _Bool*, unsigned char);
void functionF(_Bool*, _Bool*, unsigned char*, unsigned char[][4][16], unsigned char*, _Bool*);
void doIPInv(_Bool*, unsigned char*, _Bool*);

int main()
{
unsigned char PC1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4};
unsigned char PC2[48] = {14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32};
unsigned char IP_[64]  = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
unsigned char nLeftShift[16]  = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};
unsigned char EBitSelection[48] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
unsigned char P[32] = {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25};
unsigned char IPInv[64] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};
unsigned char S[8][4][16] = {
{{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7}, {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8}, {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0}, {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
{{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10}, {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5}, {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15}, {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
{{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8}, {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1}, {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7}, {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
{{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15}, {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9}, {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4}, {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
{{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9}, {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6}, {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14}, {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
{{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11}, {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8}, {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6}, {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
{{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1}, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6}, {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2}, {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
{{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7}, {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2}, {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8}, {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}
};

_Bool keyL[17][28]; // 17 keys, the length of each one is 56 / 2, denotes to C0, C1 to C16
_Bool keyR[17][28]; // 17 keys, the length of each one is 56 / 2, denotes to D0, D1 to D16
_Bool keyBeforePC2[16][56]; // 16 keys, the length of each one is 56 / 2, denotes to CnDn, n = 1:16
_Bool keyAfterPC2[16][48]; // 16 keys, the length of each one is 48 / 2, denotes to Kn, n = 1:16
_Bool messageL[17][32]; // 17 keys, the length of each one is 56 / 2, denotes to C0, C1 to C16
_Bool messageR[17][32]; // 17 keys, the length of each one is 56 / 2, denotes to D0, D1 to D16
_Bool EmessageR[17][48]; // After implementing function E over message R
_Bool KEmessageR[17][48]; // XOR of function E and Key
_Bool SmessageR[17][32] = {0}; // After applying S
_Bool FOutput[32] = {0}; // auxiliary var to store the output of F function
_Bool keyPlus[56];
_Bool PreCrypto[64];
doPC1(keyPlus, PC1, keyPlus);
printf("The K+ is :\n");
printVector(keyPlus, 56);
partitionRL_(keyPlus, 56, keyR[0], keyL[0]);
printf("\n The left part of K+ is :\n");
printVector(keyL[0], 28);
printf("\n The right part of K+ is :\n");
printVector(keyR[0], 28);
unsigned char i;
for (i = 1; i <= 16; i++)
{
    shift2Left(keyR[i - 1], nLeftShift[i - 1], keyR[i]);
    shift2Left(keyL[i - 1], nLeftShift[i - 1], keyL[i]);
    joinRL_(keyBeforePC2[i - 1], 56, keyR[i], keyL[i]);
    printf("The left part of K%d is :\t", i);
    printVector(keyL[i], 28);
    printf("The right part of K%d is :\t", i);
    printVector(keyR[i], 28);
}
for (i = 0; i < 16; i++)
{
    doPC2(keyBeforePC2[i], PC2, keyAfterPC2[i]);
    printf("\n The K%d after PC2 is :\n", i);
    printVector(keyAfterPC2[i - 1], 48);
}
doIP(PreCrypto, IP_, messageR[0], messageL[0]);
printf("The left part of message after IP is :\t");
printVector(messageL[0], 32);
printf("The right part of message after IP is :\t");
printVector(messageR[0], 32);
for (i = 1; i <= 16; i++)
{
    memcpy(messageL[i], messageR[i - 1], 32 * sizeof(messageR[i][0]));
    functionF(messageR[i - 1], keyAfterPC2[i - 1], EBitSelection, S, P, FOutput);
    XOR(messageL[i - 1], FOutput, 32, messageR[i]);
}
}
void doPC1(_Bool* key, unsigned char* PC1, _Bool* newKey)
{
unsigned char i;
for (i = 0; i < 56; i++)
{
    newKey[i] = key[PC1[i] - 1];
}
}
void doPC2(_Bool* key, unsigned char* PC2, _Bool* newKey)
{
unsigned char i;
for (i = 0; i < 48; i++)
{
    newKey[i] = key[PC2[i] - 1];
}
};
	void doPermutationP(_Bool* SmR, unsigned char* P, _Bool* PmR)
{
unsigned char i;
for (i = 0; i < 32; i++)
{
PmR[i] = SmR[P[i] - 1];
}
};
void doIP(_Bool* message, unsigned char* IP_, _Bool* newMessageR, _Bool* newMessageL)
{
_Bool newMessage[64];
unsigned char i;
for (i = 0; i < 64; i++)
{
newMessage[i] = message[IP_[i] - 1];
}
partitionRL(newMessage, 64, newMessageR, newMessageL);
}
void doPermutationP(_Bool* SmR, unsigned char* P, _Bool* PmR)
{
unsigned char i;
for (i = 0; i < 32; i++)
{
PmR[i] = SmR[P[i] - 1];
}
};
	
void doIPInv(_Bool* PreCrypto, unsigned char* IPInv, _Bool* Crypto)
{
unsigned char i;
for (i = 0; i < 64; i++)
{
Crypto[i] = PreCrypto[IPInv[i] - 1];
}
};
void functionE(_Bool* iVector, unsigned char* EBitSelection, _Bool* oVector)
{
unsigned char i;
for (i = 0; i < 48; i++)
{
oVector[i] = iVector[EBitSelection[i] - 1];
}
};
void functionS(_Bool* iVector, unsigned char S[][4][16], _Bool* oVector)
{
int i, j;
unsigned char charTmp, row, col;
_Bool boolTmp[4] = {0};
for (i = 0; i < 8; i++)
{
// The first and last bits of B represent in base 2 a number in the decimal range 0 to 3 (or binary 00 to 11).
    row = iVector[i * 6] * 2 + iVector[i * 6 + 5] * 1;
    col = iVector[i * 6 + 1] * 8 + iVector[i * 6 + 2] * 4 + iVector[i * 6 + 3] * 2 + iVector[i * 6 + 4] * 1;
    charTmp = S[i][row][col];
    char2_Bool(charTmp, boolTmp, 4);
    for (j = 0; j < 4; j++)
{
oVector[i * 4 + j] = boolTmp[j];
    }
}
};
void functionF(_Bool* mR, _Bool* Key, unsigned char* EBitSelection, unsigned char S[][4][16], unsigned char* P, _Bool* FOutput)
{
_Bool EmR[48] = {0}, KEmR[48] = {0}, SmR[32] = {0}, PmR[32] = {0};
functionE(mR, EBitSelection, EmR);
XOR(Key, EmR, 48, KEmR);
functionS(KEmR, S, SmR);
doPermutationP(SmR, P, PmR);
memcpy(FOutput, PmR, 32 * sizeof(PmR[0]));
}
void partitionRL(_Bool* vector, unsigned char length, _Bool* keyR, _Bool* keyL)
{
int i;
for (i = 0; i < ( length / 2 ); i++)
{
keyL[i] = vector[i];
 keyR[i] = vector[i + (length / 2)];
}
};
void joinRL(_Bool* vector, unsigned char length, _Bool* keyR, _Bool* keyL)
{
int i;
for (i = 0; i < ( length / 2 ); i++)
{
vector[i] = keyL[i];
 vector[i + (length / 2)] = keyR[i];
}
};
void printVector(_Bool* ip, unsigned char length)
{
int i;
for (i = 0; i < length; i++)
 printf("%d", *(ip + i));
printf("\n");
};
void shift2Left(_Bool* iVector, unsigned char nShifts, _Bool* oVector)
{
unsigned char shiftCntr, bitCntr, nBits = 28;
_Bool iVectorTmp[28];
for (bitCntr = 0; bitCntr < nBits; bitCntr++)
{
iVectorTmp[bitCntr] = iVector[bitCntr];
}
for (shiftCntr = 0; shiftCntr < nShifts; shiftCntr++)
{
oVector[nBits - 1] = iVectorTmp[0];
    for (bitCntr = 1; bitCntr < nBits; bitCntr++)
{
oVector[bitCntr - 1] = iVectorTmp[bitCntr];
    }
    for (bitCntr = 0; bitCntr < nBits; bitCntr++)
        iVectorTmp[bitCntr] = oVector[bitCntr];
}
};
void XOR(_Bool* vector1, _Bool* vector2, unsigned char nElements, _Bool* vectorRes)
{
int i;
for(i = 0; i < nElements; i++)
{
if ( ((vector1[i] == 1) && (vector2[i] == 0)) || ((vector1[i] == 0) && (vector2[i] == 1)) )
{
vectorRes[i] = 1;
    }
    else if ( ((vector1[i] == 1) && (vector2[i] == 1)) || ((vector1[i] == 0) && (vector2[i] == 0)) )
{
vectorRes[i] = 0;
    }
    }
}
void char2_Bool(unsigned char charVar, _Bool* boolVec, unsigned char nBits)
{
int i;
for (i = 0; i < nBits; i++)
{
if ( charVar % 2 == 0)
{
boolVec[nBits - i - 1] = 0;
        }
        else{
            boolVec[nBits - i - 1] = 1;
        }
    charVar = (charVar - (charVar % 2)) / 2;
    }
};
