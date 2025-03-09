#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOKLUK 0 //Kolaylık olması açısından ihtiyac isimlerimizi sabit olarak aldık.
#define UYKU 1
#define SEVGI 2
#define SOSYALLESME 3
#define SAGLIK 4
#define EGITIM 5
#define HIJYEN 6
#define TUVALET 7
#define EGLENCE 8
#define SUSUZLUK 9
#define USUME 10
#define GAZ 11



void yemek_ye(int *secici){ //tokluk ihtiyacını bu fonksiyon ile giderilecek
    char yemek_ismi[15];
    int adet;
    if(secici[TOKLUK]>=10)
        printf("Bebe daha fazla yemek yiyemez...\n");  //Tokluk  kontrolu
    else {

    printf("Bebeginizin karnini nasil doyurmak istiyorsunuz?\nSayisini ve ismini giriniz.\n1.Anne sutu(Biberon)\n2.Cici Bebe(Porsiyon)\n3.Meyve puresi(Porsiyon)\n");
    getchar();
    gets(yemek_ismi);
    adet=atoi(yemek_ismi);
    secici[TOKLUK]+=(adet)*2;
    if(secici[TOKLUK]>10)
        secici[TOKLUK]=10;

    secici[TUVALET]+=1;
    secici[UYKU]+=1;
    secici[SUSUZLUK]+=1;
}

}

void uyu(int *secici, int tekrar){//Uyku ihtiyacı için gereklı olan fonksiyon,tekrar parametresi,recursive fonksiyonun 3 kere dönmesini sağlıyor
    if(secici[UYKU]<=0)
        printf("Bebek daha fazla uyuyamaz!!!\n");//uyku düzeyi kontrolu
    else
    if(tekrar>0){
        secici[UYKU]-=2;
        if(secici[UYKU]<0)
            secici[UYKU]=0;
        secici[TOKLUK]-=1;
        secici[SEVGI]-=1;
        secici[SOSYALLESME]-=1;
        secici[HIJYEN]-=1;
        secici[TUVALET]+=1;
        secici[EGLENCE]-=1;
        secici[SUSUZLUK]+=1;
        secici[GAZ]+=1;
        uyu(secici,tekrar-1);//Recursive
    }
    if(secici[UYKU]>10)
        secici[UYKU]=10;
    if(secici[TOKLUK]>10)       //Düzeylerin 10 dan fazla olmaması için
        secici[TOKLUK]=10;
    if(secici[SAGLIK]>10)
        secici[SAGLIK]=10;

}

void sev(int *secici){  //sevgi ihtiyacı fonksiyonu
    int secim;
    if(secici[SEVGI]>=10)
        printf("Sevgi duzeyi maksimum duzeyde!!!");
        else{
    printf("Bebenizi nasil sevmek istiyorsunuz?\n1.konusarak\n2.sarilarak\n3.operek\n");
    scanf("%d",&secim);
    secici[SEVGI] +=2;
    if(secici[SEVGI]>10)
        secici[SEVGI]=10;

    secici[SOSYALLESME]+=1;
    secici[EGLENCE]+=1;
    secici[UYKU]+=1;
        }
    }

void sosyal(int *secici){ //sosyallik fonksiyonu
    int secim;
    printf("Bebenizi nasil sosyallestirmek istiyorsunuz?\n1.Disarida temiz hava aldirarak\n2.Avm'ye goturerek\n3.Komsuya giderek\n");
    scanf("%d",&secim);
    switch(secim){
    case 1:
        secici[SOSYALLESME]+=3;
        secici[UYKU]+=2;
        secici[TOKLUK]-=2;
        secici[SAGLIK]+=1;
        secici[SUSUZLUK]+=2;
        secici[HIJYEN]-=1;
        secici[USUME]+=2;

        if(secici[UYKU]>10)
        secici[UYKU]=10;
    if(secici[TOKLUK]>10)
        secici[TOKLUK]=10;
    if(secici[SAGLIK]>10)
        secici[SAGLIK]=10;

        break;
    case 2:
        secici[SOSYALLESME]+=2;
        secici[UYKU]+=2;
        secici[TOKLUK]-=1;
        secici[SUSUZLUK]+=1;
        secici[HIJYEN]-=2;

        if(secici[UYKU]>10)
        secici[UYKU]=10;
    if(secici[TOKLUK]>10)
        secici[TOKLUK]=10;
    if(secici[SAGLIK]>10)
        secici[SAGLIK]=10;

        break;
    case 3:
        secici[SOSYALLESME]+=1;
        secici[UYKU]+=1;
        secici[TOKLUK]-=1;
        secici[SUSUZLUK]+=1;

        if(secici[UYKU]>10)
        secici[UYKU]=10;
    if(secici[TOKLUK]>10)
        secici[TOKLUK]=10;
    if(secici[SAGLIK]>10)
        secici[SAGLIK]=10;

        break;
    }

    }

