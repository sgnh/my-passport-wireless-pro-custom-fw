# ********************************************************************
# Macro Specifics.
# ********************************************************************
SRC_C	= $(wildcard *.c)
SRC_S	= $(wildcard *.S)
SRC		= $(SRC_C) $(SRC_S)

OBJ_C  =  $(patsubst %.c, %.o, $(SRC_C))
OBJ_S	= $(patsubst %.S, %.o, $(SRC_S))
OBJ		= $(OBJ_C) $(OBJ_S)

# ********************************************************************
# Compile Directives.
# ********************************************************************
all: $(OBJ_C) $(OBJ_S)
	
$(OBJ_C) : %.o : %.c 
	$(CC) -c $(CFLAG) $(CDEF) $(INCLUDE) -o $(OBJ_DIR)/$@ $<

$(OBJ_S) : %.o : %.S
	$(CC) -c $(AFLAG) $(ADEF) $(INCLUDE) -o $(OBJ_DIR)/$@ $<
