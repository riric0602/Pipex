# PIPEX : *My Favourite Unix Initiation*

> This project is coded in C, its purpose is to reimplement the pipe mechanism on Shell that we use all the time in our daily tasks.

Thanks to this project, I re-implemented the mechanism of pipes whether it's executing multiple commands or output/input redirection using files. I have mastered using functions such as **pipe()**, **fork()** and **execve()** and I discovered the universe of UNIX and imperative programming, the most challenging part was to deal with unclosed file descriptors, find the command paths and avoid any leaks.

The usage of the program is :
./pipex input cmd1 cmd2 cmd3 cmdn output
