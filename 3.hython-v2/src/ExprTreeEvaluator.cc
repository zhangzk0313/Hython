#include <cassert>
#include <ExprTreeEvaluator.h>
#include <string>
#include <iostream>
#include <AST.h>

ExprTreeEvaluator::ExprTreeEvaluator() : next(nullptr) {};
ExprTreeEvaluator::ExprTreeEvaluator(ExprTreeEvaluator *next) : next(next) {};

void ExprTreeEvaluator::def_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        throw std::runtime_error("param redefined" + name);
    }
    memory[name] = val;
    return ;
}

void ExprTreeEvaluator::set_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        if (this->next) {
            this->next->set_param(name, val);
        }
        throw std::runtime_error("unknown param" + name);
    }
    memory[name] = val;
    return ;
}

int ExprTreeEvaluator::get_param(std::string name) {
    if (memory.find(name) == memory.end()) {
        if (this->next) return this->next->get_param(name);
        throw std::runtime_error("unknown param" + name);
    }
    return memory[name]; 
}

int ExprTreeEvaluator::run(haizei::ASTNode tree) {
    
    if(tree.hasToken()) {
        switch(tree.type()) {
        case INT: {
            std::string s = tree.text();
            if(s[0] == '~') {
                return -atoi(s.c_str()+1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return get_param(tree.text());
        }
        case PLUS:
            return run(tree[0]) + run(tree[1]);
        case MINUS:
            return run(tree[0]) - run(tree[1]);
        case TIMES:
            return run(tree[0]) * run(tree[1]);
        case DIV:
            return run(tree[0]) / run(tree[1]);
        case MOD:
            return run(tree[0]) % run(tree[1]);
        case BLOCK : {
            ExprTreeEvaluator new_block(this);//子对象，子作用域
            for(int i = 0; i < tree.size(); i++) {
                int r = new_block.run(tree[i]);
            }
            return 0;
        } break;
        case PRINT: {
            int r = run(tree[0]);
            printf("%d\n", r);
            return r;
        } break;
        case OR: return run(tree[0]) || run(tree[1]);     
        case AND: return run(tree[0]) && run(tree[1]);    
        case GT: return run(tree[0]) > run(tree[1]);
        case LITTLE: return run(tree[0]) < run(tree[1]);
        case EQ: return run(tree[0]) == run(tree[1]);
        case LE: return run(tree[0]) <= run(tree[1]);
        case GE: return run(tree[0]) >= run(tree[1]);
        case NE: return run(tree[0]) != run(tree[1]);
        case IF: {
            if (run(tree[0])) {
                run(tree[1]);
            } else if (tree.size() == 3) {
                run(tree[2]);
            }
            return 0;
        }
        case FOR:{
            for (run(tree[0]); run(tree[1]); run(tree[2])) {
                run(tree[3]);
            }
            return 0;
        }
        case WHILE: {
            while (run(tree[0])) {
                run(tree[1]);
            }
            return 0;
        }
        case DOWHILE: {
            do {
                run(tree[1]);
            } while (run(tree[0]));
            return 0;
        }
        case DEF: {
            int init_val = 0;
            for (int i = 0; i < tree.size(); i++) {
                std::string var(tree[i].text());
                init_val = 0;
                if (tree[i].size() == 1) {
                    init_val = run(tree[i][0]);
                }
                //std::cout << "set param val : " << var << " = " << init_val << std::endl;
                this->def_param(var, init_val);
            }
            return init_val; 
        } break;
        case ASSIGN: {
            std::string var(tree[0].text());
            get_param(var);
            int val = run(tree[1]);
            set_param(var, val);
            return val;
        }
        default:
            std::cout << "Unhandled token: #" << tree.type() << '\n';
            return -1;
        }
    }
    else {
        std::cout << "-----conclusion-----" << std::endl;
        int r = 0;
        for(int i = 0; i < tree.size(); i++) {
            r = run(tree[i]);
            printf(" value : %d\n", r);
        }
        return r;
    }
    return 0;
}

