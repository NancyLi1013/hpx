//  Copyright (c) 2019 STE||AR Group
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <hpx/config.hpp>
#include <hpx/threading_base/config/defines.hpp>
#include <hpx/threading_base/set_thread_state.hpp>

#if defined(HPX_THREAD_DATA_HAVE_DEPRECATION_WARNINGS)
#if defined(HPX_MSVC)
#pragma message(                                                               \
    "The header hpx/runtime/threads/detail/set_thread_state.hpp is deprecated, \
    please include hpx/threading_base/set_thread_state.hpp instead")
#else
#warning                                                                       \
    "The header hpx/runtime/threads/detail/set_thread_state.hpp is deprecated, \
    please include hpx/threading_base/set_thread_state.hpp instead"
#endif
#endif
