/*************************************************************************
	> File Name: haizei_handler.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年09月02日 星期三 09时00分28秒
 ************************************************************************/

#ifndef _HAIZEI_HANDLER_H
#define _HAIZEI_HANDLER_H

#include <AST.h>

namespace haizei {

class IHandle {
public:
    IHandle(IHandle *next);
    virtual bool Test(const ASTNode &) = 0;
    IHandle *next() const;
private:
    IHandle *__next;
};

class ExprHandle : public IHandle {
public :
    ExprHandle(IHandle *);
    bool Test(const ASTNode &) const ;
};

class ControlBlockHandle : public IHandle {
    ControlBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

class ControlNoBlockHandle {
    ControlNoBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

class PrintHandle {    
    PrintHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

} // end of haizei
#endif
