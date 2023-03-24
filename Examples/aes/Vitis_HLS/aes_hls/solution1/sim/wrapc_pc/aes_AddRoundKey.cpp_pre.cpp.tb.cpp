// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.2.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "/home/grunt/Vitis_HLS/aes_hls/src/common/aes_AddRoundKey.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "/home/grunt/Vitis_HLS/aes_hls/src/common/aes_AddRoundKey.cpp"
# 1 "/home/grunt/Vitis_HLS/aes_hls/src/common/aes_AddRoundKey.h" 1


int AddRoundKey(unsigned char statemt[32], int type, unsigned char n, unsigned char word[4][120]);
# 2 "/home/grunt/Vitis_HLS/aes_hls/src/common/aes_AddRoundKey.cpp" 2



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
