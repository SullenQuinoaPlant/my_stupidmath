TARGETS := \
	expl \
	flog2 \
	intpow \
	lnl \
	powl
NAME = mystupidmath
LIBNAME = libmystupidmath

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
INC_DIR := $(ROOT)/includes
OBJ_DIR := $(ROOT)/
LIB_DIR := $(ROOT)/
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(ROOT)/
OUT_DIR_H := $(ROOT)/includes

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror -I $(INC_DIR)
endif
CFLAGS += $(CFLAGS_MORE)
