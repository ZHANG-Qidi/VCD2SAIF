#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_statemt256 "../tv/cdatafile/c.aes_encrypt.autotvin_statemt256.dat"
#define AUTOTB_TVOUT_statemt256 "../tv/cdatafile/c.aes_encrypt.autotvout_statemt256.dat"
// wrapc file define:
#define AUTOTB_TVIN_key256 "../tv/cdatafile/c.aes_encrypt.autotvin_key256.dat"
#define AUTOTB_TVOUT_key256 "../tv/cdatafile/c.aes_encrypt.autotvout_key256.dat"
// wrapc file define:
#define AUTOTB_TVIN_type "../tv/cdatafile/c.aes_encrypt.autotvin_type_r.dat"
#define AUTOTB_TVOUT_type "../tv/cdatafile/c.aes_encrypt.autotvout_type_r.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_statemt256 "../tv/rtldatafile/rtl.aes_encrypt.autotvout_statemt256.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_key256 "../tv/rtldatafile/rtl.aes_encrypt.autotvout_key256.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_type "../tv/rtldatafile/rtl.aes_encrypt.autotvout_type_r.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  statemt256_depth = 0;
  key256_depth = 0;
  type_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{statemt256 " << statemt256_depth << "}\n";
  total_list << "{key256 " << key256_depth << "}\n";
  total_list << "{type_r " << type_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int statemt256_depth;
    int key256_depth;
    int type_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
struct __cosim_s20__ { char data[32]; };
extern "C" void aes_encrypt_hw_stub_wrapper(volatile void *, __cosim_s20__*, int);

extern "C" void apatb_aes_encrypt_hw(volatile void * __xlx_apatb_param_statemt256, __cosim_s20__* __xlx_apatb_param_key256, int __xlx_apatb_param_type) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_statemt256);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<256> > statemt256_pc_buffer(1);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "statemt256");
  
            // push token into output port buffer
            if (AESL_token != "") {
              statemt256_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {((long long*)__xlx_apatb_param_statemt256)[0*4+0] = statemt256_pc_buffer[0].range(63,0).to_int64();
((long long*)__xlx_apatb_param_statemt256)[0*4+1] = statemt256_pc_buffer[0].range(127,64).to_int64();
((long long*)__xlx_apatb_param_statemt256)[0*4+2] = statemt256_pc_buffer[0].range(191,128).to_int64();
((long long*)__xlx_apatb_param_statemt256)[0*4+3] = statemt256_pc_buffer[0].range(255,192).to_int64();
}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//statemt256
aesl_fh.touch(AUTOTB_TVIN_statemt256);
aesl_fh.touch(AUTOTB_TVOUT_statemt256);
//key256
aesl_fh.touch(AUTOTB_TVIN_key256);
aesl_fh.touch(AUTOTB_TVOUT_key256);
//type
aesl_fh.touch(AUTOTB_TVIN_type);
aesl_fh.touch(AUTOTB_TVOUT_type);
CodeState = DUMP_INPUTS;
// print statemt256 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_statemt256, __xlx_sprintf_buffer.data());
  {
    sc_bv<256> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)__xlx_apatb_param_statemt256)[0*4+0];
__xlx_tmp_lv.range(127,64) = ((long long*)__xlx_apatb_param_statemt256)[0*4+1];
__xlx_tmp_lv.range(191,128) = ((long long*)__xlx_apatb_param_statemt256)[0*4+2];
__xlx_tmp_lv.range(255,192) = ((long long*)__xlx_apatb_param_statemt256)[0*4+3];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_statemt256, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.statemt256_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_statemt256, __xlx_sprintf_buffer.data());
}
// print key256 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_key256, __xlx_sprintf_buffer.data());
  {
    sc_bv<256> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)__xlx_apatb_param_key256)[0*4+0];
__xlx_tmp_lv.range(127,64) = ((long long*)__xlx_apatb_param_key256)[0*4+1];
__xlx_tmp_lv.range(191,128) = ((long long*)__xlx_apatb_param_key256)[0*4+2];
__xlx_tmp_lv.range(255,192) = ((long long*)__xlx_apatb_param_key256)[0*4+3];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_key256, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.key256_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_key256, __xlx_sprintf_buffer.data());
}
// print type Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_type, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)&__xlx_apatb_param_type);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_type, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.type_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_type, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
aes_encrypt_hw_stub_wrapper(__xlx_apatb_param_statemt256, __xlx_apatb_param_key256, __xlx_apatb_param_type);
CodeState = DUMP_OUTPUTS;
// print statemt256 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_statemt256, __xlx_sprintf_buffer.data());
  {
    sc_bv<256> __xlx_tmp_lv;
__xlx_tmp_lv.range(63,0) = ((long long*)__xlx_apatb_param_statemt256)[0*4+0];
__xlx_tmp_lv.range(127,64) = ((long long*)__xlx_apatb_param_statemt256)[0*4+1];
__xlx_tmp_lv.range(191,128) = ((long long*)__xlx_apatb_param_statemt256)[0*4+2];
__xlx_tmp_lv.range(255,192) = ((long long*)__xlx_apatb_param_statemt256)[0*4+3];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_statemt256, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.statemt256_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_statemt256, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
