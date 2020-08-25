#run the makefile from any directory using below command\
make -C sim/ -s FILE=fileName

CC      = g++
C_FLAGS = -Wall -lm -g
INC_DIR =/myspace/ubuntu/practice-programs/c++/inc
SRC_DIR =/myspace/ubuntu/practice-programs/c++/src
SIM_DIR =/myspace/ubuntu/practice-programs/c++/sim

all:compile run

list:
	@ls $(SRC_DIR)

create:
	@echo "\nCreating a new C source file : $(FILE) ...\n"
	@python3 create.py $(FILE)
	@mv $(FILE) $(SRC_DIR)
	@gvim $(SRC_DIR)/$(FILE)
	@echo "\nCreated C source file : $(FILE) ...\n"

compile:
	@echo "\nCompiling $(FILE) ...\n"
	@echo "###########################################"
	@$(CC) -o $(FILE).o -I $(INC_DIR) $(SRC_DIR)/$(FILE) $(C_FLAGS); if [ $$? -ne 0 ]; then echo "\nCompilation failed...\n";exit 1; else echo "\nCompiled Successfully....\n"; fi
	@echo "###########################################"

run:compile
	@echo "\nRunning $(FILE) ...\n"
	@echo "###########################################"
	@$(SIM_DIR)/$(FILE).o ; if [ $$? -ne 0 ]; then echo "\nExecution failed....\n"; else echo "\n\n###########################################\n\nExecuted Successfully....\n"; fi

clean:
	@rm -rf *.o

.PHONY: clean run compile all
