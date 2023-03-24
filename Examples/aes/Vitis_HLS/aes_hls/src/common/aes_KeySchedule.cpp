/*
 +--------------------------------------------------------------------------+
 | CHStone : a suite of benchmark programs for C-based High-Level Synthesis |
 | ======================================================================== |
 |                                                                          |
 | * Collected and Modified : Y. Hara, H. Tomiyama, S. Honda,               |
 |                            H. Takada and K. Ishii                        |
 |                            Nagoya University, Japan                      |
 |                                                                          |
 | * Remark :                                                               |
 |    1. This source code is modified to unify the formats of the benchmark |
 |       programs in CHStone.                                               |
 |    2. Test vectors are added for CHStone.                                |
 |    3. If "main_result" is 0 at the end of the program, the program is    |
 |       correctly executed.                                                |
 |    4. Please follow the copyright of each benchmark program.             |
 +--------------------------------------------------------------------------+
 */
/* aes_key.c */
/*
 * Copyright (C) 2005
 * Akira Iwata & Masayuki Sato
 * Akira Iwata Laboratory,
 * Nagoya Institute of Technology in Japan.
 *
 * All rights reserved.
 *
 * This software is written by Masayuki Sato.
 * And if you want to contact us, send an email to Kimitake Wakayama
 * (wakayama@elcom.nitech.ac.jp)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. All advertising materials mentioning features or use of this software must
 *    display the following acknowledgment:
 *    "This product includes software developed by Akira Iwata Laboratory,
 *    Nagoya Institute of Technology in Japan
 * (http://mars.elcom.nitech.ac.jp/)."
 *
 * 4. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by Akira Iwata Laboratory,
 *     Nagoya Institute of Technology in Japan
 * (http://mars.elcom.nitech.ac.jp/)."
 *
 *   THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.
 *   AKIRA IWATA LABORATORY DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS
 *   SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS,
 *   IN NO EVENT SHALL AKIRA IWATA LABORATORY BE LIABLE FOR ANY SPECIAL,
 *   INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING
 *   FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 *   NEGLIGENCE OR OTHER TORTUOUS ACTION, ARISING OUT OF OR IN CONNECTION
 *   WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */

/*#include "aes.h"*/
#include "aes_KeySchedule.h"

/* **************key generate & key display *******************/
const unsigned char Rcon0[30] = {
    0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36,
    0x6c, 0xd8, 0xab, 0x4d, 0x9a, 0x2f, 0x5e, 0xbc, 0x63, 0xc6,
    0x97, 0x35, 0x6a, 0xd4, 0xb3, 0x7d, 0xfa, 0xef, 0xc5, 0x91,
};

// S盒
extern const unsigned char Sbox[16][16] = {
    {0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76},
    {0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0},
    {0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15},
    {0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75},
    {0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84},
    {0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf},
    {0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8},
    {0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2},
    {0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73},
    {0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb},
    {0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79},
    {0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08},
    {0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a},
    {0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e},
    {0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf},
    {0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16}};

//返回输入字节对应的S盒字节
#define SubByte(in) Sbox[(in) >> 4][(in) & 0xf]

/*  **************** key expand ************************ */
int KeySchedule(int type, unsigned char key[32], unsigned char word[4][120]) {
  // nk 密钥key的位数
  // nb 输入数据的位数
  unsigned char nk, nb, round_val;
  unsigned char i, j, temp[4];

  switch (type) {
  case 128128:
    nk = 4;
    nb = 4;
    round_val = 10;
    break;
  case 128192:
    nk = 4;
    nb = 6;
    round_val = 12;
    break;
  case 128256:
    nk = 4;
    nb = 8;
    round_val = 14;
    break;
  case 192128:
    nk = 6;
    nb = 4;
    round_val = 12;
    break;
  case 192192:
    nk = 6;
    nb = 6;
    round_val = 12;
    break;
  case 192256:
    nk = 6;
    nb = 8;
    round_val = 14;
    break;
  case 256128:
    nk = 8;
    nb = 4;
    round_val = 14;
    break;
  case 256192:
    nk = 8;
    nb = 6;
    round_val = 14;
    break;
  case 256256:
    nk = 8;
    nb = 8;
    round_val = 14;
    break;
  default:
    return -1;
  }
  //将密钥key赋值给密钥矩阵word，nk决定了密钥矩阵的列数
  for (j = 0; j < nk; ++j)
    for (i = 0; i < 4; ++i)
      /* 0 word */
      word[i][j] = key[i + j * 4];

  /* expanded key is generated */
  //扩展密钥矩阵word，数据字长nb与轮数round_val决定了扩展后的密钥矩阵的列数
  for (j = nk; j < nb * (round_val + 1); ++j) {

    /* RotByte */
    if ((j % nk) == 0) {
      //当j就是列数是nk的倍数时，临时列为对上一列执行，字循环，S盒代换，轮常量异或
      temp[0] = SubByte(word[1][j - 1]) ^ Rcon0[(j / nk) - 1];
      temp[1] = SubByte(word[2][j - 1]);
      temp[2] = SubByte(word[3][j - 1]);
      temp[3] = SubByte(word[0][j - 1]);
    }
    if ((j % nk) != 0) {
      //当j就是列数不是nk的倍数时，临时列为上一列
      temp[0] = word[0][j - 1];
      temp[1] = word[1][j - 1];
      temp[2] = word[2][j - 1];
      temp[3] = word[3][j - 1];
    }
    if (nk > 6 && j % nk == 4)
      //当初始密钥矩阵列数nk大于6同时所求的密钥新列数与nk求余等于4时，对临时列进行S盒代换
      for (i = 0; i < 4; ++i)
        temp[i] = SubByte(temp[i]);
    for (i = 0; i < 4; ++i)
      //密钥矩阵新列为前nk列和临时列异或运算
      word[i][j] = word[i][j - nk] ^ temp[i];
  }
  return 0;
}
