#ifndef _AES_TYPECONVERT_H_
#define _AES_TYPECONVERT_H_
#include "/tools/Xilinx/Vitis_HLS/2020.2/include/gmp.h"
#include "ap_int.h"
void U256toU8(ap_uint<256> data256, unsigned char data8[32], int data_type);
void U8toU256(ap_uint<256> *data256, unsigned char data8[32], int data_type);
#endif
