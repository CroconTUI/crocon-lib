PROJECT         = crocon

CROCON_LIB_ROOT = ../..

PREFIX          = /usr/local
INC_DIR         = $(CROCON_LIB_ROOT)/include
SRC_DIR         = $(CROCON_LIB_ROOT)/src
DEF_DIR         = $(CROCON_LIB_ROOT)/def
RES_DIR         = $(CROCON_LIB_ROOT)/res

BIN_DIR         = $(CROCON_LIB_ROOT)/../out/library/bin
OBJ_DIR         = $(CROCON_LIB_ROOT)/../out/library/obj

C_FLAGS         = -Wall -Wextra -O2

OBJECTS         = $(OBJ_DIR)/crocunix.o \
                  $(OBJ_DIR)/crocscrn.o \
                  $(OBJ_DIR)/crocclrs.o \
                  $(OBJ_DIR)/crocon.o

SOURCES         = $(patsubst $(OBJ_DIR)/%.o, $(SRC_DIR)/%.c, $(OBJECTS))

all: prepare $(BIN_DIR)/lib$(PROJECT).so $(BIN_DIR)/lib$(PROJECT).a

prepare:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/os/unix/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/utils/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/widgets/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@


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
