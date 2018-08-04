NAME = mystupidmath
LIBNAME = libmystupidmath

CALL_DIR := $(shell pwd)
SRC_DIR	:= $(ROOT)/
OBJ_DIR := $(ROOT)/
LIB_DIR := $(ROOT)/
LIBS_I := $(LIB_DIR)/
OUT_DIR_LIB := $(ROOT)/
OUT_DIR_H := $(ROOT)/

include $(SRC_DIR)/targets.mk

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror
endif
CFLAGS += $(CFLAGS_MORE)
