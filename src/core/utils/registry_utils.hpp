#ifndef REGISTRY_UTILS_HPP_
#define REGISTRY_UTILS_HPP_

#include "registry.hpp"

namespace Utils {

    template<typename T>
    inline const size_t get_self_id_from(T self, registry *regis);

}

#include "registry_utils.inl"

#endif