#ifndef _AES_FUNC_H_
#define _AES_FUNC_H_
void ByteSub_ShiftRow (int *, int);
void InversShiftRow_ByteSub (int *, int);
int MixColumn_AddRoundKey (int *, int, int);
int AddRoundKey_InversMixColumn (int *, int, int);
int AddRoundKey (int *, int, int);
#endif
