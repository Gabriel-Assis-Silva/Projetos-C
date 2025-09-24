#include <stdio.h>
#include <string.h>

// Declaração prévia das funções
void shiftAlphabet(char shiftedAlphabet[], int shift);
void applyAP(char shiftedAlphabet[], char newAlphabet[], int progress);
void encryptText(char cipher[], char newAlphabet[], int shift);

/*
 * Função: shiftAlphabet
 * ---------------------
 * Gera um alfabeto deslocado (cifra de César), com base em um valor de "shift".
 *
 * shiftedAlphabet: vetor onde o alfabeto deslocado será armazenado.
 * shift: valor de deslocamento (por exemplo, shift=2 transforma A→C, B→D, ..., Z→B).
 */
void shiftAlphabet(char shiftedAlphabet[], int shift) {
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 26; i++) {
		// Aplica o deslocamento circularmente usando o operador módulo
		shiftedAlphabet[i] = alphabet[(i + shift) % 26];
	}

	// Adiciona o caractere nulo ao final para formar uma string válida
	shiftedAlphabet[26] = '\0';
}

/*
 * Função: applyAP
 * ---------------
 * Reorganiza o alfabeto deslocado com base em uma Progressão Aritmética (PA).
 * A nova ordem depende do "progress", o valor da PA.
 *
 * shiftedAlphabet: o alfabeto já deslocado (por Caesar).
 * newAlphabet: onde o novo alfabeto reorganizado será armazenado.
 * progress: valor da PA (por exemplo, progress=2 seleciona índices 1, 3, 5, ...).
 */
void applyAP(char shiftedAlphabet[], char newAlphabet[], int progress) {
	int used[26] = {0}; // Marca quais posições já foram usadas na PA
	int index = 0;

	if (progress <= 0) {
        progress = 1;
	}
	if (progress > 26) {
		printf("Valor PA muito alta! Isso resulta em 0 modificacoes no alfabeto! \n"); // E aqui se a pessoa colocar acima de 26, é como se fosse colocar 1 na PA, então avisamos o usuário sobre isso.
	}

	// 1ª Parte: adiciona letras da PA ao novo alfabeto
	for (int i = progress - 1; i < 26; i += progress) {
		newAlphabet[index++] = shiftedAlphabet[i];
		used[i] = 1;
	}

	// 2ª Parte: adiciona as letras restantes que não foram incluídas na PA
	for (int i = 0; i < 26; i++) {
		if (!used[i]) {
			newAlphabet[index++] = shiftedAlphabet[i];
		}
	}

	// Finaliza string com caractere nulo
	newAlphabet[26] = '\0';
}

/*
 * Função: encryptText
 * -------------------
 * Substitui cada letra do texto original pela letra correspondente no novo alfabeto.
 *
 * cipher: texto a ser cifrado (em letras maiúsculas).
 * newAlphabet: alfabeto reorganizado que será usado como base da substituição.
 * shift: não é usado aqui, mas mantido por compatibilidade.
 */
void encryptText(char cipher[], char newAlphabet[], int shift) {
	int len = strlen(cipher);

	for (int i = 0; i < len; i++) {
		// Só modifica letras maiúsculas (A-Z)
		if (cipher[i] >= 'A' && cipher[i] <= 'Z') {
			int originalIndex = cipher[i] - 'A'; // Converte letra em índice (A=0, B=1, ..., Z=25)
			cipher[i] = newAlphabet[originalIndex]; // Substitui pela letra correspondente no novo alfabeto
		}
	}
}

/*
 * Função principal: main
 * ----------------------
 * Lê o texto, aplica as transformações de alfabeto e cifra o texto.
 */
int main() {
	char cipher[50];               // Texto original (máx. 49 caracteres + '\0')
	int shift, progress;           // Parâmetros: deslocamento e valor da PA
	char shiftedAlphabet[26];      // Alfabeto deslocado (26 letras + '\0')
	char newAlphabet[26];          // Alfabeto reorganizado com base na PA

	// Solicita entrada do usuário
	printf("Enter text in CAPITAL LETTERS ONLY: ");
	scanf("%s", cipher);

	printf("Shift (1-10): ");
	scanf("%d", &shift);

	printf("Arithmetic progression value: ");
	scanf("%d", &progress);

	// Etapas de preparação
	shiftAlphabet(shiftedAlphabet, shift);           // Etapa 1: Gera o alfabeto com Caesar Shift
	applyAP(shiftedAlphabet, newAlphabet, progress); // Etapa 2: Reorganiza o alfabeto com base na PA

	// Mostra os alfabetos intermediários
	printf("Shifted Alphabet: %s\n", shiftedAlphabet);
	printf("Custom Alphabet after AP: %s\n", newAlphabet);

	// Etapa final: cifra o texto
	encryptText(cipher, newAlphabet, shift);

	// Mostra o resultado final
	printf("Encrypted Text: %s\n", cipher);

	return 0;
}
