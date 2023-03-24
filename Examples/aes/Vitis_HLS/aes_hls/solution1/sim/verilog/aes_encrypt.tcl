
log_wave [get_objects -filter {type == in_port || type == out_port || type == inout_port || type == port} /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/*]
set designtopgroup [add_wave_group "Design Top Signals"]
set cinoutgroup [add_wave_group "C InOuts" -into $designtopgroup]
set statemt256_group [add_wave_group statemt256(wire) -into $cinoutgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/statemt256_o_ap_vld -into $statemt256_group -color #ffff00 -radix hex
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/statemt256_o -into $statemt256_group -radix hex
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/statemt256_i -into $statemt256_group -radix hex
set cinputgroup [add_wave_group "C Inputs" -into $designtopgroup]
set type_group [add_wave_group type(wire) -into $cinputgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/type_r -into $type_group -radix hex
set key256_group [add_wave_group key256(wire) -into $cinputgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/key256 -into $key256_group -radix hex
set blocksiggroup [add_wave_group "Block-level IO Handshake" -into $designtopgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_start -into $blocksiggroup
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_done -into $blocksiggroup
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_idle -into $blocksiggroup
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_ready -into $blocksiggroup
set resetgroup [add_wave_group "Reset" -into $designtopgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_rst -into $resetgroup
set clockgroup [add_wave_group "Clock" -into $designtopgroup]
add_wave /apatb_aes_encrypt_top/AESL_inst_aes_encrypt/ap_clk -into $clockgroup
save_wave_config aes_encrypt.wcfg
run all
quit

