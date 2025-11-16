SRC_DIR=src
SRCFILE=$(wildcard $(SRC_DIR)/*.c)
LIB_DIR = lib
LIB=$(LIB_DIR)/libmyadvanced.a 
BIN_DIR = bin
BINFILE = $(BIN_DIR)/myapp
OBJ_DIR=obj
OBJFILE=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCFILE:.c=.o))
INC=include


advanced_ops: $(LIB)
$(LIB): $(OBJFILE) #라이브러리 만들기
	ar rv ../$(LIB) $(OBJFILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) #소스파일->오브젝트파일
	$(CC) -c $< -I../$(INC) -o $@ 

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJFILE) $(BINFILE) $(LIB)

