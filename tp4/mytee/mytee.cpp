#include <iostream>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#define LEN 4096

int main(int argc, char **argv)
{
    int fdin, fdout;
    char buf[LEN];

    if (argc != 2)
    {
        cerr << "Erreur, il ne doit y avoir que 1 paramètre" << endl;
        return 1;
    }

    int nbrd = read(0, buf, LEN);
    cout << "Nombre de caractère lu : " << nbrd << endl;

    if (fdout = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR) == -1)
    {
        cerr << "Erreur : " << strerror(errno) << endl;
        return 1;
    }

    cout << "contenu du buffer : " << buf << endl;


    cout << endl;

    int nbwrd = write(fdout, buf, nbrd);
    cout << "Nombre de caractères écris :" << nbwrd << endl;


    close(fdout);

    return 0;
}
