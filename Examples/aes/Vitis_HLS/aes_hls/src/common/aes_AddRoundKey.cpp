#include "aes_AddRoundKey.h"

/* ******** AddRoundKey ********** */
//轮密钥加，数据矩阵与扩展后的密钥矩阵中当前轮数所对应的密钥矩阵异或
int AddRoundKey(unsigned char statemt[32], int type, unsigned char n, unsigned char word[4][120]) {
  unsigned char j, nb;

  switch (type) {
  case 128128:
  case 192128:
  case 256128:
    nb = 4;
    break;
  case 128192:
  case 192192:
  case 256192:
    nb = 6;
    break;
  case 128256:
  case 192256:
  case 256256:
    nb = 8;
    break;
  }
  for (j = 0; j < nb; ++j) {
    statemt[j * 4] ^= word[0][j + nb * n];
    statemt[1 + j * 4] ^= word[1][j + nb * n];
    statemt[2 + j * 4] ^= word[2][j + nb * n];
    statemt[3 + j * 4] ^= word[3][j + nb * n];
  }
  return 0;
}

