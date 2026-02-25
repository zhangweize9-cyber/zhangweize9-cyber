// Module Link: https://github.com/kainjow/Mustache
// Author Name: kainjow
//     License: Boost Software License - Version 1.0
#include "mustache.hpp"

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace kainjow;

std::string load_template(const std::string &filepath) {
  std::ifstream file(filepath);
  if (!file.is_open())
    return "";
  std::stringstream buffer;
  buffer << file.rdbuf();
  return buffer.str();
}

int main() {
  // Define markdown template.
  struct GenerationTask {
    // mustache file path
    std::string template_path;
    // output markdown path
    std::string output_path;
  };

  // Generate timestamp.
  auto now = std::time(nullptr);
  auto local_time = *std::localtime(&now);
  std::stringstream ss;
  ss << std::put_time(&local_time, "%Y-%m-%d, %H:%M:%S");
  std::string timestamp = ss.str();

  // This is where some data is stored.
  std::unordered_map<std::string, std::string> md_const_data_saved;
  md_const_data_saved["write_introduction"] =
      "<you-can-write-introduction-from-here>";
  md_const_data_saved["author_name"] = "the-essence-of-life";

  // Here are some consts.
  mustache::data data;
  data.set("introduction", md_const_data_saved["write_introduction"]);
  data.set("ymdhms", timestamp);
  data.set("author", md_const_data_saved["author_name"]);

  // mdt: MarkDown Template
  mustache::data mdt_list{mustache::data::type::list};

  // Render and print to the console.
  // Compilation Steps: `g++ document-module.cpp -o markdown-template-generate`
  // Usage: `./markdown-template-generate >> Template.md`
  data.set("mdt", mdt_list);
  std::vector<GenerationTask> tasks = {
      {"./md-templates/templates1.mustache", "./Output.md"},
  };
  for (const auto &task : tasks) {
    std::string raw_tmpl = load_template(task.template_path);
    if (raw_tmpl.empty()) {
      std::cerr << "Error: Could not find " << task.template_path << std::endl;
      continue;
    }

    mustache::mustache tmpl{raw_tmpl};
    std::ofstream out(task.output_path);
    out << tmpl.render(data);
    std::cout << "Generated: " << task.output_path << std::endl;
  }
  return 0;
}
