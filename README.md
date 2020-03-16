# SoalShiftSISOP20_modul2_A10
**Sandra Agnes Oktaviana  (05111840000124)**

**Adrian Danindra Indarto (05111840000068)**

## table of contents
* [soal1](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal1)
* [soal2](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal3)
* [soal3](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal3)

## soal1
source code: [soal1.c](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10/blob/master/soal1/soal1.c)

### penyelesaian & penjelasan soal
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

  **a. Program menerima 4 argumen berupa:**
      
      i. Detik: 0-59 atau * (any value) 
      ii. Menit: 0-59 atau * (any value) 
      iii. Jam: 0-23 atau * (any value) 
      iv. Path file .sh 
      
Di soal ini kita mendapat informasi bahwa kita membutuhkan empat variabel untuk menampung semua argumen yang diberikan. Variabel-variabel ini adalah:
* `char path[30];` digunakan untuk menyimpan direktori file yang akan di-bash. Variabel ini menggunakan `argv[4]` yang memuat dimana letak file yang akan di-bash. Fungsi `strcpy(path,argv[4])` berfungsi untuk melakukan copy string dari `argv[4]` ke `path[30]`
* `int sec, min, hour1` digunakan untuk menyimpan input kapan program akan dijalankan. Variabel ini menggunakan `argv[1]` untuk variabel `sec`, `argv[2]` untuk variabel `min`, dan `argv[3]` untuk variabel `hour`. variabel ini menyimpan data dalam bentuk integer, sedangkan semua argumen pada 'argv[]` masih berupa string. Untuk itu, kita menggunakan fungsi `atoi()` untuk melakukan konversi dari string ke integer

Selain variabel-variabel ini. beberapa variabel tambahan dibutuhkan untuk mendapatkan waktu pada sistem. Variabel-variabel itu adalah:
* `struct *tm timeinfo` untuk menyimpan waktu yang ada di server. Kita menggunakan `time_t rawtime = time(NULL);` dan `localtime(&rawtime)` untuk mendapatkan waktu sistem.
* `char *arg1[]` untuk menyimoan argumen-argumen yang dibutuhkan untuk menjalankan program. Di dalam variabel ini adalah `{"bash",path,NULL}` yang digunakan untuk menjalankan program bash di dalam Linux.
  
**b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai** 
 
Kita menggunakan pengecekan kondisi `argv[]` dengan menggunakan `argc` dan beberapa percabangan `if`. `argc` digunakan untuk mengecek apakah argumen yang digunakan memiliki jumlah yang dibutuhkan dalam program. Program ini memerlukan 5 argumen untuk menjalankan program. Jika argumen yang diberikan tidak sama dengan 5, maka program akan mengeluarkan pesan error dan melakukan return bernilai 0.

Percabangan `if` digunakan untuk mengecek input waktu yang diberikan. Jika dalam input diberi tanda * (yang merupakan wildcard), program akan memberi flag yang menandakan bahwa program itu dijalankan untuk setiap satuan waktu yang bertanda * dan jika tidak bertanda * , maka program akan menjalankan fungsi `atoi()` untuk mengubah string di `argv[]` ke bentuk integer untuk setiap variabel yang bersangkutan. Lalu, terdapat percabangan `if` untuk mengecek apakah input yang diberikan masih berada di dalam range input yang diperbolehkan. Jika input yang diberikan tidak berada di dalam range input, maka program akan memberikan pesan error dan melakukan return bernilai 0.
  
**c. Program hanya menerima 1 config cron** 
  
Program ini hanya menerima input langsung dari terminal sehingga kita tidak menggunakan fungsi `scanf`.
 
  d. Program berjalan di background (daemon) 
  
  e. Tidak boleh menggunakan fungsi system()    

Contoh: ./program \* 34 7 /home/somi/test.sh 
        Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap detik pada jam 07:34.
	
Program ini bekerja dengan cara membandingkan waktu sistem dengan waktu yang dikehendaki di input. Pertama, program akan melakukan refresh terhadap variabel `localtime`. Jika dalam input menggunakan wildcard * , maka program tidak akan mengecek waktu sistem. Setelah semua kriteria terpenuhi, maka program akan menggunakan variabel `arg1[]` untuk menjalankan fungsi `execv("/bin/bash",arg1);` setelah program dijalankan, program akan `sleep` selama 1 detik dan memulai proses dari awal.
        
        
## soal2
source code: [soal2.c](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10/blob/master/soal2/soal2.c)

