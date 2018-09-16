ifndef ROOT
 ROOT := ..
 include $(ROOT)/Makefile
endif

TEST_SRCS := $(wildcard $(UTEST_DIR)/*.test.c)
TEST_OBJS := $(TEST_SRCS:.c=.o)
EXECUTION_STAMPS := $(TEST_OBJS:.o=.execution.stamp)

CFLAGS_UTEST = -fno-builtin -g
CFLAGS_UTEST += $(CFLAGS_MORE) #$(CFLAGS) were annoying the hell out of me

TEST_DEPENDENCIES = libft



.PHONY : tests_all 
tests_all : build_test_dependencies clean-tests tests


############
#BUILD TESTS

.PHONY : build_tests
build_tests\
:\
build_test_dependencies\
set_utest_flags def\
\
$(TEST_OBJS)

.PHONY : build_test_dependencies
build_test_dependencies : $(TEST_DEPENDENCIES) test_prerequisites

.PHONY : set_utest_flags
set_utest_flags :
	$(eval CFLAGS += $(CFLAGS_UTEST))


.PHONY : test_prerequisites
test_prerequisites : cmocka $(UTEST_DIR)/math_ref.so


.PHONY : cmocka
cmocka : 
	if $(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -L $(LIBS_L)\
		$(UTEST_DIR)/cmocka/check_install.c\
		-o test.o\
		-lcmocka_shared\
		-Wl,-rpath="$(LIBS_L)"\
		&& ./test.o .;\
	then\
		echo "cmocka already installed";\
	else\
		echo "installing cmocka";\
		$(MAKE) -C $(UTEST_DIR)/cmocka/;\
	fi
	-@rm ./test.o


$(UTEST_DIR)/math_ref.so\
:\
$(UTEST_DIR)/math_ref.c
	gcc -c -fPIC $< -o tmp.o &&\
	gcc -shared -o $@ tmp.o -lm
	-rm tmp.o


$(UTEST_DIR)/%.test.o\
:\
$(UTEST_DIR)/%.test.c\
$(LIBS_L)/$(LIBNAME).a
	$(CC) $(CFLAGS_UTEST)\
		-I $(LIBS_I) -I $(SRC_DIR) -I $(INC_DIR)\
		$<\
		-L $(LIBS_L)\
		-lcmocka_shared\
		-l$(NAME) -lmyfloatingpoint -lft\
		$(UTEST_DIR)/math_ref.so\
		-o $@\
		-Wl,-rpath=$(LIBS_L)\
		-Wl,-rpath=$(UTEST_DIR)


%.test.c : $(UTEST_DIR)/cmocka/my_macro_overlay.h
	@:



############
#RUN TESTS :

.PHONY : tests
tests : list_tests build_tests run_tests

.PHONY : run_tests
run_tests : $(EXECUTION_STAMPS)

%.execution.stamp : %.o
	-./$*.o "$(UTEST_DIR)" \
	&& touch $@



###############
#MISCELLANEOUS:

.PHONY : clean-tests
clean-tests :
	-rm $(UTEST_DIR)/*.o
	-rm $(UTEST_DIR)/*.stamp



.PHONY : list_tests
list_tests :
	@echo "source dir is : $(SRC_DIR)"
	@echo "list of test sources:"
	@echo $(TEST_SRCS)
	@echo "list of test objects:"
	@echo $(TEST_OBJS)
