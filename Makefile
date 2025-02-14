CXX = g++ 

all:
	@echo "Usage : make compile FILE_NAME"
compile:
	$(CXX) $(FILE) -o $(basename $(FILE))  
clean:
	rm -f Stuff/*.exe Stuff/*.o Stuff/*.out
