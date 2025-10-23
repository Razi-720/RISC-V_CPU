# ==============================================================================
# __init__.py files for proper Python package structure
# ==============================================================================

"""
# tests/__init__.py
'''
RV32I Pipeline Testbench Package

A comprehensive, production-grade testbench for 5-stage pipelined RV32I processor.
'''

__version__ = "1.0.0"
__author__ = "Testbench Generator"

# Import main classes for easy access
from .driver import RV32IDriver, InstructionMemory, DataMemory
from .monitor import RV32IPipelineMonitor, PipelineSnapshot
from .scoreboard import RV32IScoreboard, Mismatch, MismatchType
from .isa_reference import RV32IReferenceModel, RV32IInstruction
from .utils import (RV32IInstructionFactory, RV32IInstructionEncoder, 
                   PerformanceAnalyzer, TestProgramGenerator, setup_logging)

__all__ = [
    'RV32IDriver',
    'InstructionMemory', 
    'DataMemory',
    'RV32IPipelineMonitor',
    'PipelineSnapshot',
    'RV32IScoreboard',
    'Mismatch',
    'MismatchType', 
    'RV32IReferenceModel',
    'RV32IInstruction',
    'RV32IInstructionFactory',
    'RV32IInstructionEncoder',
    'PerformanceAnalyzer',
    'TestProgramGenerator',
    'setup_logging'
]
"""