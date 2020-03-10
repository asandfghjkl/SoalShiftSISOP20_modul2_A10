# SoalShiftSISOP20_modul2_A10
**Sandra Agnes Oktaviana  (05111840000124)**

**Adrian Danindra Indarto (05111840000068)**

## table of contents

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

**2c) Agar rapi, setelah sebuah folder telah terisi oleh 20 gambar, folder akan di zip dan folder akan di delete(sehingga hanya menyisakan .zip). 

**2d) Karena takut program tersebut lepas kendali, Kiwa ingin program tersebut mengenerate sebuah program "killer" yang siap di run(executable) untuk menterminasi semua operasi program tersebut. Setelah di run, program yang menterminasi ini lalu akan mendelete dirinya sendiri.**

**2e) Kiwa menambahkan bahwa program utama bisa dirun dalam dua mode, yaitu MODE_A dan MODE_B. untuk mengaktifkan MODE_A, program harus dijalankan dengan argumen -a. Untuk MODE_B, program harus dijalankan dengan argumen -b. Ketika dijalankan dalam MODE_A, program utama akan langsung menghentikan semua operasinya ketika program killer dijalankan. Untuk MODE_B, ketika program killer dijalankan, program utama akan berhenti tapi membiarkan proses di setiap folder yang masih berjalan sampai selesai(semua folder terisi gambar, terzip lalu di delete).**


## soal3
source code: 

### penyelesaian & penjelasan soal

**3a) Program buatan jaya harus bisa membuat dua direktori di “/home/[USER]/modul2/”. 
    Direktori yang pertama diberi nama “indomie”, lalu lima detik kemudian membuat direktori yang kedua bernama “sedaap”.** 
    
**3b) Kemudian program tersebut harus meng-ekstrak file jpg.zip di direktori “/home/[USER]/modul2/”. Setelah tugas sebelumnya selesai, ternyata tidak hanya itu tugasnya.**

**3c) Diberilah tugas baru yaitu setelah di ekstrak, hasil dari ekstrakan tersebut (di dalam direktori “home/[USER]/modul2/jpg/”) harus  dipindahkan sesuai dengan pengelompokan, semua file harus dipindahkan ke “/home/[USER]/modul2/sedaap/” dan semua direktori harus dipindahkan ke “/home/[USER]/modul2/indomie/”.**

**3d) Untuk setiap direktori yang dipindahkan ke “/home/[USER]/modul2/indomie/” harus membuat dua file kosong. File yang pertama diberi nama “coba1.txt”, lalu 3 detik kemudian membuat file bernama “coba2.txt”. (contoh : “/home/[USER]/modul2/indomie/{nama_folder}/coba1.txt”).**
 
