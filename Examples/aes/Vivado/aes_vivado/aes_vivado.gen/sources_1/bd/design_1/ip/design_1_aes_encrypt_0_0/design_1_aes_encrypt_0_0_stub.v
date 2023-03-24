// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
// Date        : Sun Apr 17 15:51:38 2022
// Host        : grunt-VirtualBox running 64-bit Ubuntu 20.04.4 LTS
// Command     : write_verilog -force -mode synth_stub
//               /home/grunt/Vivado/aes_vivado/aes_vivado.gen/sources_1/bd/design_1/ip/design_1_aes_encrypt_0_0/design_1_aes_encrypt_0_0_stub.v
// Design      : design_1_aes_encrypt_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg484-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "aes_encrypt,Vivado 2020.2.2" *)
module design_1_aes_encrypt_0_0(statemt256_o_ap_vld, ap_clk, ap_rst, ap_start, 
  ap_done, ap_idle, ap_ready, statemt256_i, statemt256_o, key256, type_r)
/* synthesis syn_black_box black_box_pad_pin="statemt256_o_ap_vld,ap_clk,ap_rst,ap_start,ap_done,ap_idle,ap_ready,statemt256_i[255:0],statemt256_o[255:0],key256[255:0],type_r[31:0]" */;
  output statemt256_o_ap_vld;
  input ap_clk;
  input ap_rst;
  input ap_start;
  output ap_done;
  output ap_idle;
  output ap_ready;
  input [255:0]statemt256_i;
  output [255:0]statemt256_o;
  input [255:0]key256;
  input [31:0]type_r;
endmodule
