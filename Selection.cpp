#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;

string Jeux[50];
int NB_Jeux[50];
int NB_Ligne = 0;
int y = 0;

void menu();
void Delete();


void ecriture(){
    ofstream input("fichier.txt", ios::in);
    string ajouter = "";
    for (size_t h = 0; h < y; h++)
    {
        if (Jeux[h] == "")
        {
            Jeux[h] = Jeux[h+1];
            Jeux[h+1] = ""; 
        }
        
    }
    
    for (size_t t = 0; t < NB_Ligne+2; t++)
    {
        if (Jeux[t] != "")
        {
            ajouter += Jeux[t];
            ajouter += ":";
            int a = NB_Jeux[t];
            stringstream ss;
            ss << a;
            string straze = ss.str();
            ajouter += straze;
            input << ajouter << endl;
            ajouter = "";
        }
        else if (Jeux[t]=="")
        {
            input << "" << endl;
        } 
    }
    
}

void script(int a){

    switch (a)
    {
    case 0:
        system("cls");
        break;

    case 1:
        cout << "Bienvenue dans le Menu de Jeu." << endl;
        cout << "Vous avez plusieurs choix :" << endl;
        cout << "- 1 : Jeu Aleatoire" << endl;
        cout << "- 2 : Modifier vos jeux" << endl;
        cout << "- 3 : Options" << endl;
        cout << "- 4 : Quitter l'aplication" << endl;
        break;

    case 2:
        cout << "Dans le menu de modification, il y a plusieurs choix ;" << endl;
        cout << "- 1 : Ajouter un jeu" << endl;
        cout << "- 2 : Modifier un jeu" << endl;
        cout << "- 3 : Supprimer un jeu" << endl;
        cout << "- 4 : Retour" << endl;
        break;

    case 3:
        cout << "Veuillez entrer un nom de jeu" << endl;
        break;

    case 4:
        cout << "Quel jeu voulez vous choisir ? " << endl;
        for (size_t i = 0; i < y; i++)
        {
            cout << i+1 << " - " << Jeux[i] << endl;
        }
        cout << " - ";
        break;

    case 5:
        cout << "Les parametres sont tres simple il y a des nombres a coter de chaque options il suffit de rentrer le nombre associer" << endl;
        cout << "NE SOYEZ PAS BETE NE RENTRER PAS DES CHOSE ALEATOIRE, merci" << endl;
        cout << "" << endl;
        cout << "" << endl;
        Sleep(1000);
        cout << "Il y a en plus quelque specificité." << endl;
        cout << "Une fois un choix fait dans le menu il n'y a pas de retour arriere. Il faut allez au bout." << endl;
        cout << "Ensuite le fichier texte peu prendre de la place dans ce cas je vous invite a l'ouvrir et supprimer manuellement les lignes inutiles" << endl;
        cout << "" << endl;
        Sleep(2000);
        cout << "Voila c'est tout ce qu'il y a a comprendre." << endl;
        cout << "Ducoup compris ?" << endl;
        cout << " 1 - Oui     2 - Non" << endl;
        cout << " - ";
        break;

    case 6:
        cout << "NON MAIS TU LE FAIS EXPRES CE N'EST PAS POSSIBLE" << endl;
        cout << "IL EST BETE CE GOSSE OU QUOI ??" << endl;
        cout << "QUI MA DONNEZ UN INCAPABLE PAREIL POUR NE PAS COMPRENDRE CA !!" << endl;
        cout << "Allez on recommence" << endl;
        break;


    default:
        break;
    }


}

void lecture(){
    ifstream lire;
    lire.open("fichier.txt");
    y = 0;
    NB_Ligne = 0;

    while (!lire)
    {
        cout << "Vous devez relancer et ajouter des jeux" << endl;
        ofstream f("fichier.txt");
    }

    string ligne;
    while (getline(lire, ligne))
    {
        NB_Ligne++;
        string decoder = ligne;
        if (ligne != "")
        {
            int count = 0;
            string nombre_char;
            string a_tester;
            int nombre_a_tester = 0;
            bool condition = false; 
            while (count < decoder.length())
            {
                
                if (decoder[count] != ':' && condition == false)
                    a_tester += decoder[count];
                else
                    condition = true;

                if(condition == true)
                    nombre_char += decoder[count];

                count++;
            }

            for (int i = 1; i < nombre_char.length(); i++)
            {
                nombre_a_tester = nombre_a_tester * 10;
                nombre_a_tester +=  nombre_char[i] - '0';
            }
            
            Jeux[y] = a_tester;
            NB_Jeux[y] = nombre_a_tester;
            
            y++;
        }
    }
    
    cout << "Y = " << y << endl;
    cout << "L = " << NB_Ligne << endl;

}

