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
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
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
 *    Nagoya Institute of Technology in Japan (http://mars.elcom.nitech.ac.jp/)."
 *
 * 4. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by Akira Iwata Laboratory,
 *     Nagoya Institute of Technology in Japan (http://mars.elcom.nitech.ac.jp/)."
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
#include <stdio.h>

#include "aes.h"
#include "aes_enc.h"
#include "aes_dec.h"

void print_statemt(int type, int* statemt){
  for(int i = 0; i < (type%1000)/8; i++){
    printf("%02X", statemt[i]);
  }
  putchar('\n');
}

void print_key(int type, int* key){
  for(int i = 0; i < (type/1000)/8; i++){
    printf("%02X", key[i]);
  }
  putchar('\n');
}

/* ***************** main **************************** */
int
aes_main (void)
{
/*
+--------------------------------------------------------------------------+
| * Test Vectors (added for CHStone)                                       |
|     statemt, key : input data                                            |
+--------------------------------------------------------------------------+
*/
  int key[32];
  int statemt[32];
  int type;
  char * statemt_str = "0000000000000000000000000000000000000000000000000000000000000000";
  char * key_str = "0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";
  int index = 256;
  FILE * fp;
  unsigned int type_list[] = {128 , 192, 256};
  char file_name[256];
  for(int m = 0; m < 3; m++){
    for(int n = 0; n < 3; n++){
      type = type_list[m] * 1000 + type_list[n];
      for(int i = 0; i < (type/1000)/8; i++){
        char split[3];
        split[0] = key_str[i * 2];
        split[1] = key_str[i * 2 + 1];
        split[3] = '\0';
        sscanf(split, "%x", key + i);
      }
      for(int i = 0; i < (type%1000)/8; i++){
        char split[3];
        split[0] = statemt_str[i * 2];
        split[1] = statemt_str[i * 2 + 1];
        split[2] = '\0';
        sscanf(split, "%x", statemt + i);
      }
      printf("%03dkey:\t\t\t", type/1000);
      print_key(type, key);
      //putchar('\n');
      printf("%03dplaintext:\t\t", type%1000);
      print_statemt(type, statemt);
      encrypt(statemt, key, type);
      printf("%06dciphertext:\t", type);
      print_statemt(type, statemt);
      decrypt(statemt, key, type);
      printf("%06ddecrypted:\t", type);
      print_statemt(type, statemt);
      putchar('\n');
      sprintf(file_name, "ciphertext_plaintext/%06d_ciphertext.txt", type);
      fp = fopen (file_name, "w");
      for (int j = 0; j < index; j++){
        encrypt (statemt, key, type);
        for (int i = 0; i < (type%1000)/8; ++i){
          fprintf(fp, "%02X", statemt[i]);
        }
        fprintf(fp, "\r\n");
      }
      fclose(fp);
      sprintf(file_name, "ciphertext_plaintext/%06d_plaintext.txt", type);
      fp = fopen (file_name, "w");
      for (int j = 0; j < index; j++){
        decrypt (statemt, key, type);
        for (int i = 0; i < (type%1000)/8; ++i){
          fprintf(fp, "%02X", statemt[i]);
        }
        fprintf(fp, "\r\n");
      }
      fclose(fp);
    }
  }
  return 0;
}

int
main (){
  main_result = 0;
  aes_main ();
  return 0;
}
