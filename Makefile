EXEC = insura_crm.exe
TEST_EXEC = insura_crm_test.exe

SRC_MAIN = src/main.cpp
COMMON_SOURCES = $(filter-out $(SRC_MAIN), $(wildcard src/*.cpp src/**/*.cpp))
APP_SOURCES = $(COMMON_SOURCES) $(SRC_MAIN)
TEST_SOURCES = $(COMMON_SOURCES) $(wildcard tests/*.cpp tests/**/*.cpp)

all: compile run

test: $(TEST_SOURCES)
	g++ -std=c++20 -D__TEST__ -Iinclude -Itests -o $(TEST_EXEC) $^
	$(TEST_EXEC)
	rm -f $(TEST_EXEC)

run:
	$(EXEC)

compile: $(APP_SOURCES)
	g++ -std=c++20 -Iinclude -o $(EXEC) $^

clean: 
	rm -f $(EXEC)

.PHONY: all compile run clean