# ==============================================================================
# conftest.py - Pytest Configuration (Optional)
# ==============================================================================

"""
import pytest
import os
import sys

# Add testbench directory to path
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

@pytest.fixture(scope="session")
def cocotb_simulator():
    '''Configure simulator for pytest'''
    return os.environ.get('SIM', 'icarus')

@pytest.fixture(scope="session") 
def dut_name():
    '''DUT top-level name'''
    return 'Pip_RV32I'

def pytest_configure(config):
    '''Configure pytest for cocotb'''
    config.addinivalue_line(
        "markers", "cocotb: marks tests as cocotb tests"
    )
"""
