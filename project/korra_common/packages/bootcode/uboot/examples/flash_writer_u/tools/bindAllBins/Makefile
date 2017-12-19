
RM = rm -f
CC = gcc
SRC = bindAllBins.c
TARGET = bindAllBins

#OPTION += -static

all: $(TARGET)

$(TARGET): $(SRC)
#	$(CC) $(OPTION) $^ -o $(OUTPUT)
	$(CC) $^ -o $(TARGET)
	chmod +x $(TARGET)


.PHONY: clean
clean:
	$(RM) *.o $(TARGET)

