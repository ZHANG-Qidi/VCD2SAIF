`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/17/2022 03:43:40 PM
// Design Name: 
// Module Name: aes
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module aes(

    );
    
  reg ap_clk_0;
  wire ap_ctrl_0_done;
  wire ap_ctrl_0_idle;
  wire ap_ctrl_0_ready;
  reg ap_ctrl_0_start;
  reg ap_rst_0;
  reg [255:0]key256_0;
  reg [255:0]statemt256_i_0;
  wire [255:0]statemt256_o_0;
  wire statemt256_o_ap_vld_0;
  reg [31:0]type_r_0;

  design_1_wrapper UUT
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

initial begin : dump_vcd
    $dumpfile("aes.vcd");
    $dumpvars(0, aes.UUT);
end

integer count = 0;
integer write_data;
initial begin
    write_data = $fopen("aes.csv");
    $fdisplay(write_data, "time,count");
end

`define PERIOD 10
`define _AES_N_ 10

initial begin
    ap_clk_0 = 1;
    forever #(`PERIOD/2) ap_clk_0 = ~ap_clk_0;
end

reg [31:0]type;
reg [255:0]key256;
reg [255:0]plaintext256_random;
reg [255:0]plaintext256_fixed;
reg [255:0]ciphertext256_random[0:`_AES_N_*2+1];
reg [255:0]ciphertext256_random_temp;
reg [255:0]ciphertext256_fiexd;

initial begin
    type = 32'd128128;
    key256 =              256'h0123456789ABCDEF0123456789ABCDEF;
    plaintext256_random = 256'h00000000000000000000000000000000;
    plaintext256_fixed =  256'h00000000000000000000000000000000;
    $readmemh("/home/grunt/Samba/DATA/AES/Data/ciphertext_plaintext/128128_ciphertext.txt", ciphertext256_random);
    ciphertext256_fiexd = 256'h79ABC5C23868AD84D388CE61110A6274;
end

initial begin
    type_r_0 = type;
    key256_0 = key256;
    statemt256_i_0 = plaintext256_random;
end

integer random_i = 0;
integer fixed_i = -1;
integer mode = 0;
integer error = 0;

initial fork
    $fdisplay(write_data, "%0t,reset", $realtime);
    ap_rst_0 <= 1;
    ap_ctrl_0_start <= 0;
    #(`PERIOD+1) ap_rst_0 <= 0;
    #(`PERIOD*2+1) begin
        ap_ctrl_0_start <= 1;
        @(posedge ap_clk_0) begin
            $fdisplay(write_data, "%0t,%0d", $realtime, count);
            $display("// RTL Simulation random : %0d / %0d [n/a] @ \"%0t\"", random_i, `_AES_N_*2+1, $realtime);
        end
    end
join

always @(posedge ap_clk_0)
begin
    if(ap_ctrl_0_done == 1) begin
        if(mode == 0) begin
            $display("// RTL Simulation random : %0d / %0d [n/a] @ \"%0t\"", random_i+1, `_AES_N_*2+1, $realtime);
            $display("expected random ciphertext:\t%h\nciphertext:\t%h", ciphertext256_random[random_i], statemt256_o_0);
            if(ciphertext256_random[random_i] == statemt256_o_0) begin
                $display("Simulation Passed.");
            end else begin
                $display("Simulation Failed.");
                error = error + 1;
            end
            if(fixed_i < `_AES_N_ - 1) begin
                mode = 1;
            end
            ciphertext256_random_temp = statemt256_o_0;
        end else if(mode == 1) begin
            $display("// RTL Simulation fiexd : %0d / %0d [n/a] @ \"%0t\"", fixed_i+1, `_AES_N_, $realtime);
            $display("expected fixed ciphertext:\t%h,\nciphertext:\t%h", ciphertext256_fiexd, statemt256_o_0);
            if(ciphertext256_fiexd == statemt256_o_0) begin
                $display("Simulation Passed.");
            end else begin
                $display("Simulation Failed.");
                error = error + 1;
            end
            mode = 0;
        end
        if(random_i == `_AES_N_ * 2) begin
            $display("Simulation with error: %0d.", error);
            $fclose(write_data);
            $finish;
        end
        if(mode == 0) begin
            random_i = random_i + 1;
            statemt256_i_0 = ciphertext256_random_temp;
        end else if(mode == 1) begin
            fixed_i = fixed_i + 1;
            statemt256_i_0 = plaintext256_fixed;
        end
        count = count + 1;
        $fdisplay(write_data, "%0t,%0d", $realtime, count);
    end
end

endmodule
