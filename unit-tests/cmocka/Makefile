ifndef ROOT
	ROOT = ../..
	include $(ROOT)/make_vars.mk
endif

BUILD_DIR = cmocka_build
SOURCE_DIR = cmocka_source

cmocka : $(BUILD_DIR) $(SOURCE_DIR) build_cmocka pull_cmocka_files

.PHONY : pull_cmocka_files 
pull_cmocka_files :
	cp $(BUILD_DIR)/src/libcmocka* $(LIBS_L)/
	cp $(SOURCE_DIR)/include/cmocka.h $(LIBS_I)/

.PHONY : build_cmocka
build_cmocka :
	cd $(BUILD_DIR) && cmake ../$(SOURCE_DIR) && make;

$(BUILD_DIR) :
	if ! [ -d $(BUILD_DIR) ];\
	then mkdir $(BUILD_DIR);\
	fi

$(SOURCE_DIR) :
	if [ -d $(SOURCE_DIR) ];\
	then rm -rf $(SOURCE_DIR);\
	fi
	git clone \
		--depth 1 \
		git://git.cryptomilk.org/projects/cmocka.git \
		$(SOURCE_DIR)
#hack to get buggy doxygen to shut up:
	echo "" > $(SOURCE_DIR)/doc/CMakeLists.txt
