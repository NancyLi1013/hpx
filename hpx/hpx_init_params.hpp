//  Copyright (c)      2020 ETH Zurich
//
//  SPDX-License-Identifier: BSL-1.0
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/// \file hpx_init_params.hpp

#ifndef HPX_HPX_INIT_PARAMS_HPP
#define HPX_HPX_INIT_PARAMS_HPP

#include <hpx/config.hpp>
#include <hpx/functional/function.hpp>
#include <hpx/program_options.hpp>
#include <hpx/resource_partitioner/partitioner_fwd.hpp>
#include <hpx/runtime_configuration/runtime_mode.hpp>
#include <hpx/runtime/shutdown_function.hpp>
#include <hpx/runtime/startup_function.hpp>
#include <hpx/type_support/unused.hpp>

#include <functional>
#include <string>
#include <vector>

#ifndef DOXYGEN
///////////////////////////////////////////////////////////////////////////////
// One of these functions must be implemented by the application for the
// console locality.
int hpx_main();
int hpx_main(int argc, char** argv);
int hpx_main(hpx::program_options::variables_map& vm);
#endif

///////////////////////////////////////////////////////////////////////////////
/// \cond NOINTERNAL
namespace hpx_startup
{
    // As an alternative, the user can provide a function hpx_startup::user_main,
    // which is semantically equivalent to the plain old C-main.
    int user_main();
    int user_main(int argc, char** argv);
}
/// \endcond

///////////////////////////////////////////////////////////////////////////////
/// \namespace hpx
namespace hpx
{
    /// \cond NOINTERNAL
    namespace resource {
        // Utilities to init the thread_pools of the resource partitioner
        using rp_callback_type = hpx::util::function_nonser<void(
                hpx::resource::partitioner&)>;
    }
    /// \endcond

    namespace detail
    {
        HPX_EXPORT void on_exit() noexcept;
        HPX_EXPORT void on_abort(int signal) noexcept;
        // Default params to initialize the init_params struct
        extern HPX_EXPORT const hpx::program_options::options_description
            default_desc;
        extern HPX_EXPORT startup_function_type default_startup;
        extern HPX_EXPORT shutdown_function_type default_shutdown;
        HPX_MAYBE_UNUSED extern HPX_EXPORT int dummy_argc;
        // TODO: make it only one parameter, probably add a cast
        HPX_MAYBE_UNUSED extern HPX_EXPORT char **dummy_argv;
    }

#ifndef DOXYGEN
    typedef int (*hpx_main_type)(hpx::program_options::variables_map&);
    typedef int (*hpx_user_main_type)(int argc, char** argv);
#endif

    /// \struct init_params
    /// \brief  Parameters used to initialize the HPX runtime through
    ///         \a hpx::init and \a hpx::start
    ///
    /// \var desc_cmdline   This parameter may hold the description of additional
    ///                     command line arguments understood by the
    ///                     application. These options will be prepended to
    ///                     the default command line options understood by
    ///                     \a hpx::init.
    /// \var cfg            A list of configuration settings which will be added
    ///                     to the system configuration before the runtime
    ///                     instance is run. Each of the entries in this list
    ///                     must have the format of a fully defined key/value
    ///                     pair from an ini-file (for instance
    ///                     'hpx.component.enabled=1')
    /// \var startup        A function to be executed inside a HPX
    ///                     thread before \p f is called. If this parameter
    ///                     is not given no function will be executed.
    /// \var shutdown       A function to be executed inside an HPX
    ///                     thread while hpx::finalize is executed. If this
    ///                     parameter is not given no function will be
    ///                     executed.
    /// \var mode           The mode the created runtime environment
    ///                     should be initialized in. There has to be exactly
    ///                     one locality in each HPX application which is
    ///                     executed in console mode (\a hpx::runtime_mode_console),
    ///                     all other localities have to be run in worker mode
    ///                     (\a hpx::runtime_mode_worker). Normally this is
    ///                     set up automatically, but sometimes it is necessary
    ///                     to explicitly specify the mode.
    /// \var rp_mode        The mode the resource partitioner should be created
    ///                     in. If none is specified, the
    ///                     \a hpx::resource::mode_default will be used.
    /// \var rp_callback    This callback is called after the resource
    ///                     partitioner creation, it may be used to
    ///                     initialize thread pools. If none is specified no
    ///                     function will be executed.
    struct init_params {
        // Parameters
        std::reference_wrapper<hpx::program_options::options_description const>
            desc_cmdline = detail::default_desc;
        std::vector<std::string> cfg;
        startup_function_type& startup = detail::default_startup;
        shutdown_function_type& shutdown = detail::default_startup;
        hpx::runtime_mode mode = ::hpx::runtime_mode_default;
        hpx::resource::partitioner_mode rp_mode = ::hpx::resource::mode_default;
        hpx::resource::rp_callback_type rp_callback;
    };
}

#endif
