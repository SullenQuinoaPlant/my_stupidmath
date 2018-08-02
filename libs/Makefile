ifndef ROOT
	ROOT = ..
	include $(ROOT)/make_vars.mk
endif


.PHONY : build_dependencies
build_dependecies : $(DEPENDENCIES)

define BUILD_LIB
	$(MAKE) -C $@/ 
	cp $@/$@.a $(LIBS_L)
	cp $@/$@.h $(LIBS_I)
	rm -rf $@
	touch $@
endef
	
libft :
	git clone \
		--single-branch \
		-b the_lib https://github.com/SullenQuinoaPlant/Libft.git \
		-depth 1 \
		$@/
	$(BUILD_LIB)


libmyfloatingpoint :
	git clone \
		--single-branch \
		-b release https://github.com/SullenQuinoaPlant/my_floatingpoint.git \
		-depth 1 \
		$(BUILD_DIR)/
	$(BUILD_LIB)


.PHONY : clean-*
clean-% :
	-rm $(LIBS_DIR)/$*
	-rm $(LIBS_I)/$*.h
	-rm $(LIBS_L)/$*.a