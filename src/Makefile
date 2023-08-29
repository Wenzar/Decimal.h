CC=gcc
C_FLAGS=-Wall -Wextra -Werror -std=c11 
TEST_FLAGS= $(C_FLAGS) -g
LINUX_FLAGS=-lsubunit -lrt -lpthread -lm
UNIT_TESTS=$(wildcard ./unit_tests/s21_*.c)
SRC=$(wildcard s21_*.c)
OBJ=$(patsubst %.c,%.o, $(SRC))
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
OS:= $(shell uname -s)

TARGET=s21_decimal.a

all: $(TARGET) gcov_report clean_all_but_report

$(TARGET): $(OBJ)
	ar rc $@ $^
	ranlib $@
	make clean_obj

test: $(TARGET)
ifeq ($(OS), Darwin)
	$(CC) $(C_FLAGS) $(UNIT_TESTS) $< -o units_test -lcheck
else
	$(CC) $(C_FLAGS) $(UNIT_TESTS) $< -o units_test -lcheck $(LINUX_FLAGS)
endif
	./units_test

gcov_report: clean_report

ifeq ($(OS), Darwin)
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) $(UNIT_TESTS) $(SRC) -o test -lcheck
else
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) $(UNIT_TESTS) $(SRC) -o test -lcheck $(LINUX_FLAGS)
endif
	./test
	lcov -t "TEST" -o s21_test.info -c -d .
	genhtml -o report s21_test.info

style:
	clang-format -n --style=Google *.c *.h

lcov:
	brew install lcov

clean:
	rm -rf *.o *.a units_test 
	make clean_report

clean_obj:
	rm -rf $(OBJ)

clean_report:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean_all_but_report:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf *.a