### penyelesaian & penjelasan soal  
**2a) Pertama-tama, Kiwa  membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].**

Setelah dibuat folder khusus, buat program c untuk membuat folder dengan nama timestamp setiap 30 detik. berikut potongan kode untuk menyelesaikan soal 2a:
```
char foldername[100] = "/home/sun/khusus/";
char strtime[100];
time_t t_folder = time(NULL);
struct tm *t = localtime(&t_folder);
strftime(strtime, sizeof(foldername)-1, "%Y-%m-%d_%H:%M:%S", t);
strcat(foldername,strtime);

char *arg1[]={"mkdir",foldername,NULL};
execv("/bin/mkdir", arg1);
```
* `char foldername[100] = "/home/sun/khusus/";` deklarasi string untuk menyimpan nama folder. Folder yang akan dibuat akan disimpan di path `/home/sun/khusus/`
* `char strtime[100];`  deklarasi string untuk menyimpan timestamp
* `time_t t_folder = time(NULL);` t_folder merupakan variabel untuk menyimpan waktu
* `struct tm *t = localtime(&t_folder);` t merupakan pointer yang menunjuk ke localtime t_folder
* `strftime(strtime, sizeof(foldername)-1, "%Y-%m-%d_%H:%M:%S", t);` untuk mendapatkan format yang sesuai, dilakukan copy time ke string, dan disimpan ke variabel strtime
* `strcat(foldername,strtime);` hasil waktu yang disimpan di strtime kemudian di tambahkan ke string foldername
* bash yang akan djalankan untuk membuat direktori dengan nama timestamp ialah `mkdir foldername`

**2b) Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYYmm-dd_HH:ii:ss].**

Untuk menyelesaikan soal 2b, selanjutnya akan dilakukan fork() dengan soal 2a sebagai child processnya, dan soal 2b sebagai parent process. Isi dari parent process untuk menyelesaikan soal 2b sebagai berikut:
```
while((wait(&status2)) > 0);
for(int i=0; i<20; i++) {
  pid_t pid3 = fork();
	if(pid3 == 0) {
	    time_t t_file = time(NULL);
			struct tm *tp = localtime(&t_file);

			char filename[100];
	    strcpy(filename, foldername);
			strcat(filename,"/");

			char timefilename[100];
	    strftime(timefilename, sizeof(timefilename)-1, "%Y-%m-%d_%H:%M:%S", tp);
			strcat(filename, timefilename);
      
      char stime[10];
	    strftime(stime, sizeof(stime)-1, "%S", tp);
      int st = atoi(stime);
      st = (st%1000)+100;

      sprintf(stime, "%d", st);

	    char linkphoto[100];
		  strcpy(linkphoto,"https://picsum.photos/");
      strcat(linkphoto,stime);

			char *arg2[]={"wget","-O",filename,linkphoto,NULL};
      execv("/usr/bin/wget", arg2);
  }
  sleep(5);
}
 ```
 
* sebelum command dijalankan, dilakukan `while((wait(&status2)) > 0);` wait child process berjalan hingga selesai baru ke parent process
* selanjutnya untuk mendapatkan 20 gambar, maka dilakukan looping `for(int i=0; i<20; i++)` dimana setiap loop akan dilakukan fork() dengan isi child proses sebagai berikut:
    * `time_t t_file = time(NULL);` t_file merupakan variabel untuk menyimpan waktu untuk tiap-tiap file
    * `struct tm *tp = localtime(&t_file);` tp merupakan pointer yang menunjuk ke localtime t_file
    * `char filename[100]; strcpy(filename, foldername); strcat(filename,"/");` untuk menyimpan nama file. pertama-tama akan meng-copy nama folder ke filename untuk tau di path mana file akan dibuat.
    * `char timefilename[100]; strftime(timefilename, sizeof(timefilename)-1, "%Y-%m-%d_%H:%M:%S", tp);` untuk mendapatkan format yang sesuai, dilakukan copy time ke string, dan disimpan ke variabel timefilename
    * `strcat(filename, timefilename);` menambahkan timefilename ke filename
    * `char stime[10]; strftime(stime, sizeof(stime)-1, "%S", tp);` untuk mendapatkan detik dari waktu file, maka dilakukan copy second time nya dan disimpan ke stime.
    * `int st = atoi(stime);` stime diubah ke int dengan fungsi atoi() dan disimpan ke st
    * `st = (st%1000)+100;` untuk perhitungan ukuran pixel yang diminta
    * `sprintf(stime, "%d", st);` copy st ke string 
    * `char linkphoto[100]; strcpy(linkphoto,"https://picsum.photos/"); strcat(linkphoto,stime);` link untuk mengunduh gambar berupa dengan ukuran pixel yang disesuaikan detik waktunya
    * kemudian diakukan bash `wget -O filename linkphoto` untuk mengunduh gambar dari linkphoto kemudian disimpan dengan nama filename
    
