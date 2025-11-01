###############################################################################
# Makefile for RV32I 5-Stage Pipelined Processor Synthesis
# Target: Sky130A PDK
# Tools: IIC-OSIC-TOOLS (Yosys, OpenSTA, OpenROAD)
# Author: Razi Ahmed
###############################################################################

###############################################################################
# Configuration
###############################################################################
DESIGN_NAME = Pip_RV32I
TOP_MODULE  = Pip_RV32I

# Directory structure
SRC_DIR     = ../
SYN_DIR     = .
RESULTS_DIR = results
REPORTS_DIR = reports
LOGS_DIR    = logs

# PDK Configuration (using IIC-OSIC-TOOLS environment)
PDK_ROOT   ?= $(PDK_ROOT)
PDK         = sky130A
STD_CELL    = sky130_fd_sc_hd

# Liberty files
LIB_TYPICAL = $(PDK_ROOT)/$(PDK)/libs.ref/$(STD_CELL)/lib/$(STD_CELL)__tt_025C_1v80.lib
LIB_FAST    = $(PDK_ROOT)/$(PDK)/libs.ref/$(STD_CELL)/lib/$(STD_CELL)__ff_n40C_1v95.lib
LIB_SLOW    = $(PDK_ROOT)/$(PDK)/libs.ref/$(STD_CELL)/lib/$(STD_CELL)__ss_100C_1v60.lib

# LEF files
TECH_LEF    = $(PDK_ROOT)/$(PDK)/libs.ref/$(STD_CELL)/lef/$(STD_CELL).tlef
CELL_LEF    = $(PDK_ROOT)/$(PDK)/libs.ref/$(STD_CELL)/lef/$(STD_CELL).lef

# Scripts
YOSYS_SCRIPT = yosys_script.ys
# SDC_FILE     = $(SRC_DIR)/synthesis_constraints.sdc
SDC_FILE     = synthesis_constraints.sdc

# Output files
NETLIST      = $(RESULTS_DIR)/synthesized_netlist.v
NETLIST_JSON = $(RESULTS_DIR)/synthesized_netlist.json
SYN_LOG      = $(LOGS_DIR)/synthesis.log
STA_LOG      = $(LOGS_DIR)/sta.log

# Tools
YOSYS       = yosys
STA         = sta
OPENROAD    = openroad

