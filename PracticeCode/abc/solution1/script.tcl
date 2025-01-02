############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project abc
add_files mat_mul_prg/mat.h
add_files mat_mul_prg/matrix.cpp
add_files -tb mat_mul_prg/matrix_tb.cpp
open_solution "solution1"
set_part {xc7z020clg484-1} -tool vivado
create_clock -period 10 -name default
set_clock_uncertainty 1.25
#source "./abc/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
