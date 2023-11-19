CC = g++
CC_FLAGS = -std=c++11

BINARIES = main
OBJS = I-Type.o R-Type.o readInstructions.o runInstruction.o main.o
HEADERS = instructions.h readInstructions.h runInstruction.h

main: $(OBJS) 
	$(CC) $(CC_FLAGS) $^ -o $@

%.o: %.cpp $(HEADERS)
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	@echo "cleaning..."
	-rm -f $(BINARIES) *.o *.out

