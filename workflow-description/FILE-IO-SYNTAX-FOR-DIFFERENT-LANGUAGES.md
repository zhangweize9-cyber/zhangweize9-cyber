# FILE IO SYNTAX FOR DIFFERENT LANGUAGES

## c plus plus

The following outlines the entire process for reading and writing files in C++.

```cpp
#include <fstream>
#include <iostream>
int main() {
  char data[100];

  // Step1: Open the file in write mode.
  std::ofstream outfile;
  outfile.open("file.txt");

  std::cout << "Writing to the file" << std::endl;
  std::cout << "Enter your content: ";

  std::cin.getline(data, 100);

  // Step 2: Write the data obtained from user input.
  outfile << data << std::endl;

  // Step 3: Close the open file.
  outfile.close();

  // Step 4: Open the file in read-only mode
  std::ifstream infile;

  infile.open("file.txt");

  // Step 5: Display file contents.
  std::cout << "Reading from the file" << std::endl;
  infile >> data;
  std::cout << data << std::endl;

  // Step 6: Close the file.
  infile.close();
}
```

## python

The following outlines the entire process for reading and writing files in C++.

```python
import os

## File read/write.
# Step 1: Open the file.
fo = open("file.txt", "a+")

# Step 2: Read file status.
print "File name: ", fo.name
print "Status: ", fo.closed
print "Access mode: ", fo.mode
print "Is a trailing space required? ", fo.softspace

# Step 3: Content to be written.
fo.write("hello world!\n")

# Step 4: Read file string.
fo = open("foo.txt", "r+")
str = fo.read()
print "String: ", str

# Step 5: Locate File Location.
print "Current file location: ", position

## File operations.
# Step 6: Rename files.
os.rename("file.txt", "new-file.txt")

# Step 7: Remove files.
os.remove("file.txt")

# Step 8: Create directory.
os.mkdir("new-directory")

# Step 9: Switch directories.
os.chdir("new-directory")

# Step 10: Display the current working directory.
print os.getcwd()

# Step 11: Delete directory.
os.rmdir("new-directory")

# Step 12: Recursively delete directories.
os.removedirs("new-directory")

# Step 13: Close the file.
fo.close()
```

## go

The following outlines the entire process for reading and writing files in go.

```go
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    /// File read/write.
    // Step 1: Create files.
    file, err := os.Create("example.txt")
    if err != nil {
        log.Fatal(err)
    }
    defer file.Close()  
    log.Println("Create file successfully!")

    // Step 2: Open files.
    file, err := os.Open("example.txt")
    if err != nil {
        fmt.Println("Error opening file:", err)
        return
    }
    defer file.Close()
    fmt.Println("File opened successfully!")

    // Step 3: Read files.
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        fmt.Println(scanner.Text())
    }
    if err := scanner.Err(); err != nil {
        fmt.Println("Error reading file:", err)
    }

    // Step 4: Write to file.
    writer := bufio.NewWriter(file)
    fmt.Fprintln(writer, "hello world")
    writer.Flush()

    // Step 5: Append text to the file.
    if _, err := file.WriteString("Appended text."); err != nil {
        fmt.Println("Error appending to file:", err)
        return
    }
    fmt.Println("Text appended successfully!")

    /// File operation.
    // Step 6: Remove files.
    err := os.Remove("output.txt")
    if err != nil {
        fmt.Println("Error deleting file:", err)
        return
    }
    fmt.Println("File deleted successfully!")

    // Step 7: Retrieve file information.
    fileInfo, err := os.Stat("test.txt")
    if err != nil {
        log.Fatal(err)
    }
    fmt.Println("File name: ", fileInfo.Name())
    fmt.Println("File size: ", fileInfo.Size(), "byte")
    fmt.Println("File permission: ", fileInfo.Mode())
    fmt.Println("Last Modified Date: ", fileInfo.ModTime())
    fmt.Println("Is directory: ", fileInfo.IsDir())

    // Step 8: Check if the file exists.
    if _, err := os.Stat("test.txt"); os.IsNotExist(err) {
        fmt.Println("File not exists!")
    } else {
        fmt.Println("File exists!")
    }
}
```
