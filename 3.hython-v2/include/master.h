/*************************************************************************
	> File Name: master.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年09月02日 星期三 10时11分14秒
 ************************************************************************/

#ifndef _MASTER_H
#define _MASTER_H

#include <AST.h>

class IMaster {
public :
    virtual int run(ASTNode &, share_ptr<Parameter> &) = 0;
};

class ExprMaster : public IMaster {
    virtual int run(ASTNode &, share_ptr<Parameter> &) = 0;
    
};
class ControlBlockMaster : public IMaster {
    virtual int run(ASTNode &, share_ptr<Parameter> &) = 0;
    
};
class ExprNoBlockMaster : public IMaster {
    virtual int run(ASTNode &, share_ptr<Parameter> &) = 0;
    
};
class PrintMaster : public IMaster {
    virtual int run(ASTNode &, share_ptr<Parameter> &) = 0;
    
};

#endif
