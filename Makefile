.PHONY : def
def : targets all


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
	git clone -b the_lib --single-branch https://github.com/SullenQuinoaPlant/Libft.git $(OUT)/libft
	cp Makefile.mk $(OUT)/Makefile
	cp -r $(SRC_DIR)/ $(OUT)/


################
#MISCELLANEOUS :

.PHONY : c
c :
	git commit -a -m i

.PHONY : p
p :
	git push

.PHONY : cp
cp :
	git commit -a -m i; git push;
