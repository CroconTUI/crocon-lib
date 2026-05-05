PROJECT         =  crocon

CROCON_LIB_ROOT =  ../..

CROCON_DEBUG    =? false
CROCON_LEGACY   =? false

INC_DIR         =  $(CROCON_LIB_ROOT)/include
SRC_DIR         =  $(CROCON_LIB_ROOT)/src
DEF_DIR         =  $(CROCON_LIB_ROOT)/def
RES_DIR         =  $(CROCON_LIB_ROOT)/res

SRC_DIRS        =  $(SRC_DIR) \
                   $(SRC_DIR)/os/unix \
                   $(SRC_DIR)/utils \
                   $(SRC_DIR)/widgets

BIN_DIR         =  $(CROCON_LIB_ROOT)/../out/library/bin
OBJ_DIR         =  $(CROCON_LIB_ROOT)/../out/library/obj

CC = gcc

ifeq ($(CROCON_LEGACY),true)

ifeq ($(CROCON_DEBUG),true)
C_FLAGS         =  -O0 -fPIC -DUNIX -DUNIX_LEGACY -DHAVE_VPRINTF -g3 -fno-omit-frame-pointer
else
C_FLAGS         =  -O2 -fPIC -DUNIX -DUNIX_LEGACY -DHAVE_VPRINTF
endif

else

ifeq ($(CROCON_DEBUG),true)
C_FLAGS         =  -O0 -fPIC -DUNIX -DHAVE_VPRINTF -g3 -fno-omit-frame-pointer -fno-optimize-sibling-calls 
else
C_FLAGS         =  -O2 -fPIC -DUNIX -DHAVE_VPRINTF
endif

endif

SOURCES         =  $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))

OBJECTS         =  $(OBJ_DIR)/crocunix.o \
                   $(OBJ_DIR)/crocscrn.o \
                   $(OBJ_DIR)/crocclrs.o \
                   $(OBJ_DIR)/window.o \
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
	$(CC) $(LD_ARCH) -shared -o $@ $(OBJECTS) $(LD_FLAGS)

$(BIN_DIR)/lib$(PROJECT).a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

install: all
	mkdir -p $(PREFIX)/lib
	cp $(BIN_DIR)/lib$(PROJECT).so $(PREFIX)
	cp $(BIN_DIR)/lib$(PROJECT).a $(PREFIX)

	mkdir -p $(PREFIX)/include/$(PROJECT)
	cp $(INC_DIR)/*.h $(PREFIX)/include/$(PROJECT)/

clean:
	rm -rf $(OBJ_DIR) $(LIB_DIR)

rebuild:
	clean all

.PHONY: 
	all install clean rebuild
