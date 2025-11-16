SRC_DIR=src
OBJ_DIR=obj
LIB_DIR = lib
LIB=$(LIB_DIR)/libmybasic.a
BIN_DIR = bin
BINFILE = $(BIN_DIR)/myapp
OBJFILE=$(subst $(SRC_DIR), $(OBJ_DIR), $(SRCFILE:.c=.o))
SRCFILE=$(wildcard $(SRC_DIR)/*.c)
INC=include


all: $(BINFILE)

$(BINFILE): $(SRC_DIR)/myapp.c $(LIB) #라이브러리는 기능을 나열. main함수가 프로그램에서 기능 호출
	$(CC) $< -lmybasic -I$(INC) -L$(LIB_DIR) -o $@

basic: $(LIB)
$(LIB): $(OBJFILE) #라이브러리 만들기
	ar rv $(LIB) $(OBJFILE)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) #소스파일->오브젝트파일
	$(CC) -I$(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJFILE) $(BINFILE) $(LIB)

#all: $(LIB)
#	$(CC) $(SRC_DIR)/myapp.c -Llib -lmybasic -I$(INC) -o $(BIN_DIR)/myap



#오브젝트 파일을 모아둔것이 정적 라이브러리
#오브젝트 - 라이브러리 - binfile