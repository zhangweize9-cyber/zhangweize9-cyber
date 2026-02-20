[Here's my article](https://medium.com/@zhangweize9/learn-how-to-set-up-a-programming-environment-from-scratch-816a5620c7f9)

---

# Learn how to set up a programming environment from scratch

## Introduction

I know, as someone just starting out in programming, the most important thing isn't actually learning how to use function interfaces. It's understanding the logic of the programming language itself. As for me, I won't bore you with all that basic stuff like how to use functions—that's all in the official documentation. And honestly, you'll never memorize every single function out there. You should just see functions as a means to an end. All you really need is to master the core, fundamental syntax.

For example, if I were to say the phrase “hello world” in English, I'd probably have to learn things like the International Phonetic Alphabet, along with the pronunciation of letters—including vowels and consonants.

Similarly, if you learn programming, you'll find that different programming languages have different syntaxes and different ways of configuring environments.

## Core Logic

For beginners in programming, grasping the core logic of coding is essential. Let's revisit the classic example of writing “Hello World” in English. If you're just starting out, you've likely encountered code snippets like this in your textbooks. Take Lua as an example:

```lua
print("hello world")
```

Simply writing constants directly inside functions is acceptable if you're writing a script for practice. However, I don't recommend this approach in actual development, especially for large-scale projects. Here's why:
- Inconvenient for semantic understanding
- Significantly reduced maintainability
- Difficult to locate and reproduce issues

Therefore, the most recommended approach in actual development is to first store the constant in a variable—essentially giving it a name—and then import it into the function via that variable. For example:

```lua
local print_hello_world = "hello world"
print(print_hello_world)
```

Great! If you've made it this far, congratulations—you've got the basics down! Next, you might start writing code that looks something like this:

```lua
print("hello")
print("hi")
print("nice")
print("to")
print("meet")
print("you")
```

In actual development, if you need to call an interface once per line of output, it's manageable when the code is brief. However, as the code grows, you'll find many features require repeatedly implementing the same method multiple times. Copying and pasting becomes cumbersome and difficult to debug. Therefore, there are two optimization approaches here. One involves using a for loop to iterate through the data, while the other is to directly encapsulate it into a function.

First, let's discuss the first type: iteration. The keyword commonly used for this is `for`. Generally, when iterating over parameters, we need to establish a data type first. For example, a table. In Lua, the syntax for implementing a table is very simple. You just need to wrap it with `value = {}`. Of course, this is a global variable. In actual development, we often use something called a local variable, like this: `local value = {}`.

Lua tables can store many data types, such as integers, floating-point numbers, strings, functions, and so on.

So if you don't want to repeat certain operations, you can write it like this:

```lua
local print_string = {
  "hello",
  "hi",
  "nice",
  "to",
  "meet",
  "you"
}

for _, string in ipairs(print_string) do
  print(string)
end
```

Of course, in actual engineering project development, the more commonly used approach is the second one—that is, directly encapsulating a function to achieve the implementation.

```lua
local function Batch_print_characters(print_strings)
  for _, string in ipairs(print_strings) do
    print(string)
  end
end

Batch_print_characters({
  "hello",
  "hi",
  "nice",
  "to",
  "meet",
  "you"
})
```

The above are merely the basics. In actual development, to ensure the security of program execution, we perform data type checks on program elements. Take a password field, for example. If its type isn't locked to string before input, it could cause irreparable damage in a production environment. If you're using the Lua programming language, you can use `type(value) == "string"` to determine whether it's a string.

For example, this is a program used to enter passwords during login (though the actual logic is far more complex in practice, involving things like string encryption, which we won't go into here).

```lua
local user_info = {
  name = "none",
  password = "ksjdinxw",
}

if type(user_info.password) == "string" then
  return
end
```

## How to Use the Terminal

In practical development, the terminal is often an unavoidable topic. Many operations are debugged within the terminal, and numerous software packages are compiled using it. Terminals come in two main types: Windows Terminal and Linux distributions, which are widely used by programmers. They are compact and take up minimal space. If you're engaged in long-term programming development, Linux distributions are the preferred choice because resolving dependency issues is more straightforward than on Windows. Speaking of dependencies, we must mention package managers. Think of them as the equivalent of the Windows 11 Store, except Linux package managers also handle system upgrades. The commands used depend on your distribution, as they vary across different versions. For example, Arch Linux uses `sudo pacman -S nodejs` for installing and upgrading software, while Ubuntu employs `sudo apt install nodejs`.

We inevitably need to perform operations like creating files and folders in the terminal, including deleting files. Therefore, we still need to master some basic command operations. Take creating files and folders, for instance. In Windows, we right-click and select “New.” In Linux, we type `touch file.txt` to create a file and `mkdir directory` to create a folder. To delete files and folders, we use the `rm` command. However, deletion in Linux has two scenarios: single files and entire directories. For a single file, simply use `rm file.txt`. To delete an entire directory, enter `rm -r directory`. To view the contents of the current directory, use the `ls` command. To display the current working directory, use `pwd`. If you want detailed information about each file in the current directory, enter `ls -la` to view the full list.

The above describes operations within the current directory. To change directories, you must use the `cd` command, which can navigate up or down one level. To **move up one directory** level, enter `cd ..`. To **move down** one level, combine it with `ls`. For example, to navigate to the “test” directory, enter `cd test`. When booting a Linux distribution, the **default directory** is the `$HOME` directory. To quickly switch to it, enter `cd ~`. You can also use `echo $HOME` to view the location of the `$HOME` directory in your operating system.

As for the commands mentioned earlier, they actually all have specific meanings. Essentially, they're just abbreviations in English.

- `cd` - change directory
- `ls` - list files
- `rm` - remove
- `print` - print working directory

## Run the program

With the theoretical knowledge covered above, let's now learn how to run programs. Since Lua is a **scripting language**, you'll need to create a `test.lua` file first. Write your program inside it, save the file, and that's the basic logic. However, in practice, you must first verify that Lua and Vim or Neovim are properly installed. Since you'll be editing text files, you absolutely cannot do without Vim or Neovim.

As for how to use Vim, here's the process:

1. First, open the file (using neovim as an example here), which is `nvim test.lua`.
2. Upon entering the interface, you are in normal mode. You can type `dd` to delete an entire line, or type `o` to insert a new line below the current cursor position. Similarly, pressing `<shift>o` inserts a new line above the current cursor position. Pressing `gg` quickly moves the cursor to the first line, while `<shift>g` moves it to the last line. Below are operations for quick cursor positioning in normal mode. 
3. Here's how to quickly position the cursor in normal mode. To start editing text—that is, to begin writing code—press the `i` key on your keyboard to enter insert mode.
4. After writing your code, to save it, first press the `<esc>` key on your keyboard to exit insert mode and return to normal mode. Then press the `:` key to enter command line mode and type `wq`, which means write the current content to the file and exit.

If you want to run a Lua program in the terminal, ensure your Lua environment is installed, then enter `lua test.lua` to see the program's output.
