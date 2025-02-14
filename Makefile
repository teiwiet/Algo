CXX = g++ 
<<<<<<< HEAD
all:
	@echo "Usage : make compile FILE=file_name"
compile:
	$(CXX) $(FILE) -o $(basename $(FILE)).exe  
=======

all:
	@echo "Usage : make compile FILE_NAME"
compile:
	$(CXX) $(FILE) -o$(basename $(FILE)).exe  
run:
	@$(FILE)
>>>>>>> a8b3b338d47c62d18781efe60d72e151a663837a
clean:
	rm -f *.exe *.o *.out
