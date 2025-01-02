set moduleName add_hw
set isTopModule 0
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isFreeRunPipelineModule 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {add_hw}
set C_modelType { void 0 }
set C_modelArgList {
	{ state_matrix int 8 regular {array 144 { 2 3 } 1 1 }  }
	{ index1 int 6 regular  }
	{ index2 int 5 regular  }
	{ arr1 int 8 regular {array 8 { 2 3 } 1 1 }  }
	{ arr2 int 8 regular {array 8 { 2 3 } 1 1 }  }
	{ arr3 int 8 regular {array 32 { 2 2 } 1 1 }  }
	{ arr4 int 8 regular {array 32 { 2 0 } 1 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "state_matrix", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "index1", "interface" : "wire", "bitwidth" : 6, "direction" : "READONLY"} , 
 	{ "Name" : "index2", "interface" : "wire", "bitwidth" : 5, "direction" : "READONLY"} , 
 	{ "Name" : "arr1", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "arr2", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "arr3", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} , 
 	{ "Name" : "arr4", "interface" : "memory", "bitwidth" : 8, "direction" : "READWRITE"} ]}
# RTL Port declarations: 
set portNum 42
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ state_matrix_address0 sc_out sc_lv 8 signal 0 } 
	{ state_matrix_ce0 sc_out sc_logic 1 signal 0 } 
	{ state_matrix_we0 sc_out sc_logic 1 signal 0 } 
	{ state_matrix_d0 sc_out sc_lv 8 signal 0 } 
	{ state_matrix_q0 sc_in sc_lv 8 signal 0 } 
	{ index1 sc_in sc_lv 6 signal 1 } 
	{ index2 sc_in sc_lv 5 signal 2 } 
	{ arr1_address0 sc_out sc_lv 3 signal 3 } 
	{ arr1_ce0 sc_out sc_logic 1 signal 3 } 
	{ arr1_we0 sc_out sc_logic 1 signal 3 } 
	{ arr1_d0 sc_out sc_lv 8 signal 3 } 
	{ arr1_q0 sc_in sc_lv 8 signal 3 } 
	{ arr2_address0 sc_out sc_lv 3 signal 4 } 
	{ arr2_ce0 sc_out sc_logic 1 signal 4 } 
	{ arr2_we0 sc_out sc_logic 1 signal 4 } 
	{ arr2_d0 sc_out sc_lv 8 signal 4 } 
	{ arr2_q0 sc_in sc_lv 8 signal 4 } 
	{ arr3_address0 sc_out sc_lv 5 signal 5 } 
	{ arr3_ce0 sc_out sc_logic 1 signal 5 } 
	{ arr3_we0 sc_out sc_logic 1 signal 5 } 
	{ arr3_d0 sc_out sc_lv 8 signal 5 } 
	{ arr3_q0 sc_in sc_lv 8 signal 5 } 
	{ arr3_address1 sc_out sc_lv 5 signal 5 } 
	{ arr3_ce1 sc_out sc_logic 1 signal 5 } 
	{ arr3_we1 sc_out sc_logic 1 signal 5 } 
	{ arr3_d1 sc_out sc_lv 8 signal 5 } 
	{ arr3_q1 sc_in sc_lv 8 signal 5 } 
	{ arr4_address0 sc_out sc_lv 5 signal 6 } 
	{ arr4_ce0 sc_out sc_logic 1 signal 6 } 
	{ arr4_we0 sc_out sc_logic 1 signal 6 } 
	{ arr4_d0 sc_out sc_lv 8 signal 6 } 
	{ arr4_q0 sc_in sc_lv 8 signal 6 } 
	{ arr4_address1 sc_out sc_lv 5 signal 6 } 
	{ arr4_ce1 sc_out sc_logic 1 signal 6 } 
	{ arr4_we1 sc_out sc_logic 1 signal 6 } 
	{ arr4_d1 sc_out sc_lv 8 signal 6 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "state_matrix_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "address0" }} , 
 	{ "name": "state_matrix_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "state_matrix", "role": "ce0" }} , 
 	{ "name": "state_matrix_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "state_matrix", "role": "we0" }} , 
 	{ "name": "state_matrix_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "d0" }} , 
 	{ "name": "state_matrix_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "q0" }} , 
 	{ "name": "index1", "direction": "in", "datatype": "sc_lv", "bitwidth":6, "type": "signal", "bundle":{"name": "index1", "role": "default" }} , 
 	{ "name": "index2", "direction": "in", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "index2", "role": "default" }} , 
 	{ "name": "arr1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "arr1", "role": "address0" }} , 
 	{ "name": "arr1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr1", "role": "ce0" }} , 
 	{ "name": "arr1_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr1", "role": "we0" }} , 
 	{ "name": "arr1_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr1", "role": "d0" }} , 
 	{ "name": "arr1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr1", "role": "q0" }} , 
 	{ "name": "arr2_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "arr2", "role": "address0" }} , 
 	{ "name": "arr2_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr2", "role": "ce0" }} , 
 	{ "name": "arr2_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr2", "role": "we0" }} , 
 	{ "name": "arr2_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr2", "role": "d0" }} , 
 	{ "name": "arr2_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr2", "role": "q0" }} , 
 	{ "name": "arr3_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "arr3", "role": "address0" }} , 
 	{ "name": "arr3_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr3", "role": "ce0" }} , 
 	{ "name": "arr3_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr3", "role": "we0" }} , 
 	{ "name": "arr3_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr3", "role": "d0" }} , 
 	{ "name": "arr3_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr3", "role": "q0" }} , 
 	{ "name": "arr3_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "arr3", "role": "address1" }} , 
 	{ "name": "arr3_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr3", "role": "ce1" }} , 
 	{ "name": "arr3_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr3", "role": "we1" }} , 
 	{ "name": "arr3_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr3", "role": "d1" }} , 
 	{ "name": "arr3_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr3", "role": "q1" }} , 
 	{ "name": "arr4_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "arr4", "role": "address0" }} , 
 	{ "name": "arr4_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr4", "role": "ce0" }} , 
 	{ "name": "arr4_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr4", "role": "we0" }} , 
 	{ "name": "arr4_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr4", "role": "d0" }} , 
 	{ "name": "arr4_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr4", "role": "q0" }} , 
 	{ "name": "arr4_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "arr4", "role": "address1" }} , 
 	{ "name": "arr4_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr4", "role": "ce1" }} , 
 	{ "name": "arr4_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "arr4", "role": "we1" }} , 
 	{ "name": "arr4_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "arr4", "role": "d1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "add_hw",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "102", "EstimateLatencyMax" : "102",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"WaitState" : [
			{"State" : "ap_ST_fsm_state8", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_convert_hex_to_binar_fu_344"},
			{"State" : "ap_ST_fsm_state8", "FSM" : "ap_CS_fsm", "SubInstance" : "grp_convert_hex_to_binar_fu_352"}],
		"Port" : [
			{"Name" : "state_matrix", "Type" : "Memory", "Direction" : "IO"},
			{"Name" : "index1", "Type" : "None", "Direction" : "I"},
			{"Name" : "index2", "Type" : "None", "Direction" : "I"},
			{"Name" : "arr1", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_convert_hex_to_binar_fu_344", "Port" : "hex"}]},
			{"Name" : "arr2", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "2", "SubInstance" : "grp_convert_hex_to_binar_fu_352", "Port" : "hex"}]},
			{"Name" : "arr3", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "1", "SubInstance" : "grp_convert_hex_to_binar_fu_344", "Port" : "bin"}]},
			{"Name" : "arr4", "Type" : "Memory", "Direction" : "IO",
				"SubConnect" : [
					{"ID" : "2", "SubInstance" : "grp_convert_hex_to_binar_fu_352", "Port" : "bin"}]}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_convert_hex_to_binar_fu_344", "Parent" : "0",
		"CDFG" : "convert_hex_to_binar",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "18", "EstimateLatencyMax" : "18",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "hex", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "bin", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.grp_convert_hex_to_binar_fu_352", "Parent" : "0",
		"CDFG" : "convert_hex_to_binar",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "18", "EstimateLatencyMax" : "18",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "hex", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "bin", "Type" : "Memory", "Direction" : "O"}]}]}


