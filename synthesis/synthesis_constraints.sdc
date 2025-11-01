###############################################################################
# Synopsys Design Constraints (SDC) File
# RV32I 5-Stage Pipelined Processor
# Target: Sky130A PDK
# Tool: OpenSTA (via IIC-OSIC-TOOLS)
###############################################################################

###############################################################################
# Design Information
###############################################################################
set design_name "Pip_RV32I"

###############################################################################
# Clock Definition
###############################################################################
# Target frequency: 100 MHz (10 ns period)
# Aggressive target for Sky130A standard cells - requires careful optimization
set clk_period 10.0
set clk_port "Clk_In"
set clk_name "clk"

# Create clock
create_clock -name $clk_name -period $clk_period [get_ports $clk_port]

# Clock uncertainty (jitter + skew)
# For 100 MHz, tighter uncertainty is needed: 5-7% of clock period
set clk_uncertainty [expr {$clk_period * 0.06}]  ;# 6% uncertainty = 0.6ns
set_clock_uncertainty $clk_uncertainty [get_clocks $clk_name]

# Clock transition (rise/fall time)
# Faster transition for higher frequency
set clk_transition 0.3  ;# 300ps transition time
set_clock_transition $clk_transition [get_clocks $clk_name]

# Clock latency (on-chip clock tree delay)
# Reduced latency budget for 100 MHz
set clk_latency 1.5  ;# 1.5ns estimated clock tree latency
set_clock_latency $clk_latency [get_clocks $clk_name]

###############################################################################
# Reset Constraints
###############################################################################
# Reset is asynchronous but should be synchronously de-asserted
set_false_path -from [get_ports Rst_In]

###############################################################################
# Input Delays
###############################################################################
# Input delay for instruction memory interface
# For 100 MHz, tighter timing: assume fast memory (3ns access + 1ns routing)
set input_delay_instr 4.0
set_input_delay -clock $clk_name -max $input_delay_instr [get_ports Instruction_In*]
set_input_delay -clock $clk_name -min [expr {$input_delay_instr * 0.2}] [get_ports Instruction_In*]

# Input delay for data memory interface
# Fast memory required for 100 MHz operation (3ns access + 1ns routing)
set input_delay_data 4.0
set_input_delay -clock $clk_name -max $input_delay_data [get_ports DM_Data_In*]
set_input_delay -clock $clk_name -min [expr {$input_delay_data * 0.2}] [get_ports DM_Data_In*]

###############################################################################
# Output Delays
###############################################################################
# Output delay for instruction address (to instruction memory)
# Tighter budget: 2ns for address propagation and memory setup
set output_delay_addr 2.0
set_output_delay -clock $clk_name -max $output_delay_addr [get_ports Instr_Addr_Out*]
set_output_delay -clock $clk_name -min [expr {$output_delay_addr * 0.15}] [get_ports Instr_Addr_Out*]

# Output delay for data memory interface
set output_delay_dm 2.0
set_output_delay -clock $clk_name -max $output_delay_dm [get_ports DM_Addr_Out*]
set_output_delay -clock $clk_name -max $output_delay_dm [get_ports DM_Data_Out*]
set_output_delay -clock $clk_name -max $output_delay_dm [get_ports DM_Mask_Out*]
set_output_delay -clock $clk_name -max $output_delay_dm [get_ports DM_WrEn_Out]

set_output_delay -clock $clk_name -min [expr {$output_delay_dm * 0.15}] [get_ports DM_Addr_Out*]
set_output_delay -clock $clk_name -min [expr {$output_delay_dm * 0.15}] [get_ports DM_Data_Out*]
set_output_delay -clock $clk_name -min [expr {$output_delay_dm * 0.15}] [get_ports DM_Mask_Out*]
set_output_delay -clock $clk_name -min [expr {$output_delay_dm * 0.15}] [get_ports DM_WrEn_Out]

###############################################################################
# Load Constraints
###############################################################################
# Output load capacitance (typical for Sky130A)
# Standard load: ~10fF per output
set output_load 0.01  ;# 10fF in pF

