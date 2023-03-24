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
/* aes_function.c */
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
#include "aes_enc_func.h"

// S盒
extern const unsigned char Sbox[16][16];

//返回输入字节对应的S盒字节
#define SubByte(in) Sbox[(in) >> 4][(in) & 0xf]

/* ********* ByteSub & ShiftRow ********* */
// S盒代换与行移位
void ByteSub_ShiftRow(unsigned char statemt[32], unsigned char nb) {
  unsigned char temp;

  //根据输入数据位数选择
  switch (nb) {
  //当输入数据为4字节时，对statemt[0]到statemt[15]进行S盒代换，同时执行行移位，移位方式为向左循环移位
  case 4:
    //每一块代表输入数据矩阵的1行
    /*((0 4 8 12)
     * (1 5 9 13)
     * (2 6 10 14)
     * (3 7 11 15))*/
    //行移位后
    /*((0 4 8 12)0位
     * (5 9 13 1)1位
     * (10 14 2 6)2位
     * (15 3 7 11))3位*/
    temp = SubByte(statemt[1]);
    statemt[1] = SubByte(statemt[5]);
    statemt[5] = SubByte(statemt[9]);
    statemt[9] = SubByte(statemt[13]);
    statemt[13] = temp;

    temp = SubByte(statemt[2]);
    statemt[2] = SubByte(statemt[10]);
    statemt[10] = temp;
    temp = SubByte(statemt[6]);
    statemt[6] = SubByte(statemt[14]);
    statemt[14] = temp;

    temp = SubByte(statemt[3]);
    statemt[3] = SubByte(statemt[15]);
    statemt[15] = SubByte(statemt[11]);
    statemt[11] = SubByte(statemt[7]);
    statemt[7] = temp;

    statemt[0] = SubByte(statemt[0]);
    statemt[4] = SubByte(statemt[4]);
    statemt[8] = SubByte(statemt[8]);
    statemt[12] = SubByte(statemt[12]);
    break;
  case 6:
    /*((0 4 8 12 16 20)
     * (1 5 9 13 17 21)
     * (2 6 10 14 18 22)
     * (3 7 11 15 19 23))*/
    /*((0 4 8 12 16 20)0位
     * (5 9 13 17 21 1)1位
     * (10 14 18 22 2 6)2位
     * (15 19 23 3 7 11))3位*/
    temp = SubByte(statemt[1]);
    statemt[1] = SubByte(statemt[5]);
    statemt[5] = SubByte(statemt[9]);
    statemt[9] = SubByte(statemt[13]);
    statemt[13] = SubByte(statemt[17]);
    statemt[17] = SubByte(statemt[21]);
    statemt[21] = temp;

    temp = SubByte(statemt[2]);
    statemt[2] = SubByte(statemt[10]);
    statemt[10] = SubByte(statemt[18]);
    statemt[18] = temp;
    temp = SubByte(statemt[6]);
    statemt[6] = SubByte(statemt[14]);
    statemt[14] = SubByte(statemt[22]);
    statemt[22] = temp;

    temp = SubByte(statemt[3]);
    statemt[3] = SubByte(statemt[15]);
    statemt[15] = temp;
    temp = SubByte(statemt[7]);
    statemt[7] = SubByte(statemt[19]);
    statemt[19] = temp;
    temp = SubByte(statemt[11]);
    statemt[11] = SubByte(statemt[23]);
    statemt[23] = temp;

    statemt[0] = SubByte(statemt[0]);
    statemt[4] = SubByte(statemt[4]);
    statemt[8] = SubByte(statemt[8]);
    statemt[12] = SubByte(statemt[12]);
    statemt[16] = SubByte(statemt[16]);
    statemt[20] = SubByte(statemt[20]);
    break;
  case 8:
    /*((0 4 8 12 16 20 24 28)
     * (1 5 9 13 17 21 25 29)
     * (2 6 10 14 18 22 26 30)
     * (3 7 11 15 19 23 27 31))*/
    /*((0 4 8 12 16 20 24 28)左移0位
     * (5 9 13 17 21 25 29 1)左移1位
     * (14 18 22 26 30 2 6 10)左移3位
     * (19 23 27 31 3 7 11 15))左移4位*/
    temp = SubByte(statemt[1]);
    statemt[1] = SubByte(statemt[5]);
    statemt[5] = SubByte(statemt[9]);
    statemt[9] = SubByte(statemt[13]);
    statemt[13] = SubByte(statemt[17]);
    statemt[17] = SubByte(statemt[21]);
    statemt[21] = SubByte(statemt[25]);
    statemt[25] = SubByte(statemt[29]);
    statemt[29] = temp;

    temp = SubByte(statemt[2]);
    statemt[2] = SubByte(statemt[14]);
    statemt[14] = SubByte(statemt[26]);
    statemt[26] = SubByte(statemt[6]);
    statemt[6] = SubByte(statemt[18]);
    statemt[18] = SubByte(statemt[30]);
    statemt[30] = SubByte(statemt[10]);
    statemt[10] = SubByte(statemt[22]);
    statemt[22] = temp;

    temp = SubByte(statemt[3]);
    statemt[3] = SubByte(statemt[19]);
    statemt[19] = temp;
    temp = SubByte(statemt[7]);
    statemt[7] = SubByte(statemt[23]);
    statemt[23] = temp;
    temp = SubByte(statemt[11]);
    statemt[11] = SubByte(statemt[27]);
    statemt[27] = temp;
    temp = SubByte(statemt[15]);
    statemt[15] = SubByte(statemt[31]);
    statemt[31] = temp;

    statemt[0] = SubByte(statemt[0]);
    statemt[4] = SubByte(statemt[4]);
    statemt[8] = SubByte(statemt[8]);
    statemt[12] = SubByte(statemt[12]);
    statemt[16] = SubByte(statemt[16]);
    statemt[20] = SubByte(statemt[20]);
    statemt[24] = SubByte(statemt[24]);
    statemt[28] = SubByte(statemt[28]);
    break;
  }
}

