#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <iostream>
#include <string>

/* Copie d'un fichier avec les primitives systèmes open, read, write*/
/* Nicolas Louvet, Laure Gonnord pour LIFASR5, 2019/20*/

using namespace std;

#define LEN 4096

// Fonction d'aide en cas de mauvais appel du programme
void print_usage(const string &name)
{
    cerr << "Usage : " << name << " source destination" << endl;
}

int main(int argc, char *argv[])
{
    char buf[LEN], *p;
    int fdin, fdout;
    int nbrd, nbwr, nbrem;

    if (argc < 3)
    {
        print_usage(argv[0]);
        return 1;
    }

    // Ouverture du fichier source dont le nom est argv[1]
    if ((fdin = open(argv[1], O_RDONLY)) == -1)
    {
        cerr << "Erreur : " << strerror(errno) << endl;
        return 1;
    }

    // ouverture du fichier destination dont le nom est argv[2]
    // man open (section "Linux Programmer's Manual") pour les options
    if ((fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    {
        cerr << "Erreur : " << strerror(errno) << endl;
        close(fdin);
        return 1;
    }

    do
    {
        nbrd = read(fdin, buf, LEN);
        if (nbrd == -1)
        {
            cerr << "Erreur : " << strerror(errno) << endl;
            return 1;
        }
        nbrem = nbrd; //nbrem est le nb d'octet restant
        p = buf;
        while (nbrem > 0)
        {
            cout << "Nombre d'ocets restant à écrire : " << nbrem << endl;
            //écriture dans le fichier (la copie)
            nbwr = write(fdout, buf, nbrem);
            if (nbwr == -1)
            {
                cerr << "Erreur : " << strerror(errno) << endl;
                return 1;
            }
            nbrem -= nbwr;
            p = p + nbwr;
        }

    } while (nbrd > 0);

    // MODIFIER ICI
    close(fdin);
    close(fdout);

    return 0;
}
