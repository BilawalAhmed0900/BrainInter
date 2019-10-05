#include <iostream>
#include <string>
#include <vector>

#include "interpreter.h"
#include "version.h"

/*
 * Intended to use firstly main()
 * Doesn't check for string completion
 */
std::vector<std::string> c_to_cpp_argv(int argc, char *argv[])
{
    std::vector<std::string> result;
    result.reserve(argc);

    /*
     * i = 1, as argv[0] is filename
     */
    for (int i = 1; i < argc; i++)
    {
        result.emplace_back(std::string(argv[i]));
    }

    return result;
}

bool is_balanced_loop(const std::string& str)
{
    constexpr char LOOP_START = '[';
    constexpr char LOOP_END = ']';

    size_t level_loop = 0;

    for (auto const& c: str)
    {
        if (c == LOOP_START)
        {
            level_loop++;
        }
        else if (c == LOOP_END)
        {
            level_loop--;
        }
    }

    return level_loop == 0;
}

void runtime_mode()
{
    constexpr char SYNTAX_ERROR_LOOP_NOT_BALANCED[] = "Syntax Error: Loop not balanced within expression";

    interpreter inter;
    std::cout << version::version_info() << "\n";
    std::cout << "Type \"quit()\" to quit, \"clear()\" to memset data pointer to 0.\n";

    while (true)
    {
        std::string read;
        std::cout << ">>> ";
        std::getline(std::cin, read);
        if (std::cin.fail())
        {
            std::cout << "\nCtrl-C detected, quitting...\n";
            std::cin.clear();
            break;
        }

        if (read == "quit()")
        {
            break;
        }
        else if (read == "quit")
        {
            std::cout << "Type \"quit()\" or Ctrl-C to quit...\n";
        }

        if (read == "clear()")
        {
            inter.clear_data_ptr();
        }

        if (! is_balanced_loop(read))
        {
            std::cout << SYNTAX_ERROR_LOOP_NOT_BALANCED << "\n";
            continue;
        }

        inter.parse_all(read);
    }
}

void file_mode(std::ifstream& in, bool output_mode, std::ofstream& out)
{
    in.seekg(0, std::ios::end);
    size_t size = in.tellg();
    in.seekg(0);

    char *ptr = new char[size];
    in.read(ptr, size);

    std::string read(ptr);

    interpreter inter(DATA_PTR_SIZE, output_mode);
    inter.parse_all(read);

    if (output_mode)
    {
        out << inter.get_if_output();
    }

}

int main(int argc, char *argv[])
{
    auto parameters = c_to_cpp_argv(argc, argv);
    if (parameters.empty())
    {
        runtime_mode();
        return 0;
    }

    if (parameters.size() != 1 && parameters.size() != 2)
    {
        std::cout << "Expecting at most two parameters\n";
        return -1;
    }

    bool output_mode = false;
    if (parameters[0] == "-c" || parameters[1] == "-c")
    {
        output_mode = true;
    }

    std::ofstream out;
    if (output_mode)
    {
        out.open(parameters[0] + ".c");
    }

    std::ifstream in(parameters[0] != "-c" ? parameters[0] : parameters[1], std::ios::binary);
    if (! in.good())
    {
        std::cout << "Cannot open file \"" << parameters[0] << "\"\n";
        return -2;
    }

    file_mode(in, output_mode, out);

    return 0;
}