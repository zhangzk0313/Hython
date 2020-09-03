all: grammer main.cpp
	g++ -std=c++11 -I./include -I./include/antlr -L./lib -o ./bin/hython main.cpp ./src/*.c ./src/*.cc -lantlr3c

debug: grammer main.cpp
	g++ -DDEBUG -std=c++11 -I./include -I./include/antlr -L./lib -o ./bin/hython main.cpp ./src/*.c ./src/*.cc -lantlr3c

grammer: ./third_part/hython.g
	java -jar ./third_part/antlr-3.4-complete.jar ./third_part/hython.g
	mv ./hython.tokens ./third_part/
	mv ./third_part/*.c src/
	mv ./third_part/*.h include/

run:
	./bin/hython ./testdata/input1
	./bin/hython ./testdata/input2 
	./bin/hython ./testdata/input3

