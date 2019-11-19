# Simple Shell

The simple shell project is the largest and most difficult project we have worked on at Holberton School.
This project consists of creating a shell so that it behaves very similar to the Bourne Shell "sh".

This project was built by Alejandro López and Juan Marcos Cabezas

# Table of Contents
1. [Authors](#Authors)
2. [Features](#Features)
3. [How Use](#How-Use)
3. [Tasks](#Tasks)
4. [General Test Cases](#general-Test-Cases)

# Authors
 👤 **Hugo Bayona**

- Twitter: [@batmanesfriki](https://twitter.com/batmanesfriki)
- Github: [@hb4y](https://github.com/hb4y)

👤 **Juan Marcos Cabezas**

- Twitter: [@juanmarcab](https://twitter.com/juanmarcab)
- Github: [@juanmarcoscabezas](https://github.com/juanmarcoscabezas)

# Features
- The main function uses structures to call the function corresponding to the case, this allows greater code scalability.
- As in the original printf, the function has a buffer that stores and prints the output strings every 1024 bytes.
- Just like the original printf, the returns of our function are the number of characters printed, when the input is incorrect the return is error -1


# How Use

## How to compile

### Requirements

 - compile on Ubuntu 14.04 LTS
 - compile with gcc 4.8.4
 
### Flags to compile

`$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Examples

```bash
./hsh
echo "/bin/ls" | ./hsh
./hsh FILENAME
```

# Tasks

# General Test Cases

- [x] ./hsh;
- [x] echo "/bin/ls" | ./hsh
- [x] ./hsh FILENAME

