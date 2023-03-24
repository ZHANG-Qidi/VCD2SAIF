set moduleName MixColumn_AddRoundKey
set isTopModule 0
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {MixColumn_AddRoundKey}
set C_modelType { void 0 }
set C_modelArgList {
	{ statemt int 8 regular {array 32 { 2 2 } 1 1 }  }
	{ nb uint 4 regular  }
	{ n uint 4 regular  }
	{ word int 8 regular {array 480 { 1 1 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "statemt", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "nb", "interface" : "wire", "bitwidth" : 4, "direction" : "READONLY"} , 
 	{ "Name" : "n", "interface" : "wire", "bitwidth" : 4, "direction" : "READONLY"} , 
 	{ "Name" : "word", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 24
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ statemt_address0 sc_out sc_lv 5 signal 0 } 
	{ statemt_ce0 sc_out sc_logic 1 signal 0 } 
	{ statemt_we0 sc_out sc_logic 1 signal 0 } 
	{ statemt_d0 sc_out sc_lv 8 signal 0 } 
	{ statemt_q0 sc_in sc_lv 8 signal 0 } 
	{ statemt_address1 sc_out sc_lv 5 signal 0 } 
	{ statemt_ce1 sc_out sc_logic 1 signal 0 } 
	{ statemt_we1 sc_out sc_logic 1 signal 0 } 
	{ statemt_d1 sc_out sc_lv 8 signal 0 } 
	{ statemt_q1 sc_in sc_lv 8 signal 0 } 
	{ nb sc_in sc_lv 4 signal 1 } 
	{ n sc_in sc_lv 4 signal 2 } 
	{ word_address0 sc_out sc_lv 9 signal 3 } 
	{ word_ce0 sc_out sc_logic 1 signal 3 } 
	{ word_q0 sc_in sc_lv 8 signal 3 } 
	{ word_address1 sc_out sc_lv 9 signal 3 } 
	{ word_ce1 sc_out sc_logic 1 signal 3 } 
	{ word_q1 sc_in sc_lv 8 signal 3 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "statemt_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "statemt", "role": "address0" }} , 
 	{ "name": "statemt_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "statemt", "role": "ce0" }} , 
 	{ "name": "statemt_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "statemt", "role": "we0" }} , 
 	{ "name": "statemt_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "statemt", "role": "d0" }} , 
 	{ "name": "statemt_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "statemt", "role": "q0" }} , 
 	{ "name": "statemt_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "statemt", "role": "address1" }} , 
 	{ "name": "statemt_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "statemt", "role": "ce1" }} , 
 	{ "name": "statemt_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "statemt", "role": "we1" }} , 
 	{ "name": "statemt_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "statemt", "role": "d1" }} , 
 	{ "name": "statemt_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "statemt", "role": "q1" }} , 
 	{ "name": "nb", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "nb", "role": "default" }} , 
 	{ "name": "n", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "n", "role": "default" }} , 
 	{ "name": "word_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "word", "role": "address0" }} , 
 	{ "name": "word_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "ce0" }} , 
 	{ "name": "word_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "q0" }} , 
 	{ "name": "word_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "word", "role": "address1" }} , 
 	{ "name": "word_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "ce1" }} , 
 	{ "name": "word_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "MixColumn_AddRoundKey",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "21", "EstimateLatencyMax" : "37",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "statemt", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "nb", "Type" : "None", "Direction" : "I"},
			{"Name" : "n", "Type" : "None", "Direction" : "I"},
			{"Name" : "word", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.ret_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_4ns_4ns_7_1_1_U14", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	MixColumn_AddRoundKey {
		statemt {Type IO LastRead 3 FirstWrite 4}
		nb {Type I LastRead 0 FirstWrite -1}
		n {Type I LastRead 0 FirstWrite -1}
		word {Type I LastRead 3 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "21", "Max" : "37"}
	, {"Name" : "Interval", "Min" : "21", "Max" : "37"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
]}

set Spec2ImplPortList { 
	statemt { ap_memory {  { statemt_address0 mem_address 1 5 }  { statemt_ce0 mem_ce 1 1 }  { statemt_we0 mem_we 1 1 }  { statemt_d0 mem_din 1 8 }  { statemt_q0 mem_dout 0 8 }  { statemt_address1 MemPortADDR2 1 5 }  { statemt_ce1 MemPortCE2 1 1 }  { statemt_we1 MemPortWE2 1 1 }  { statemt_d1 MemPortDIN2 1 8 }  { statemt_q1 MemPortDOUT2 0 8 } } }
	nb { ap_none {  { nb in_data 0 4 } } }
	n { ap_none {  { n in_data 0 4 } } }
	word { ap_memory {  { word_address0 mem_address 1 9 }  { word_ce0 mem_ce 1 1 }  { word_q0 mem_dout 0 8 }  { word_address1 MemPortADDR2 1 9 }  { word_ce1 MemPortCE2 1 1 }  { word_q1 MemPortDOUT2 0 8 } } }
}
