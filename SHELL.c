#include<stdio.h>
#include<stdlib.h>       // ----------------> it also contains exit() fn
#include<string.h>
#include<unistd.h>      // -------------------> it contain execl() fn
#include<sys/types.h>   // ------------------> it contains fork() fn
#include<sys/wait.h>   // ------------------> is contains the wait() fn


int main(){
	char str[1000];

	do{
		fgets(str,1000,stdin);
		if(str[0] == 'l'){           // --------------------------------------- ls command 
			
			if(str[4] == 'l'){      // ls -l
				char *b_path = "/bin/ls";
				char *arg1 = "-l";
				pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,NULL);
				}
				wait(NULL);
				

			}
			else if(str[4] == 's'){      // ls -l
				char *b_path = "/bin/ls";
				char *arg1 = "-s";
				//
				pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,NULL);
				}
				wait(NULL);

				//
				//execl(b_path,b_path,arg1,NULL);

			}
			else if(str[2] == '\n'){
				char *b_path = "/bin/ls";

				pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,NULL);
				}
				wait(NULL);
				
			}
			else{
				printf("ls: invalid option! plese chose a proper option!!!!!");
			}



		}
		if(str[0] == 'c' && str[1] == 'a'){        // -----------------------------> this is cat command    [external 2]

			if(str[3] =='\n'){
				char *b_path = "/bin/cat";          // only cat
				pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,NULL);
				}
				wait(NULL);
				


			}
			else if(str[5] == 'n'){

				char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}

				char *arg1 = "-n";
				char *b_path = "/bin/cat";
				pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);




			}
			else if(str[5] == 'e'){
				char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}

				char *arg1 = "-e";
				char *b_path = "/bin/cat";
				pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);

			}
			else{
				printf("cat: invalid option -- '%c",str[5]);
				printf("'");
			}

        }
        if(str[0] == 'd'){                         // ------------------------------> this is date command    [external 3]
        	if(str[6] == '+'){
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}

        		char *b_path = "/bin/date";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg2,NULL);
				}
				wait(NULL);


        	}
        	else if(str[6] == 'r'){
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		char *b_path = "/bin/date";
        		char *arg1 = "-r";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);

        		//
        	}
        	else if(str[4] == '\n'){
        		char *b_path = "/bin/date";
        		pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,NULL);
				}
				wait(NULL);


        	}
        	else{
        		printf("date: invalid option! plese choose a valid option");
        	}

        }
        if(str[0] == 'r'){                         // -------------------------------> this is rm command      [external 4]


        	// option 1 for rm
        	if(str[4] == 'r'){      // this is rm -r for removing directory
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		char *b_path = "/bin/rm";
        		char *arg1 = "-r";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);

        	}
        	else if(str[4] == 'v'){    // option 2 for rm command
        		//
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		char *b_path = "/bin/rm";
        		char *arg1 = "-v";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);
        		//

        	}
        	else{
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		//
        		char *b_path = "/bin/rm";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg2,NULL);
				}
				wait(NULL);

        		//


        	}

        }
        if(str[0] == 'm'){                          // ------------------------------> this is mkdir command   [external 5]
        	if(str[5] == '\n'){
        		printf("mkdir: missing operand");
        	}
        	else if(str[7] == 'p'){
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		char *b_path = "/bin/mkdir";
        		char *arg1 = "-p";
        		pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);



        	}
        	else if(str[7] == 'v'){
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}
        		char *b_path = "/bin/mkdir";
        		char *arg1 = "-v";
        		pid_t pid = fork();
				if(pid < 0){
					perror("(X) !fork failed ");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg1,arg2,NULL);
				}
				wait(NULL);

        	}
        	else{
        		char* fl = strtok(str," ");
        		fl = strtok(NULL," ");
        		char arg2[100] ="";
        		for(int i = 0; i<(strlen(fl)-1); i++){
        			arg2[i] += fl[i];
        		}

        		char *b_path = "/bin/mkdir";
        		//
        		pid_t pid = fork();
				if(pid < 0){
					perror("fork failed");
					exit(1);
				}
				else if(pid == 0){
					execl(b_path,b_path,arg2,NULL);
				}
				wait(NULL);

        	}

        }
        if(str[0] == 'p' && str[1] == 'w'){   // -----------------------------------> pwd command [internal 1] [pwd]
        	char dir[1200];
        	printf("Current Directory: %s",getcwd(dir, sizeof(dir)));
        }
        if(str[0] == 'c' && str[1] == 'd'){   // ------------------------------------> cd command [internal 2] [cd]

        }
        if(str[0] == 'e' && str[1] == 'c'){   // ------------------------------------> echo command [internal 3] [echo]

        	if(str[4] == '\n' && str[5] == '-' && str[6] == 'e'){          // this is echo -e "hi\n"
        		

        	}
            else if(str[4] == '\n' && str[5] == '-' && str[6] == 'n'){     // this is echo -n 

            }
            else{
            	char s[1000] = "";
            	char *ptr = strtok(str, " ");
                ptr = strtok(NULL, " ");
                 while(ptr != NULL)
                {
                    strcat(s,ptr);
                    strcat(s," ");

                    ptr = strtok(NULL, " ");
                }
                puts(s);

            }



        } 


	}while(!(str[0] == 'e' && str[1] == 'n' && str[2] == 'd'));

	
}
