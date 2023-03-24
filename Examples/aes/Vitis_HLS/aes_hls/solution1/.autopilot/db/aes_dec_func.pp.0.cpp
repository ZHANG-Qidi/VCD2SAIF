# 1 "aes_hls/src/decrypt/aes_dec_func.cpp"
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
# 1 "aes_hls/src/decrypt/aes_dec_func.cpp" 2
# 66 "aes_hls/src/decrypt/aes_dec_func.cpp"
# 1 "aes_hls/src/decrypt/aes_dec_func.h" 1


void InversShiftRow_ByteSub(unsigned char statemt[32], unsigned char nb);
int AddRoundKey_InversMixColumn(unsigned char statemt[32], unsigned char nb, unsigned char n,
        unsigned char word[4][120]);
int AddRoundKey_dec(unsigned char statemt[32], int type, unsigned char n, unsigned char word[4][120]);
# 67 "aes_hls/src/decrypt/aes_dec_func.cpp" 2


const unsigned char invSbox[16][16] = {
    {0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb},
    {0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb},
    {0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e},
    {0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25},
    {0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92},
    {0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84},
    {0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06},
    {0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b},
    {0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73},
    {0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e},
    {0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b},
    {0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4},
    {0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f},
    {0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef},
    {0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61},
    {0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d}};



void InversShiftRow_ByteSub(unsigned char statemt[32], unsigned char nb) {
  unsigned char temp;

  switch (nb) {
  case 4:
    temp = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
    statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
    statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
    statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
    statemt[1] = temp;

    temp = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
    statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
    statemt[6] = temp;
    temp = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
    statemt[2] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
    statemt[10] = temp;

    temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
    statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
    statemt[3] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
    statemt[7] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
    statemt[11] = temp;

    statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
    statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
    statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
    statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
    break;
  case 6:
    temp = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
    statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
    statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
    statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
    statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
    statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
    statemt[1] = temp;

    temp = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
    statemt[22] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
    statemt[14] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
    statemt[6] = temp;
    temp = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
    statemt[18] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
    statemt[10] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
    statemt[2] = temp;

    temp = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
    statemt[15] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
    statemt[3] = temp;
    temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
    statemt[19] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
    statemt[7] = temp;
    temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
    statemt[23] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
    statemt[11] = temp;

    statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
    statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
    statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
    statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
    statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
    statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
    break;
  case 8:
    temp = invSbox[statemt[29] >> 4][statemt[29] & 0xf];
    statemt[29] = invSbox[statemt[25] >> 4][statemt[25] & 0xf];
    statemt[25] = invSbox[statemt[21] >> 4][statemt[21] & 0xf];
    statemt[21] = invSbox[statemt[17] >> 4][statemt[17] & 0xf];
    statemt[17] = invSbox[statemt[13] >> 4][statemt[13] & 0xf];
    statemt[13] = invSbox[statemt[9] >> 4][statemt[9] & 0xf];
    statemt[9] = invSbox[statemt[5] >> 4][statemt[5] & 0xf];
    statemt[5] = invSbox[statemt[1] >> 4][statemt[1] & 0xf];
    statemt[1] = temp;

    temp = invSbox[statemt[30] >> 4][statemt[30] & 0xf];
    statemt[30] = invSbox[statemt[18] >> 4][statemt[18] & 0xf];
    statemt[18] = invSbox[statemt[6] >> 4][statemt[6] & 0xf];
    statemt[6] = invSbox[statemt[26] >> 4][statemt[26] & 0xf];
    statemt[26] = invSbox[statemt[14] >> 4][statemt[14] & 0xf];
    statemt[14] = invSbox[statemt[2] >> 4][statemt[2] & 0xf];
    statemt[2] = invSbox[statemt[22] >> 4][statemt[22] & 0xf];
    statemt[22] = invSbox[statemt[10] >> 4][statemt[10] & 0xf];
    statemt[10] = temp;

    temp = invSbox[statemt[31] >> 4][statemt[31] & 0xf];
    statemt[31] = invSbox[statemt[15] >> 4][statemt[15] & 0xf];
    statemt[15] = temp;
    temp = invSbox[statemt[27] >> 4][statemt[27] & 0xf];
    statemt[27] = invSbox[statemt[11] >> 4][statemt[11] & 0xf];
    statemt[11] = temp;
    temp = invSbox[statemt[23] >> 4][statemt[23] & 0xf];
    statemt[23] = invSbox[statemt[7] >> 4][statemt[7] & 0xf];
    statemt[7] = temp;
    temp = invSbox[statemt[19] >> 4][statemt[19] & 0xf];
    statemt[19] = invSbox[statemt[3] >> 4][statemt[3] & 0xf];
    statemt[3] = temp;

    statemt[0] = invSbox[statemt[0] >> 4][statemt[0] & 0xf];
    statemt[4] = invSbox[statemt[4] >> 4][statemt[4] & 0xf];
    statemt[8] = invSbox[statemt[8] >> 4][statemt[8] & 0xf];
    statemt[12] = invSbox[statemt[12] >> 4][statemt[12] & 0xf];
    statemt[16] = invSbox[statemt[16] >> 4][statemt[16] & 0xf];
    statemt[20] = invSbox[statemt[20] >> 4][statemt[20] & 0xf];
    statemt[24] = invSbox[statemt[24] >> 4][statemt[24] & 0xf];
    statemt[28] = invSbox[statemt[28] >> 4][statemt[28] & 0xf];
    break;
  }
}



int AddRoundKey_InversMixColumn(unsigned char statemt[32], unsigned char nb,
                                unsigned char n, unsigned char word[4][120]) {
  unsigned char ret[8 * 4], i, j;
  register unsigned int x;


  VITIS_LOOP_207_1: for (j = 0; j < nb; ++j) {
    statemt[j * 4] ^= word[0][j + nb * n];
    statemt[1 + j * 4] ^= word[1][j + nb * n];
    statemt[2 + j * 4] ^= word[2][j + nb * n];
    statemt[3 + j * 4] ^= word[3][j + nb * n];
  }







  VITIS_LOOP_220_2: for (j = 0; j < nb; ++j)



    VITIS_LOOP_224_3: for (i = 0; i < 4; ++i) {

      x = (statemt[i + j * 4] << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[i + j * 4];

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[i + j * 4];

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;
      ret[i + j * 4] = x;


      x = (statemt[(i + 1) % 4 + j * 4] << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[(i + 1) % 4 + j * 4];

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[(i + 1) % 4 + j * 4];
      ret[i + j * 4] ^= x;


      x = (statemt[(i + 2) % 4 + j * 4] << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[(i + 2) % 4 + j * 4];

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;
      x ^= statemt[(i + 2) % 4 + j * 4];
      ret[i + j * 4] ^= x;



      x = (statemt[(i + 3) % 4 + j * 4] << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x = (x << 1);
      if ((x >> 8) == 1)
        x ^= 283;

      x ^= statemt[(i + 3) % 4 + j * 4];
      ret[i + j * 4] ^= x;
    }
  VITIS_LOOP_295_4: for (i = 0; i < nb; ++i) {
    statemt[i * 4] = ret[i * 4];
    statemt[1 + i * 4] = ret[1 + i * 4];
    statemt[2 + i * 4] = ret[2 + i * 4];
    statemt[3 + i * 4] = ret[3 + i * 4];
  }
  return 0;
}
