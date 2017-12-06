#include <string>

#pragma once

using error = std::string;
error new_error(std::string msg) {
    return msg;
}
