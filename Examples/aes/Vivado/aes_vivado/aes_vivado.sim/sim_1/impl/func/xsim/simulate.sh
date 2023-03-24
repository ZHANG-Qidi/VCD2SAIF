#!/bin/bash -f
# ****************************************************************************
# Vivado (TM) v2020.2.2 (64-bit)
#
# Filename    : simulate.sh
# Simulator   : Xilinx Vivado Simulator
# Description : Script for simulating the design by launching the simulator
#
# Generated by Vivado on Mon Apr 18 00:06:07 JST 2022
# SW Build 3118627 on Tue Feb  9 05:13:49 MST 2021
#
# Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
#
# usage: simulate.sh
#
# ****************************************************************************
set -Eeuo pipefail
# simulate design
echo "xsim aes_func_impl -key {Post-Implementation:sim_1:Functional:aes} -tclbatch aes.tcl -protoinst "protoinst_files/design_1.protoinst" -log simulate.log"
xsim aes_func_impl -key {Post-Implementation:sim_1:Functional:aes} -tclbatch aes.tcl -protoinst "protoinst_files/design_1.protoinst" -log simulate.log

