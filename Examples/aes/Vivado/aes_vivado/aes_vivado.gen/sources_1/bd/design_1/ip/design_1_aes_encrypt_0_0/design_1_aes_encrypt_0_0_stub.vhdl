-- Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2020.2.2 (lin64) Build 3118627 Tue Feb  9 05:13:49 MST 2021
-- Date        : Sun Apr 17 15:51:38 2022
-- Host        : grunt-VirtualBox running 64-bit Ubuntu 20.04.4 LTS
-- Command     : write_vhdl -force -mode synth_stub
--               /home/grunt/Vivado/aes_vivado/aes_vivado.gen/sources_1/bd/design_1/ip/design_1_aes_encrypt_0_0/design_1_aes_encrypt_0_0_stub.vhdl
-- Design      : design_1_aes_encrypt_0_0
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7z020clg484-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_aes_encrypt_0_0 is
  Port ( 
    statemt256_o_ap_vld : out STD_LOGIC;
    ap_clk : in STD_LOGIC;
    ap_rst : in STD_LOGIC;
    ap_start : in STD_LOGIC;
    ap_done : out STD_LOGIC;
    ap_idle : out STD_LOGIC;
    ap_ready : out STD_LOGIC;
    statemt256_i : in STD_LOGIC_VECTOR ( 255 downto 0 );
    statemt256_o : out STD_LOGIC_VECTOR ( 255 downto 0 );
    key256 : in STD_LOGIC_VECTOR ( 255 downto 0 );
    type_r : in STD_LOGIC_VECTOR ( 31 downto 0 )
  );

end design_1_aes_encrypt_0_0;

architecture stub of design_1_aes_encrypt_0_0 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "statemt256_o_ap_vld,ap_clk,ap_rst,ap_start,ap_done,ap_idle,ap_ready,statemt256_i[255:0],statemt256_o[255:0],key256[255:0],type_r[31:0]";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "aes_encrypt,Vivado 2020.2.2";
begin
end;