/* ******** MixColumn ********** */
//列混合与轮密钥加，形参n表示当前轮数
int MixColumn_AddRoundKey(unsigned char statemt[32], unsigned char nb, unsigned char n, unsigned char word[4][120]) {
  unsigned char j;
  unsigned int ret[8 * 4];
  register unsigned int x;

  //列混合矩阵
  /*((2 3 1 1)
   (1 2 3 1)
   (1 1 2 3)
   (3 1 1 2))*/
  //循环输入的字节数
  //该循环相当于数据矩阵左乘列混合矩阵同时进行轮密钥加
  for (j = 0; j < nb; ++j) {
    //(2 3 1 1)
    // GF28域内乘2
    ret[j * 4] = (statemt[j * 4] << 1);
    if ((ret[j * 4] >> 8) == 1)
      ret[j * 4] ^= 283;
    // GF28域内乘3
    x = statemt[1 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1)
      ret[j * 4] ^= (x ^ 283);
    else
      ret[j * 4] ^= x;
    //异或word相当于轮密钥加操作
    ret[j * 4] ^= statemt[2 + j * 4] ^ statemt[3 + j * 4] ^ word[0][j + nb * n];

    //(1 2 3 1)
    ret[1 + j * 4] = (statemt[1 + j * 4] << 1);
    if ((ret[1 + j * 4] >> 8) == 1)
      ret[1 + j * 4] ^= 283;
    x = statemt[2 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1)
      ret[1 + j * 4] ^= (x ^ 283);
    else
      ret[1 + j * 4] ^= x;
    ret[1 + j * 4] ^= statemt[3 + j * 4] ^ statemt[j * 4] ^ word[1][j + nb * n];

    //(1 1 2 3)
    ret[2 + j * 4] = (statemt[2 + j * 4] << 1);
    if ((ret[2 + j * 4] >> 8) == 1)
      ret[2 + j * 4] ^= 283;
    x = statemt[3 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1)
      ret[2 + j * 4] ^= (x ^ 283);
    else
      ret[2 + j * 4] ^= x;
    ret[2 + j * 4] ^= statemt[j * 4] ^ statemt[1 + j * 4] ^ word[2][j + nb * n];

    //(3 1 1 2)
    ret[3 + j * 4] = (statemt[3 + j * 4] << 1);
    if ((ret[3 + j * 4] >> 8) == 1)
      ret[3 + j * 4] ^= 283;
    x = statemt[j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1)
      ret[3 + j * 4] ^= (x ^ 283);
    else
      ret[3 + j * 4] ^= x;
    ret[3 + j * 4] ^=
        statemt[1 + j * 4] ^ statemt[2 + j * 4] ^ word[3][j + nb * n];
  }
  for (j = 0; j < nb; ++j) {
    statemt[j * 4] = ret[j * 4];
    statemt[1 + j * 4] = ret[1 + j * 4];
    statemt[2 + j * 4] = ret[2 + j * 4];
    statemt[3 + j * 4] = ret[3 + j * 4];
  }
  return 0;
}

