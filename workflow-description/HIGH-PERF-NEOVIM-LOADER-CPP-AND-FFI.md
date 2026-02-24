# High-Perf Neovim Loader: C++ & FFI

> INTRODUCTION: During the configuration loading process of Neovim, leveraging the C++ programming language, high-performance optimization for module loading is achieved by utilizing Lua's FFI module and the Lua built-in function `package.loaded`.

`#include <chrono>`

Here we introduce the official C++ standard library for [handling time and dates.](https://en.cppreference.com/w/cpp/chrono.html)

`#include <fstream>`

This module is primarily responsible for [handling file read and write operations.](https://cplusplus.com/reference/fstream/fstream/)

`#include <iostream>`  
`#include <string>`  

`#define EXPORT __attribute__((visibility("default")))`

extern "C" {
EXPORT void profile_load_with_path(const char *modname, const char *json_path,
                                   void (*original_load)(const char *)) {
  auto start = std::chrono::steady_clock::now();

  original_load(modname);

  auto end = std::chrono::steady_clock::now();
  double duration =
      std::chrono::duration<double, std::milli>(end - start).count();

  if (duration > 50.0) {
    std::cout << "Performance: " << modname << " cost " << duration << "ms"
              << std::endl;

    std::ofstream json_file(json_path, std::ios::app);
    if (json_file.is_open()) {
      json_file << "{\"module\": \"" << modname
                << "\", \"cost_ms\": " << duration << "}\n";
      json_file.close();
    }
  }
}
}
