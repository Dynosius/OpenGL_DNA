# OpenGL_DNA - Dino Kralj


[Github link]: https://github.com/Dynosius/OpenGL_DNA  

Prilažem svoj kod za DNA molekulu iz zadatka 2.  

Ovaj program je produkt otprilike 6 dana višesatnog istraživanja, trial&error postupaka,  
te malo pomoći i feedbacka od prijatelja i kolega.  
***
## Proces izrade

Sama izrada je započela proučavanjem same ideje toga što se treba napraviti, iz koje je proizašao  
zaključak da treba odrediti spirale. Uz cijelo popodne mozganja i isprobavanja, pomoć sam našao u  
[prezentaciji]: http://www.stevenstanek.com/CS/OpenGL/OpenGL_Pres_Latest.pdf  

U to vrijeme sam koristio primitivne placeholder perspektivne projekcije iz OpenGL Redbooka, koje  
su se kasnije pokazale vrlo neprikladne za moj primjer. Konkretno, s depth bufferom, s kojim mi je na kraju pomogao kolega Dizdar (zahvaljujem).  

Idućih par dana sam proveo čitajući i pokušavajući shvatiti kako funkcionira perspektiva u OpenGL-u,  
i uspio sam ju postaviti, na *možda i nekonvencionalan* način, koristeći z-os za up vector.  


Nakon toga, trebalo je izmisliti nekakvu vizualnu reprezentaciju linija.  
S obzirom na moje neiskustvo, većina koda je možda "blesava" za nekog iskusnijeg, no meni je radio
ono što sam zamislio.  

Napisao sam funkcije **drawOutline()** (koja crta helix-e) i **drawLine()** (koja crta veze između tih helixa)  
te uz malo sreće dobio oblik kojim mogu demonstrirati tu molekulu u *"3d"* obliku.  
Vrijednosti unutar tih funkcija su izabrane trial&error metodom, da bi se dobio *najljepši* oblik  
te molekule koji sam mogao izvesti.  

***
Za animacije sam si pomogao gledanjem u template kodove s vježbi, i korištenjem funkcije **glutTimerFunc()** uspio napraviti   animaciju. Koristio sam globalnu varijablu **temp** kao primitivan način ograničavanja animacije u *zoom()* metodi.   
*rotate()* metoda ima mogućnost neograničene vrtnje, tako da ako vam je zabavno, slobodno pritišćite button za pokretanje   rotacije.

Za kraj sam pokušao dodati lighting efekte, koje sam kopirao s Redbooka, jer nisam bio siguran kako točno rade, i uz malo   refaktoriranja, dobio lighting na svojoj DNA molekuli. S obzirom da sam koristio primitive *GL_LINE_STRIP* i *GL_LINES*, nisam  točno znao na kraju svog programa kako dodati normale na vektore, pa sam se goristio funkcijom glEnable(GL_NORMALIZE); da mi  OpenGL automatski normalizira svaki vektor.   

## Upute korištenja

Program ima mappane keyeve "ESC", "Q" i "A".  
ESC i Q - izlaz iz programa.  
A - pokretanje animacije.  

Nije potrebno pisati nikakve argumente. Ukoliko ih ima, samo mijenjate ime prozora.  

***
## Zaključak

Sve u svemu, ovo je bilo vrlo poučno iskustvo koje me uvjerilo da želim dalje proučavati računalnu grafiku, sukladno s mojom željom da budem game developer.   

Svjestan sam nedostataka svog softwarea, ali sam ujedino i zadovoljan svojim radom, i stečenim iskustvom iz ovog projekta.   

Vrlo rado ću poslušati kritike i savjet za daljnim napretkom.  
