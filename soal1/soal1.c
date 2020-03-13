
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
	pid_t pid, sid;        // Variabel untuk menyimpan PID

	pid = fork();     // Menyimpan PID dari Child Process

	  /* Keluar saat fork gagal
	  * (nilai variabel pid < 0) */
	if (pid < 0) {
	    exit(EXIT_FAILURE);
	}

 	 /* Keluar saat fork berhasil
 	 * (nilai variabel pid adalah PID dari child process) */
	if (pid > 0) {
	    exit(EXIT_SUCCESS);
  	}

  	umask(0);

  	sid = setsid();
 	if (sid < 0) {
 	   exit(EXIT_FAILURE);
	  }

	if ((chdir("/home/sun")) < 0) {
	    exit(EXIT_FAILURE);
	  }


	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);	
	while (1) {
	       	// cek apakah argumen berjumlah 5
	       	if(argc!=5) {
              		printf("argumen tidak sesuai.\n");
                	return 0;
        	}
        	char path[30];
        	strcpy(path,argv[4]);

        	int sec, min, hour;

		// cek detik
        	if((argv[1][0]=='*') && (strlen(argv[1])==1))
                        sec=-1;
                else {
			sec=atoi(argv[1]);
			if(sec<0 || sec > 59) {
                        	printf("argumen tidak sesuai.\n");
                        	return 0;
                	}
		}

		// cek menit
		if((argv[2][0]=='*') && (strlen(argv[2])==1))
                        min=-1;
                else {
			min=atoi(argv[2]);
			if(min<0 || min>59) {
                                printf("argumen tidak sesuai.\n");
                                return 0;
                        }

		}

		// cek jam
                if((argv[3][0]=='*') && (strlen(argv[3])==1))
                        hour=-1;
		else {
			hour=atoi(argv[3]);
			if(hour<0 || hour>23) {
                                printf("argumen tidak sesuai.\n");
                                return 0;
                        }
		}

  		time_t rawtime = time(NULL);
  		struct tm *timeinfo = localtime(&rawtime);

		// menjalankan bash saat waktu sesuai input (seperti cron)
		if((timeinfo->tm_sec == sec || sec==-1) && (timeinfo->tm_min == min  || min==-1) && (timeinfo->tm_hour == hour || hour==-1)) {
			pid_t pid1 =  fork();
			if(pid1 == 0) {
				char *arg1[]={"bash",path,NULL};
				execv("/bin/bash",arg1);
			}
		}
   		sleep(1);
	}

}

