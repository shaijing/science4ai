"""
Science4ai
==========

"""

from . import version
from .version import __version__


def science4ai():
    print("This is Science4ai package!")


try:
    from . import mod

    MOD_LOAD = True
except ImportError:
    MOD_LOAD = False