void choix(int NB_Jeux[], int y2){
    int max = 0;
    int somme = 0;
    int NB_Jeux2[y];

    for (size_t i = 0; i < y; i++)
    {
        NB_Jeux2[i] = NB_Jeux[i];
    }
    

    for(int k = 0; k < y2 ; k++){
        if (NB_Jeux2[k] > max){
            max = NB_Jeux2[k]; //détermine le max
        }
    }

    for(int i = 0; i < y2 ; i++){
        NB_Jeux2[i] = (int)floor((max*10) / NB_Jeux2[i]);
        somme += NB_Jeux2[i]; //ajuste les poids
    }

    int listRandom[somme];
    srand((unsigned int)time(NULL));
    int aleatoire = rand() % somme;
    
    
    int t = 0;
    int j;
    for(j = 0; j < y2 && t < aleatoire; j++){
        while(NB_Jeux2[j] > 0 && t < aleatoire){
            NB_Jeux2[j]--;   //création de la liste des index "pondéré"
            t++;
        }
    }

    cout << "Vous allez jouer a " << Jeux[j] << endl;
    Sleep(5000);
    NB_Jeux[j]++;

    
}

void Ajout(){
    string nom_jeux;
    script(3);
    cout << " - ";
    cin >> nom_jeux;
    cout << nom_jeux << endl;
    Jeux[y] = nom_jeux;
    NB_Jeux[y] = 1;
    y++;

    ecriture();

}

void var_changement(int i){
    string changement = Jeux[i-1];
    cout << "Vous avez choisi " << changement << endl;
    cout << "Remplacer le par : ";
    string sx;
    cin >> sx;
    cout << "Vous voulez remplacer " << changement << " par " << sx << endl;
    int x;
    cout << " 1 - Oui         2 - Non" << endl;
    cin >> x;
    if (x==1)
    {
        Jeux[i-1] = sx;
        ecriture();
    }
    else
        var_changement(i);
    
}

void Modif_Jeu(){
    script(4);
    int x;
    cin >> x;
    if ( x<=y )
    {
    }
    else{  
        script(0);
        cout << "Votre reponse est innaceptable" << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        Modif_Jeu();
    }
    for (size_t i = 0; i < NB_Ligne+1; i++)
    {
        if (x == i)
            var_changement(i);   
    }
    menu();
}

void Verif_Delete(int i){
    string changement = Jeux[i-1];
    cout << "Vous voulez supprimer " << changement << endl;
    int x;
    cout << " 1 - Oui         2 - Non" << endl;
    cin >> x;
    if (x==1)
    {        
        Jeux[i-1] = "";
        ecriture();
        lecture();
    }
    else{
        Delete();
    }
}

void Delete(){
    script(4);
    int x;
    cin >> x;
    if ( x<=y+1 )
    {
        for (size_t i = 0; i < y+1; i++)
        {
            if (i == x)
            {
                Verif_Delete(i);
            }
        }
    }
    else{  
        script(0);
        cout << "Votre reponse est innaceptable" << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        Delete();
    }
}

void modification(){
    script(2);
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        Ajout();
        menu();
        break;
    case 2:
        Modif_Jeu();
        break;
    case 3:
        Delete();
        menu();
        break;
    case 4:
        menu();
        break;
    
    default:
        script(0);
        cout << "Votre reponse est innaceptable" << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        modification();
        break;
    }


}

void param(){
    script(0);
    script(5);
    int azer = 0;
    cin >> azer;
    switch (azer)
    {
    case 2:
        script(0);
        script(6);
        Sleep(10000);
        param();
        break;
    
    default:
        break;
    }    
}

void menu(){
    script(0);
    int x = 0;
    script(1);
    cout << " - ";
    cin >> x;
    switch (x)
    {
    case 1:
        choix(NB_Jeux, y);
        ecriture();
        lecture();
        menu();
        break;
    case 2:
        script(0);
        modification();
        break;
    case 3:
        param();
        menu();
        break;
    case 4:
        break;
    
    default:
        script(0);
        cout << "Votre reponse est innaceptable" << endl;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
        }
        menu();
        break;
    }
}



int main()
{
    lecture();
    menu();
    return 0;

}