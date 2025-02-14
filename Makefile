CXX = g++ 

all:
	@echo "Usage : make compile FILE_NAME"
compile:
	$(CXX) $(FILE) -o $(basename $(FILE))  
clean:
	rm -f *.exe *.o *.out