###############################################################################
# Color Definitions for Pretty Output
###############################################################################
COLOR_RESET  = \033[0m
COLOR_GREEN  = \033[0;32m
COLOR_YELLOW = \033[0;33m
COLOR_BLUE   = \033[0;34m
COLOR_RED    = \033[0;31m

###############################################################################
# Default Target
###############################################################################
.PHONY: all
all: setup synthesis sta report
	@echo "$(COLOR_GREEN)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)Complete synthesis flow finished!$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)=========================================$(COLOR_RESET)"

###############################################################################
# Setup Directories
###############################################################################
.PHONY: setup
setup:
	@echo "$(COLOR_BLUE)Setting up directories...$(COLOR_RESET)"
	@mkdir -p $(RESULTS_DIR)
	@mkdir -p $(REPORTS_DIR)
	@mkdir -p $(LOGS_DIR)
	@echo "$(COLOR_GREEN)✓ Directories created$(COLOR_RESET)"

###############################################################################
# Synthesis with Yosys
###############################################################################
.PHONY: synthesis
synthesis: setup
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)Starting Yosys Synthesis...$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "Design: $(DESIGN_NAME)"
	@echo "Target: $(STD_CELL)"
	@echo "PDK: $(PDK)"
	@$(YOSYS) -s $(YOSYS_SCRIPT) | tee $(SYN_LOG)
	@mv synthesized_netlist.v $(RESULTS_DIR)/ 2>/dev/null || true
	@mv synthesized_netlist_debug.v $(RESULTS_DIR)/ 2>/dev/null || true
	@mv synthesized_netlist.json $(RESULTS_DIR)/ 2>/dev/null || true
	@mv synthesized_netlist.blif $(RESULTS_DIR)/ 2>/dev/null || true
	@mv synthesis_stats.txt $(REPORTS_DIR)/ 2>/dev/null || true
	@echo "$(COLOR_GREEN)✓ Synthesis complete!$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  Netlist: $(NETLIST)$(COLOR_RESET)"

###############################################################################
# Static Timing Analysis with OpenSTA
###############################################################################
.PHONY: sta
sta: synthesis
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)Running Static Timing Analysis...$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "read_liberty $(LIB_TYPICAL)" > $(LOGS_DIR)/sta_script.tcl
	@echo "read_verilog $(NETLIST)" >> $(LOGS_DIR)/sta_script.tcl
	@echo "link_design $(TOP_MODULE)" >> $(LOGS_DIR)/sta_script.tcl
	@echo "read_sdc $(SDC_FILE)" >> $(LOGS_DIR)/sta_script.tcl
	@echo "report_checks -path_delay min_max -format full_clock_expanded" >> $(LOGS_DIR)/sta_script.tcl
	@echo "report_tns" >> $(LOGS_DIR)/sta_script.tcl
	@echo "report_wns" >> $(LOGS_DIR)/sta_script.tcl
	@echo "report_power" >> $(LOGS_DIR)/sta_script.tcl
	@$(STA) -exit $(LOGS_DIR)/sta_script.tcl | tee $(STA_LOG)
	@echo "$(COLOR_GREEN)✓ Timing analysis complete!$(COLOR_RESET)"
	@echo "$(COLOR_GREEN)  Report: $(STA_LOG)$(COLOR_RESET)"


###############################################################################
# Generate Reports
###############################################################################
.PHONY: report
report:
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)Generating Synthesis Reports...$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_YELLOW)Area Report:$(COLOR_RESET)"
	@grep -A 20 "Number of cells" $(REPORTS_DIR)/synthesis_stats.txt || true
	@echo ""
	@echo "$(COLOR_YELLOW)Cell Usage:$(COLOR_RESET)"
	@grep "sky130_fd_sc_hd__" $(REPORTS_DIR)/synthesis_stats.txt | head -20 || true
	@echo ""
	@echo "$(COLOR_GREEN)✓ Reports generated in $(REPORTS_DIR)/$(COLOR_RESET)"

###############################################################################
# Visualize Design
###############################################################################
.PHONY: visualize
visualize: synthesis
	@echo "$(COLOR_BLUE)Generating design visualization...$(COLOR_RESET)"
	@echo "read_verilog $(NETLIST)" > $(LOGS_DIR)/show.ys
	@echo "hierarchy -check -top $(TOP_MODULE)" >> $(LOGS_DIR)/show.ys
	@echo "proc; opt; memory; opt" >> $(LOGS_DIR)/show.ys
	@echo "show -format dot -prefix $(RESULTS_DIR)/design" >> $(LOGS_DIR)/show.ys
	@$(YOSYS) -s $(LOGS_DIR)/show.ys
	@echo "$(COLOR_GREEN)✓ Visualization generated: $(RESULTS_DIR)/design.dot$(COLOR_RESET)"

###############################################################################
# Equivalence Checking (using Yosys)
###############################################################################
.PHONY: equiv
equiv: synthesis
	@echo "$(COLOR_BLUE)Running equivalence check...$(COLOR_RESET)"
	@echo "read_verilog -sv $(SRC_DIR)/*.v" > $(LOGS_DIR)/equiv.ys
	@echo "hierarchy -check -top $(TOP_MODULE)" >> $(LOGS_DIR)/equiv.ys
	@echo "proc; opt; memory; opt" >> $(LOGS_DIR)/equiv.ys
	@echo "design -stash gold" >> $(LOGS_DIR)/equiv.ys
	@echo "read_verilog $(NETLIST)" >> $(LOGS_DIR)/equiv.ys
	@echo "prep -top $(TOP_MODULE)" >> $(LOGS_DIR)/equiv.ys
	@echo "design -stash gate" >> $(LOGS_DIR)/equiv.ys
	@echo "design -copy-from gold -as gold $(TOP_MODULE)" >> $(LOGS_DIR)/equiv.ys
	@echo "design -copy-from gate -as gate $(TOP_MODULE)" >> $(LOGS_DIR)/equiv.ys
	@echo "equiv_make gold gate equiv" >> $(LOGS_DIR)/equiv.ys
	@echo "equiv_simple -undef" >> $(LOGS_DIR)/equiv.ys
	@echo "equiv_induct -undef" >> $(LOGS_DIR)/equiv.ys
	@echo "equiv_status -assert" >> $(LOGS_DIR)/equiv.ys
	@$(YOSYS) -s $(LOGS_DIR)/equiv.ys | tee $(LOGS_DIR)/equiv.log
	@echo "$(COLOR_GREEN)✓ Equivalence check complete$(COLOR_RESET)"

###############################################################################
# Clean Targets
###############################################################################
.PHONY: clean
clean:
	@echo "$(COLOR_YELLOW)Cleaning synthesis outputs...$(COLOR_RESET)"
	@rm -rf $(RESULTS_DIR)
	@rm -rf $(REPORTS_DIR)
	@rm -rf $(LOGS_DIR)
	@rm -f *.log *.v *.json *.blif *.dot *.svg
	@echo "$(COLOR_GREEN)✓ Clean complete$(COLOR_RESET)"

.PHONY: clean-all
clean-all: clean
	@echo "$(COLOR_YELLOW)Deep cleaning...$(COLOR_RESET)"
	@rm -f *~
	@echo "$(COLOR_GREEN)✓ Deep clean complete$(COLOR_RESET)"

###############################################################################
# Help Target
###############################################################################
.PHONY: help
help:
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)RV32I Synthesis Makefile Help$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)=========================================$(COLOR_RESET)"
	@echo ""
	@echo "$(COLOR_YELLOW)Available targets:$(COLOR_RESET)"
	@echo "  $(COLOR_GREEN)all$(COLOR_RESET)              - Run complete synthesis flow"
	@echo "  $(COLOR_GREEN)setup$(COLOR_RESET)            - Create required directories"
	@echo "  $(COLOR_GREEN)synthesis$(COLOR_RESET)        - Run Yosys synthesis"
	@echo "  $(COLOR_GREEN)sta$(COLOR_RESET)              - Run static timing analysis (typical corner)"
	@echo "  $(COLOR_GREEN)report$(COLOR_RESET)           - Generate synthesis reports"
	@echo "  $(COLOR_GREEN)visualize$(COLOR_RESET)        - Generate design visualization"
	@echo "  $(COLOR_GREEN)equiv$(COLOR_RESET)            - Run equivalence checking"
	@echo "  $(COLOR_GREEN)clean$(COLOR_RESET)            - Remove generated files"
	@echo "  $(COLOR_GREEN)clean-all$(COLOR_RESET)        - Deep clean"
	@echo "  $(COLOR_GREEN)help$(COLOR_RESET)             - Show this help message"
	@echo ""
	@echo "$(COLOR_YELLOW)Environment Variables:$(COLOR_RESET)"
	@echo "  PDK_ROOT=$(PDK_ROOT)"
	@echo "  PDK=$(PDK)"
	@echo "  STD_CELL=$(STD_CELL)"
	@echo ""
	@echo "$(COLOR_YELLOW)Example Usage:$(COLOR_RESET)"
	@echo "  make all              # Complete flow"
	@echo "  make synthesis        # Synthesis only"
	@echo ""

###############################################################################
# Phony Targets
###############################################################################
.PHONY: all setup synthesis sta report visualize equiv clean clean-all help