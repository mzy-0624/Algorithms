FILE ?=
DEBUG ?= OFF
run:
	g++ -std=c++17 -o $(FILE).out $(FILE).cpp -D__LOCAL__ -D__DEBUG__$(DEBUG) && ./$(FILE).out;
clean:
	rm -rf *.out;