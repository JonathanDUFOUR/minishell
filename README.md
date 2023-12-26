# minishell
![Project illustration](./illustartion.png "Sarah Connor ?")  
This project is the 9th of the 42 School cursus.

# Description
In this project, we must implement our own shell program,
taking either bash or [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/contents.html) as reference.  
Our shell must:
 - display a prompt when waiting for new commands
 - have a working history
 - search and run the right executable when dealing with commands
 - not use more than 1 global variable
 - not interpret special characters('\', ';', ...), or unclosed quotes
 - handle single-quoted (') and dual-quoted (") token portions
 - implement redirections <, >, <<, >>
 - implement pipes (|)
 - handle environment variables ($var0, $VAR1, ...)
 - handle $? as the exit status of the last ran command
 - handle Ctrl-C, Ctrl-D, and Ctrl-\ signals
 - implement builtins:
   - echo, with -n option
   - cd, with no options, and with only a relative or absolute path
   - pwd, with no options
   - export, with no options
   - unset, with no options
   - env, with no options nor arguments
   - exit, with no options
