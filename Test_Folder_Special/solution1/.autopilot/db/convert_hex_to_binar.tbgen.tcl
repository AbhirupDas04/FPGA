set moduleName convert_hex_to_binar
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
set C_modelName {convert_hex_to_binar}
set C_modelType { void 0 }
set C_modelArgList {
	{ hex int 8 regular {array 8 { 1 3 } 1 1 }  }
	{ bin int 8 regular {array 32 { 0 0 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "hex", "interface" : "memory", "bitwidth" : 8, "direction" : "READONLY"} , 
 	{ "Name" : "bin", "interface" : "memory", "bitwidth" : 8, "direction" : "WRITEONLY"} ]}
# RTL Port declarations: 
set portNum 17
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ hex_address0 sc_out sc_lv 3 signal 0 } 
	{ hex_ce0 sc_out sc_logic 1 signal 0 } 
	{ hex_q0 sc_in sc_lv 8 signal 0 } 
	{ bin_address0 sc_out sc_lv 5 signal 1 } 
	{ bin_ce0 sc_out sc_logic 1 signal 1 } 
	{ bin_we0 sc_out sc_logic 1 signal 1 } 
	{ bin_d0 sc_out sc_lv 8 signal 1 } 
	{ bin_address1 sc_out sc_lv 5 signal 1 } 
	{ bin_ce1 sc_out sc_logic 1 signal 1 } 
	{ bin_we1 sc_out sc_logic 1 signal 1 } 
	{ bin_d1 sc_out sc_lv 8 signal 1 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "hex_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "hex", "role": "address0" }} , 
 	{ "name": "hex_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "hex", "role": "ce0" }} , 
 	{ "name": "hex_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "hex", "role": "q0" }} , 
 	{ "name": "bin_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "bin", "role": "address0" }} , 
 	{ "name": "bin_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bin", "role": "ce0" }} , 
 	{ "name": "bin_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bin", "role": "we0" }} , 
 	{ "name": "bin_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "bin", "role": "d0" }} , 
 	{ "name": "bin_address1", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "bin", "role": "address1" }} , 
 	{ "name": "bin_ce1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bin", "role": "ce1" }} , 
 	{ "name": "bin_we1", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "bin", "role": "we1" }} , 
 	{ "name": "bin_d1", "direction": "out", "datatype": "sc_lv", "bitwidth":8, "type": "signal", "bundle":{"name": "bin", "role": "d1" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "",
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
	convert_hex_to_binar {
		hex {Type I LastRead 1 FirstWrite -1}
		bin {Type O LastRead -1 FirstWrite 2}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "18", "Max" : "18"}
	, {"Name" : "Interval", "Min" : "18", "Max" : "18"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	hex { ap_memory {  { hex_address0 mem_address 1 3 }  { hex_ce0 mem_ce 1 1 }  { hex_q0 mem_dout 0 8 } } }
	bin { ap_memory {  { bin_address0 mem_address 1 5 }  { bin_ce0 mem_ce 1 1 }  { bin_we0 mem_we 1 1 }  { bin_d0 mem_din 1 8 }  { bin_address1 MemPortADDR2 1 5 }  { bin_ce1 MemPortCE2 1 1 }  { bin_we1 MemPortWE2 1 1 }  { bin_d1 MemPortDIN2 1 8 } } }
}
