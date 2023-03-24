set moduleName KeySchedule
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
set C_modelName {KeySchedule}
set C_modelType { void 0 }
set C_modelArgList {
	{ type_r int 32 regular  }
	{ key int 8 regular {array 32 { 1 3 } 1 1 }  }
	{ word int 8 regular {array 480 { 2 2 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "type_r", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY"} , 
 	{ "Name" : "key", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "word", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ type_r sc_in sc_lv 32 signal 0 } 
	{ key_address0 sc_out sc_lv 5 signal 1 } 
	{ key_ce0 sc_out sc_logic 1 signal 1 } 
	{ key_q0 sc_in sc_lv 8 signal 1 } 
	{ word_address0 sc_out sc_lv 9 signal 2 } 
	{ word_ce0 sc_out sc_logic 1 signal 2 } 
	{ word_we0 sc_out sc_logic 1 signal 2 } 
	{ word_d0 sc_out sc_lv 8 signal 2 } 
	{ word_q0 sc_in sc_lv 8 signal 2 } 
	{ word_address1 sc_out sc_lv 9 signal 2 } 
	{ word_ce1 sc_out sc_logic 1 signal 2 } 
	{ word_we1 sc_out sc_logic 1 signal 2 } 
	{ word_d1 sc_out sc_lv 8 signal 2 } 
	{ word_q1 sc_in sc_lv 8 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "type_r", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "type_r", "role": "default" }} , 
 	{ "name": "key_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "key", "role": "address0" }} , 
 	{ "name": "key_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key", "role": "ce0" }} , 
 	{ "name": "key_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "key", "role": "q0" }} , 
 	{ "name": "word_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "word", "role": "address0" }} , 
 	{ "name": "word_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "ce0" }} , 
 	{ "name": "word_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "we0" }} , 
 	{ "name": "word_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "d0" }} , 
 	{ "name": "word_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "q0" }} , 
 	{ "name": "word_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":9, "type": "signal", "bundle":{"name": "word", "role": "address1" }} , 
 	{ "name": "word_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "ce1" }} , 
 	{ "name": "word_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "word", "role": "we1" }} , 
 	{ "name": "word_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "d1" }} , 
 	{ "name": "word_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "word", "role": "q1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5"],
		"CDFG" : "KeySchedule",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "-1", "EstimateLatencyMax" : "-1",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "type_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "key", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "word", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "Sbox", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "Rcon0", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Sbox_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.Rcon0_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_4ns_4ns_8_1_1_U1", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.urem_7ns_4ns_3_11_1_U2", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.udiv_7ns_4ns_5_11_1_U3", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	KeySchedule {
		type_r {Type I LastRead 0 FirstWrite -1}
		key {Type I LastRead 1 FirstWrite -1}
		word {Type IO LastRead 25 FirstWrite 2}
		Sbox {Type I LastRead -1 FirstWrite -1}
		Rcon0 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "-1", "Max" : "-1"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
]}

set Spec2ImplPortList { 
	type_r { ap_none {  { type_r in_data 0 32 } } }
	key { ap_memory {  { key_address0 mem_address 1 5 }  { key_ce0 mem_ce 1 1 }  { key_q0 mem_dout 0 8 } } }
	word { ap_memory {  { word_address0 mem_address 1 9 }  { word_ce0 mem_ce 1 1 }  { word_we0 mem_we 1 1 }  { word_d0 mem_din 1 8 }  { word_q0 mem_dout 0 8 }  { word_address1 MemPortADDR2 1 9 }  { word_ce1 MemPortCE2 1 1 }  { word_we1 MemPortWE2 1 1 }  { word_d1 MemPortDIN2 1 8 }  { word_q1 MemPortDOUT2 0 8 } } }
}
