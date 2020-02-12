///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Andreas Wass
// Licenced under MIT license. See LICENSE.txt for details.
///////////////////////////////////////////////////////////////////////////////

#ifndef CPPCORO_COROUTINE_HPP_INCLUDED
#define CPPCORO_COROUTINE_HPP_INCLUDED

#if defined __has_include
#   if __has_include (<coroutine>)
#       include <coroutine>
namespace cppcoro
{
namespace stdcoro = std;
}
#   elif __has_include (<experimental/coroutine>)
#       include <experimental/coroutine>
namespace cppcoro
{
namespace stdcoro = std::experimental;
}
#   endif
#endif

#endif