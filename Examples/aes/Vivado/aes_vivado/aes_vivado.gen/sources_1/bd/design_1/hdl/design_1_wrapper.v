//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Sun Apr 17 15:50:04 2022
//Host        : grunt-VirtualBox running 64-bit Ubuntu 20.04.4 LTS
//Command     : generate_target design_1_wrapper.bd
//Design      : design_1_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module design_1_wrapper
   (ap_clk_0,
    ap_ctrl_0_done,
    ap_ctrl_0_idle,
    ap_ctrl_0_ready,
    ap_ctrl_0_start,
    ap_rst_0,
    key256_0,
    statemt256_i_0,
    statemt256_o_0,
    statemt256_o_ap_vld_0,
    type_r_0);
  input ap_clk_0;
  output ap_ctrl_0_done;
  output ap_ctrl_0_idle;
  output ap_ctrl_0_ready;
  input ap_ctrl_0_start;
  input ap_rst_0;
  input [255:0]key256_0;
  input [255:0]statemt256_i_0;
  output [255:0]statemt256_o_0;
  output statemt256_o_ap_vld_0;
  input [31:0]type_r_0;

  wire ap_clk_0;
  wire ap_ctrl_0_done;
  wire ap_ctrl_0_idle;
  wire ap_ctrl_0_ready;
  wire ap_ctrl_0_start;
  wire ap_rst_0;
  wire [255:0]key256_0;
  wire [255:0]statemt256_i_0;
  wire [255:0]statemt256_o_0;
  wire statemt256_o_ap_vld_0;
  wire [31:0]type_r_0;

  design_1 design_1_i
       (.ap_clk_0(ap_clk_0),
        .ap_ctrl_0_done(ap_ctrl_0_done),
        .ap_ctrl_0_idle(ap_ctrl_0_idle),
        .ap_ctrl_0_ready(ap_ctrl_0_ready),
        .ap_ctrl_0_start(ap_ctrl_0_start),
        .ap_rst_0(ap_rst_0),
        .key256_0(key256_0),
        .statemt256_i_0(statemt256_i_0),
        .statemt256_o_0(statemt256_o_0),
        .statemt256_o_ap_vld_0(statemt256_o_ap_vld_0),
        .type_r_0(type_r_0));
endmodule
