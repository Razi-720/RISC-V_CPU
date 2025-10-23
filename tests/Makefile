# ==============================================================================
# Makefile - Build and Run Configuration
# ==============================================================================

# Makefile for RV32I Pipeline Testbench

# Simulator selection
SIM ?= verilator
TOPLEVEL_LANG ?= verilog

# DUT configuration
TOPLEVEL = Pip_RV32I
MODULE = tests.test_pipeline_rv32i

# src source files (adjust paths as needed)
VERILOG_SOURCES += $(shell pwd)/../src/Pip_RV32I.v

# Compiler flags
COMPILE_ARGS += -I$(shell pwd)/../src
COMPILE_ARGS += -DSIM

# Cocotb configuration
export COCOTB_REDUCED_LOG_FMT=1

# Waveform configuration - Modified for Icarus compatibility
WAVES ?= 1
# Waveform configuration - Modified for Verilator compatibility
WAVES ?= 1
ifeq ($(WAVES),1)
    ifeq ($(SIM),verilator)
        COMPILE_ARGS += -DCOCOTB_WAVES=1
        EXTRA_ARGS += --trace --trace-structs
        SIM_BUILD_ARGS += --coverage --trace-fst --trace-structs
    endif
    ifeq ($(SIM),icarus)
        COMPILE_ARGS += -DCOCOTB_WAVES=1
        SIM_BUILD_ARGS += -lxt2
    endif
endif


# Test configuration
COCOTB_LOG_LEVEL ?= INFO
RANDOM_SEED ?= 12345

# Python path
export PYTHONPATH := $(shell pwd):$(PYTHONPATH)

# Include cocotb makefiles
include $(shell cocotb-config --makefiles)/Makefile.sim

# Additional targets
.PHONY: clean test-all test-basic test-memory test-branch test-hazards test-performance

# Run all tests
test-all: clean
	$(MAKE) MODULE=tests.test_pipeline_rv32i

# Run individual test suites
test-basic:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_basic_arithmetic

test-memory:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_memory_operations

test-branch:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_branch_instructions

test-hazards:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_data_hazards

test-performance:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_pipeline_performance

test-stress:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_stress_random

test-edge:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE=test_edge_cases

# Coverage collection (if supported)
coverage:
	$(MAKE) SIM_ARGS="--coverage" test-all

# Clean up generated files
clean-all:
	rm -rf sim_build/
	rm -rf __pycache__/
	rm -rf tests/__pycache__/
	rm -f results.xml
	rm -f *.vcd *.fst *.ghw
	rm -f testbench.log
	rm -f *_report.json

# Debug target with waveform dump
debug:
	$(MAKE) MODULE=tests.test_pipeline_rv32i TESTCASE?=test_basic_arithmetic WAVES=1


# Regression testing
regression:
	@echo "Running regression test suite..."
	$(MAKE) test-basic
	$(MAKE) test-memory  
	$(MAKE) test-branch
	$(MAKE) test-hazards
	$(MAKE) test-edge
	@echo "Regression testing completed"

# Help target
help:
	@echo "Available targets:"
	@echo "  test-all      - Run complete test suite"
	@echo "  test-basic    - Run basic arithmetic tests"
	@echo "  test-memory   - Run memory operation tests"
	@echo "  test-branch   - Run branch instruction tests"
	@echo "  test-hazards  - Run data hazard tests"
	@echo "  test-performance - Run pipeline performance tests"
	@echo "  test-stress   - Run random stress tests"
	@echo "  test-edge     - Run edge case tests"
	@echo "  regression    - Run regression test suite"
	@echo "  coverage      - Run tests with coverage collection"
	@echo "  debug         - Run basic test with waveform dump"
	@echo "  clean         - Clean generated files"
	@echo ""
	@echo "Environment variables:"
	@echo "  SIM=icarus|ghdl|questa  - Select simulator"
	@echo "  RANDOM_SEED=<num>       - Set random seed"
	@echo "  COCOTB_LOG_LEVEL=<level> - Set log level"
