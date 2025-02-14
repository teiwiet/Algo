CXX = g++ 

all:
	@echo "Usage : make compile FILE_NAME"
compile:
	$(CXX) Stuff/$(FILE) -o Stuff/$(basename $(FILE)).exe  
clean:
	rm -f Stuff/*.exe Stuff/*.o Stuff/*.out
