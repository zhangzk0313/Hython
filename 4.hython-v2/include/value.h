/*************************************************************************
	> File Name: vallue.h
	> Author: zzk
	> Mail: 815028387@qq.com
	> Created Time: 2020年09月03日 星期四 09时57分39秒
 ************************************************************************/

#ifndef _VALLUE_H
#define _VALLUE_H

#include <string>

namespace haizei {

template<typename T>
class IValue {
public :
    virtual std::string toString() = 0;

protected:
    T val;
};

template<typename T>
class BaseValue : public IValue {
public :
    virtual std::string toString() {
        return std::to_string(val);
    }

protected:

}


class IntValue : public IValue<int> {
public :
};

class FloatValue : public IValue<double> {
public :
};

class StringValue : public IValue<std::string> {
public :
};

extern SIValue HZNULL;

} //end of haizei

#endif
