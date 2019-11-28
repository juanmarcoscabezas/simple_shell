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
- Display a prompt and wait for the user to type a command.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- The command lines are made only of one word. No arguments will be passed to programs.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle the “end of file” condition (Ctrl+D) and the signal (Ctrl+C).

# How Use

## How to compile

gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

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

