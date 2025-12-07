CC = gcc
CFLAGS = -Wall -Wextra

TARGET = sort

all: $(TARGET)

$(TARGET): sort_making_leak.c
	$(CC) $(CFLAGS) sort_making_leak.c -o $(TARGET)

opt:
	$(CC) $(CFLAGS) -O2 sort_making_leak.c -o $(TARGET)_opt

debug:
	$(CC) $(CFLAGS) -g -O0 sort_making_leak.c -o $(TARGET)_debug

clean:
	rm -f $(TARGET) $(TARGET)_opt $(TARGET)_debug

