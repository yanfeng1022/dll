//=======================================================================
// Copyright (c) 2014-2017 Baptiste Wicht
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
//  http://opensource.org/licenses/MIT)
//=======================================================================

#pragma once

#include "dll/base_conf.hpp"
#include "dll/util/tmp.hpp"

namespace dll {

/*!
 * \brief Describe a layer that merges layers together.
 */
template <size_t D, typename... Layers>
struct merge_layer_desc {
    /*!
     * \brief A list of all the parameters of the descriptor
     */
    using parameters = cpp::type_list<>;

    /*! The layer type */
    using layer_t = merge_layer_impl<D, Layers...>;

    /*! The layer type */
    using dyn_layer_t = merge_layer_impl<D, Layers...>;

    static_assert(sizeof...(Layers) > 0, "A merge layer must contain at least one layer");
};

/*!
 * \brief Describe a standard merge layer.
 */
template <size_t D, typename... Layers>
using merge_layer = typename merge_layer_desc<D, Layers...>::layer_t;

} //end of dll namespace