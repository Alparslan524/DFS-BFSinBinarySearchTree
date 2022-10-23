#include <iostream>
#include <queue>
#include <stack>
#include <chrono>
int gecen_sure;

using namespace std;
#define UZUNLUK 68	//dizilerde yer alan eleman sayısı
int dizi1[] = { 1064,1065,1066,1067,1068,1069,1070,1071,1072,1073,1074,1075,1076,1077,1078,1079,1080,1081,1082,1083,2001,2002,2003,2004,2013,2014,2015,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012,3013,3014,3015,3016,3017,3018,3019,3020,3021,3022,3023,3024,3025,3026,3027,3028,3029,3030,3031,3032,3033,3034,3035,3036,3037,3038,3039,3040,3041 };	//agac1 için kullanılacak veriler
int dizi2[] = { 3041,3040,3039,3038,3037,3036,3035,3034,3033,3032,3031,3030,3029,3028,3027,3026,3025,3024,3023,3022,3021,3020,3019,3018,3017,3016,3015,3014,3013,3012,3011,3010,3009,3008,3007,3006,3005,3004,3003,3002,3001,2015,2014,2013,2004,2003,2002,2001,1083,1082,1081,1080,1079,1078,1077,1076,1075,1074,1073,1072,1071,1070,1069,1068,1067,1066,1065,1064 };	//agac2 için kullanılacak veriler
int dizi3[] = { 3039,1074,3010,1082,3016,3005,3008,3014,3015,3023,3025,2002,3021,3035,1077,1065,1069,1073,3011,2004,3020,3001,3030,1076,1081,3031,3040,1071,3013,3029,3036,3027,3033,1070,3038,1068,1080,3037,2014,3003,3007,1072,1066,1083,2015,2003,3018,3024,3034,3009,3012,3019,3028,1078,3017,2001,1079,3041,1067,2013,3026,1064,3004,3022,3006,1075,3032,3002 };	//agac3 için kullanılacak veriler



struct Dugum {		//Agacta yer alan her bir dugumun veri yapisi
    int veri; 		//Dugumde tutulan veri
    Dugum* sag;	    //Dugumun sag cocuguna isaretci
    Dugum* sol;  	//Dugumun sol cocuguna isaretci
};

struct IkiliSiralamaAgaci {	//Ikili siralama agaci veri yapisi
    Dugum* kok;			    //Agac kokune isaretci
    void agacKur(int*); 	//Dizi isaretcisi alir ve dizinin elemanlarini ikili siralama agacina uygun sekilde yerlestirir
    void agacKapat();		//Agacin dugumleri icin alinan bellek gozlerini program sonlanmadan hemen once iade eder
    void olustur();
    int dugum_sayisi;
    bool DFS(Dugum*, int);
    bool BFS(Dugum*, int);
};



void IkiliSiralamaAgaci::olustur()
{
    kok = NULL;
    dugum_sayisi = 0;
}
void IkiliSiralamaAgaci::agacKur(int* eklenecek_veri)
{
    bool eklendi = false;
    Dugum* tara;
    Dugum* yeni = new Dugum();
    tara = kok;
    yeni->veri = *eklenecek_veri;
    yeni->sol = NULL;
    yeni->sag = NULL;

    if (kok == NULL) {
        kok = yeni;
        return;
    }
    while ((tara != NULL) && (!eklendi))
    {
        if (yeni->veri < tara->veri)
        {
            if (tara->sol != NULL)
            {
                tara = tara->sol;
            }
            else
            {
                tara->sol = yeni;
                eklendi = true;
            }
        }
        else
            if (yeni->veri > tara->veri)
            {
                if (tara->sag != NULL)
                {
                    tara = tara->sag;
                }
                else
                {
                    tara->sag = yeni;
                    eklendi = true;
                }
            }
    }
}
void IkiliSiralamaAgaci::agacKapat() 
{
   
}

//void Inorder(Dugum* nptr)//inorder yazdırma
//{
//    if (nptr)
//    {
//        Inorder(nptr->sol);
//        cout << nptr->veri << endl;
//        Inorder(nptr->sag);
//    }
//}


