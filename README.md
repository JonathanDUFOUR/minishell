# minishell
![Project illustration](./illustartion.png "Sarah Connor ?")<br>
This project is the 9th of the 42 School cursus.<br>

# Description
In this project, we must implement our own shell program, taking either bash or POSIX as reference.<br>
Our shell must :<br>
 - display a prompt when waiting for new commands<br>
 - have a working history<br>
 - search and run the right executable when dealing with commands<br>
 - not use more than 1 global variable<br>
 - not interpret special characters('\', ';', ...), or unclosed quotes<br>
 - handle single-quoted (') and dual-quoted (") token portions<br>
 - implement redirections <, >, <<, >><br>
 - implement pipes (|)<br>
 - handle environment variables ($var0, $VAR1, ...)<br>
 - handle $? as the exit status of the last ran command<br>
 - handle Ctrl-C, Ctrl-D, and Ctrl-\ signals<br>
 - implement builtins:<br>
   - echo, with -n option<br>
   - cd, with no options, and with only a relative or absolute path<br>
   - pwd, with no options<br>
   - export, with no options<br>
   - unset, with no options<br>
   - env, with no options nor arguments<br>
   - exit, with no options<br>
