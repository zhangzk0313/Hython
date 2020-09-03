/*************************************************************************
	> File Name: haizei_factory.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年09月02日 星期三 09时03分37秒
 ************************************************************************/

#ifndef _HAIZEI_FACTORY_H
#define _HAIZEI_FACTORY_H
#include <haizei_master.h>

namespace haizei {

class PrintFactory : public IMaster::IFactory {
    virtual IMaster *create(ASTree &, Parameter *);
};

class ExprFactory : public IMaster::IFactory {
    virtual IMaster *create(ASTree &, Parameter *);
};

class BlockFactory : public IMaster::IFactory {
    virtual IMaster *create(ASTree &, Parameter *);
};

}
#endif
