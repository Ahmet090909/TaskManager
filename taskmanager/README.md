# TaskManager – C++ / Qt Taakbeheer

## Overzicht

Dit project is een **taakbeheerprogramma** geschreven in moderne C++ met een **Qt GUI**.

Het doel is vooral om:

- correcte **Object Georiënteerde Programmatie (OOP)** te tonen,
- een duidelijke **scheiding tussen logica en UI** te hebben,
- basisconcepten zoals **inheritance**, **polymorfisme**, **abstracte basisklassen**, **templates**, **lambda’s** en **exception handling** te gebruiken,
- én de taken visueel en gebruiksvriendelijk te beheren in een grafische interface.

De gebruiker kan o.a.:

- simpele taken aanmaken,
- taken met een vervaldatum (“timed tasks”) aanmaken,
- taken bekijken in een lijst,
- taken markeren als klaar,
- taken verwijderen,
- taken opslaan naar en laden uit een tekstbestand.

---

## Functionaliteit

In de GUI kun je:

- **Titel** invullen (tekstveld rechtsboven)
- **Beschrijving** invullen (groter tekstvak eronder)
- **Prioriteit (0–10)** instellen (spinbox)
- **Vervaldatum** invullen als tekst (bijv. `2025-12-31 23:59`)

Daaronder staan knoppen:

- **“Voeg simpele taak toe”**  
  → maakt een `SimpleTask` zonder extra velden.
- **“Voeg timed taak toe”**  
  → maakt een `TimedTask` met extra veld `vervaldatum`.
- **“Verwijderen”**  
  → verwijdert de momenteel geselecteerde taak in de lijst.
- **“Markeer klaar”**  
  → zet de geselecteerde taak op “done” (klaar).
- **“Opslaan”**  
  → opent dialoog om alle taken naar een tekstbestand te schrijven.
- **“Laden”**  
  → opent dialoog om taken uit een eerder opgeslagen tekstbestand te laden.

Links zie je een **lijst met taken**.  
Elke regel toont:

- type (`[Simpel]` of `[Timed]`)
- ID
- prioriteit
- `[KLAAR]` als de taak gedaan is
- titel, beschrijving
- bij een timed taak: de vervaldatum

---

## Projectstructuur

De belangrijkste bestanden:

```text
TaskManager/                ← Git repository root
  CMakeLists.txt            ← CMake configuratie
  include/
    Task.h                  ← abstracte basisklasse voor taken
    SimpleTask.h            ← afgeleide klasse voor simpele taken
    TimedTask.h             ← afgeleide klasse voor timed taken
    TaskManager.h           ← klasse die alle taken beheert
    MainWindow.h            ← Qt hoofdvenster (GUI)
  src/
    main.cpp                ← startpunt, maakt QApplication/MainWindow
    Task.cpp
    SimpleTask.cpp
    TimedTask.cpp
    TaskManager.cpp
    MainWindow.cpp
    MainWindow.ui           ← Qt Designer bestand (layout + styling)
