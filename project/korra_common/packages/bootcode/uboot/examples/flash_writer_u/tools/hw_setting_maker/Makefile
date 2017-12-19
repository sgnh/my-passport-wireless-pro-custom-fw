
RM = rm -f
CC = gcc
SRC = generate_config.c
TARGET = generate_config 

#OPTION += -static

all: $(TARGET)

$(TARGET): $(SRC)
#	$(CC) $(OPTION) $^ -o $(OUTPUT)
	$(CC) $^ -o $(TARGET)
	chmod +x $(TARGET)


.PHONY: clean
clean:
	$(RM) *.o $(TARGET)