set_load $output_load [get_ports Instr_Addr_Out*]
set_load $output_load [get_ports DM_Addr_Out*]
set_load $output_load [get_ports DM_Data_Out*]
set_load $output_load [get_ports DM_Mask_Out*]
set_load $output_load [get_ports DM_WrEn_Out]

###############################################################################
# Drive Strength Constraints
###############################################################################
# Input drive strength (assume strong external drivers for 100 MHz)
# Using Sky130A high-drive buffers for better performance
set input_drive 2.0  ;# Drive strength in library units

set_driving_cell -lib_cell sky130_fd_sc_hd__buf_8 -library sky130_fd_sc_hd__tt_025C_1v80 [get_ports Instruction_In*]
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_8 -library sky130_fd_sc_hd__tt_025C_1v80 [get_ports DM_Data_In*]

# Clock and reset have strongest drivers for 100 MHz operation
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_16 -library sky130_fd_sc_hd__tt_025C_1v80 [get_ports Clk_In]
set_driving_cell -lib_cell sky130_fd_sc_hd__buf_16 -library sky130_fd_sc_hd__tt_025C_1v80 [get_ports Rst_In]

###############################################################################
# Multi-Cycle Paths
###############################################################################
# Pipeline registers naturally provide multi-cycle paths
# Most critical paths are within single stage

# Memory operations might need multi-cycle consideration
# (Uncomment if needed based on memory latency)
# set_multicycle_path -setup 2 -from [get_pins reg_e_m/*] -to [get_pins reg_m_w/*]
# set_multicycle_path -hold 1 -from [get_pins reg_e_m/*] -to [get_pins reg_m_w/*]

###############################################################################
# False Paths
###############################################################################
# Reset is asynchronous (already defined above)
set_false_path -from [get_ports Rst_In]

# Paths between different clock domains (if any)
# Currently single clock domain, so no additional false paths needed

###############################################################################
# Max Transition Constraints
###############################################################################
# Limit signal transition times for 100 MHz operation
# Tighter constraints needed for signal integrity at higher frequency
set max_transition 1.0  ;# 1.0ns max transition
set_max_transition $max_transition [current_design]

###############################################################################
# Max Fanout Constraints
###############################################################################
# Limit fanout for better timing at 100 MHz
# More aggressive than 50 MHz design
set max_fanout 12
set_max_fanout $max_fanout [current_design]

###############################################################################
# Max Capacitance Constraints
###############################################################################
# Limit net capacitance for signal integrity at 100 MHz
# Tighter than 50 MHz requirements
set max_capacitance 0.3  ;# 300fF max capacitance
set_max_capacitance $max_capacitance [current_design]

###############################################################################
# Area Constraints
###############################################################################
# Set maximum area constraint (let tool optimize)
# Value of 0 means minimize area
set_max_area 0

###############################################################################
# Critical Path Groups
###############################################################################
# Group paths for better analysis
group_path -name INPUTS -from [all_inputs]
group_path -name OUTPUTS -to [all_outputs]
group_path -name COMBO -from [all_inputs] -to [all_outputs]

# # Pipeline stage groups for analysis
# group_path -name FETCH -from [get_pins pc_unit/*] -to [get_pins reg_f_d/*]
# group_path -name DECODE -from [get_pins reg_f_d/*] -to [get_pins reg_d_e/*]
# group_path -name EXECUTE -from [get_pins reg_d_e/*] -to [get_pins reg_e_m/*]
# group_path -name MEMORY -from [get_pins reg_e_m/*] -to [get_pins reg_m_w/*]
# group_path -name WRITEBACK -from [get_pins reg_m_w/*] -to [get_pins reg_file/*]

###############################################################################
# Environment Conditions
###############################################################################
# Operating conditions for Sky130A
# Set to typical corner for initial synthesis
set_operating_conditions -library sky130_fd_sc_hd_tt_025C_1v80

###############################################################################
# Wire Load Model (if needed for pre-layout)
###############################################################################
# Sky130A typically uses statistical wire models
# Uncomment if wire load model is required
# set_wire_load_model -name "Small" -library sky130_fd_sc_hd

###############################################################################
# Design Rule Constraints
###############################################################################
# Additional design rules specific to Sky130A
# These are typically handled by the PDK

###############################################################################
# End of Constraints File
###############################################################################