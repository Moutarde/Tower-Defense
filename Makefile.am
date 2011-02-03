bin_PROGRAMS = towerdefense tests

towerdefense_SOURCES = src/main.c

tests_SOURCES = test/tests.c \
test/enemy/test_enemy.c \
src/enemy/enemy.c \
src/enemy/typeEn.c

towerdefense_LDADD = -lSDL
tests_LDADD = -lSDL -lcunit