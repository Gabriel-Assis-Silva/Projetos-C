#include <stdio.h>  // Includes standard input/output library
#include <string.h>

// Function declaration: takes a string and a shift value
void shiftAlphabet  (char shiftedAlphabet[], int shift);
void applyAP        (char shiftedAlphabet[], char newAlphabet[], int progress);
void encryptText    (char cipher[], char newAlphabet[], int shift);

void shiftAlphabet(char shiftedAlphabet[], int shift) {
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 26; i++) {
        // A lógica é simples, vamos até 26, e a cada ciclo, obtemos o valor atual do i e aplicamos o shift.
		shiftedAlphabet[i] = alphabet[(i + shift) % 26];
        // com o i + shift, obtemos a posição especifica do caractére A[0], B[1], C[2], D[3], E[4]
        // Com shift 2 -> Y[0] Z[1] A[2] B[3] C[4] D[5] E[6]
        // O % permite o valor voltar para 0 e acima caso ultrapasse 26:
        // shift 3 -> Y[24 + 3] > Y[0] {25 -> 26 -> 0}
	}

	shiftedAlphabet[26] = '\0'; // Corrigimos o alfabeto modificado adicionado o null character no final
}

void applyAP(char shiftedAlphabet[], char newAlphabet[], int progress) {
	int used[26] = {0};
	int index = 0;

	// Para criar o alfabeto novo, precisamos adicionar os characteres validos que cai na posição do AP
    // Vamos com um AP de 2
    
    // i = 2 - 1 (1); 1 < 26 -> true; i = 1 + 2 
	for (int i = progress-1; i < 26; i += progress) {
        // newAlphabet[0] = shiftedAlphabet[1] [B ou outra palavra shifted]
        // newAlphabet[1] = shiftedAlphabet[3] [D ou outra palavra shifted]
		newAlphabet[index++] = shiftedAlphabet[i];
        //used[1] = 1;
		used[i] = 1;
	}
	
    // Se a palavra não for usada, adiciona no novo alphabeto com a posição depois das palavras corretas.
	for (int i = 0; i < 26; i++) {
		if (!used[i]) {
			newAlphabet[index++] = shiftedAlphabet[i];
		}
	}
	
	newAlphabet[26] = '\0';
}

void encryptText(char cipher[], char newAlphabet[], int shift) {
    // Utilizamos um truque com os caracteres para cifrar o texto
    // Ele mantem que a parte da cifra é acima ou igual a 'A' e menor ou igual a 'Z', 
    // já que esses dois caracteres tem valores relevantes para a condição
    // Não tem como eu conseguir explicar bem oque o código está fazendo, 
    // essa é a parte mais complexa do código
	int len = strlen(cipher);
	for (int i = 0; i < len; i++) {
		if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
			int originalIndex = cipher[i] - 'A'; 
			cipher[i] = newAlphabet[originalIndex];
		}
	}
}

int main() {
    // Começamos por aqui
	char cipher[50];
	int shift, progress;
	char shiftedAlphabet[27];
	char newAlphabet[27]; // Alfabeto + 1 -> ("\0")
	
    // Por enquanto aceitamos só as letras maiúsculas, isso limita a um alfabeto de 26 caracteres.
	printf("Enter text in CAPITAL LETTERS ONLY: "); 

	scanf("%s", cipher);
	
	printf("Shift (1-10): ");
	scanf("%d", &shift);
	
	printf("Arithmetic progression value: ");
	scanf("%d", &progress);
	// ^^^^^^^^ Obtemos valores necessários como o shift, e o P.A

	shiftAlphabet(shiftedAlphabet, shift); // Primeiro vamos fazer um shift com o alfabeto que queremos modificar
	applyAP(shiftedAlphabet, newAlphabet, progress); // Depois vamos aplicar a P.A
	
	printf("Shifted Alphabet: %s\n", shiftedAlphabet);
	printf("Custom Alphabet after AP: %s\n", newAlphabet);
	
	encryptText(cipher, newAlphabet, shift);
	
	printf("Encrypted Text: %s\n", cipher);
	
	return 0;
}