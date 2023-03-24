############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project aes_hls
set_top aes_encrypt
add_files aes_hls/src/common/aes_AddRoundKey.cpp
add_files aes_hls/src/common/aes_AddRoundKey.h
add_files aes_hls/src/common/aes_KeySchedule.cpp
add_files aes_hls/src/common/aes_KeySchedule.h
add_files aes_hls/src/common/aes_TypeConvert.cpp
add_files aes_hls/src/common/aes_TypeConvert.h
add_files aes_hls/src/decrypt/aes_dec.cpp
add_files aes_hls/src/decrypt/aes_dec.h
add_files aes_hls/src/decrypt/aes_dec_func.cpp
add_files aes_hls/src/decrypt/aes_dec_func.h
add_files aes_hls/src/encrypt/aes_enc.cpp
add_files aes_hls/src/encrypt/aes_enc.h
add_files aes_hls/src/encrypt/aes_enc_func.cpp
add_files aes_hls/src/encrypt/aes_enc_func.h
add_files -tb aes_hls/src/aes_tb.cpp
add_files -tb aes_hls/src/aes_tb.h
open_solution "solution1" -flow_target vivado
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./aes_hls/solution1/directives.tcl"
csim_design -clean
csynth_design
cosim_design -trace_level port
export_design -rtl verilog -format ip_catalog
