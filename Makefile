#FEES_MAKEFILE
#Author: Matteo Franceschini

OUTPUT= FEES_OUT
INC_PATH = ./devices/
SRC_PATH = ./src/
OBJ= main.o
CXX = g++
CXXVARS = -std=c++11 -I $(INC_PATH)

.PHONY= tidy
.PHONY= clean
.PHONY= xx

all:$(OUTPUT)

tidy:
	rm-f *.o

clean:
	rm -f *.o
	rm -f $(OUTPUT)
xx:
	./$(OUTPUT)

%.o:$(SRC_PATH)%.cpp
	@echo "[CXX] $<" 
	$(CXX) $< $(CXXVARS) -c

$(OUTPUT):$(OBJ)
	@echo "[LNK] $^"
	$(CXX) $^ -o $@

