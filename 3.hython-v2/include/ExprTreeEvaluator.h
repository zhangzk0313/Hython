/*************************************************************************
	> File Name: ExprTreeEvaluator.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年08月29日 星期六 11时32分41秒
 ************************************************************************/

#ifndef _EXPRTREEEVALUATOR_H
#define _EXPRTREEEVALUATOR_H

#include <string>
#include <map>
#include <AST.h>

class ExprTreeEvaluator {
public:  
    ExprTreeEvaluator();
    ExprTreeEvaluator(ExprTreeEvaluator *next);
    int run(haizei::ASTNode);
    void set_param(std::string, int);
    void def_param(std::string, int);
    int get_param(std::string);
    ExprTreeEvaluator *next;

private:
    std::map<std::string, int> memory;
};

#endif
