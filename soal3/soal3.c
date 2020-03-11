#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
	pid_t pid1 = fork();
   	int status1;
   	if (pid1 == 0) {
		// 3a) buat 2 direktori: indomie dan (5 detik kemudian) sedaap
		pid_t pid2 = fork();
		if(pid2 == 0) {
       			char *argv[]={"mkdir","/home/sun/modul2/indomie",NULL};
       			execv("/bin/mkdir",argv);
		}
		else {
			sleep(5);
        	        char *arg2[]={"mkdir","/home/sun/modul2/sedaap",NULL};
                	execv("/bin/mkdir",arg2);
		}
   	}
  	else {
       		while ((wait(&status1)) > 0);
		pid_t pid3 =  fork();
		int status3;
        	if(pid3 == 0) {
		        // 3b) extract file jpg.zip ke /home/<user>/modul2
        		char *arg[]={"unzip","-qq","/home/sun/modul2/jpg.zip","-d","/home/sun/modul2",NULL};
        		execv("/usr/bin/unzip",arg);
        	}
        	else {
			// 3c) file hasil ekstrak dipindahkan ke sedaap, direktori ke indomie
			while ((wait(&status3)) > 0);
			pid_t pid4 = fork();
			int status4;
			if(pid4 == 0) {
                		char *arg[]={"find","/home/sun/modul2/jpg","-type","f","-exec","mv","{}","/home/sun/modul2/sedaap",";",NULL};
                		execv("/usr/bin/find",arg);
			}
			else {
				while((wait(&status4)) > 0);
				pid_t pid5 = fork();
				int status5;
				if(pid5 == 0) {
 					char *arg[]={"find","/home/sun/modul2/jpg","!","-path","/home/sun/modul2/jpg","-prune","-exec","mv","{}","/home/sun/modul2/indomie",";",NULL};
        	                	execv("/usr/bin/find",arg);
				}
				else {
					// 3d) untuk setiap direktori pada indomie, dibuat 2 file kosong coba1.txt dan (3 detik kemudian) coba2.txt
					while((wait(&status5)) > 0);
					pid_t pid6 = fork();
					if(pid6 == 0) {
						char *arg[]={"find","/home/sun/modul2/indomie","!","-path","/home/sun/modul2/indomie","-prune","-exec","touch","{}/coba1.txt",";",NULL};
						execv("/usr/bin/find",arg);
					}
					else {
						sleep(3);
						char *arg[]={"find","/home/sun/modul2/indomie","!","-path","/home/sun/modul2/indomie","-prune","-exec","touch","{}/coba2.txt",";",NULL};
                                                execv("/usr/bin/find",arg);

					}
				}
			}
        	}
   	}
}

