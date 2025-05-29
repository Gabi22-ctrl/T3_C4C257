#include <stdio.h>
#include <ctype.h>

//esNumero revisa si una linea tiene solo numeros
int esNumero(char linea[]) {
    int i = 0; //contador para revisar por caracteres

    while (linea[i] != '\0' && linea[i] != '\n') { //mientras que el caractear sea diferente al nulo y no haya salto de linea
        if (!isdigit(linea[i])) {
            return 0; // si devuelve o es porque encuntra algo que no es nmero
        }
        i++; //reviso el siguiente caracter
    }

    return 1; // Sí es número
}

int main() {
    char linea[100];

    // Leer línea por línea desde stdin (entrada estándar)
    while (fgets(linea, 100, stdin) != NULL) {
        if (esNumero(linea)) {
            // Si la funcion devuelve 1, se escribe dentro del char linea
            printf("Número: '%s'", linea);
        } else { //si devuelve cerp
            //no es un número válido: lo escribeen stderr
            fprintf(stderr, "Error - Línea inválida: '%s'", linea);
        }
    }

    return 0;
}
