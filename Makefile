.PHONY : def
def : targets
	$(MAKE) all


############
#VARIABLES :

ifndef ROOT
 ROOT := .
endif

include $(ROOT)/make_vars.mk


#######
#CORE :

include $(ROOT)/Makefile.mk


##########
#TARGETS :

include $(SRC_DIR)/Makefile


#######
#LIBS :

include $(LIB_DIR)/Makefile

########
#TESTS :
	
include $(UTEST_DIR)/Makefile

########
#DEBUG :

include $(DEBUG_DIR)/Makefile


#########
#OUTPUT :

OUT = out_$(NAME)

.PHONY : distribute
distribute :
	if ! [ -d $(OUT) ]; then mkdir $(OUT); fi
	cp auteur $(OUT)/
	cp Makefile.mk $(OUT)/Makefile
	cp -r $(SRC_DIR)/ $(OUT)/
