cmake_minimum_required(VERSION 3.8)
project(cppcoro)

set(lib_sources
${CMAKE_CURRENT_LIST_DIR}/lib/async_auto_reset_event.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/async_manual_reset_event.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/async_mutex.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/cancellation_state.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/cancellation_token.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/cancellation_source.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/cancellation_registration.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/lightweight_manual_reset_event.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ip_address.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ip_endpoint.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ipv4_address.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ipv4_endpoint.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ipv6_address.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/ipv6_endpoint.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/static_thread_pool.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/auto_reset_event.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/spin_wait.cpp
${CMAKE_CURRENT_LIST_DIR}/lib/spin_mutex.cpp
)

set(detail_headers
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/void_value.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/when_all_ready_awaitable.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/when_all_counter.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/when_all_task.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/get_awaiter.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/is_awaiter.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/any.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/sync_wait_task.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/unwrap_reference.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/lightweight_manual_reset_event.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/manual_lifetime.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/detail/remove_rvalue_reference.hpp
)

set(headers
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/awaitable_traits.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/is_awaitable.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_auto_reset_event.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_manual_reset_event.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_generator.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_mutex.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_latch.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/async_scope.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/broken_promise.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/cancellation_registration.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/cancellation_source.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/cancellation_token.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/coroutine.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/task.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/sequence_barrier.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/sequence_traits.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/single_producer_sequencer.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/multi_producer_sequencer.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/shared_task.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/single_consumer_event.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/single_consumer_async_auto_reset_event.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/sync_wait.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/task.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/io_service.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/config.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/on_scope_exit.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file_share_mode.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file_open_mode.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file_buffering_mode.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/fmap.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/when_all.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/when_all_ready.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/resume_on.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/schedule_on.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/generator.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/readable_file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/recursive_generator.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/writable_file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/read_only_file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/write_only_file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/read_write_file.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file_read_operation.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/file_write_operation.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/static_thread_pool.hpp
)

set(net_headers
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ip_address.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ip_endpoint.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ipv4_address.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ipv4_endpoint.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ipv6_address.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/ipv6_endpoint.hpp
${CMAKE_CURRENT_LIST_DIR}/include/cppcoro/net/socket.hpp
)

add_library(cppcoro ${lib_sources})

include(GNUInstallDirs)

target_include_directories(cppcoro PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(cppcoro PUBLIC cxx_std_20)

install(
    TARGETS cppcoro
    EXPORT cppcoro-config
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(
    EXPORT cppcoro-config
    NAMESPACE cppcoro::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cppcoro)

install(
    FILES ${headers}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cppcoro
)

install(
    FILES ${net_headers}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cppcoro/net
)

install(
    FILES ${detail_headers}
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/cppcoro/detail
)