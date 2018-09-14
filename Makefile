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
include $(ROOT)/core.mk

##########
#TARGETS :
include $(SRC_DIR)/Makefile

#######
#LIBS :
include $(LIB_DIR)/Makefile

########
#TESTS :
include $(UTEST_DIR)/Makefile

#########
#RELEASE :
RELEASE_DIR = release_$(NAME)

.PHONY : release
release : $(ROOT)/$(RELEASE_DIR)

.PHONY : $(ROOT)/$(RELEASE_DIR)
$(ROOT)/$(RELEASE_DIR) :
	if [ -d $@ ];\
	then rm -rf $@/;\
	fi
	git clone \
		--single-branch \
		-b release \
		$(GIT_REPO) \
		$@
	cd $@ && git rm -rf *
	cp auteur $@/
	mkdir $@/sources
	cp -r $(SRC_DIR)/*.c $@/sources/
	mkdir $@/includes
	cp -r $(ROOT)/*.h $@/includes
	cp $(patsubst %,$(LIBS_I)/%.h,$(DEPENDENCIES)) $@/includes
	cp core.mk $@/Makefile
	cp $(ROOT)/targets.mk $@/make_vars.mk
	cat make_vars_release.mk >> $@/make_vars.mk
	cd $@ && \
		git add * && \
		git commit -m make_release && \
		git push origin release
