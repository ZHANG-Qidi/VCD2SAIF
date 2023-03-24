//Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
//Date        : Sun Apr 17 15:50:04 2022
//Host        : grunt-VirtualBox running 64-bit Ubuntu 20.04.4 LTS
//Command     : generate_target design_1.bd
//Design      : design_1
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

(* CORE_GENERATION_INFO = "design_1,IP_Integrator,{x_ipVendor=xilinx.com,x_ipLibrary=BlockDiagram,x_ipName=design_1,x_ipVersion=1.00.a,x_ipLanguage=VERILOG,numBlks=1,numReposBlks=1,numNonXlnxBlks=0,numHierBlks=0,maxHierDepth=0,numSysgenBlks=0,numHlsBlks=1,numHdlrefBlks=0,numPkgbdBlks=0,bdsource=USER,synth_mode=OOC_per_IP}" *) (* HW_HANDOFF = "design_1.hwdef" *) 
module design_1
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
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.AP_CLK_0 CLK" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.AP_CLK_0, ASSOCIATED_RESET ap_rst_0, CLK_DOMAIN design_1_ap_clk_0, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, INSERT_VIP 0, PHASE 0.000" *) input ap_clk_0;
  (* X_INTERFACE_INFO = "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_0 done" *) output ap_ctrl_0_done;
  (* X_INTERFACE_INFO = "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_0 idle" *) output ap_ctrl_0_idle;
  (* X_INTERFACE_INFO = "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_0 ready" *) output ap_ctrl_0_ready;
  (* X_INTERFACE_INFO = "xilinx.com:interface:acc_handshake:1.0 ap_ctrl_0 start" *) input ap_ctrl_0_start;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.AP_RST_0 RST" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.AP_RST_0, INSERT_VIP 0, POLARITY ACTIVE_HIGH" *) input ap_rst_0;
  (* X_INTERFACE_INFO = "xilinx.com:signal:data:1.0 DATA.KEY256_0 DATA" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME DATA.KEY256_0, LAYERED_METADATA undef" *) input [255:0]key256_0;
  (* X_INTERFACE_INFO = "xilinx.com:signal:data:1.0 DATA.STATEMT256_I_0 DATA" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME DATA.STATEMT256_I_0, LAYERED_METADATA undef" *) input [255:0]statemt256_i_0;
  (* X_INTERFACE_INFO = "xilinx.com:signal:data:1.0 DATA.STATEMT256_O_0 DATA" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME DATA.STATEMT256_O_0, LAYERED_METADATA undef" *) output [255:0]statemt256_o_0;
  output statemt256_o_ap_vld_0;
  (* X_INTERFACE_INFO = "xilinx.com:signal:data:1.0 DATA.TYPE_R_0 DATA" *) (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME DATA.TYPE_R_0, LAYERED_METADATA undef" *) input [31:0]type_r_0;

  wire [255:0]aes_encrypt_0_statemt256_o;
  wire aes_encrypt_0_statemt256_o_ap_vld;
  wire ap_clk_0_1;
  wire ap_ctrl_0_1_done;
  wire ap_ctrl_0_1_idle;
  wire ap_ctrl_0_1_ready;
  wire ap_ctrl_0_1_start;
  wire ap_rst_0_1;
  wire [255:0]key256_0_1;
  wire [255:0]statemt256_i_0_1;
  wire [31:0]type_r_0_1;

  assign ap_clk_0_1 = ap_clk_0;
  assign ap_ctrl_0_1_start = ap_ctrl_0_start;
  assign ap_ctrl_0_done = ap_ctrl_0_1_done;
  assign ap_ctrl_0_idle = ap_ctrl_0_1_idle;
  assign ap_ctrl_0_ready = ap_ctrl_0_1_ready;
  assign ap_rst_0_1 = ap_rst_0;
  assign key256_0_1 = key256_0[255:0];
  assign statemt256_i_0_1 = statemt256_i_0[255:0];
  assign statemt256_o_0[255:0] = aes_encrypt_0_statemt256_o;
  assign statemt256_o_ap_vld_0 = aes_encrypt_0_statemt256_o_ap_vld;
  assign type_r_0_1 = type_r_0[31:0];
  design_1_aes_encrypt_0_0 aes_encrypt_0
       (.ap_clk(ap_clk_0_1),
        .ap_done(ap_ctrl_0_1_done),
        .ap_idle(ap_ctrl_0_1_idle),
        .ap_ready(ap_ctrl_0_1_ready),
        .ap_rst(ap_rst_0_1),
        .ap_start(ap_ctrl_0_1_start),
        .key256(key256_0_1),
        .statemt256_i(statemt256_i_0_1),
        .statemt256_o(aes_encrypt_0_statemt256_o),
        .statemt256_o_ap_vld(aes_encrypt_0_statemt256_o_ap_vld),
        .type_r(type_r_0_1));
endmodule