bool IkiliSiralamaAgaci::DFS(Dugum* dugum1, int aranacak_veri)
{
    auto begin = std::chrono::high_resolution_clock::now();
    IkiliSiralamaAgaci* p;
    stack<Dugum*> yigin;
    yigin.push(kok);

    while (!yigin.empty())
    {
        dugum1 = yigin.top();
        yigin.pop();
        
        
        if (aranacak_veri == dugum1->veri)
        {
            cout << "Sonuc: Veri Bulundu" << endl;
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            gecen_sure = elapsed.count();
            return 1;//veriyi buldu 
        }

        else
        {
            if (dugum1->sag)
            {
                yigin.push(dugum1->sag);
            }
            if (dugum1->sol)
            {
                yigin.push(dugum1->sol);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    gecen_sure = elapsed.count();
    return 0;//veriyibulamadı
}

bool IkiliSiralamaAgaci::BFS(Dugum* dugum1, int aranacak_veri)
{
    auto begin = std::chrono::high_resolution_clock::now();
    IkiliSiralamaAgaci* p;
    queue<Dugum*> kuyruk;
    kuyruk.push(kok);

    while (!kuyruk.empty())
    {
        dugum1 = kuyruk.front();
        kuyruk.pop();
        
        if (aranacak_veri == dugum1->veri)
        {
            cout << "Sonuc: Veri Bulundu" << endl;
            auto end = std::chrono::high_resolution_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
            gecen_sure = elapsed.count();
            return 1;//veriyi buldu 
        }

        else
        {
            if (dugum1->sol)
            {
                kuyruk.push(dugum1->sol);
            }
            if (dugum1->sag)
            {
                kuyruk.push(dugum1->sag);
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    gecen_sure = elapsed.count();
    return 0;//veriyibulamadı
}

int main()
{
    IkiliSiralamaAgaci* agac1 = new IkiliSiralamaAgaci();
    IkiliSiralamaAgaci* agac2 = new IkiliSiralamaAgaci();
    IkiliSiralamaAgaci* agac3 = new IkiliSiralamaAgaci();

    agac1->olustur();//ağaç1 oluşturuldu(Null)
    for (int i = 0; i < UZUNLUK;i++)
    {
        agac1->agacKur(&dizi1[i]);
    }

    agac2->olustur();//ağaç2 oluşturuldu(Null)
    for (int i = 0; i < UZUNLUK;i++)
    {
        agac2->agacKur(&dizi2[i]);
    }

    agac3->olustur();//ağaç3 oluşturuldu(Null)
    for (int i = 0; i < UZUNLUK;i++)
    {
        agac3->agacKur(&dizi3[i]);
    }



    int secim_agac, arama_yontemi, aranacak_veri, temp;
    cout << "Arama yapacaginiz agaci seciniz(1,2,3): ";    
    cin >> secim_agac;

    switch (secim_agac)
    {
    case 1:
    {
        cout << "Agac 1 icin arama yontemini seciniz (DFS:1, BFS:2): ";
        cin >> arama_yontemi;
        switch (arama_yontemi)
        {
        case 1:
        {
            cout << "Agac 1 uzerinde DFS ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac1->DFS(agac1->kok, aranacak_veri);
            if (temp == 1)
            {
                cout <<"Gecen Sure: "<< gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Agac 1 uzerinde bfs ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac1->BFS(agac1->kok, aranacak_veri);
            if (temp == 1)
            {
                cout << "Gecen Sure: " << gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        default:
        {
            cout << "Hatali Secim!!" << endl;
            break;
        }
        }
        break;
    }

    case 2:
    {
        cout << "Agac 2 icin arama yontemini seciniz (DFS:1, BFS:2): ";
        cin >> arama_yontemi;
        switch (arama_yontemi)
        {
        case 1:
        {
            cout << "Agac 2 uzerinde DFS ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac2->DFS(agac2->kok, aranacak_veri);
            if (temp == 1)
            {
                cout << "Gecen Sure: " << gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Agac 2 uzerinde bfs ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac2->BFS(agac2->kok, aranacak_veri);
            if (temp == 1)
            {
                cout << "Gecen Sure: " << gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        default:
        {
            cout << "Hatali Secim!!" << endl;
            break;
        }
        }
        break;
    }

    case 3:
    {
        cout << "Agac 3 icin arama yontemini seciniz (DFS:1, BFS:2): ";
        cin >> arama_yontemi;
        switch (arama_yontemi)
        {
        case 1:
        {
            cout << "Agac 3 uzerinde DFS ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac3->DFS(agac3->kok, aranacak_veri);
            if (temp == 1)
            {
                cout << "Gecen Sure: " << gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        case 2:
        {
            cout << "Agac 3 uzerinde bfs ile arayacaginiz degeri giriniz: ";
            cin >> aranacak_veri;
            int temp = agac3->BFS(agac3->kok, aranacak_veri);
            if (temp == 1)
            {
                cout << "Gecen Sure: " << gecen_sure << endl;
            }
            if (temp == 0)
            {
                cout << "Veri bulunamadi" << endl;
            }
            break;
        }
        default:
        {
            cout << "Hatali Secim!!" << endl;
            break;
        }
        }
        break;
    }

    default:
    {
        cout << "Hatali Secim" << endl;
        break;
    }

    }
}

