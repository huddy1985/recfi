##===- lib/CfiPasses/Makefile -----------------------*- Makefile -*-===##
#
#                     The LLVM Compiler Infrastructure
#
# This file is distributed under the University of Illinois Open Source
# License. See LICENSE.TXT for details.
#
##===----------------------------------------------------------------------===##

LEVEL = ../../

LIBRARYNAME=CfiPasses

LLVMSRC = /home/rohan/recfi/llvm-3.3
POOLALLOC_SRCDIR := $(LLVMSRC)/projects/poolalloc
SC_FLAGS = -I$(POOLALLOC_SRCDIR)/include -I$(PROJ_SRC_ROOT)/include

CFLAGS   += $(SC_FLAGS)
CPPFLAGS += $(SC_FLAGS)
CXXFLAGS += $(SC_FLAGS)

LOADABLE_MODULE := 1
BUILD_ARCHIVE := 1
SHARED_LIBRARY := 1

include $(LEVEL)/Makefile.common
