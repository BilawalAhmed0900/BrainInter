//
// Created by Mian Bilawal on 05-Oct-2019.
//

#ifndef BRAINFUCK_INTERPRETER_VERSION_H
#define BRAINFUCK_INTERPRETER_VERSION_H

#include <climits>

#include <string>
#include <sstream>

#if UINTPTR_MAX == 0xffffffffffffffffULL
# define BUILD_64   1
#endif

namespace version
{
    constexpr char PROGRAM_NAME[] = "Brainfuck";
    constexpr char PROGRAM_VERSION[] = "0.6.0";

    std::string version_info()
    {
        std::stringstream ss;
        ss << PROGRAM_NAME << " ";
        ss << PROGRAM_VERSION << " ";
        ss << "(" << __TIMESTAMP__ << ") ";
#ifdef __GNUC__
        ss << "[GNU v" << __GNUC__ << "." <<  __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__;
#ifdef BUILD_64
        ss << " 64bit";
#else
        ss << " 32bit";
#endif
        ss << "]";
#endif
        return ss.str();
    }
}


#endif //BRAINFUCK_INTERPRETER_VERSION_H
