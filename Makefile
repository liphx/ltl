CPP     = g++ -g -std=c++20 -W -Wall -Werror -Wfatal-errors -iquote include
LDFLAGS = -lgtest -lgtest_main
TESTS   = $(wildcard unittests/*_test.cpp)

test_all: $(TESTS)
	$(CPP) -o $@ $^ $(LDFLAGS)

%_test: unittests/%_test.cpp
	$(CPP) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf *.o *_test test_all *.dSYM a.out

lint:
	clang-format -i unittests/* include/detail/*
