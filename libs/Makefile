ifndef ROOT
	ROOT = ..
	include $(ROOT)/Makefile
endif


.PHONY : build_dependencies
build_dependencies : $(DEPENDENCIES)
	@echo "$(DEPENDENCIES)"

define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$(@F).a $(LIBS_L)
	cp $@/includes/$(@F).h $(LIBS_I)
endef

.PHONY : libft
libft : $(LIB_DIR)/libft
$(LIB_DIR)/libft :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/Libft.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)

.PHONY : libmyfloatingpoint
libmyfloatingpoint : $(LIB_DIR)/libmyfloatingpoint
$(LIB_DIR)/libmyfloatingpoint :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_floatingpoint.git \
		--depth 1 \
		$@/
	$(BUILD_LIB)


.PHONY : clean-*
clean-% :
	-rm -rf $(LIB_DIR)/$*
	-rm $(LIBS_I)/$*.h
	-rm $(LIBS_L)/$*.a

CLEAN_ALL_LIBS := $(patsubst %,clean-%, $(DEPENDENCIES))
.PHONY : clean-libs
clean-libs : $(CLEAN_ALL_LIBS)

.PHONY : libs_re
libs_re : clean-libs build_dependencies
