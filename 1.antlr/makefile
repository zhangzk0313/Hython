all: ./ExprCppTree.g main.cpp
	java -jar ./antlr-3.4-complete.jar ExprCppTree.g
	g++ -L ./libs main.cpp ./ExprCppTreeLexer.c ./ExprCppTreeParser.c -lantlr3c 

