#include <single.h>

namespace haizei {

int MasterChainSingle::run(ASTNode &node, std::shared_ptr<Parameter> &p) {
    const IHandle *h = get();
    int ret = 0;
    while (h != nullptr) {
        if (!(h->Test(node))) {
            h = h->next();
            continue;
        }
        // 执行对应的master的 run 方法
        break;
    }
    return ret;
}

const IHandle *MasterChainSingle::get() {
    if (object == nullptr) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (object == nullptr) {
            object = SingleInit();
        }
    }
    return object;
}

} //end of haizei
