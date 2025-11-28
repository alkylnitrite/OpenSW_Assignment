CC      = gcc
CFLAGS  = -Iinclude -fPIC -Wall

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
LIB_DIR = lib

OBJS    = $(OBJ_DIR)/myadd.o $(OBJ_DIR)/mysub.o $(OBJ_DIR)/mymul.o $(OBJ_DIR)/mydiv.o $(OBJ_DIR)/mymod.o $(OBJ_DIR)/mypow.o

LIB     = $(LIB_DIR)/libmyops.so.1.0
EXE     = $(BIN_DIR)/myapp

all: $(EXE)

$(LIB): $(OBJS)
	@mkdir -p $(LIB_DIR)
	$(CC) -shared -Wl,-soname,libmyops.so.1 -o $@ $^
	ln -sf $@ $(LIB_DIR)/libmyops.so

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/myapp.o: $(SRC_DIR)/myapp.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXE): $(OBJ_DIR)/myapp.o $(LIB)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -L$(LIB_DIR) -lmyops -Wl,-rpath=$(LIB_DIR) -o $@

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/myapp $(LIB_DIR)/libmyops.so*

.PHONY: all clean
