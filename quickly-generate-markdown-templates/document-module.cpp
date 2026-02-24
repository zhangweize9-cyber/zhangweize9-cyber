#include "mustache.hpp"
#include <iostream>
#include <string>

using namespace kainjow;

int main() {
  std::string md_template = "# hello {{test}}\n"
                            "## test: {{result}}\n";

  mustache::data data;
  data.set("test", "world");
  data.set("result", "passed");

  // mdt: MarkDown Template
  mustache::data mdt_list{mustache::data::type::list};

  data.set("mdt", mdt_list);

  mustache::mustache tmpl(md_template);
  std::string final_md = tmpl.render(data);

  std::cout << final_md << std::endl;
  return 0;
}
