# Qui veut gagner des millions ?

Un quiz en langage C inspiré du jeu télévisé. Il se joue dans le terminal. Le but est de répondre correctement aux questions pour aller jusqu’à la 15ᵉ.

## Règles du jeu

1. Lis la question et saisis la réponse de ton choix.
2. Chaque bonne réponse te fait avancer d’une question. Une mauvaise réponse met fin à la partie.
3. La progression est marquée par trois paliers.

| Question | Progression |
| --- | --- |
| 5 | Premier palier |
| 10 | Deuxième palier |
| 15 | Dernier palier |

Lorsque le jeu affiche une invite `Y/N`, saisis `Y` pour oui ou `N` pour non.

## Compiler et lancer le jeu

Il te faut un compilateur C, par exemple GCC. Ouvre un terminal dans le dossier du projet. Les commandes ci-dessous supposent que le jeu est dans un seul fichier appelé `main.c`. Remplace ce nom par celui de ton fichier si besoin.

### Linux ou WSL

```bash
gcc -Wall -Wextra main.c -o millions
./millions
```

### Windows avec GCC dans PowerShell

```powershell
gcc -Wall -Wextra main.c -o millions.exe
.\millions.exe
```

## Notions de C utilisées

- **Structures et tableaux** pour organiser les données du quiz.
- **Boucles et conditions** pour enchaîner les questions et vérifier les réponses.
- **`toupper()`** pour convertir les lettres saisies en majuscules.
- **Codes ANSI** pour afficher des couleurs dans un terminal compatible.

