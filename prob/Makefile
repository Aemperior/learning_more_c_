
EXECUTABLE  = prob

COMPILER    = gcc
CFLAGS      = -Wall -g -std=gnu11 -fsanitize=address -ldl
LDFLAGS     = -fsanitize=address -lm
EXCLUDE     = ''#currently nothing excluded, to exclude 'test', outcomment following: #'*test*'


SOURCEDIR = src
INCLUDEDIR = inc
OBJECTDIR = build

SOURCES := $(patsubst $(SOURCEDIR)/%, %, $(shell find $(SOURCEDIR) -name '*.c'  ! -name $(EXCLUDE)  ! -path $(EXCLUDE)))
OBJECTS = $(addprefix $(OBJECTDIR)/, $(SOURCES:.c=.o))

all: $(EXECUTABLE) 

rebuild: clean all
	
clean:
	rm -f $(EXECUTABLE)
	rm -rf $(OBJECTDIR)

## executable depends on object files: link them
$(EXECUTABLE): $(OBJECTS) 
	$(COMPILER) $^ -o $@ $(LDFLAGS)

## object files depend on source files: compile them
$(OBJECTDIR)/%.o: $(SOURCEDIR)/%.c
	@mkdir -p $(@D)
	$(COMPILER) -I$(INCLUDEDIR) -o $@ -c $(CFLAGS) $<

	
.PHONY: all rebuild clean

