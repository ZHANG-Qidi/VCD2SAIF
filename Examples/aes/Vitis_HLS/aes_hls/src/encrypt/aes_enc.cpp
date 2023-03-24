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
/* aes_enc.c */
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

#include "aes_enc.h"
#include "aes_enc_func.h"
#include "../common/aes_KeySchedule.h"
#include "../common/aes_AddRoundKey.h"
#include "../common/aes_TypeConvert.h"

/*  ******* encrypto ************ */
void aes_encrypt(ap_uint<256> *statemt256, ap_uint<256> key256, int type) {
	unsigned char i;
	unsigned char word[4][120];
	unsigned char nb;
	unsigned char round_val;

	unsigned char statemt[32];
	unsigned char key[32];
	int statemt_type;
	int key_type;
	switch (type) {
	case 128128:
		key_type = 128;
		statemt_type = 128;
		break;
	case 192128:
		key_type = 192;
		statemt_type = 128;
		break;
	case 256128:
		key_type = 256;
		statemt_type = 128;
		break;
	case 128192:
		key_type = 128;
		statemt_type = 192;
		break;
	case 192192:
		key_type = 192;
		statemt_type = 192;
		break;
	case 256192:
		key_type = 256;
		statemt_type = 192;
		break;
	case 128256:
		key_type = 128;
		statemt_type = 256;
		break;
	case 192256:
		key_type = 192;
		statemt_type = 256;
		break;
	case 256256:
		key_type = 256;
		statemt_type = 256;
		break;
	default:
		break;
	}
	U256toU8(*statemt256, statemt, statemt_type);
	U256toU8(key256, key, key_type);

	/*
	 +--------------------------------------------------------------------------+
	 | * Test Vector (added for CHStone)                                        |
	 |     out_enc_statemt : expected output data for "encrypt"                 |
	 +--------------------------------------------------------------------------+
	 */
	//拡大鍵生成
	//入力：type、aes種類
	//入力：key、128bit鍵
	//出力：word、拡大鍵
	KeySchedule(type, key, word);
	switch (type) {
	case 128128:
		round_val = 0;
		nb = 4;
		break;
	case 192128:
		round_val = 2;
		nb = 4;
		break;
	case 256128:
		round_val = 4;
		nb = 4;
		break;
	case 128192:
	case 192192:
		round_val = 2;
		nb = 6;
		break;
	case 256192:
		round_val = 4;
		nb = 6;
		break;
	case 128256:
	case 192256:
	case 256256:
		round_val = 4;
		nb = 8;
		break;
	}
	// ラウンド鍵とのXORをとる
	AddRoundKey(statemt, type, 0, word);
	for (i = 1; i <= round_val + 9; ++i) {
		// 換字表（Sボックス）による１バイト単位の置換、4バイト単位の行を一定規則で左シフトする
		ByteSub_ShiftRow(statemt, nb);
		// ビット演算による４バイト単位の行列変換、ラウンド鍵とのXORをとる
		MixColumn_AddRoundKey(statemt, nb, i, word);
	}
	// 換字表（Sボックス）による１バイト単位の置換、4バイト単位の行を一定規則で左シフトする
	ByteSub_ShiftRow(statemt, nb);
	// ラウンド鍵とのXORをとる
	AddRoundKey(statemt, type, i, word);
	U8toU256(statemt256, statemt, statemt_type);
}
