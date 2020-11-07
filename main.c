#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_TAM 512
#define STDOUT_FILENO 1

void verificarComando(char* args[], char* ProxComando, int OutroComando, int* fd){

  //encerra o programa.
  if(strcmp(args[0], "quit") == 0){ 
	  	exit(0);
	}

  //entrada nula.
	if(args[0] == NULL){ 
    return;
  }


  if(OutroComando == 1 && ProxComando == NULL){ 
		pid_t pid = fork(); //Cria um processo filho.
		if (pid < 0) {
			perror("fork errado");
		}
		if (pid == 0) { //Filho executa esse bloco.	
			if (execvp(args[0], args) == -1) {
				perror("erro no comando");
        exit(1);
			}
		}	
		//Processo pai espera filho terminar de executar.
		if (wait(0) == -1) {
			perror("erro no wait 1");
		}

 
	} else if(OutroComando == 0 && ProxComando == NULL){ 
		pid_t pid = fork(); //Cria um processo filho.
		if (pid < 0) {
			perror("erro no fork\n");
		}
		if (pid == 0) { //Filho executa esse bloco.	
			dup2(fd[0], STDIN_FILENO);	
			close(fd[0]);
			close(fd[1]);

			if (execvp(args[0], args) == -1) {
				perror("erro no comando\n");
				exit(2);
			}
		}
		//encerra o pipe do programa.
		close(fd[0]);
		close(fd[1]);

		if (wait(0) == -1) {
			perror("erro no wait\n");
		}

	} else if(OutroComando == 1 && ProxComando != NULL){ 
		pid_t pid = fork(); //Cria um processo filho.
		if (pid < 0){
			perror("erro no fork\n");
		}
		if(pid == 0){ //Filho executa esse bloco.		
			dup2(fd[1], STDOUT_FILENO);
			close(fd[0]);			
			close(fd[1]);

			if(execvp(args[0], args) == -1){
				perror("erro no comando\n");
				exit(3);
			}
		}
    	if (wait(0) == -1) {
			perror("erro no wait\n");
		}	
	}
}

