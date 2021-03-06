// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
// Copyright (c) 2016 Hartmut Kaiser
//
//  SPDX-License-Identifier: BSL-1.0
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef HPX_PROCESS_EXECUTE_HPP
#define HPX_PROCESS_EXECUTE_HPP

#include <hpx/config.hpp>

#if defined(HPX_WINDOWS)
#include <hpx/components/process/util/windows/execute.hpp>
namespace hpx { namespace components { namespace process { namespace util
{
    using windows::execute;
}}}}
#else
#include <hpx/components/process/util/posix/execute.hpp>
namespace hpx { namespace components { namespace process { namespace util
{
    using posix::execute;
}}}}
#endif


#endif
