EXEC_NAME = mycp

OBJ_FILE = mycp.o

CFLAGS = -Wall

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJ_FILE)
	g++ $(OBJ_FILE) -o $(EXEC_NAME)

mycp.o: mycp.cpp
	g++ -c mycp.cpp $(CFLAGS)

clean: $(OBJ_FILE)
	rm $(OBJ_FILE)

fclean: clean
	rm $(EXEC_NAME)
