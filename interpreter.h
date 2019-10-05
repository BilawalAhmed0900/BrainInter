//
// Created by Mian Bilawal on 05-Oct-2019.
//

#ifndef BRAINFUCK_INTERPRETER_INTERPRETER_H
#define BRAINFUCK_INTERPRETER_INTERPRETER_H

#include <fstream>
#include <memory>
#include <sstream>

#include <cstring>
#include <cstddef>

constexpr size_t DATA_PTR_SIZE = 1u << 24u;

typedef char data_type;

class interpreter
{
    std::stringstream output;
    bool output_mode;

    std::unique_ptr<data_type[]> data_ptr;
    size_t length_data_ptr;
    int32_t current_position;

    void loop_enter(const std::string&);
    size_t parse_one_future(const std::string&, size_t, const char&);

    std::string BASIC_C_FILE_STRUCTURE()
    {
        std::stringstream ss;
        ss << "#include <stdio.h>\n";
        ss << "#include <stdlib.h>\n";
        ss << "char *wrap_min(char *d, char *min, char *max){ if (d < min) return max - (min - d); return d; }\n";
        ss << "int main(){";
        ss << "size_t len = " << DATA_PTR_SIZE << ";char *data = (char *)malloc(sizeof(char)*len);";
        ss << "if (data==NULL){return 1;}char *ptr_min = data; char *ptr_max = data + " << DATA_PTR_SIZE << ";";

        return ss.str();
    }

public:
    explicit interpreter(size_t length_data_ptr = DATA_PTR_SIZE, bool output_mode = false)
        : length_data_ptr(length_data_ptr), current_position(0), output_mode(output_mode)
    {
        data_ptr = std::make_unique<data_type[]>(length_data_ptr);
        memset(&data_ptr[0], 0, length_data_ptr * sizeof(data_type));

        if (output_mode)
        {
            output << BASIC_C_FILE_STRUCTURE();
        }
    }

    ~interpreter() { output.clear(); }

    void parse_all(const std::string&);
    void clear_data_ptr() { memset(&data_ptr[0], 0, length_data_ptr * sizeof(data_type)); }
    std::string get_if_output() { if (output_mode) { return output.str() + "free(data);return 0;}"; } return ""; }
};


#endif //BRAINFUCK_INTERPRETER_INTERPRETER_H
