#ifndef AES_ENC_H
#define AES_ENC_H
#include "/tools/Xilinx/Vitis_HLS/2020.2/include/gmp.h"
#include "ap_int.h"
void aes_encrypt(ap_uint<256> * statemt256, ap_uint<256> key256, int type);
#endif
