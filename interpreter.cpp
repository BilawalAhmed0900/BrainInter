//
// Created by Mian Bilawal on 05-Oct-2019.
//

#include <iostream>

#include <cstdio>

#include "interpreter.h"

#define OUTPUT_MODE_CHECK(x)\
    if (output_mode)\
    {\
        x;\
    }

size_t find_loop_end(const std::string& str, size_t loop_level)
{
    constexpr char LOOP_START = '[';
    constexpr char LOOP_END = ']';

    size_t position = 0;
    for (const auto& character: str)
    {
        if (character == LOOP_START) ++loop_level;

        if (character == LOOP_END && --loop_level == 0)
        {
            return position + 1;
        }

        position++;
    }

    return -1;
}

void interpreter::parse_one(const char& c)
{
    switch (c)
    {
        case '>':
            OUTPUT_MODE_CHECK(
                    output << "data = (char *)((size_t)(data + 1) % len);";
                    )
            current_position++;
            break;

        case '<':
            OUTPUT_MODE_CHECK(
                    output << "data = wrap_min(data - 1, ptr_min, ptr_max);";
            )
            current_position--;
            if (current_position < 0)
            {
                current_position = length_data_ptr - abs(current_position);
            }
            break;

        case '+':
            OUTPUT_MODE_CHECK(
                    output << "++*data;";
            )
            this->data_ptr[current_position]++;
            if (current_position >= length_data_ptr)
            {
                current_position = 0;
            }
            break;

        case '-':
            OUTPUT_MODE_CHECK(
                    output << "--*data;";
            )
            this->data_ptr[current_position]--;
            break;

        case '.':
            OUTPUT_MODE_CHECK(
                    output << "putchar(*data);"
            )

            if (!output_mode)
                std::cout << this->data_ptr[current_position];
            break;

        case ',':
            OUTPUT_MODE_CHECK(
                    output << "*data = getchar();"
            )

            if (!output_mode)
            {
                std::cout << "Character Required: ";
                this->data_ptr[current_position] = (char)getchar();
            }

            break;

        default:
            break;
    }
}

size_t interpreter::parse_one_future(const std::string& str, size_t i, const char& c)
{
    size_t how_many = 0;
    while (str[i++] == c) how_many++;

    switch (c)
    {
        case '>':
            OUTPUT_MODE_CHECK(
                    output << "data = (char *)((size_t)(data + " << how_many << ") % len);";
            )
            current_position = current_position + how_many;
            break;

        case '<':
            OUTPUT_MODE_CHECK(
                    output << "data = wrap_min(data - " << how_many << ", ptr_min, ptr_max);";
            )
            current_position = current_position - how_many;
            if (current_position < 0)
            {
                current_position = length_data_ptr - abs(current_position);
            }
            break;

        case '+':
            OUTPUT_MODE_CHECK(
                    output << "*data = *data + " << how_many << ";";
            )
            this->data_ptr[current_position] = this->data_ptr[current_position] + how_many;
            if (current_position >= length_data_ptr)
            {
                current_position = 0;
            }
            break;

        case '-':
            OUTPUT_MODE_CHECK(
                    output << "*data = *data - " << how_many << ";";
            )
            this->data_ptr[current_position] = this->data_ptr[current_position] - how_many;
            break;

        case '.':
            if (how_many > 1)
            {
                OUTPUT_MODE_CHECK(
                        output << "for (size_t i = 0; i < " << how_many << "; i++) putchar(*data);"
                )
            }
            else
            {
                OUTPUT_MODE_CHECK(
                        output << "putchar(*data);"
                )
            }

            if (!output_mode)
            for (size_t j = 0; j < how_many; j++)
            {
                std::cout << this->data_ptr[current_position];
            }
            break;
        case ',':
            if (how_many > 1)
            {
                OUTPUT_MODE_CHECK(
                        output << "for (size_t i = 0; i < " << how_many << "; i++) *data = getchar();"
                )
            }
            else
            {
                OUTPUT_MODE_CHECK(
                        output << "*data = getchar();"
                )
            }

            if (!output_mode)
            {
                std::cout << "Character Required: ";
                for (size_t j = 0; j < how_many; j++)
                    this->data_ptr[current_position] = (char)getchar();
            }

            break;

        default:
            break;
    }

    return how_many;
}

void interpreter::loop_enter(const std::string& str)
{
    constexpr size_t NO_OF_BF_COMMANDS = 8u;
    constexpr std::array<char, NO_OF_BF_COMMANDS> COMMANDS =
            {'>', '<', '+', '-', '.', ',', '[', ']'};

    constexpr char LOOP_START = '[';
    constexpr char LOOP_END = ']';

    size_t position = 0;
    for (size_t i = 0, max = str.length(); i < max;)
    {
        const char& c = str[i];

        if (c == LOOP_START)
        {
            size_t loop_end = find_loop_end(str.substr(i + 1), 1);
            std::string loop_string = str.substr(i + 1,  loop_end - 1);

            size_t iteration = 0;
            OUTPUT_MODE_CHECK(
                    output << "while (*data){"
            )
            if (output_mode)
            {
                /*
                 * We have to output to C only once
                 */
                if (this->data_ptr[current_position])
                {
                    this->loop_enter(loop_string);
                }
            }
            else
            {
                while (this->data_ptr[current_position])
                {
                    this->loop_enter(loop_string);
                    iteration++;
                }
            }

            OUTPUT_MODE_CHECK(
                    output << "}"
            )

            /*
             * Next character after this
             */
            i += loop_end + 1;
            continue;
        }
        else if (c == LOOP_END)
        {
            continue;
        }

        /*
         * 1 will be increased in loop too
         */
        i += parse_one_future(str, i, c);
        position++;
    }
}

std::string remove_comments(const std::string& str)
{
    std::stringstream ss;
    for (const auto& c: str)
    {
        if (c == '<' || c == '>' || c == '+' || c == '-' || c == '[' || c == ']' || c == ',' || c == '.')
            ss << c;
    }

    return ss.str();
}

void interpreter::parse_all(const std::string& str)
{
    /*
     * Considering full statement a loop too
     */
    loop_enter(remove_comments(str));
}