set ArgLastReadFirstWriteLatency {
	add_hw {
		state_matrix {Type IO LastRead 3 FirstWrite 11}
		index1 {Type I LastRead 0 FirstWrite -1}
		index2 {Type I LastRead 0 FirstWrite -1}
		arr1 {Type IO LastRead 10 FirstWrite -1}
		arr2 {Type IO LastRead 1 FirstWrite -1}
		arr3 {Type IO LastRead 10 FirstWrite 2}
		arr4 {Type IO LastRead 6 FirstWrite 2}}
	convert_hex_to_binar {
		hex {Type I LastRead 1 FirstWrite -1}
		bin {Type O LastRead -1 FirstWrite 2}}
	convert_hex_to_binar {
		hex {Type I LastRead 1 FirstWrite -1}
		bin {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "102", "Max" : "102"}
	, {"Name" : "Interval", "Min" : "102", "Max" : "102"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
	{"Pipeline" : "4", "EnableSignal" : "ap_enable_pp4"}
]}

set Spec2ImplPortList { 
	state_matrix { ap_memory {  { state_matrix_address0 mem_address 1 8 }  { state_matrix_ce0 mem_ce 1 1 }  { state_matrix_we0 mem_we 1 1 }  { state_matrix_d0 mem_din 1 8 }  { state_matrix_q0 mem_dout 0 8 } } }
	index1 { ap_none {  { index1 in_data 0 6 } } }
	index2 { ap_none {  { index2 in_data 0 5 } } }
	arr1 { ap_memory {  { arr1_address0 mem_address 1 3 }  { arr1_ce0 mem_ce 1 1 }  { arr1_we0 mem_we 1 1 }  { arr1_d0 mem_din 1 8 }  { arr1_q0 mem_dout 0 8 } } }
	arr2 { ap_memory {  { arr2_address0 mem_address 1 3 }  { arr2_ce0 mem_ce 1 1 }  { arr2_we0 mem_we 1 1 }  { arr2_d0 mem_din 1 8 }  { arr2_q0 mem_dout 0 8 } } }
	arr3 { ap_memory {  { arr3_address0 mem_address 1 5 }  { arr3_ce0 mem_ce 1 1 }  { arr3_we0 mem_we 1 1 }  { arr3_d0 mem_din 1 8 }  { arr3_q0 mem_dout 0 8 }  { arr3_address1 MemPortADDR2 1 5 }  { arr3_ce1 MemPortCE2 1 1 }  { arr3_we1 MemPortWE2 1 1 }  { arr3_d1 MemPortDIN2 1 8 }  { arr3_q1 MemPortDOUT2 0 8 } } }
	arr4 { ap_memory {  { arr4_address0 mem_address 1 5 }  { arr4_ce0 mem_ce 1 1 }  { arr4_we0 mem_we 1 1 }  { arr4_d0 mem_din 1 8 }  { arr4_q0 mem_dout 0 8 }  { arr4_address1 MemPortADDR2 1 5 }  { arr4_ce1 MemPortCE2 1 1 }  { arr4_we1 MemPortWE2 1 1 }  { arr4_d1 MemPortDIN2 1 8 } } }
}
