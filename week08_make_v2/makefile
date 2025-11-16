.PHONY: all basic_ops advanced_ops clean

SRC_DIR=src
OBJ_DIR=obj
OBJFILE=$(OBJ_DIR)/*.o
LIB_DIR=lib
BIN_DIR = bin
SRCFILE=$(wildcard $(SRC_DIR)/*.c)
INC=include

BASIC_LIB = $(LIB_DIR)/libmybasic.a
ADV_LIB = $(LIB_DIR)/libmyadvanced.a
BINFILE = $(BIN_DIR)/myapp

all: advanced_ops basic_ops $(BINFILE)

$(BINFILE): $(SRC_DIR)/myapp.c $(BASIC_LIB) $(ADV_LIB) 
	$(CC) $< -lmybasic -lmyadvanced -I$(INC) -L$(LIB_DIR) -lm -o $@

basic_ops:
	$(MAKE) -C basic_ops

advanced_ops:
	$(MAKE) -C advanced_ops

clean:
	rm -f $(OBJFILE) $(BINFILE) $(LIB_DIR)/*.a
	$(MAKE) -C advanced_ops clean;
	$(MAKE) -C basic_ops clean;