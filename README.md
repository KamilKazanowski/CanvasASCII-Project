# Program CanvasASCII

Program CanvasASCII używa obiektów klasy CanvasASCII zawierających wskaźniki na tablice 2d alokowane dynamicznie, które można następnie zapisywać figurami geometrycznymi rodziny klas Figure. Obsługa programu odbywa się za pomocą pliku wejściowego, a skutkiem jego działania jest utworzenie pliku wyjściowego *.txt* z tablicą zapisaną figurami.

Ściągnąć go można z mojego GitHuba (znajduje się też tam przykładowy plik wejściowy). Pliki programu mają rozszerzenia *.cpp* i *.h*, a pliki wyjściowe/wejściowe *.txt*. Wszystko należy umieścić w jednym folderze. Kompilujemy komendą

> g++ main.cpp canvas.cpp figure.cpp

a następnie program uruchamiamy z nazwą pliku wejściowego jako argumentem. Przykładowo

> /.a.exe inputfile.txt

Po wykonaniu programu w folderze, w którym znajduje się program, utworzony zostanie plik wyjściowy

## Opis klas

### Rodzina klas Canvas:

Implementacja tej rodziny klas jest zapisana w plikach *canvas.cpp* i *canvas.h*. *Canvas* jest klasą abstrakcyjną, z której dziedziczy klasa *CanvasASCII*. *CanvasASCII* posiada metodę *print* wypisującą tablicę w terminalu (użytkownik może chcieć ją dopisać na końcu pliku main).

### Rodzina klas Figure:
Implementacja tej rodziny klas jest zapisana w plikach *figure.cpp* i *figure.h*. *Figure* jest klasą abstrakcyjną, z której dziedziczą klasy *Rectangle*, z której dziedziczy klasa *Square*, oraz *Circle*.  Klasy te są zaprzyjażnione z klasą *CanvasASCII*. Dzięki temu posiadane przez nie metody *draw* mogą wprowadzać zmiany na tablicy klasy *CanvasASCII* zgodne z danymi przechowywanymi w polach klas.  

Pole klasy *Figure* posiada współrzędne figury (interpretowane jako lewy dolny róg w przypadku *Rectangle* lub środek koła w przypadku *Circle*) oraz znak należenia do figury.  Pole klasy *Rectangle* posiada dodatkowo wymiary prostokąta, a pole klasy *Circle* promień okręgu. W kodzie programu konsekwentnie stosuje się konwencję, zgodnie z którą najpierw podawane są współrzędne "horyzontalne", a następnie "wertykalne".

## Obsługa programu za pomocą pliku wejściowego

Obsługa programu odbywa się za pomocą pliku wejściowego, który należy umieścić w folderze z plikami progamu oraz którego nazwę należy podać jako argument przy uruchamianiu programu (zgodnie z instrukcją opisaną powyżej). Z pliku tego wczytywane będą dane tablicy oraz figur przy pomocy operatora *>>* obiektów klasy *std::ifstream*, dlatego muszą one być oddzielone spacją. Pierwsze dwie liczby będą kolejno szerokością i wysokością tablicy. Kolejny string jest nazwą pliku wyjściowego (należy wprost napisać, że ma on mieć rozszerzenie *.txt*, jak w załączonym przykładzie). Pierwszy znak następnego stringa będzie pełnił funkcję elementu tablicy niezapisanego żadną figurą. Aby ustawić go na spacę należy wpisać space. Następnie iterator ustawi się na pierwsze słowo kluczowe rectangle, square lub circle. i wczyta wszystkie stringi, aż do następnego słowa kluczowego. Wczytane zostaną do obiektu odpowiedniego typu w kolejności współrzędna horyzontalna, wertykalna, własności figury (długość horyzontalna prostokąta, długość wertykalna prostokąta; długość boku kwadratu; promień), znak należenia do figury.  Niemożliwe jest utworzenie tablicy, której długość któregoś z boków nie należy do przedziału [3, 50].
