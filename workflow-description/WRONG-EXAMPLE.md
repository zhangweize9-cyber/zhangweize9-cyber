Wrong Example

### \#1

```cpp
#include <fstream>
#include <iostream>
int main() {
    char data[100];

    std::ofstream outfile;
    std::outfile.open("file.txt");

    std::cout << "Writing to the file" << std::endl;
    std::cout << "Enter your content: "; 
    std::cin.getline(data, 100);

    std::outfile << data << std::endl;

    std::outfile.close();

    std::ifstream infile; 
    std::infile.open("file.txt"); 

    std::cout << "Reading from the file" << std::endl; 
    std::infile >> data;
    std::cout << data << std::endl;
    std::infile >> data; 
    std::cout << data << std::endl;

    infile.close();
}
```
