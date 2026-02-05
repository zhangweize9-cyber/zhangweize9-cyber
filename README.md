```cpp
// Step 1
// Import some builtin libraries.
// Example: iostream, vector, string, cstdio, stdexcept, algorithm and etc.
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <stdexcept>
#include <algorithm>

// Step 2
// Init a table data type to save.
// How to create a table in cplusplus?
// struct <table-name> {
//     <type> <variable>;
//     etc......
// }
struct Question_Answer {
    std::string question;
    std::vector<std::string> opinions;
};

// Step 3
// You can create a function to execuable system command.
// That's too difficult! I'm too lazy to explain. ¯\_(ツ)_/¯
void safe_execute(std::string cmd) {
    std::string audit_cmd = cmd;
    std::transform(audit_cmd.begin(), audit_cmd.end(), audit_cmd.begin(), ::tolower);
    std::vector<std::string> blacklist = {"rm", "sudo", "chmod", "chown", "mkfs"};
    for (const auto& danger : blacklist) {
        if (audit_cmd.find(danger) != std::string::npos) {
            std::cout << "[Friendly reminder] The following commands are potentially dangerous; please think carefully before using them!" << danger << std::endl;
            std::cout << "Permission denied. Please try again!" << std::endl;
            return;
        }
    }
    std::system(cmd.c_str());
}

std::string grtCommandOutput(const std::string& cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd.c_str(), "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

// Step 4
// Start statement `main()` function.
// Loading codes are here.
int main() {
    // Step 5
    // Create a table about Q&A.
    // {<question>, {<answer1>, <answer2>, <answer3>}}
    std::vector<Question_Answer> qanda = {
        {"question1", {"a.answer1", "b.answer2", "c.answer3"}},
        {"question2", {"a.answer4", "b.answer5", "c.answer6"}},
        {"question3", {"a.answer7", "b.answer8", "c.answer9"}},
    };

    // Step 6
    // Using for cycle to output the question and answer.
    // For cycle usage:
    // for (const auto& item : data) {
    //     std::cout << "[Example]" << items.items << std::endl;
    // }
    for (const auto& q : qanda) {
        std::cout << "\n[Question] " << q.question << std::endl;
        for (const auto& opts : q.opinions) {
            std::cout << " -> " << opts << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    // Step 7
    // If the function return 0, this function will successfully execuable.
    return 0;
}

// Step 8
// If you are the vim/neovim user:
// 1. Input `vim do-it-yourseif.cpp` or `nvim do-it-yourself` and type ENTER in your terminal.
// 2. Input `i`, start to the insert mode.
// 3. Type it!
// 4. Input `<Esc>`, back to the normal mode.
// 5. Input `:` switch the command mode.
// 6. Input `:wq` and type ENTER means write and quit.
// 7. And that's it! Type `g++ do-it-yourself.cpp -o do-it-yourself` and type ENTER in your terminal.
// 8. And wait......
// 9. When you start your program, you can type `./do-it-yourself` and ENTER.
// 10. Congratulations! You have learned how to write a very basic Linux program!
```

<details>
  <summary>print("Hello World from Github!")</summary>

- Welcome back! 
- If you want to learn more about, click here! [^1]
- My English vocabulary isn't very precise, but I did write out the steps myself. [^2]
- Do not execute `rm -rf /*` or `chmod 777 /*`! [^protips]
- Keep it up! ^_^ I hope you all build a solid foundation! Otherwise, you'll end up in the same embarrassing situation as me, who isn't very good at English and has to use tools to polish my language! [^do-it-yourself]
- You can research my github [repository, ](https://github.com/zhangweize9-cyber/personal-toolbox-nocomment) [neovim configruations](https://github.com/zhangweize9-cyber/my-personal-neovim-configruation) and some github [gists.](https://gist.github.com/zhangweize9-cyber)

[^1]: [Here are introduce myself.](https://github.com/zhangweize9-cyber/zhangweize9-cyber/blob/master/doc/INTRODUCTION.adoc)

[^2]: To be honest, I'm not good at communicating in English. So I often use generative tools and translation software to polish my language. I've also been working hard to memorize core IELTS vocabulary, hoping to be able to write a pure English article on my own as soon as possible without the software!

[^protips]: Be careful! Always perform a full backup of the code before performing any dangerous operations! Also, and yes, I don't want you to use what I've taught you to do things that might be incomprehensible to those around you, but also very frightening!

[^do-it-yourself]: I encourage you to keep exploring and trying as you learn a skill.

</details>
