// Module Link: https://github.com/kainjow/Mustache
// Author Name: kainjow
//     License: Boost Software License - Version 1.0
#include "mustache.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace kainjow;

int main() {
  // Define markdown template.
  std::string md_template = "# Programming Log\n"
                            "# INTRODUCTION\n"
                            "# PROCESS\n"
                            "# DEBUG STEP\n"
                            "# SUMMARY\n"
                            "\n"
                            "Timestamp: {{ymdhms}}\n"
                            "Author name: {{author}}\n";

  // Generate timestamp.
  auto now = std::time(nullptr);
  auto local_time = *std::localtime(&now);
  std::stringstream ss;
  ss << std::put_time(&local_time, "%Y-%m-%d, %H:%M:%S");
  std::string timestamp = ss.str();

  // Here are some consts.
  mustache::data data;
  data.set("ymdhms", timestamp);
  data.set("author", "the-essence-of-life");

  // mdt: MarkDown Template
  mustache::data mdt_list{mustache::data::type::list};

  // Render and print to the console.
  // Compilation Steps: `g++ document-module.cpp -o markdown-template-generate`
  // Usage: `./markdown-template-generate >> Template.md`
  data.set("mdt", mdt_list);
  mustache::mustache tmpl(md_template);
  std::string final_md = tmpl.render(data);
  std::cout << final_md << std::endl;
  return 0;
}
