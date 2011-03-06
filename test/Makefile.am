TESTS = tests

noinst_PROGRAMS = $(TESTS)

bin_PROGRAMS = tests

tests_SOURCES = tests.c \
enemy/test_enemy.c \
../src/enemy/enemy.c \
../src/enemy/typeEn.c

AM_CFLAGS=-Wall -std=c99

tests_LDADD = -lSDLmain -lSDL -lSDL_image -lcunit
