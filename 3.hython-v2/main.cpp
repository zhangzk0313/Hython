#include <hythonLexer.h>
#include <hythonParser.h>
#include <cassert>
#include <map>
#include <string>
#include <iostream>
#include <AST.h>
#include <ExprTreeEvaluator.h>

int main(int argc, char* argv[]){
    assert(argc > 1);
    haizei::ASTNode tree(argv[1]);

    ExprTreeEvaluator eval;
    int rr = eval.run(tree);
    tree.destroy();
    return 0;
}

