#include <stdio.h>
#include <stdbool.h>

#define CANAL_MINIMO 1
#define CANAL_MAXIMO 520
#define VOLUME_MINIMO 0
#define VOLUME_MAXIMO 100

// Estrutura que representa a TV
typedef struct {
    int canal;
    int ultimoCanal;
    int volume;
    bool ligada;
    bool mudo;
} TV;

// Liga a TV
void ligar(TV *tv) {
    tv->ligada = true;
    if (tv->ultimoCanal != 0)
        tv->canal = tv->ultimoCanal;
    printf("🔘 TV ligada no canal %d\n", tv->canal);
}

// Desliga a TV
void desligar(TV *tv) {
    tv->ligada = false;
    tv->ultimoCanal = tv->canal;
    printf("🔴 TV desligada.\n");
}

// Aumenta volume
void aumentarVolume(TV *tv) {
    if (tv->ligada && !tv->mudo) {
        if (tv->volume < VOLUME_MAXIMO) {
            tv->volume++;
            printf("🔊 Volume atual: %d\n", tv->volume);
        } else {
            printf("⚠ Volume já está no máximo!\n");
        }
    } else {
        printf("⚠ A TV está desligada ou mutada.\n");
    }
}

// Diminui volume
void diminuirVolume(TV *tv) {
    if (tv->ligada && !tv->mudo) {
        if (tv->volume > VOLUME_MINIMO) {
            tv->volume--;
            printf("🔉 Volume atual: %d\n", tv->volume);
        } else {
            printf("⚠ Volume já está no mínimo!\n");
        }
    } else {
        printf("⚠ A TV está desligada ou mutada.\n");
    }
}

// Ativa/desativa mudo
void ativarMudo(TV *tv) {
    if (tv->ligada) {
        tv->mudo = !tv->mudo;
        if (tv->mudo)
            printf("🔇 TV mutada.\n");
        else
            printf("🔈 Mudo desativado. Volume atual: %d\n", tv->volume);
    } else {
        printf("⚠ A TV está desligada.\n");
    }
}

// Próximo canal
void proximoCanal(TV *tv) {
    if (tv->ligada) {
        if (tv->canal < CANAL_MAXIMO)
            tv->canal++;
        else
            printf("⚠ Você já está no último canal!\n");

        printf("📺 Canal atual: %d\n", tv->canal);
    } else {
        printf("⚠ A TV está desligada.\n");
    }
}

// Canal anterior
void canalAnterior(TV *tv) {
    if (tv->ligada) {
        if (tv->canal > CANAL_MINIMO)
            tv->canal--;
        else
            printf("⚠ Você já está no primeiro canal!\n");

        printf("📺 Canal atual: %d\n", tv->canal);
    } else {
        printf("⚠ A TV está desligada.\n");
    }
}

// Mudar para canal específico
void irParaCanal(TV *tv, int novoCanal) {
    if (tv->ligada) {
        if (novoCanal >= CANAL_MINIMO && novoCanal <= CANAL_MAXIMO) {
            tv->canal = novoCanal;
            printf("📺 Canal alterado para: %d\n", tv->canal);
        } else {
            printf("⚠ Canal inválido! (1 a 520)\n");
        }
    } else {
        printf("⚠ A TV está desligada.\n");
    }
}

// Status da TV
void exibirStatus(TV *tv) {
    printf("\n📺 --- STATUS DA TV ---\n");
    printf("Ligada: %s\n", tv->ligada ? "Sim" : "Não");
    printf("Canal: %d\n", tv->canal);
    printf("Volume: %s\n", tv->mudo ? "MUDO" : (char[4]){ tv->volume + '0', 0 });
    printf("-----------------------\n\n");
}

int main() {
    TV tv = { CANAL_MINIMO, 0, 20, false, false };
    int opcao, canal;

    do {
        printf("========= MENU TV =========\n");
        printf("1 - Ligar TV\n");
        printf("2 - Desligar TV\n");
        printf("3 - Aumentar Volume\n");
        printf("4 - Diminuir Volume\n");
        printf("5 - Ativar/Desativar Mudo\n");
        printf("6 - Próximo Canal\n");
        printf("7 - Canal Anterior\n");
        printf("8 - Ir para Canal Específico\n");
        printf("9 - Exibir Status\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: ligar(&tv); break;
            case 2: desligar(&tv); break;
            case 3: aumentarVolume(&tv); break;
            case 4: diminuirVolume(&tv); break;
            case 5: ativarMudo(&tv); break;
            case 6: proximoCanal(&tv); break;
            case 7: canalAnterior(&tv); break;
            case 8:
                printf("Digite o canal (1-520): ");
                scanf("%d", &canal);
                irParaCanal(&tv, canal);
                break;
            case 9:
                exibirStatus(&tv);
                break;
            case 0:
                printf("👋 Encerrando o programa...\n");
                break;
            default:
                printf("⚠ Opção inválida!\n");
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}
