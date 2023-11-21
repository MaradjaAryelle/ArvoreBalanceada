#include <iostream>

using namespace std;

struct NoArvore {
    int data;
    NoArvore *esquerda;
    NoArvore *direita;
};

void preOrdem(NoArvore *raiz) {
    if (raiz != NULL) {
        cout << raiz->data << " ";
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int altura(NoArvore *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsq = altura(raiz->esquerda);
    int alturaDir = altura(raiz->direita);

    if (alturaEsq > alturaDir) {
        return alturaEsq + 1;
    } else {
        return alturaDir + 1;
    }
}

bool arvoreBalanceada(NoArvore *raiz) {
    if (raiz == NULL) {
        return true;
    }

    int alturaEsq = altura(raiz->esquerda);
    int alturaDir = altura(raiz->direita);

    int diferenca = alturaEsq - alturaDir;

    if (diferenca > 1 || diferenca < -1) {
        return false;
    }

    return arvoreBalanceada(raiz->esquerda) && arvoreBalanceada(raiz->direita);
}

int main(int argc, char** argv) {
    NoArvore *raiz = new NoArvore;
    raiz->data = 1;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    NoArvore *elementoEsquerda = new NoArvore;
    elementoEsquerda->data = 2;
    elementoEsquerda->esquerda = NULL;
    elementoEsquerda->direita = NULL;
    raiz->esquerda = elementoEsquerda;

    NoArvore *elementoDireita = new NoArvore;
    elementoDireita->data = 3;
    elementoDireita->esquerda = NULL;
    elementoDireita->direita = NULL;
    raiz->direita = elementoDireita;

    elementoEsquerda->esquerda = new NoArvore;
    elementoEsquerda->esquerda->data = 4;
    elementoEsquerda->esquerda->esquerda = NULL;
    elementoEsquerda->esquerda->direita = NULL;

    elementoEsquerda->direita = new NoArvore;
    elementoEsquerda->direita->data = 5;
    elementoEsquerda->direita->esquerda = NULL;
    elementoEsquerda->direita->direita = NULL;

    elementoDireita->esquerda = new NoArvore;
    elementoDireita->esquerda->data = 6;
    elementoDireita->esquerda->esquerda = NULL;
    elementoDireita->esquerda->direita = NULL;

    elementoDireita->direita = new NoArvore;
    elementoDireita->direita->data = 7;
    elementoDireita->direita->esquerda = NULL;
    elementoDireita->direita->direita = NULL;
    
    elementoEsquerda->esquerda->esquerda = new NoArvore;
    elementoEsquerda->esquerda->esquerda->data = 8;
    elementoEsquerda->esquerda->esquerda->esquerda = NULL;
    elementoEsquerda->esquerda->esquerda->direita = NULL; 

    preOrdem(raiz);

	/* PRA DESBALANCEAR COMENTA AS FOLHAS 6 E 7 QUE DÁ CERTO PRA TESTAR*/

    cout << "\nA arvore e balanceada? 1-Sim 0-Nao: " << arvoreBalanceada(raiz) << endl;

    return  0;
}
