set moduleName aes_encrypt
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {aes_encrypt}
set C_modelType { void 0 }
set C_modelArgList {
	{ statemt256 int 256 regular {pointer 2}  }
	{ key256 int 256 regular  }
	{ type_r int 32 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "statemt256", "interface" : "wire", "bitwidth" : 256, "direction" : "READWRITE", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "statemt256","cData": "int256","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "key256", "interface" : "wire", "bitwidth" : 256, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "key256","cData": "int256","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "type_r", "interface" : "wire", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "type","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 11
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ statemt256_i sc_in sc_lv 256 signal 0 } 
	{ statemt256_o sc_out sc_lv 256 signal 0 } 
	{ statemt256_o_ap_vld sc_out sc_logic 1 outvld 0 } 
	{ key256 sc_in sc_lv 256 signal 1 } 
	{ type_r sc_in sc_lv 32 signal 2 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "statemt256_i", "direction": "in", "datatype": "sc_lv", "bitwidth":256, "type": "signal", "bundle":{"name": "statemt256", "role": "i" }} , 
 	{ "name": "statemt256_o", "direction": "out", "datatype": "sc_lv", "bitwidth":256, "type": "signal", "bundle":{"name": "statemt256", "role": "o" }} , 
 	{ "name": "statemt256_o_ap_vld", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "outvld", "bundle":{"name": "statemt256", "role": "o_ap_vld" }} , 
 	{ "name": "key256", "direction": "in", "datatype": "sc_lv", "bitwidth":256, "type": "signal", "bundle":{"name": "key256", "role": "default" }} , 
 	{ "name": "type_r", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "type_r", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "6", "12", "15"],
		"CDFG" : "aes_encrypt",
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
			{"Name" : "statemt256", "Type" : "OVld", "Direction" : "IO"},
			{"Name" : "key256", "Type" : "None", "Direction" : "I"},
			{"Name" : "type_r", "Type" : "None", "Direction" : "I"},
			{"Name" : "Sbox", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_KeySchedule_fu_454", "Port" : "Sbox"},
					{"ID" : "4", "SubInstance" : "grp_ByteSub_ShiftRow_fu_446", "Port" : "Sbox"}]},
			{"Name" : "Rcon0", "Type" : "Memory", "Direction" : "I",
				"SubConnect" : [
					{"ID" : "6", "SubInstance" : "grp_KeySchedule_fu_454", "Port" : "Rcon0"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.word_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.statemt_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.key_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_ByteSub_ShiftRow_fu_446", "Parent" : "0", "Child" : ["5"],
		"CDFG" : "ByteSub_ShiftRow",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "1", "EstimateLatencyMax" : "30",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "statemt", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "nb", "Type" : "None", "Direction" : "I"},
			{"Name" : "Sbox", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "5", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_ByteSub_ShiftRow_fu_446.Sbox_U", "Parent" : "4"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454", "Parent" : "0", "Child" : ["7", "8", "9", "10", "11"],
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
	{"ID" : "7", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454.Sbox_U", "Parent" : "6"},
	{"ID" : "8", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454.Rcon0_U", "Parent" : "6"},
	{"ID" : "9", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454.mul_4ns_4ns_8_1_1_U1", "Parent" : "6"},
	{"ID" : "10", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454.urem_7ns_4ns_3_11_1_U2", "Parent" : "6"},
	{"ID" : "11", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_KeySchedule_fu_454.udiv_7ns_4ns_5_11_1_U3", "Parent" : "6"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_MixColumn_AddRoundKey_fu_465", "Parent" : "0", "Child" : ["13", "14"],
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
	{"ID" : "13", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MixColumn_AddRoundKey_fu_465.ret_U", "Parent" : "12"},
	{"ID" : "14", "Level" : "2", "Path" : "`AUTOTB_DUT_INST.grp_MixColumn_AddRoundKey_fu_465.mul_4ns_4ns_7_1_1_U14", "Parent" : "12"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mul_4ns_4ns_7_1_1_U21", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	aes_encrypt {
		statemt256 {Type IO LastRead 1 FirstWrite 14}
		key256 {Type I LastRead 1 FirstWrite -1}
		type_r {Type I LastRead 0 FirstWrite -1}
		Sbox {Type I LastRead -1 FirstWrite -1}
		Rcon0 {Type I LastRead -1 FirstWrite -1}}
	ByteSub_ShiftRow {
		statemt {Type IO LastRead 19 FirstWrite 3}
		nb {Type I LastRead 0 FirstWrite -1}
		Sbox {Type I LastRead -1 FirstWrite -1}}
	KeySchedule {
		type_r {Type I LastRead 0 FirstWrite -1}
		key {Type I LastRead 1 FirstWrite -1}
		word {Type IO LastRead 25 FirstWrite 2}
		Sbox {Type I LastRead -1 FirstWrite -1}
		Rcon0 {Type I LastRead -1 FirstWrite -1}}
	MixColumn_AddRoundKey {
		statemt {Type IO LastRead 3 FirstWrite 4}
		nb {Type I LastRead 0 FirstWrite -1}
		n {Type I LastRead 0 FirstWrite -1}
		word {Type I LastRead 3 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "-1", "Max" : "-1"}
	, {"Name" : "Interval", "Min" : "0", "Max" : "0"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
]}

set Spec2ImplPortList { 
	statemt256 { ap_ovld {  { statemt256_i in_data 0 256 }  { statemt256_o out_data 1 256 }  { statemt256_o_ap_vld out_vld 1 1 } } }
	key256 { ap_none {  { key256 in_data 0 256 } } }
	type_r { ap_none {  { type_r in_data 0 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
