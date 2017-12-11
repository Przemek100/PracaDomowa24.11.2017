FUNKCJA printf scanf
===================
Komputer byłby całkowicie bezużyteczny, gdyby użytkownik nie mógł się z nim porozumieć (tj. wprowadzić danych lub otrzymać wyników pracy programu). Programy komputerowe służą w największym uproszczeniu do obróbki danych - więc muszą te dane jakoś od nas otrzymać, przetworzyć i przekazać nam wynik.
Takie wczytywanie i "wyrzucanie" danych w terminologii komputerowej nazywamy wejściem (input) i wyjściem (output). Bardzo często mówi się o wejściu i wyjściu danych łącznie - input/output, albo po prostu I/O.
W C do komunikacji z użytkownikiem służą odpowiednie funkcje. Zresztą, do wielu zadań w C służą funkcje, które są zdefiniowane w bibliotece standartowej stdio.h. 

    #include <stdio.h>

Używając funkcji, nie musimy wiedzieć, w jaki sposób komputer wykonuje jakieś zadanie, interesuje nas tylko to, co ta funkcja robi. Funkcje niejako "wykonują za nas część pracy", ponieważ nie musimy pisać być może dziesiątek linijek kodu, żeby np. wypisać tekst na ekranie (wbrew pozorom - kod funkcji wyświetlającej tekst na ekranie jest dość skomplikowany).
## Funkcja printf()
Jest to funkcja wyjścia, zdefiniowana jest w bibliotece stdio.h służy do wypisywania danych na ekran.Jest jedną z bardziej skomplikowanych funkcji i jednocześnie jedną z  najczęściej używanych funkcji w języku C.
 Tak wygląda najprostsze użycie tej funkcji.
 
     #include <stdio.h>
      int main(void)
     {
       printf("Witaj swiecie!\n");
       return 0;
     }
Po skompilowaniu i uruchomieniu komputer wyświetli na ekranie:
    
    Witaj swiecie!
 Tekst umieszczony w cudzysłowach wewnątrz nawiasów funkcji nazywamy formatem lub tekstem sterującym, może zawierać:
− zwykłe znaki (które są po prostu kopiowane na ekran)
    
    Witaj swiecje
− znaki specyjalne:
    
    '\a' - alarm (sygnał akustyczny terminala)
    '\b' - backspace (usuwa poprzedzający znak)
    '\f' - wysuniecie strony (np. w drukarce)
    '\r' - powrót kursora (karetki) do początku wiersza
    '\n' - znak nowego wiersza
    '\"' - cudzysłów
    '\'' - apostrof
    '\\' - ukośnik wsteczny (backslash)
    '\t' - tabulacja pozioma
    '\v' - tabulacja pionowa
    '\?' - znak zapytania (pytajnik)
    '\ooo' - liczba zapisana w systemie oktalnym (ósemkowym), gdzie 'oo' należy zastąpić trzycyfrową liczbą w tym systemie
    '\xhh' - liczba zapisana w systemie heksadecymalnym (szesnastkowym), gdzie 'hh' należy zastąpić dwucyfrową liczbą w tym systemie

− kody formatujące kolejnych argumentów:

    %c − pojedynczy znak
    %s − łańcuch znaków
    %d − liczba dziesiętna ze znakiem
    %f − liczba zmiennoprzecinkowa (notacja dziesiętna)
    %e − liczba zmiennoprzecinkowa (notacja wykładnicza)
    %g − liczba zmiennoprzecinkowa (krótszy z formatów %f %e)
    %u − liczba dziesiętna bez znaku
    %x − liczba w kodzie szesnastkowym (bez znaku)
    %o − liczba w kodzie ósemkowym (bez znaku)
    l − przedrostek (long) stosowany przed: d u d u x o
 
przykładowo:
    
    int i = 23;
    printf("Liczbami naturalnymi są\n na przykład %i oraz %i.\n", 1, i);
 Na ekranie wyświetlony zostanie:
 
     Liczbami naturalnymi są 
     na przykład 1 oraz 23.
Najczęstsze użycie printf():
    
    printf("%i", i); gdy i jest typu int; zamiast %i można użyć %d
    printf("%f", i); gdy i jest typu float lub double
    printf("%c", i); gdy i jest typu char (i chcemy wydrukować znak)
    printf("%s", i); gdy i jest napisem (typu char*)
Na liście argumentów możemy mieszać ze sobą zmienne różnych typów, liczby, napisy itp. w dowolnej liczbie.Nalezy jednak pamietać żeby nie pomylić typów lub kolejności.
>Przy włączeniu ostrzeżeń (opcja -Wall lub -Wformat w GCC) kompilator powinien nas ostrzec, gdy format nie odpowiada podanym elementom.
    
    int i = 5;
    printf("%i %s %i", 5, 4, "napis"); /* powinno być: "%i %i %s" */
Istniej możliwość wyświetlenia danych przechowywanych w pamięci(buforze)
    
    printf(buf);
lub:
 
    printf("%s", zmienna);
Aby określić ilość drukowanych cyfr do kodu formatującego można
dodać kody długości:
>%Xd %X.Xf np.

    %4d − liczba dziesiętna na czterech pozycjach
    %10f − liczba rzeczywista na 10 pozycjach
    %10.2f − liczba rzeczywista na 10 pozycjach, 2 cyfry po przecinku
     %.3f − liczba rzeczywista z dokladnoscią do 3 cyfr po przecinku 

## Funkcja scanf()
Jest to funkcja wejścia,zdefiniowana jest w bibliotece stdio.h służy do przekazania znaków z klawiatury do  zadeklarowanej zmiennej w pamięci.
Na początku używamy słowa kluczowego scanf,  a następnie otwieramy nawias. W cudzysłowiu ustalamy typ zmiennej tekst sterujący (format), a następnie po przecinku wprowadzamy nazwę zmiennej, do której chcemy przypisać wartość, poprzedzoną znakiem "&".

    scanf ( "tekst_sterujący" , &adres_1 , &adres_2 ,  . . .  ) ;
Kody formatujące podobne, jak dla printf():

    %c    -    pojedynczy znak
    %s    -    łańcuch znaków
    %d    -    liczba dziesiętna ze znakiem
    %f  lub  %e    -    liczba zmiennoprzecinkowa
    %u    -    liczba dziesiętna bez znaku
    %x    -    liczba w kodzie szesnastkowym (bez znaku)
    %o    -    liczba w kodzie ósemkowym (bez znaku)
    l    -    przedrostek stosowany przed:  d  u  x  o  (long int)
    l    -    przedrostek stosowany przed:  f  e  (double)
    L    -    przedrostek stosowany przed:  f  e  (long double)
 Przykładowe uzycie funkcji scanf() i printf():
    
    #include<stdio.h>                             
    int main()                                        
    {
    char imie[20];
    printf("Podaj swoje imie \n");     
    scanf("%s", &imie);                       
    printf("Witaj %s!", imie);               
    return 0;
    } 
Program wypisze

    Podaj swoje imie
Po wpisaniu np. Marek i zatwierdzenia enterem komputer przypisze Marek do zmiennej imie i wyoisze na ekranie:

    Witaj Marek!
