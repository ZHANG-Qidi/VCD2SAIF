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
/* aes.c */
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
#include "aes_tb.h"
#include "decrypt/aes_dec.h"
#include "encrypt/aes_enc.h"
#include "common/aes_TypeConvert.h"
#include "common/aes_AddRoundKey.h"
#include "ap_int.h"
#include <stdio.h>

ap_uint<256> key[3];
ap_uint<256> statemt[3];

/* ***************** main **************************** */
int aes_main(void) {
    key[0] = ap_uint<256>("0123456789ABCDEF0123456789ABCDEF", 16);
    key[1] = ap_uint<256>("0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF", 16);
    key[2] = ap_uint<256>("0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF", 16);
    statemt[0] = ap_uint<256>("00000000000000000000000000000000", 16);
    statemt[1] = ap_uint<256>("000000000000000000000000000000000000000000000000", 16);
    statemt[2] = ap_uint<256>("0000000000000000000000000000000000000000000000000000000000000000", 16);

	/*
	 +--------------------------------------------------------------------------+
	 | * Test Vectors (added for CHStone)                                       |
	 |     statemt, key : input data                                            |
	 +--------------------------------------------------------------------------+
	 */

	// bits of key, bits of statemt
	int type;
	int type_list[3] = {128, 192, 256};
	ap_uint<256> statemt_temp;
	int main_result = 0;
	for(int i = 0; i < 3; i++){
	    for(int j = 0; j < 3; j++){
	        statemt_temp = statemt[i];
	        type = type_list[j] * 1000 + type_list[i];
	        // 输出原始数据
	        // print original data
	        printf("Run in AES%d mode\n", type);
	        printf("message\t\t\t\t%s\n", statemt_temp.to_string(16).c_str());
	        printf("key\t\t\t\t\t%s\n", key[j].to_string(16).c_str());
	        // 加密计算
	        aes_encrypt(&statemt_temp, key[j], type);
	        printf("encrypted message\t%s\n", statemt_temp.to_string(16).c_str());
	        // 解密计算
	        aes_decrypt(&statemt_temp, key[j], type);
	        // test of decrypt
	        printf("decrypted message\t%s\n\n", statemt_temp.to_string(16).c_str());
	        main_result += (statemt_temp != statemt[i]);
	    }
	}
	printf("Check decrypted message = %03d\n", main_result);
	return main_result;
}
int main() {
	int main_result;
	main_result = aes_main();
	printf("%d\n", main_result);
	return main_result;
}
