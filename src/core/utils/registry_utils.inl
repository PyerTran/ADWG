#include "registry_utils.hpp"

namespace Utils {

    template<typename T>
    inline const size_t get_self_id_from(T *self, registry *regis) {
        size_t id;
        
        sparse_array<T> extract = regis->get_components<T>();
        id = extract.get_index(self);

        return id;
    }

}