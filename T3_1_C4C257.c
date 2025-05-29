#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *texto = NULL;  //Puntero al string
    char buffer[100];    //Buffer temporal para leer por partes, se utiliza en un ciclo
    char caracter; 
    int contador = 0;
    int len_total = 0;

    printf("Ingrese una cadena de texto:\n");

    //Ciclo que permite leer por partes el string usando fgets y pasando su contenido a un buffer temporal
    while (fgets(buffer, sizeof(buffer), stdin)) { //Mientras que no se encuentre un salto de linea, se lee desde el stdin y se guarda el string
        int len = strlen(buffer); //Guardamos la longitud total de la cadena antes de que encuentre el salto de lìnea

        //Se reserva o expande memoria para el texto acumulado
        char *nuevo = realloc(texto, (len_total + len + 1) * sizeof(char)); //Se pasa la direccion de memoria de texto y es +1 para el caracter '\0'
        if (nuevo == NULL) { //Se verifica que la memoria se haya signado correctamente
            printf("Error: no se pudo asignar memoria.\n");
            free(texto); //se libera la dirección de memoria
            return 1;
        }

        texto = nuevo; //actualizo al puntero para que apunte a la cadena de caracteres
        strcpy(texto + len_total, buffer); //Se empieza a copiar justo despues de lo ultimo que se añadió
        len_total += len; //Se actualiza el tamano total del buffer para poder copiar en la posiciòn correcta en cada iteracion

        //Si se detecta que el usuario presionó Enter, osea que hay un salto de lìnea, salimos
        if (buffer[len - 1] == '\n') {
            texto[len_total - 1] = '\0';  //quitar el salto de línea
            len_total--;
            break;
        }
    }

    printf("Ingrese el caracter que desea contar: ");
    scanf(" %c", &caracter);

    // Contar cada vez qye se topa al caracter
    for (int i = 0; i < len_total; i++) {
        if (texto[i] == caracter) {
            contador++;
        }
    }

    printf("El caracter '%c' aparece %d veces.\n", caracter, contador);

    // Imprimir el texto en orden inverso
    printf("Cadena invertida: ");
    for (int i = len_total - 1; i >= 0; i--) {
        putchar(texto[i]);
    }
    printf("\n");

    free(texto);  // Liberar la memoria usada
    return 0;
}
