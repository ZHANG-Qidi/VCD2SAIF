#ifndef AES_ENC_FUNC_H
#define AES_ENC_FUNC_H
void ByteSub_ShiftRow(unsigned char statemt[32], unsigned char nb);
int MixColumn_AddRoundKey(unsigned char statemt[32], unsigned char nb, unsigned char n, unsigned char word[4][120]);
#endif