void saglikli_olma(int *secici){
    int secim;
    printf("Lutfen tedavi yontemi seciniz:\n1.Surup icir\n2.Ası yaptir\n3.Bitkisel urunler kullan\n");
    scanf("%d",&secim);

    switch(secim){
    case 1:
        secici[SAGLIK]+=2;
        secici[USUME]-=2;
        break;
    case 2:
        secici[SAGLIK]+=3;
        secici[USUME]+=2;
        break;
    case 3:
        secici[SAGLIK]+=1;
        secici[USUME]+=1;
        break;
    }

}

void egit(int *secici){
    int secim;
    if(secici[EGITIM]>=10)
        printf("Egitim en yuksek duzeyde daha fazla calisilamaz!!!\n");
        else{
    printf("Egitim sekli seciniz\n1.Kitap okumak\n2.Puzzle yapmak\n3.Lego oynamak\n");
    scanf("%d",&secim);
    switch(secim) {
    case 1:
        secici[EGITIM]+=2;
        if(secici[EGITIM]>10)
        secici[EGITIM]=10;
        secici[UYKU]+=2;
        secici[TUVALET]+=1;
        secici[TOKLUK]-=1;
        break;
    case 2:
        secici[EGITIM]+=2;
        if(secici[EGITIM]>10)
        secici[EGITIM]=10;
        secici[EGLENCE]+=2;
        secici[TOKLUK]-=1;
        break;
    case 3:
        secici[EGITIM]+=2;
        if(secici[EGITIM]>10)
        secici[EGITIM]=10;
        secici[EGLENCE]+=2;
        secici[TOKLUK]-=1;
        break;
    }
        }

}

void hijyenik_ol(int *secici){ //hijyen fonksiyonu

    secici[HIJYEN]+=3;
    secici[SAGLIK]+=1;
    secici[USUME]+=2;
    secici[GAZ]+=2;
    secici[UYKU]+=2;
    secici[TOKLUK]-=1;

    if(secici[TOKLUK]>0)
                if(secici[SAGLIK]>0)
                    if(secici[UYKU>0])
                        printf("Bebek banyo yaptirildi\n");
}

void WC(int *secici){ //tuvalet fonksiyonu
    secici[TUVALET]-=3;
    secici[HIJYEN]+=1;
    secici[SAGLIK]+=1;
    printf("Bebeginizin bezi degistirildi...\n");
}

void eglen(int *secici){
    int secim;

    printf("Nasil eglendirmek istiyorsunuz?\n1.Oyuncak oynama\n2.Tv Izleme\n3.Parka goturme\n");
    scanf("%d",&secim);
    switch(secim){
        case 1:
            secici[EGLENCE]+=2;
            secici[TOKLUK]-=1;
            secici[UYKU]+=1;
            secici[TUVALET]+=1;
            secici[SUSUZLUK]+=1;

            if(secici[TOKLUK]>0)
                if(secici[SAGLIK]>0)
                    if(secici[UYKU>0])
                        printf("Bebenizin eglencesi yerinde...\n\n");

            if(secici[EGLENCE]>10)
                secici[EGLENCE]=10;
        break;
        case 2:
            secici[EGLENCE]+=1;
            secici[TOKLUK]-=1;
            secici[UYKU]-=1;
            secici[SUSUZLUK]-=1;
            secici[SAGLIK]-=1;

            if(secici[TOKLUK]>0)
                if(secici[SAGLIK]>0)
                    if(secici[UYKU>0])
                        printf("Bebenizin eglencesi yerinde...\n\n");
            if(secici[EGLENCE]>10)
                secici[EGLENCE]=10;
            break;
        case 3:
            secici[EGLENCE]+=3;
            secici[TOKLUK]-=2;
            secici[UYKU]-=2;
            secici[SUSUZLUK]-=2;
            secici[HIJYEN]-=2;
            secici[SOSYALLESME]+=1;

            if(secici[TOKLUK]>0)
                if(secici[SAGLIK]>0)
                    if(secici[UYKU>0])
                        printf("Bebenizin eglencesi yerinde...\n\n");
            if(secici[EGLENCE]>10)
                secici[EGLENCE]=10;

            break;


    }


}

void susuzluk_gider(int *secici){ //susuzluk fonksiyonu
    char miktar[12];
    int adet;
        printf("Icilecek miktari giriniz(maks 3 bardak)\n");
        getchar();
        gets(miktar);
        adet=atoi(miktar);

        secici[SUSUZLUK] -=(adet)*1;
        secici[TUVALET] +=2;

        printf("Bebeginizin susuzlugu giderildi...\n");

}

void Isin(int *secici){ //Usume fonksiyonu
    printf("Bebeniz battaniyeye sariliyor...\n");
    secici[USUME]-=3;
    secici[UYKU]+=2;
    secici[TOKLUK]-=1;
    secici[SAGLIK]+=2;
    printf("Bebeginiz isindi...\n");
}

