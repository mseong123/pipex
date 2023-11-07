# pipex | 42KL

The purpose of this project is the discovery in detail UNIX mechanism - pipe and child process. The following C system/api calls are required to complete the project:
 - execve (replace current process with program to be executed)
 - pipe (creating pipes)
 - fork (to create child process)
 - exit
 - waitpid

[`Subject PDF`](https://github.com/mseong123/pipex/blob/5510e00e0aabfb577879685b5f32a7b565e04e99/en.subject.pdf) link.

### Discription of mandatory part
The program `pipex` should repeat the behaviour of the next shell command
```bash
$> < file1 cmd1 | cmd2 > file2
```
and looks like this:
```bash
$> ./pipex file1 cmd1 cmd2 file2
```
All errors like: wrong commands,  permission to files and etc, need be handle.
### Discription of bonus part
Program need handle multiple pipes
```bash
$> < file1 cmd1 | cmd2 | cmd3 | ... | cmdn > file2

$> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
Support `<<` and `>>`, when instead of `file1` is`here_doc`.
```bash
$> cmd1 << LIMITER | cmd2 >> file2

$> ./pipex here_doc LIMITER cmd1 cmd2 file2
```
## Status

Validated 6/6/2023. Grade: 125%. Project duration: 1 weeks.

## Clone

Clone the repository:

```
git clone https://github.com/mseong123/pipex.git
```

## Compile and Run

The program is split into a mandatory part and a bonus part. Both can be compiled and run using the following command.

```shell
make
```

To run the program:

Run the program as per description of mandatory and bonus above.
