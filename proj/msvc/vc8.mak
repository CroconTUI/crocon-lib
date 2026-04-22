PROJECT 		= crocon

CROCON_ROOT 		= ..\..

INC_DIR			= $(CROCON_ROOT)\include
SRC_DIR 		= $(CROCON_ROOT)\src
DEF_DIR			= $(CROCON_ROOT)\def
RES_DIR			= $(CROCON_ROOT)\res


BIN_DIR 		= $(CROCON_ROOT)\..\out\library\bin
OBJ_DIR 		= $(CROCON_ROOT)\..\out\library\obj

C_FLAGS			= -MT -W3 -EHsc -Zi -Od

!ifdef DEBUG
	C_FLAGS 	= -Z7 -DDEBUG
	LD_FLAGS	= -debug -pdb:none
!endif


LD_FLAGS 		= -dll -out:$(BIN_DIR)\crocon.dll -def:$(DEF_DIR)\crocon.def

CC_FLAGS		= $(C_FLAGS) -I$(INC_DIR) -DCROC_STATIC_BUILD -DWIN32 -DWINDOWS
CC_FLAGS_DLL		= $(C_FLAGS) -I$(INC_DIR)
CC_LIBS			= user32.lib

CC				= cl -nologo
LINKER			= link.exe -nologo

CROCON_LIBS		= $(BIN_DIR)\crocon.lib

OBJECTS 		= $(OBJ_DIR)\crocw32.obj \
				  $(OBJ_DIR)\crocscrn.obj \
				  $(OBJ_DIR)\crocon.obj

all: $(BIN_DIR)\$(PROJECT).dll

$(BIN_DIR)\$(PROJECT).dll: $(OBJECTS)
	@if not exist $(BIN_DIR) mkdir $(BIN_DIR)
	$(LINKER) $(LD_FLAGS) /OUT:$@ $**

{$(SRC_DIR)}.c{$(OBJ_DIR)}.obj:
	@if not exist $(CROCON_ROOT)\out mkdir $(CROCON_ROOT)\out
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -Fo$@

{$(SRC_DIR)\os\win32}.c{$(OBJ_DIR)}.obj:
	@if not exist $(CROCON_ROOT)\out mkdir $(CROCON_ROOT)\out
	@if not exist $(OBJ_DIR) mkdir $(OBJ_DIR)
	$(CC) $(CC_FLAGS) -c $< -Fo$@

clean:
	-del $(OBJ_DIR)\*.obj
	-del $(BIN_DIR)\crocon.lib
