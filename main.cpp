#include "Film.h"

int main()
{
    cout << "------------ Tugas Besar -------------------------------" << endl;
    cout << "------------ Palm House --------------------------------" << endl;
    cout << "Anggota Kelompok :" << endl;
    cout << "Daud Jeremiah Oscar Simanjuntak - 1301213404" << endl;
    cout << "Dio Irsaputra Siregar - 1301213012" << endl;
    listFilm Lf;
    adr_film Pf;
    listSutradara Ls;
    adr_sutradara Ps;
    infotype F;
    string nameS;
    int x,durasi;


    x = 99;
    createListFilm(Lf);
    createListSutradara(Ls);
    while (x!=0){
        cout << "-------------------------------------------------------" << endl;
        cout << "1. Memasukan Data Film"<<endl;
        cout << "2. Memasukan Nama Sutradara"<<endl;
        cout << "3. Menampilkan Sutradara"<< endl;
        cout << "4. Menyambungkan Sutradara " <<endl;
        cout << "5. Menampilkan Sutradara yang Paling Banyak Menyutradarai Film "<< endl;
        cout << "6. Menampilkan Semua Data Film"<<endl;
        cout << "7. Menghapus Semua Data Film"<<endl;
        cout << "0. Keluar"<<endl;
        cout << "Pilihan Anda: ";
        cin >> x;
        system("cls");
        cout << endl;
        switch(x){
        case 1:
            cout << "==========Masukkan Film========"<<endl;
            cout << "Judul: ";
            cin >> F.Judul;
            cout << "Genre: ";
            cin >> F.Genre;
            cout << "Durasi: ";
            cin >> F.Durasi;
            Pf = createNewFilm(F.Judul,F.Genre,F.Durasi,Pf);
            insertLastFilm(Lf,Pf);
            system("cls");
            break;
        case 2:
            cout << "========Masukan Nama Sutradara========="<< endl;
            cout << "Nama Sutradara: ";
            cin >> nameS;
            Ps = createNewSutradara(nameS,Ps);
            insertLastSutradara(Ls,Ps);
            system("cls");
            break;
        case 3:
            cout << "====== List Nama Sutradara ========"<<endl;
            printSutradara(Ls);
            cout << endl;
            break ;
        case 5:
            cout << "=======Menampilkan Sutradara yang Paling Banyak Menyutradarai Film========="<<endl;
            mostFilm(Lf,Ls);
            cout << endl;
            break;
        case 6:
            cout << "=========Semua Film======="<<endl;
            printFilm(Lf,Ls);
            cout << endl;
            cout << "Banyak Film: " << countFilm(Lf,Ls)<<endl;
            cout << endl;
            break;
        case 4:
            cout << "========Menyambungkan Sutradara========="<<endl;
            cout << "========Mencari Film========="<<endl;
            string Fjudul, Fgenre;
            int Fdurasi;
            cout << "Judul: ";
            cin >> Fjudul;
            cout << "Genre: ";
            cin >> Fgenre;
            cout << "Durasi: ";
            cin >> Fdurasi;
            adr_film Pf = findFilm(Lf,Fjudul, Fgenre, Fdurasi);
            if ((Pf == nil) && ((info(Pf).Judul == F.Judul) && (info(Pf).Genre == F.Genre) && (info(Pf).Durasi == F.Durasi))){
                cout << "Data Film Tidak Ditemukan"<<endl;
            }
            cout << "========Mencari Sutradara======="<<endl;
            cout << "Nama Sutradara: ";
            cin >> nameS;
            adr_sutradara Ps = findSutradara(Ls, nameS);
            if (Ps == nil || info(Ps) != nameS){
                cout << "Nama Sutradara Tidak Ditemukan"<<endl;
            }
            else if (((Pf != nil)&&(Ps != nil)) || (info(Pf).Judul == F.Judul) && (info(Pf).Genre == F.Genre) && (info(Pf).Durasi == F.Durasi) && (info(Ps)!= nameS) ){
                tambahRelasi(Lf, Ls,Pf,Ps);
            }

            break;

        }
            cout << endl;
        cout<< endl;

    }
    cout << "Keluar dari Program... "<<endl;

    return 0;
}