void gaz_cikar(int *secici){ //gaz fonksiyonu
    printf("Bebeginizin sirti sivazlaniyor");
    secici[GAZ]-=3;
    secici[SAGLIK]+=2;
    secici[UYKU]+=1;
    printf("Bebek gazini cikardi ve rahatladi...\n");
}

int main()
{
    char *ihtiyaclar[12]={"Tokluk","Uyku","Sevgi","Sosyallesme","Saglik","Egitim","Hijyen","Tuvalet","Eglence","Susuzluk","Usume","Gaz"};
    int duzeyler[12]={5,5,5,5,5,5,5,5,5,5,5,5};
    char bebe_ismi[30]="";
    char bebe_cins[30]="";
    int ihtiyac_secimi;
    int while_kont=1;//while döngüsü için kontrol değişkeni
    int *secici=duzeyler;//duzeyler dizisini gösteren secici pointerimiz

    printf("Bebe Bakma Simulator\n");
    printf("***Hos Geldiniz***\n");
    printf("Lutfen Bebeginizin Ismini Giriniz=");
    gets(bebe_ismi);
    printf("Lutfen Bebeginizin Cinsiyetini Giriniz="); //giriş kısmı
    gets(bebe_cins);
    printf("*\n*\n*\n*\n");
    printf("Nur topu gibi bir Bebeniz oldu.\n");
    printf("Bebenizin Adi=");
    puts(bebe_ismi);
    printf("Bebenizin cinsi=");
    puts(bebe_cins);
    printf("\n");

    while(while_kont){



            if(secici[TOKLUK]<=0){
            printf("Bebeginiz asiri acliktan oldu...\n"); //3 kritik ihtiyac kontrolu
            return;
            }

            if(secici[UYKU]>10){
                printf("Bebek asiri uykusuzluktan oldu...\n");  //3 kritik ihtiyac kontrolu
                return;
            }
            if(secici[SAGLIK]<0){
                printf("Bebe asırı sagliksiztan oldu...\n");    //3 kritik ihtiyac kontrolu
                return;
            }
            if(secici[TUVALET]>10){
                printf("!!!!!!!!!!!\nBebek tuvaletini daha fazla tutamadi ve bebek altina yapti\n");
                    secici[TUVALET]=10;
                secici[HIJYEN]=0;
                secici[SAGLIK]-=3;
            }

            if(secici[SEVGI]>10){
                secici[SEVGI]=10;
            }
            if(secici[SOSYALLESME]>10){
                secici[SOSYALLESME]=10;
            }
            if(secici[SAGLIK]>10){      //duzeylerin 10 dan fazla olmaması için kontroller
                secici[SAGLIK]=10;
            }
            if(secici[EGITIM]>10){
                secici[EGITIM]=10;
            }
            if(secici[HIJYEN]>10){
                secici[HIJYEN]=10;
            }
            if(secici[EGLENCE]>10){
                secici[EGLENCE]=10;
            }
            if(secici[SUSUZLUK]>=10){
                secici[SUSUZLUK]=10;
                printf("Bebek susuz kaldi\n");
                secici[SAGLIK]-=3;
            }
            if(secici[USUME]>10){
                secici[USUME]=10;
                printf("Bebek usuyor...\n\n\n");
                secici[SAGLIK]-=3;
            }
            if(secici[GAZ]>10){
                secici[GAZ]=10;
                printf("bebek gaz dolu!!!!!\Surekli zirliyor\n");
                secici[SAGLIK]-=3;
            }

        for(int i=0; i<12; i++){
            printf("%.2d:%s: (%d)\n",i+1,*(ihtiyaclar+i),duzeyler[i]); //Tüm ihtiyac duzeylerini gösteren döngümüz

    }
        printf("\n");
        printf("Cikmak icin 0 Giriniz\n");
        printf("Kac numarali ihtiyaci secmek istiyorsunuz?:\n");
        scanf("%d",&ihtiyac_secimi);

        switch(ihtiyac_secimi) //switch yapısı ile hangi ihtiyacı gidereceğimizi seciyoruz
        {
            case 1:
               yemek_ye(secici);
                break;
            case 2:
               uyu(secici,3);
                break;
            case 3:
                sev(secici);
                break;
            case 4:
                sosyal(secici);
                break;
            case 5:
                saglikli_olma(secici);
                break;
            case 6:
                egit(secici);
                break;
            case 7:
                hijyenik_ol(secici);
                break;
            case 8:
                WC(secici);
                break;
            case 9:
                eglen(secici);
                break;
            case 10:
                susuzluk_gider(secici);
                break;
            case 11:
                Isin(secici);
                break;
            case 12:
                gaz_cikar(secici);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                while_kont=0;
                break;

            default:
                printf("Yanlis tus girdiniz yeniden giriniz\n");
        }

    }

    return 0;
}
