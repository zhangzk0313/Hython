/*************************************************************************
	> File Name: single.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年09月02日 星期三 09时52分47秒
 ************************************************************************/

#ifndef _SINGLE_H
#define _SINGLE_H
#include <handle.h>
#include <mutex>

namespace haizei {

class Singleton {
public:
protected :
    Singleton() = default;
    static std::mutex m_mutex;
};

class MasterChainSingle : public Singleton {
public :
    static int run(ASTNode &, std::shared_ptr<Parameter> &);
private :
    static const IHandle *get();
    MasterChainSingle() = delete;
    static const IHandle *SingleInit();
    static const IHandle *object;
};

}

#endif
