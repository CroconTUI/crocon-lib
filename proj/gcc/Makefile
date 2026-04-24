PROJECT         = crocon

CROCON_LIB_ROOT = ../..

PREFIX          = /usr/local
INC_DIR         = $(CROCON_LIB_ROOT)/include
SRC_DIR         = $(CROCON_LIB_ROOT)/src
DEF_DIR         = $(CROCON_LIB_ROOT)/def
RES_DIR         = $(CROCON_LIB_ROOT)/res

SRC_DIRS        = $(SRC_DIR) \
                  $(SRC_DIR)/os/unix \
                  $(SRC_DIR)/utils \
                  $(SRC_DIR)/widgets

BIN_DIR         = $(CROCON_LIB_ROOT)/../out/library/bin
OBJ_DIR         = $(CROCON_LIB_ROOT)/../out/library/obj

C_FLAGS         = -O2 -fPIC 

SOURCES         = $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

OBJECTS         = $(OBJ_DIR)/crocunix.o \
                  $(OBJ_DIR)/crocscrn.o \
                  $(OBJ_DIR)/crocclrs.o \
                  $(OBJ_DIR)/crocon.o

all: prepare $(BIN_DIR)/lib$(PROJECT).so $(BIN_DIR)/lib$(PROJECT).a

prepare:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/os/unix/%.c
	$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/utils/%.c
	$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/widgets/%.c
	$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@


$(BIN_DIR)/lib$(PROJECT).so: $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

$(BIN_DIR)/lib$(PROJECT).a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

install: all
	mkdir -p $(PREFIX)/lib
	cp $(LIB_DIR)/lib$(PROJECT).so $(PREFIX)/lib/
	cp $(LIB_DIR)/lib$(PROJECT).a $(PREFIX)/lib/

	mkdir -p $(PREFIX)/include/$(PROJECT)
	cp $(INC_DIR)/*.h $(PREFIX)/include/$(PROJECT)/

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

rebuild:
	clean all

.PHONY: 
	all install clean rebuild
