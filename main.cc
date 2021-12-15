#include <fmt/format.h>
#include <fmt/printf.h>
#include <exception>
#include <iostream>

void vlog(const char* file, int line,
          fmt::string_view format, fmt::format_args args) {
//   fmt::print("{}: {}: ", file, line);
//   fmt::printf(format, args);
}

template <typename S, typename... Args>
void log(const char* file, int line,
         const S& format, Args&&... args) {
try{
    fmt::print("{}: {}: ", file, line);
    fmt::printf(format, args...);
    fmt::print("\n");
}catch(std::exception& e){
    fmt::print("{}: {}: ", file, line);
    fmt::print("has mismatch format and arguments ");
    fmt::print("\n");
}
    
}

#define MY_LOG(format, ...) \
  log(__FILE__, __LINE__, FMT_STRING(format), __VA_ARGS__)

int main() {
    int a(1);
  MY_LOG("invalid squishiness: %s", 42); // mismatch reported, print string but int is given.
  MY_LOG("invalid squishiness string: %s", "2");
  MY_LOG("invalid squishiness float: %f", .342);
}
