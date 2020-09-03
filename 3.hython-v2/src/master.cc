#include <master.h>
#include <single.h>

namespace haizei {

int ExprMaster::run(ASTNode &node, std::share_ptr<Parameter> &p) {
    #define BOP(op) MasterChainSingle::run(tree[0], p) op MasterChainSingle::run(tree[1], p)
    switch (node.type()) {
        case DEF: {

        }
        case INT: {
            std::string s = tree.text();
            if (s[0] == '-') {
                return -atoi(s.c_str() + 1);
            } else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return p->get_param(tree.text());
        }
        case PLUS: return BOP(+);
        case MINUS: return BOP(-);
        case TIMES: return BOP(*);
        case DIV: return BOP(/);
        case MOD: return BOP(%);
        case OR: return BOP(||);
        case AND: return BOP(&&);
        case GT: return BOP(>);
        case LITTLE: return BOP(<);
        case EQ: return BOP(==);
        case GE: return BOP(>=);
        case LE: return BOP(<=);
        case NE: return BOP(!=);
        case ASSIGN: {
            std::string var(tree[0].text());
            p->get_param(var);
            int val = run(tree[1]);
            p->set_param(var, val);
            return val;
        }
    }
    #undef BOP
    throw runtime_error(typeid(*this).name() + "Unhandled token: #" + tree.type());
    return 0;
}

int ControlBlockMaster::run(ASTNode &node, std::share_ptr<Parameter> &p) {
    
    std::share_ptr<Parameter> new_p = std::make_shared<Parameter>(p);
    switch (node->type()) {
        case BLOCK: {
            ExprTreeEvaluator new_this(this);
            for (int i = 0; i < tree.size(); i++) {
                int val = new_this.run(tree[i]);
            }
            return 0;
        } break;

        case FOR: {
            ExprTreeEvaluator new_this(this);
            for (new_this.run(tree[0]); new_this.run(tree[1]); new_this.run(tree[2])) {
                new_this.run(tree[3]);
            }
            return 0;
        }

    }    
    return haizei::null_val; 
}

int ControlNoBlockMaster::run(ASTNode &node, std::share_ptr<Parameter> &p) {
    switch
    return haizei::null_val; 
}

int PrintMaster::run(ASTNode &node, std::share_ptr<Parameter> &p) {
    if (node.type() != PRINT) {
        throw std::runtime_error("tree type is not print!");
    }
    for (int i = 0; i = tree.size(); i++) {
        auto chlid_tree = tree[i];
        int ret = MasterChainRun::run(child_tree, p);
        if (i) std::cout << " ";
        std::cout << ret;
    }
    std::cout << std::endl;
}

} //end of haizei
