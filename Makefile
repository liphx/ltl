CPP     = g++ -g -std=c++20 -W -Wall -Werror -Wfatal-errors
LTL     = -iquote include
STD     = -Dltl=std
LDFLAGS = -lgtest -lgtest_main
TESTS   = $(wildcard unittests/*_test.cpp)

test_all: $(TESTS)
	$(CPP) $(LTL) -o $@ $^ $(LDFLAGS)

test_std_all: $(TESTS)
	$(CPP) $(STD) -o $@ $^ $(LDFLAGS)

%_test: unittests/%_test.cpp
	$(CPP) $(LTL) -o $@ $^ $(LDFLAGS)

%_std_test: unittests/%_test.cpp
	$(CPP) $(STD) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o *_test test_all *.dSYM a.out test_std_all

lint:
	clang-format -i unittests/* include/detail/*
