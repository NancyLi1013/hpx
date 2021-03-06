# Copyright (c) 2019 The STE||AR-Group
#
# SPDX-License-Identifier: BSL-1.0
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

# Compatibility with using Boost.FileSystem, introduced in V1.4.0
hpx_option(HPX_DATASTRUCTURES_WITH_ADAPT_STD_TUPLE
  BOOL "Enable compatibility of hpx::util::tuple with std::tuple. (default: ON)"
  ON ADVANCED CATEGORY "Modules")

if(HPX_DATASTRUCTURES_WITH_ADAPT_STD_TUPLE)
  hpx_add_config_define_namespace(
    DEFINE HPX_DATASTRUCTURES_HAVE_ADAPT_STD_TUPLE
    NAMESPACE DATASTRUCTURES)
endif()

set(datastructures_headers
  hpx/datastructures/any.hpp
  hpx/datastructures/member_pack.hpp
  hpx/datastructures/optional.hpp
  hpx/datastructures/tuple.hpp
  hpx/datastructures/traits/supports_streaming_with_any.hpp
  hpx/datastructures/traits/is_tuple_like.hpp
  hpx/datastructures/variant_helper.hpp
)

set(datastructures_compat_headers
  hpx/datastructures/detail/pack.hpp
  hpx/traits/supports_streaming_with_any.hpp
  hpx/traits/is_tuple_like.hpp
  hpx/util/detail/pack.hpp
  hpx/util/any.hpp
  hpx/util/optional.hpp
  hpx/util/tuple.hpp
)

set(datastructures_sources)

include(HPX_AddModule)
add_hpx_module(datastructures
  COMPATIBILITY_HEADERS ON
  DEPRECATION_WARNINGS
  FORCE_LINKING_GEN
  GLOBAL_HEADER_GEN ON
  SOURCES ${datastructures_sources}
  HEADERS ${datastructures_headers}
  COMPAT_HEADERS ${datastructures_compat_headers}
  EXCLUDE_FROM_GLOBAL_HEADER
    "hpx/datastructures/variant_helper.hpp"
  DEPENDENCIES
    hpx_assertion
    hpx_config
    hpx_type_support
  CMAKE_SUBDIRS examples tests
)
