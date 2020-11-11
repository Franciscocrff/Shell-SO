# Shell-SO

Francisco Carlos Ramos Ferreira Filho - 4889
<br>
Gabriel Guimarães Batalha - 3915
<br>
Matheus de Deus Rocha - 3918
<br>

Projeto solicitado pela disciplina SIN 351 - Sistemas Operacionais referente ao período 04/2020.
<br>

Para compilar e executar o programa, é necessário baixar o projeto do GIT, acessar a pasta do projeto, iniciar o terminal e executar o comando "make".

<br>
A proposta do trabalho era desenvolver um Shell/Interpretador de Comandos(CLI) que seja capaz de receber entradas dos usuários (comandos), processá-los (caso ele exista) e exibir a saída na tela de Prompt.
<br>
Algumas validações feitas pelos usuários foram:
<br>
 ./main
<br>
Meu.Shell> cat file
<br>
cat: file: No such file or directory
<br>
Meu.Shell> ls     
<br>
file.txt  francisco  gabriel  main  main.c  matheus
<br>
Meu.Shell> cat file , ls
<br>
cat: file: No such file or directory
<br>
file.txt  francisco  gabriel  main  main.c  matheus
<br>
Foram realizados diversos testes, porém apenas estes documentados.
<br>

Seguem referências utilizadas:
<br>
https://stackoverflow.com/questions/48923791/dup2-paramater-order-confusion
<br>
https://www.dca.ufrn.br/~adelardo/cursos/DCA409/node39.html
<br>
https://stackoverflow.com/questions/64728068/basic-shell-that-takes-multiple-word-command
<br>
https://man7.org/linux/man-pages/man2/execve.2.html
<br>
https://stackoverflow.com/questions/64731327/how-to-use-execl-in-order-to-pipe-multiple-processes
<br>
https://www.dca.ufrn.br/~adelardo/cursos/DCA409/node34.html
<br>
https://linux.die.net/man/3/strtok_r
<br>
https://stackoverflow.com/questions/4693884/nested-strtok-function-problem-in-c
