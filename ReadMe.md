# DFS-BFS in Binary Search Tree

## Proje Amacı
İkili sıralama ağacı oluşturulup 3 adet dizi entegre edilecektir. Ve daha sonra DFS(Depth first search) ve BFS(Breadht first search) algoritmaları ile arama işlemleri yapılacaktır. Temel amaç DSF ve BSF için hangi sıralama ağaçlarının (Küçükten büyüğe sıralı veriler - Büyükten küçüğe sıralı veriler - Karışık veriler) uygun olduğunu öğrenmektir.
*** 
## Veri Yapıları ve Değişkenler
1. Ağaç: Ağaç veri yapısı ikili sıralı ağaç veri yapısı olarak kullanılmıştır. Yani veriler sürekli olarak sol tarafa küçük, sağ tarafa büyük olarak eklenecektir. Ve herhangi bir düğümün derecesi 2’den fazla olamaz (ikili ağaç). Oluşturulması ise [ekran görüntüsündeki](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/AğaçYapisi.png) gibidir.

2. DFS: DFS yani ilk derinlik arama, derinlik öncelikli arama anlamına gelmektedir. Aramaya kök ile başlar ve ardından ağacın daha derinlerine inerek düğümleri araştırır. Çocuğu olmayan bir düğümle karşılaşıncaya kadar derinlemesine araştırır. Ayrıca DFS için hazır yığın veri yapısını kullanıyoruz. (Zaman ölçmek için chrono kütüphanesinin kodları da bulunmaktadır).
3. BFS: BFS yani ilk genişlik arama, genişlik öncelikli arama tipidir. BFS arama da kök düğümle başlar ve bir sonraki derinlik seviyesindeki düğümlere geçmeden önce, mevcut derinlikteki düğümleri araştırır. Aramayı satır-satır yapar şeklinde de düşünebiliriz. Ayrıca BFS için hazır kuyruk veri yapısını kullanıyoruz. (Zaman ölçmek için chrono kütüphanesinin kodları da bulunmaktadır).
***
## Program Akışı
1. İlk olarak IkiliSiralamaAgaci tipinde agac1-2-3 şeklinde bellekten yer ayırıyoruz. Daha sonra agacx->oluştur(); ile ağacımızı oluşturuyoruz ve sırasıyla FOR döngüleri ile dizileri ağaçlarımızın içine [agacKur](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/AğaçOluştur.png) fonksiyonu ile sıralı ve ikili ağaç olacak şekilde ekliyoruz.  
2. Devamında ise Switch-Case yapısı ile arama yapılacak ağacı, arama tipini(DFS ve BFS) ve veriyi seçiyoruz. Seçilen ağaç, arama tipi ve veriye göre değişen zamanı şu şekilde ekranda görüyoruz. 
* [1](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/1.png)
* [2](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/2.png)
* [3](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/3.png)
* [4](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/4.png)
* [5](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/5.png)
* [6](https://raw.githubusercontent.com/Alparslan524/DFS-BFSinBinarySearchTree/main/EkranGoruntuleri/6.png)
***
## Sonuç
1070 verisini aradığımızda;
1.	ağaçta BFS’nin daha hızlı olduğunu,
2.	ağaçta DFS’nin daha hızlı olduğunu,
3.	ağaçta DFS’nin daha hızlı olduğunu,
görüyoruz. 

3004 verisini aradığımızda;
1.  ağaçta DFS’nin daha hızlı olduğunu,
2.	ağaçta BFS’nin daha hızlı olduğunu,
3.	ağaçta DFS’nin daha hızlı olduğunu,
görüyoruz.

1070 verisi 1. Ağaçta başlarda, 2. Ağaçta ise sonlarda yer alıyor.  Bu yüzden 1070 verisi, 1. Ağaçta, 2. Ağaçtan arama türü fark etmeksizin daha hızlı bir şekilde bulunuyor.
Aynı durum 3004 verisinde de geçerli. 3004 verisi 2. Ağaçta başlarda, 1. Ağaçta ise sonlarda yer alıyor.  Bu yüzden 3004 verisi, 2. Ağaçta, 1. Ağaçtan arama türü fark etmeksizin daha hızlı bir şekilde bulunuyor.
3. Ağaca gelindiğinde ise işler karışıyor. Verinin yerine göre arama hızı değişiyor.
***
## Kullanılan Diller
* C++
***


# Alparslan Aydoğan
- [GitHub](https://github.com/Alparslan524)
- [Linkedin](https://www.linkedin.com/in/alparslan-aydoğan-6038771bb/)
***
