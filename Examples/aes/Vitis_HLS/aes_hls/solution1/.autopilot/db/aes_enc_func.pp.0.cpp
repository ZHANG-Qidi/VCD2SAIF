# 1 "aes_hls/src/encrypt/aes_enc_func.cpp"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 375 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/tools/Xilinx/Vitis_HLS/2020.2/common/technology/autopilot/etc/autopilot_ssdm_op.h" 1
# 158 "/tools/Xilinx/Vitis_HLS/2020.2/common/technology/autopilot/etc/autopilot_ssdm_op.h"
extern "C" {






    void _ssdm_op_IfRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_IfWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfNbWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_IfCanWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_StreamRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_StreamWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamNbWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_StreamCanWrite(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned _ssdm_StreamSize(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_ReadReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Read(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_WriteReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Write(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbReadReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    unsigned int __attribute__ ((bitwidth(1))) _ssdm_op_NbWriteReq(...) __attribute__ ((nothrow)) __attribute__((overloadable));




    void _ssdm_op_MemShiftRead(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_Wait(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_Poll(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_Return(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_op_SpecSynModule(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecTopModule(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProcessDecl(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProcessDef(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPort(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecConnection(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecChannel(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecSensitive(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecModuleInst(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPortMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecReset(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPlatform(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecClockDomain(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecPowerDomain(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    int _ssdm_op_SpecRegionBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    int _ssdm_op_SpecRegionEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecLoopName(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecLoopTripCount(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    int _ssdm_op_SpecStateBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    int _ssdm_op_SpecStateEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecInterface(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPipeline(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecDataflowPipeline(...) __attribute__ ((nothrow)) __attribute__((overloadable));


    void _ssdm_op_SpecLatency(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecParallel(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecProtocol(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecOccurrence(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecResource(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecResourceLimit(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecCHCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecFUCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecIFCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecIPCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecKeepValue(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecMemCore(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecExt(...) __attribute__ ((nothrow)) __attribute__((overloadable));




    void _ssdm_SpecArrayDimSize(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_RegionBegin(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_RegionEnd(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_Unroll(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_UnrollRegion(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_InlineAll(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineLoop(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_Inline(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineSelf(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_InlineRegion(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecArrayMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecArrayPartition(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecArrayReshape(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecStream(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecStable(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecStableContent(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecBindPort(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecPipoDepth(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecExpr(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecExprBalance(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecDependence(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecLoopMerge(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecLoopFlatten(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecLoopRewind(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_SpecFuncInstantiation(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecFuncBuffer(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecFuncExtract(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecConstant(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_DataPack(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_SpecDataPack(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void _ssdm_op_SpecBitsMap(...) __attribute__ ((nothrow)) __attribute__((overloadable));
    void _ssdm_op_SpecLicense(...) __attribute__ ((nothrow)) __attribute__((overloadable));

    void __xilinx_ip_top(...) __attribute__ ((nothrow)) __attribute__((overloadable));


}
# 2 "<built-in>" 2
# 1 "aes_hls/src/encrypt/aes_enc_func.cpp" 2
# 66 "aes_hls/src/encrypt/aes_enc_func.cpp"
# 1 "aes_hls/src/encrypt/aes_enc_func.h" 1


void ByteSub_ShiftRow(unsigned char statemt[32], unsigned char nb);
int MixColumn_AddRoundKey(unsigned char statemt[32], unsigned char nb, unsigned char n, unsigned char word[4][120]);
# 67 "aes_hls/src/encrypt/aes_enc_func.cpp" 2


extern const unsigned char Sbox[16][16];






void ByteSub_ShiftRow(unsigned char statemt[32], unsigned char nb) {
  unsigned char temp;


  switch (nb) {

  case 4:
# 93 "aes_hls/src/encrypt/aes_enc_func.cpp"
    temp = Sbox[(statemt[1]) >> 4][(statemt[1]) & 0xf];
    statemt[1] = Sbox[(statemt[5]) >> 4][(statemt[5]) & 0xf];
    statemt[5] = Sbox[(statemt[9]) >> 4][(statemt[9]) & 0xf];
    statemt[9] = Sbox[(statemt[13]) >> 4][(statemt[13]) & 0xf];
    statemt[13] = temp;

    temp = Sbox[(statemt[2]) >> 4][(statemt[2]) & 0xf];
    statemt[2] = Sbox[(statemt[10]) >> 4][(statemt[10]) & 0xf];
    statemt[10] = temp;
    temp = Sbox[(statemt[6]) >> 4][(statemt[6]) & 0xf];
    statemt[6] = Sbox[(statemt[14]) >> 4][(statemt[14]) & 0xf];
    statemt[14] = temp;

    temp = Sbox[(statemt[3]) >> 4][(statemt[3]) & 0xf];
    statemt[3] = Sbox[(statemt[15]) >> 4][(statemt[15]) & 0xf];
    statemt[15] = Sbox[(statemt[11]) >> 4][(statemt[11]) & 0xf];
    statemt[11] = Sbox[(statemt[7]) >> 4][(statemt[7]) & 0xf];
    statemt[7] = temp;

    statemt[0] = Sbox[(statemt[0]) >> 4][(statemt[0]) & 0xf];
    statemt[4] = Sbox[(statemt[4]) >> 4][(statemt[4]) & 0xf];
    statemt[8] = Sbox[(statemt[8]) >> 4][(statemt[8]) & 0xf];
    statemt[12] = Sbox[(statemt[12]) >> 4][(statemt[12]) & 0xf];
    break;
  case 6:
# 126 "aes_hls/src/encrypt/aes_enc_func.cpp"
    temp = Sbox[(statemt[1]) >> 4][(statemt[1]) & 0xf];
    statemt[1] = Sbox[(statemt[5]) >> 4][(statemt[5]) & 0xf];
    statemt[5] = Sbox[(statemt[9]) >> 4][(statemt[9]) & 0xf];
    statemt[9] = Sbox[(statemt[13]) >> 4][(statemt[13]) & 0xf];
    statemt[13] = Sbox[(statemt[17]) >> 4][(statemt[17]) & 0xf];
    statemt[17] = Sbox[(statemt[21]) >> 4][(statemt[21]) & 0xf];
    statemt[21] = temp;

    temp = Sbox[(statemt[2]) >> 4][(statemt[2]) & 0xf];
    statemt[2] = Sbox[(statemt[10]) >> 4][(statemt[10]) & 0xf];
    statemt[10] = Sbox[(statemt[18]) >> 4][(statemt[18]) & 0xf];
    statemt[18] = temp;
    temp = Sbox[(statemt[6]) >> 4][(statemt[6]) & 0xf];
    statemt[6] = Sbox[(statemt[14]) >> 4][(statemt[14]) & 0xf];
    statemt[14] = Sbox[(statemt[22]) >> 4][(statemt[22]) & 0xf];
    statemt[22] = temp;

    temp = Sbox[(statemt[3]) >> 4][(statemt[3]) & 0xf];
    statemt[3] = Sbox[(statemt[15]) >> 4][(statemt[15]) & 0xf];
    statemt[15] = temp;
    temp = Sbox[(statemt[7]) >> 4][(statemt[7]) & 0xf];
    statemt[7] = Sbox[(statemt[19]) >> 4][(statemt[19]) & 0xf];
    statemt[19] = temp;
    temp = Sbox[(statemt[11]) >> 4][(statemt[11]) & 0xf];
    statemt[11] = Sbox[(statemt[23]) >> 4][(statemt[23]) & 0xf];
    statemt[23] = temp;

    statemt[0] = Sbox[(statemt[0]) >> 4][(statemt[0]) & 0xf];
    statemt[4] = Sbox[(statemt[4]) >> 4][(statemt[4]) & 0xf];
    statemt[8] = Sbox[(statemt[8]) >> 4][(statemt[8]) & 0xf];
    statemt[12] = Sbox[(statemt[12]) >> 4][(statemt[12]) & 0xf];
    statemt[16] = Sbox[(statemt[16]) >> 4][(statemt[16]) & 0xf];
    statemt[20] = Sbox[(statemt[20]) >> 4][(statemt[20]) & 0xf];
    break;
  case 8:
# 169 "aes_hls/src/encrypt/aes_enc_func.cpp"
    temp = Sbox[(statemt[1]) >> 4][(statemt[1]) & 0xf];
    statemt[1] = Sbox[(statemt[5]) >> 4][(statemt[5]) & 0xf];
    statemt[5] = Sbox[(statemt[9]) >> 4][(statemt[9]) & 0xf];
    statemt[9] = Sbox[(statemt[13]) >> 4][(statemt[13]) & 0xf];
    statemt[13] = Sbox[(statemt[17]) >> 4][(statemt[17]) & 0xf];
    statemt[17] = Sbox[(statemt[21]) >> 4][(statemt[21]) & 0xf];
    statemt[21] = Sbox[(statemt[25]) >> 4][(statemt[25]) & 0xf];
    statemt[25] = Sbox[(statemt[29]) >> 4][(statemt[29]) & 0xf];
    statemt[29] = temp;

    temp = Sbox[(statemt[2]) >> 4][(statemt[2]) & 0xf];
    statemt[2] = Sbox[(statemt[14]) >> 4][(statemt[14]) & 0xf];
    statemt[14] = Sbox[(statemt[26]) >> 4][(statemt[26]) & 0xf];
    statemt[26] = Sbox[(statemt[6]) >> 4][(statemt[6]) & 0xf];
    statemt[6] = Sbox[(statemt[18]) >> 4][(statemt[18]) & 0xf];
    statemt[18] = Sbox[(statemt[30]) >> 4][(statemt[30]) & 0xf];
    statemt[30] = Sbox[(statemt[10]) >> 4][(statemt[10]) & 0xf];
    statemt[10] = Sbox[(statemt[22]) >> 4][(statemt[22]) & 0xf];
    statemt[22] = temp;

    temp = Sbox[(statemt[3]) >> 4][(statemt[3]) & 0xf];
    statemt[3] = Sbox[(statemt[19]) >> 4][(statemt[19]) & 0xf];
    statemt[19] = temp;
    temp = Sbox[(statemt[7]) >> 4][(statemt[7]) & 0xf];
    statemt[7] = Sbox[(statemt[23]) >> 4][(statemt[23]) & 0xf];
    statemt[23] = temp;
    temp = Sbox[(statemt[11]) >> 4][(statemt[11]) & 0xf];
    statemt[11] = Sbox[(statemt[27]) >> 4][(statemt[27]) & 0xf];
    statemt[27] = temp;
    temp = Sbox[(statemt[15]) >> 4][(statemt[15]) & 0xf];
    statemt[15] = Sbox[(statemt[31]) >> 4][(statemt[31]) & 0xf];
    statemt[31] = temp;

    statemt[0] = Sbox[(statemt[0]) >> 4][(statemt[0]) & 0xf];
    statemt[4] = Sbox[(statemt[4]) >> 4][(statemt[4]) & 0xf];
    statemt[8] = Sbox[(statemt[8]) >> 4][(statemt[8]) & 0xf];
    statemt[12] = Sbox[(statemt[12]) >> 4][(statemt[12]) & 0xf];
    statemt[16] = Sbox[(statemt[16]) >> 4][(statemt[16]) & 0xf];
    statemt[20] = Sbox[(statemt[20]) >> 4][(statemt[20]) & 0xf];
    statemt[24] = Sbox[(statemt[24]) >> 4][(statemt[24]) & 0xf];
    statemt[28] = Sbox[(statemt[28]) >> 4][(statemt[28]) & 0xf];
    break;
  }
}



int MixColumn_AddRoundKey(unsigned char statemt[32], unsigned char nb, unsigned char n, unsigned char word[4][120]) {
  unsigned char j;
  unsigned int ret[8 * 4];
  register unsigned int x;
# 228 "aes_hls/src/encrypt/aes_enc_func.cpp"
  VITIS_LOOP_228_1: for (j = 0; j < nb; ++j) {


    ret[j * 4] = (statemt[j * 4] << 1);
    if ((ret[j * 4] >> 8) == 1)
      ret[j * 4] ^= 283;

    x = statemt[1 + j * 4];
    x ^= (x << 1);
    if ((x >> 8) == 1)
      ret[j * 4] ^= (x ^ 283);
    else
      ret[j * 4] ^= x;

    ret[j * 4] ^= statemt[2 + j * 4] ^ statemt[3 + j * 4] ^ word[0][j + nb * n];


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
  VITIS_LOOP_281_2: for (j = 0; j < nb; ++j) {
    statemt[j * 4] = ret[j * 4];
    statemt[1 + j * 4] = ret[1 + j * 4];
    statemt[2 + j * 4] = ret[2 + j * 4];
    statemt[3 + j * 4] = ret[3 + j * 4];
  }
  return 0;
}
