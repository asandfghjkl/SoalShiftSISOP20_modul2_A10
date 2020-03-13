# SoalShiftSISOP20_modul2_A10
**Sandra Agnes Oktaviana  (05111840000124)**

**Adrian Danindra Indarto (05111840000068)**

## table of contents
* [soal1](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal1)
* [soal2](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal3)
* [soal3](https://github.com/asandfghjkl/SoalShiftSISOP20_modul2_A10#soal3)

## soal1
source code: 

### penyelesaian & penjelasan soal
Buatlah program C yang menyerupai crontab untuk menjalankan script bash dengan ketentuan sebagai berikut:

  a. Program menerima 4 argumen berupa: 
      
      i. Detik: 0-59 atau * (any value) 
      ii. Menit: 0-59 atau * (any value) 
      iii. Jam: 0-23 atau * (any value) 
      iv. Path file .sh 
  
  b. Program akan mengeluarkan pesan error jika argumen yang diberikan tidak sesuai 
  
  c. Program hanya menerima 1 config cron 
  
  d. Program berjalan di background (daemon) 
  
  e. Tidak boleh menggunakan fungsi system()    

Contoh: ./program \* 34 7 /home/somi/test.sh 
        Program dengan argumen seperti contoh di atas akan menjalankan script test.sh setiap detik pada jam 07:34.
        
        
## soal2
source code: 

### penyelesaian & penjelasan soal  
**2a) Pertama-tama, Kiwa  membuat sebuah folder khusus, di dalamnya dia membuat sebuah program C yang per 30 detik membuat sebuah folder dengan nama timestamp [YYYY-mm-dd_HH:ii:ss].**

**2b) Tiap-tiap folder lalu diisi dengan 20 gambar yang di download dari https://picsum.photos/, dimana tiap gambar di download setiap 5 detik. Tiap gambar berbentuk persegi dengan ukuran (t%1000)+100 piksel dimana t adalah detik Epoch Unix. Gambar tersebut diberi nama dengan format timestamp [YYYYmm-dd_HH:ii:ss].**

**2c) Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip).**

**2d) Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut mengenerate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.**

**2e) Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).**


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
    *  `! -path /home/sun/modul2/jpg -prune` kecuali path /home/sun/modul2/jpg akan di `-prune` yaitu untuk mencegah melakukan find ke path tersebut
    * `-exec mv {} /home/sun/modul2/indomie ;` hasil find kemudian akan dipindahkan dengan `mv` ke /home/sun/modul2/indomie

**3d) Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).**
 
