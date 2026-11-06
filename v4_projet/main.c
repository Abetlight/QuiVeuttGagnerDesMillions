#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void affQuestionsReponses (int nb, char txt[], char chx[] )
{
    printf("\n \33[1;35m*******Question numero %d:******\n\n\33[0m%s\n\n", nb,txt);
    printf ("\33[1;36mChoisis ta reponse entre:\n\n\33[0m\33[1;37m%s\33[0m\n\n", chx);
}

void affGains(int nbQ, int nb5, int nb10)
{
    if (nbQ<=5)
        {
        printf("\n\33[1;32mPerdu ! Tu reparts avec \33[1;41m0$\33[0m \33[1;32m!\33[0m\n" );
        }
    else if(nbQ>5 && nbQ<=10)
        {
        printf("\n\33[1;32mPerdu ! Tu reparts quand meme avec \33[1;41m%d$\33[0m \33[1;32m!\33[0m\n", nb5 );
        }
    else
        {
        printf("\n\33[1;32mPerdu ! C'est dommage ! Mais \33[1;41m%d$\33[0m \33[1;32mc'est pas rien !\33[0m\n", nb10);
        }

}

struct quiVeutDesMillions   // Déclaration de la structure
{
   int questions; //num questions
   char text[200]; // Les questions
   char choix[500]; // Les reponses
   char bonneRep; // La bonne rep
   int gains; // Montant win
};
int main()
{
     char apro;
     char reponseJ;


    printf ("\n\33[1;34;5m================Bienvenue a QuiVeutGagneDesMillions!================\33[0m\n\n\n");
    printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: "); // Validation d'entrée dans le game.
    scanf(" %c", &apro); // l'espace annule le dernier char invisible.
    apro=toupper(apro);

    while (apro != 'Y')
    {
      printf ("\33[1;33m******Pret a commencer?******\33[0m\n \33[1;36mY ou N: "); // 'Y' pour continuer, sinon repose la question.
      scanf(" %c", &apro);
      apro=toupper(apro);
    }

      printf("\n\33[1;33m*******C'est parti !*******\33[0m\n\n");

    struct quiVeutDesMillions jeux[15]=
    {
        {1,"Couleur du soleil?","A : Vert\nB : Bleu\nC : Jaune\nD : Violet",'C',100},
        {2,"Combien de cotes un triangle ?","A : 3\nB : 4\nC : 5\nD : 6",'A',200},
        {3,"Quel animal miaule?","A : Le chien\nB : Le cheval\nC : La vache\nD : Le chat",'D',300},
        {4,"La planete rouge?","A : Venus\nB : Mars\nC : Jupiter\nD : Saturne",'B',500},
        {5,"Minutes compte une heure?","A : 30\nB : 60\nC : 90\nD : 100",'B',1000},
        {6,"Le plus grand ocean ?","A : Atlantique\nB : Indien\nC : Pacifique\nD : Arctique",'C',2000},                                                                            // Déclaration de la variable jeux.
        {7,"Qui a peint la Joconde?","A : Leonard de Vinci\nB : Picasso\nC : Monet\nD : Van Gogh",'A',4000},
        {8,"Quel pays a pour capitale Tokyo?","A : La Chine\nB : La Coree du Sud\nC : La Thailande\nD : Le Japon",'D',8000},  // Structure jeux.
        {9,"Quel organe pompe le sang?","A : Le foie\nB : Le poumon\nC : Le coeur\nD : Le rein",'C',12000},
        {10,"Symbole chimique de l or?","A : Ag\nB : Au\nC : Fe\nD : Cu",'B',24000},
        {11,"Qui a ecrit Les Miserables?","A : Victor Hugo\nB : Emile Zola\nC : Moliere\nD : Albert Camus",'A',36000},
        {12,"Os possede habituellement un adulte?","A : 106\nB : 156\nC : 206\nD : 306",'C',72000},
        {13,"Unite de la resistance electrique?","A : Le volt\nB : Le watt\nC : L'ampere\nD : L'ohm",'D',150000},
        {14,"La capitale de l'Italie?","A : Rome\nB : Madrid\nC : Paris\nD : Berlin",'A',300000},
        {15,"Qui est le meilleur?","A : Sylvain\nB : Roberto!\nC : Jerome\nD : La reponse D",'B',1000000}
    };

    for (int i=0; i<15; i++)   // Nombre de questions est définies, utilisation du for.
    {
        affQuestionsReponses (jeux[i].questions, jeux[i].text, jeux[i].choix);
        scanf(" %c", &reponseJ);
        reponseJ = toupper(reponseJ); // Convertion MIN en MAJ.

        while (reponseJ != 'A' && reponseJ !='B' && reponseJ !='C' && reponseJ !='D') // La réponse ne peut pas être diff de abc ou d, sinon question reposée.
        {
         affQuestionsReponses (jeux[i].questions,jeux[i].text, jeux[i].choix);
         scanf(" %c", &reponseJ);
         reponseJ = toupper(reponseJ);
        }


       if (jeux[i].bonneRep == reponseJ)
       {
           printf("\n\33[1;32mBonne reponse ! Tu as passe le palier des\33[0m \33[1;41m%d$\33[0m\n", jeux[i].gains); // Bonne rep => question suivante.

       if (jeux[i].questions == 5 || jeux[i].questions == 10)
            {
           printf("\33[1;33m\n******Tu as le choix de t'arreter ?*******\33[0m\n \33[1;36mY ou N\33[0m\n"); // Choix stop ou continue sur q5 et q10.
           scanf(" %c", &apro);
           apro=toupper(apro);

           while (apro != 'Y' && apro != 'N' )
           {
           printf("\33[1;33m\n******Tu as le choix de t'arreter ?*******\33[0m\n \33[1;36mY ou N\33[0m\n"); // rep ne peut etre diff de Y ou N.
           scanf(" %c", &apro);
           apro=toupper(apro);
           }

           if (apro == 'Y')
                {
                printf("\33[1;32m====== BRAVO TU AS GAGNE \33[1;41m%d $\33[0m\33[1;32m ======\33[0m\n", jeux[i].gains); // action selon  la rep.
                break;
                }
            if (apro == 'N')
                {
                printf("\n\33[1;33mTres bien on continu !\33[0m\n");
                }
            }
        if (jeux[i].questions == 15) // Mess si derniere quest ok.
            {
              printf("\n\n\n\33[1;32;5m======== FELICITATION TU VIENS DE GAGNE QuiVeutGagneDesMillions! ET \33[1;41;5m%d$\33[0m \33[1;32;5m!!! ========\33[0m\n\n\n", jeux[14].gains);
            }

         }
         else
         {
         affGains(jeux[i].questions, jeux[4].gains, jeux[9].gains);  // gains attribué si mauvaise reponse, selon la question.
         break;
         }
    }
    return 0;
}