**2c) Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).**

Dari soal 2b, setelah 20 gambar selesai diunduh, maka akan di zip. Berikut penyelesaian soal 2c:
```
pid_t pid4 = fork();
int status4;
if(pid4 == 0) {
    char zipname[100];
		strcpy(zipname, foldername);
		strcat(zipname,".zip");
		char *arg3[]={"zip","-j","-r","-m",zipname,foldername,NULL};
		execv("/usr/bin/zip",arg3);
}
else {
		while((wait(&status4)) > 0);
    char *arg4[]={"rm","-d",foldername,NULL};
    execv("/bin/rm",arg4);
}
```

Dilakukan fork() dimana:
* child processnya akan melakukan zip file
    * `char zipname[100]; strcpy(zipname, foldername); strcat(zipname,".zip");` path folder yang akan di zip dicopykan ke zipname dengan menambahkan ekstensi .zip
    * kemudian dilakukan bash `zip -j -r -m zipname foldername` untuk meng-zip isi foldername ke zipname secara recursively (`-r`) dan menghapusnya setelah selesai di zip.
* parent processnya akan melakukan menghapus sisa directory foldername
    * `while((wait(&status4)) > 0);` menunggu child process selesai elakukan prosesnya
    * kemudian dilakukan bash `rm -d foldername` untuk menghapus sisa directory
    
**2d) Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut mengenerate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.**

**2e) Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).**

**kendala**

soal 2d dan 2e belum selesai. 

## soal3
source code: [soal3.c](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10/blob/master/soal3/soal3.c)

### penyelesaian & penjelasan soal

**3a) Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. 
    Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.** 
    
```
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
 ```
Untuk menyelesaikan soal 3a, pembuatan direktori dilakukan dengan melakukan fork() pid2.
Child process akan melakukan `mkdir /home/sun/modul2/indomie`, dan parent process  akan melakukan `mkdir /home/sun/modul2/sedaap` dalam selang waktu 5 detik kemudian sehingga digunakan `sleep(5)`.

**3b) Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.**

Dari soal 3a, maka perlu dilakukan fork() dimana child process akan melalukan soal 3a, dan parent processnya akan meng-ekstrak file jpg.zip ke direktori /home/[user]/modul2/
```
char *arg[]={"unzip","-qq","/home/sun/modul2/jpg.zip","-d","/home/sun/modul2",NULL};
execv("/usr/bin/unzip",arg);
```
* `unzip` bash command untuk unzip file
* `-qq` agar unzip tidak mengeluarkan outpun apapun (quiet)
* `/home/sun/modul2/jpg.zip`  path ke file jpg.zip
* `-d /home/sun/modul2` hasil unzipped file akan diletakkan ke /home/sun/modul2


**3c) Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus  dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.**

Setelah soal 3a dan 3b dilakukan, selanjutnya untuk 3c maka akan dilakukan fork() dengan soal 3b merupakan child processnya, dan soal 3c pada parent process. 

