/* Copyright (c) 2014 Vinícius dos Santos Oliveira

   Distributed under the Boost Software License, Version 1.0. (See accompanying
   file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt) */

#ifndef BOOST_HTTP_FILE_SERVER_HPP
#define BOOST_HTTP_FILE_SERVER_HPP

namespace boost {
namespace http {

template<class Socket, class String, class Message, class CharT,
         class Traits = std::char_traits<CharT>, class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
async_serve_file(Socket &socket, const String &input_path, Message &message,
                 std::basic_istream<CharT, Traits> &file,
                 CompletionToken &&token);

template<class Socket, class String, class Message, class CompletionToken>
typename asio::async_result<
    typename asio::handler_type<CompletionToken,
                                void(system::error_code)>::type>::type
async_serve_dir(Socket &socket, const String &input_path, Message &message,
                const filesystem::path &root_dir, CompletionToken &&token);

} // namespace http
} // namespace boost

#endif // BOOST_HTTP_FILE_SERVER_HPP
