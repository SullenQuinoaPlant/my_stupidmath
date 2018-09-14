NAME = mystupidmath
LIBNAME = libmystupidmath
GIT_REPO = https://github.com/SullenQuinoaPlant/my_stupidmath.git

CALL_DIR := $(shell pwd)
SRC_DIR := $(ROOT)/sources
OBJ_DIR := $(ROOT)/objects
LIB_DIR := $(ROOT)/libs
LIBS_L := $(LIB_DIR)/objects
LIBS_I := $(LIB_DIR)/includes
OUT_DIR_LIB := $(LIBS_L)
OUT_DIR_H := $(LIBS_I)

include $(SRC_DIR)/targets.mk

DEPENDENCIES = libmyfloatingpoint libft

CC := gcc
CFLAGS_MORE =
ifndef CFLAGS
	CFLAGS := -Wall -Wextra -Werror
endif
CFLAGS += $(CFLAGS_MORE)

UTEST_DIR := $(ROOT)/unit-tests