Untuk menyelesaikan soal 3c, dimana hasil ekstrak jpg.zip yang berupa file akan dipindahkan ke /home/[USER]/modul2/sedaap/ dan yang berupa direktori akan dipindahkan ke /home/[USER]/modul2/indomie/ akan diperlukan 2 proses. Sehingga dilakukan fork() dan penyelesaian soal 3c sebagai berikut:
```
pid_t pid4 = fork();
int status4;
if(pid4 == 0) {
  char *arg[]={"find","/home/sun/modul2/jpg","-type","f","-exec","mv","{}","/home/sun/modul2/sedaap",";",NULL};
  execv("/usr/bin/find",arg);
}
else {
  while((wait(&status4)) > 0);
  char *arg[]={"find","/home/sun/modul2/jpg","!","-path","/home/sun/modul2/jpg","-prune","-exec","mv","{}","/home/sun/modul2/indomie",";",NULL};
  execv("/usr/bin/find",arg);
}
 
 ```
 * `pid_t pid4 = fork();`process di fork() dan `int status4;` untuk status process
 * dalam child process untuk mencari isi direktori jpg yang berbentuk file dan memindahkannya ke /home/sun/modul2/sedaap, maka dilakukan bash command: `find /home/sun/modul2/jpg -type f -exec mv {} /home/sun/modul2/sedaap ;` 
    * `find /home/sun/modul2/jpg` command untuk mencari /home/sun/modul2/jpg
    * `-type f` find akan mencari yang bertype file
    * `-exec mv {} /home/sun/modul2/sedaap ;` hasil find kemudian akan dipindahkan dengan `mv` ke /home/sun/modul2/sedaap
 * dalam parent process untuk mencari isi direktori jpg yang berbentuk direktori dan memindahkannya ke /home/sun/modul2/indomie, maka dilakukan bash command: `find /home/sun/modul2/jpg ! -path /home/sun/modul2/jpg -prune -exec mv {} /home/sun/modul2/indomie ;`
    * sebelum command dijalankan, dilakukan `while((wait(&status4)) > 0);` wait child process berjalan hingga selesai baru ke parent process
    * `find /home/sun/modul2/jpg` command untuk mencari /home/sun/modul2/jpg
    *  `! -path /home/sun/modul2/jpg -prune` kecuali path /home/sun/modul2/jpg itu sendiri akan di `-prune`, yaitu untuk mencegah melakukan find ke path tersebut
    * `-exec mv {} /home/sun/modul2/indomie ;` hasil find kemudian akan dipindahkan dengan `mv` ke /home/sun/modul2/indomie

**3d) Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).**

Setelah soal 3a, 3b dan 3c dilakukan, selanjutnya untuk 3d maka akan dilakukan fork() dengan soal 3c (bagian untuk memindahkan direktori) merupakan child processnya, dan soal 3d pada parent process. 

Untuk menyelesaikan soal 3d, dilakukan fork() sebagai berikut:
 ```
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
```

* `pid_t pid6 = fork();`process di fork()
* dalam child process akan dibuat file coba1.txt di masing-masing direktori yang ada di `/home/sun/modul2/indomie`, maka dilakukan bash command: `find /home/sun/modul2/indomie ! -path /home/sun/modul2/indomie -prune -exec touch {}/coba1.txt ;` 
    * `find /home/sun/modul2/indomie` command untuk mencari /home/sun/modul2/indomie dimana letak direktori yang akan diisi coba1.txt dan coba2.txt
    * `-path /home/sun/modul2/indomie -prune` kecuali path /home/sun/modul2/indomie itu sendiri akan di `-prune`, yaitu untuk mencegah melakukan find ke path tersebut
    * `-exec touch {}/coba1.txt ;` hasil find kemudian akan dilakukan `touch` atau membuat file kosong coba1.txt
* dalam parent process akan dibuat file coba2.txt di masing-masing direktori yang ada di `/home/sun/modul2/indomie` dalam selang waktu 3 detik setelah coba1.txt, maka dilakukan bash command: `find /home/sun/modul2/indomie ! -path /home/sun/modul2/indomie -prune -exec touch {}/coba2.txt ;` dengan sleep(3) sebelum bash dijalankan.
    * sebelum command dijalankan, dilakukan `sleep(3);` wait child process berjalan hingga selesai baru ke parent process
    * `find /home/sun/modul2/jpg` command untuk mencari /home/sun/modul2/jpg
    *  `! -path /home/sun/modul2/indomie -prune` kecuali path /home/sun/modul2/indomie akan di `-prune` yaitu untuk mencegah melakukan find ke path tersebut
     * `-exec touch {}/coba2.txt ;` hasil find kemudian akan dilakukan `touch` atau membuat file kosong coba2.txt
