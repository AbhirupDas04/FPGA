set moduleName split_2_hw
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
set C_modelName {split_2_hw}
set C_modelType { void 0 }
set C_modelArgList {
	{ state_matrix int 8 regular {array 144 { 1 1 } 1 1 }  }
	{ key_stream int 8 regular {array 750 { 0 0 } 0 1 }  }
	{ start int 12 regular  }
	{ mode int 1 regular  }
}
set C_modelArgMapList {[ 
	{ "Name" : "state_matrix", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "key_stream", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} , 
 	{ "Name" : "start", "interface" : "wire", "bitwidth" : 12, "direction" : "READONLY"} , 
 	{ "Name" : "mode", "interface" : "wire", "bitwidth" : 1, "direction" : "READONLY"} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ state_matrix_address0 sc_out sc_lv 8 signal 0 } 
	{ state_matrix_ce0 sc_out sc_logic 1 signal 0 } 
	{ state_matrix_q0 sc_in sc_lv 8 signal 0 } 
	{ state_matrix_address1 sc_out sc_lv 8 signal 0 } 
	{ state_matrix_ce1 sc_out sc_logic 1 signal 0 } 
	{ state_matrix_q1 sc_in sc_lv 8 signal 0 } 
	{ key_stream_address0 sc_out sc_lv 10 signal 1 } 
	{ key_stream_ce0 sc_out sc_logic 1 signal 1 } 
	{ key_stream_we0 sc_out sc_logic 1 signal 1 } 
	{ key_stream_d0 sc_out sc_lv 8 signal 1 } 
	{ key_stream_address1 sc_out sc_lv 10 signal 1 } 
	{ key_stream_ce1 sc_out sc_logic 1 signal 1 } 
	{ key_stream_we1 sc_out sc_logic 1 signal 1 } 
	{ key_stream_d1 sc_out sc_lv 8 signal 1 } 
	{ start sc_in sc_lv 12 signal 2 } 
	{ mode sc_in sc_lv 1 signal 3 } 
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
 	{ "name": "state_matrix_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "q0" }} , 
 	{ "name": "state_matrix_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "address1" }} , 
 	{ "name": "state_matrix_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "state_matrix", "role": "ce1" }} , 
 	{ "name": "state_matrix_q1", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "state_matrix", "role": "q1" }} , 
 	{ "name": "key_stream_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "key_stream", "role": "address0" }} , 
 	{ "name": "key_stream_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key_stream", "role": "ce0" }} , 
 	{ "name": "key_stream_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key_stream", "role": "we0" }} , 
 	{ "name": "key_stream_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "key_stream", "role": "d0" }} , 
 	{ "name": "key_stream_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":10, "type": "signal", "bundle":{"name": "key_stream", "role": "address1" }} , 
 	{ "name": "key_stream_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key_stream", "role": "ce1" }} , 
 	{ "name": "key_stream_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "key_stream", "role": "we1" }} , 
 	{ "name": "key_stream_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "key_stream", "role": "d1" }} , 
 	{ "name": "start", "direction": "in", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "start", "role": "default" }} , 
 	{ "name": "mode", "direction": "in", "datatype": "sc_lv", "bitwidth":1, "type": "signal", "bundle":{"name": "mode", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
		"CDFG" : "split_2_hw",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "5", "EstimateLatencyMax" : "68",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "state_matrix", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "key_stream", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "start", "Type" : "None", "Direction" : "I"},
			{"Name" : "mode", "Type" : "None", "Direction" : "I"}]}]}


set ArgLastReadFirstWriteLatency {
	split_2_hw {
		state_matrix {Type I LastRead 3 FirstWrite -1}
		key_stream {Type O LastRead -1 FirstWrite 3}
		start {Type I LastRead 0 FirstWrite -1}
		mode {Type I LastRead 0 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "5", "Max" : "68"}
	, {"Name" : "Interval", "Min" : "5", "Max" : "68"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	state_matrix { ap_memory {  { state_matrix_address0 mem_address 1 8 }  { state_matrix_ce0 mem_ce 1 1 }  { state_matrix_q0 mem_dout 0 8 }  { state_matrix_address1 MemPortADDR2 1 8 }  { state_matrix_ce1 MemPortCE2 1 1 }  { state_matrix_q1 MemPortDOUT2 0 8 } } }
	key_stream { ap_memory {  { key_stream_address0 mem_address 1 10 }  { key_stream_ce0 mem_ce 1 1 }  { key_stream_we0 mem_we 1 1 }  { key_stream_d0 mem_din 1 8 }  { key_stream_address1 MemPortADDR2 1 10 }  { key_stream_ce1 MemPortCE2 1 1 }  { key_stream_we1 MemPortWE2 1 1 }  { key_stream_d1 MemPortDIN2 1 8 } } }
	start { ap_none {  { start in_data 0 12 } } }
	mode { ap_none {  { mode in_data 0 1 } } }
}
