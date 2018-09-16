ifndef ROOT
 ROOT := .
 include $(ROOT)/make_vars.mk
endif


OBJS := $(patsubst %,$(OBJ_DIR)/%.o,$(TARGETS))

all : $(OUT_DIR_LIB)/$(LIBNAME).a header

.PHONY : header
header : $(OUT_DIR_H)/$(LIBNAME).h
$(OUT_DIR_H)/$(LIBNAME).h :
	sed -e '13,14s@\(MYSTUPIDMATH_H\)@LIB\1@'\
		-e '4s@\([a-z0-9][a-z0-9]*\.h\)   @lib\1@'\
		$(INC_DIR)/$(NAME).h >\
		$(OUT_DIR_H)/$(LIBNAME).h

$(OUT_DIR_LIB)/$(LIBNAME).a : $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS)\
		-I $(LIBS_I)\
		-o $@ -c $<

.PHONY : re fclean clean all
clean :
	-rm $(OBJS)
	-rm $(OBJ_DIR)/$(NAME).o

fclean : clean
	-rm $(OUT_DIR_LIB)/$(LIBNAME).a
	-rm $(OUT_DIR_H)/$(LIBNAME).h

re : fclean all
