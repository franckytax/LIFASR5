EXEC_NAME = mytee

OBJ_FILE = mytee.o

CFLAGS = -Wall

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILE)
	g++ $(OBJ_FILE) -o $(EXEC_NAME)

mytee.o: mytee.cpp
	g++ -c mytee.cpp $(CFLAGS)

clean: $(OBJ_FILE)
	rm $(OBJ_FILE)

fclean: clean
	rm $(EXEC_NAME)
