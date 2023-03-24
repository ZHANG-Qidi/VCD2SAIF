#include "aes_TypeConvert.h"
//  转换256位数据到32长度的8位数组中，8位数组最低位为256位最高位
void U256toU8(ap_uint<256> data256, unsigned char data8[32], int data_type) {
	unsigned char round;
	switch (data_type) {
	case 128:
		round = 16;
		break;
	case 192:
		round = 24;
		break;
	default:
		round = 32;
		break;
	}
	for (int i = 0; i < round; i++) {
		data8[round - 1 - i] = data256.range(i * 8 + 7, i * 8);
	}
}
// 转换32长度8位数组到256位数据中，8位数组最低位为256位最高位
void U8toU256(ap_uint<256> *data256, unsigned char data8[32], int data_type) {
	unsigned char round;
	switch (data_type) {
	case 128:
		round = 16;
		(*data256).range(255, 128) = ap_uint<128>("0", 16);
		break;
	case 192:
		round = 24;
		(*data256).range(255, 192) = ap_uint<64>("0", 16);
		break;
	default:
		round = 32;
		break;
	}
	for (int i = 0; i < round; i++) {
		(*data256).range(i * 8 + 7, i * 8) = data8[round - 1 - i];
	}
}
