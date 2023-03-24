#ifndef AES_DEC_H
#define AES_DEC_H

#include "/tools/Xilinx/Vitis_HLS/2020.2/include/gmp.h"

#include "ap_int.h"
void aes_decrypt(ap_uint<256> * statemt256, ap_uint<256> key256, int type);
#endif
