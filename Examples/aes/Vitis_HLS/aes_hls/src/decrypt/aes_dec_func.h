#ifndef AES_DEC_FUNC_H
#define AES_DEC_FUNC_H
void InversShiftRow_ByteSub(unsigned char statemt[32], unsigned char nb);
int AddRoundKey_InversMixColumn(unsigned char statemt[32], unsigned char nb, unsigned char n,
        unsigned char word[4][120]);
int AddRoundKey_dec(unsigned char statemt[32], int type, unsigned char n, unsigned char word[4][120]);
#endif
