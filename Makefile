EXEC = insura_crm.exe
SOURCES = $(wildcard src/*.cpp src/**/*.cpp)

all: compile run

run:
	$(EXEC)

compile: $(SOURCES)
	g++ -Iinclude -o $(EXEC) $^

clean: 
	rm -f $(EXEC)

.PHONY: all compile run clean