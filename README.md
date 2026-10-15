## Bezprzewodowe Guziki Do Familiady


Hardware'owy system przycisków turniejowych (w stylu "Familiady") zbudowany w oparciu o mikrokontrolery Arduino i komunikację radiową 2.4 GHz. System bezbłędnie rozstrzyga, który z graczy zgłosił się jako pierwszy, blokując pozostałe przyciski.

![Animacja Działania](media/dzialanie.gif)

## Wykorzystany Hardware

System opiera się na inteligentnych węzłach. **Główny, czerwony przycisk (Master)** pełni podwójną rolę: służy do zgłaszania się i jednocześnie jest "mózgiem" zarządzającym całą grą. Pozostałe przyciski działają jako urządzenia podrzędne (Slaves). Do budowy każdego z nich użyto:
* **Mikrokontroler:** Arduino Nano (ATmega328P)
* **Komunikacja:** Moduł radiowy nRF24L01 (komunikacja po magistrali SPI)
* **Zasilanie:** Pakiet 2x18650 (mobilność i długi czas działania)


## Logika działania i wyzwania techniczne

Kluczowym problemem w tego typu systemach jest opóźnienie oraz jednoczesne wciśnięcie przycisków. Zostało to rozwiązane poprzez:
1. **Architekturę Master-Slave w jednym z węzłów:** Czerwony guzik (Master) nasłuchuje zgłoszeń od pozostałych przycisków i przetwarza je w czasie rzeczywistym. Decyduje, kto wcisnął przycisk jako pierwszy, a następnie wysyła sygnał blokujący do reszty uczestników.
2. **Debouncing sprzętowy/programowy:** Zabezpieczenie przed "drganiem styków" mechanicznych przycisków, aby jedno uderzenie nie było rejestrowane jako seria kliknięć.
3. **Zarządzanie stanem gry:** Główny przycisk jest odpowiedzialny za resetowanie rundy i przywracanie pozostałych guzików do stanu gotowości.

## Galeria (Wnętrze i elektronika)

![Animacja Działania](media/bebechy.gif)

## Jak uruchomić kod
W repozytorium znajdują się dwa warianty kodu:
* `master_czerwony.ino` - kod wgrywany do głównego (czerwonego) guzika, zawierający logikę decyzyjną.
* `slave_zwykly.ino` - kod wgrywany do pozostałych przycisków graczy.

Wymagane biblioteki (dostępne w Menedżerze Bibliotek Arduino IDE):
* `RF24` 
* `SPI` 
