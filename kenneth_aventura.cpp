/*
 * Jogo: O Roubo das Cartas
 * Autores: [Gabriel Perazza Fischer, Vinicius, Mathias Andino, Lucas Perazza Fischer]
 * Disciplina: [Algoritmos de Programacao]
 */
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Le numero inteiro; se o jogador digitar letra, pede de novo (evita loop infinito de erro).
int ler_int() {
    int valor;
    while (!(cin >> valor)) {
        cout << "Entrada invalida. Digite um numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

// Converte entrada para minusculas (so letras) para aceitar SIM, Sim, etc.
static string minusculas_simples(const string& s) {
    string r;
    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            r += static_cast<char>(c - 'A' + 'a');
        } else {
            r += c;
        }
    }
    return r;
}

// Aceita: sim, nao, s, n. Qualquer outra coisa -> pergunta de novo.
// Sempre devolve "sim" ou "nao" para o resto do codigo usar if (x == "sim").
string ler_sim_nao() {
    string bruto;
    while (true) {
        cin >> bruto;
        string t = minusculas_simples(bruto);
        if (t == "sim" || t == "s") {
            return "sim";
        }
        if (t == "nao" || t == "n") {
            return "nao";
        }
        cout << "Digite 'sim' ou 'nao' (ou 's' / 'n'): ";
    }
}

// void = funcao que nao retorna valor; so executa um bloco (cena da historia).
// Funcao para quando for lutar contra o ladrao
void cena_luta() {
    cout << "\nO ladrao percebe a chegada de Kenneth. Escolha um numero entre 1 a 5 para decidir o que fazer:\n";
    int r = ler_int();

    // if / else if: cada ramo e uma opcao do menu; else final = numero fora do esperado
    if (r == 1) {
        cout << "\nKenneth tenta fugir, mas o ladrao e mais rapido e o alcanca, imobilizando-o. O ladrao entao rouba os pertences de Kenneth e foge pela janela, deixando Kenneth ferido e assustado.\n";
    } else if (r == 2) {
        cout << "\nKenneth tenta lutar contra o ladrao, mas ele e mais forte e consegue domina-lo. O ladrao entao rouba os pertences de Kenneth e foge pela janela, deixando Kenneth ferido e assustado.\n";
    } else if (r == 3) {
        cout << "\nKenneth tenta se esconder, mas o ladrao e persistente e o encontra. O ladrao entao rouba os pertences de Kenneth e foge pela janela, deixando Kenneth ferido e assustado.\n";
    } else if (r == 4) {
        cout << "\nKenneth tenta gritar por ajuda, mas o ladrao e rapido e o silencia. O ladrao entao rouba os pertences de Kenneth e foge pela janela, deixando Kenneth ferido e assustado.\n";
    } else if (r == 5) {
        cout << "\nKenneth tenta negociar com o ladrao, oferecendo dinheiro ou objetos de valor em troca de sua seguranca. O ladrao nao aceita a oferta e continua a ameacar Kenneth e vai para cima dele, roubando seus pertences e fugindo pela janela, deixando Kenneth ferido e assustado.\n";
    } else {
        cout << "\nOpcao errada. O ladrao aproveita a hesitacao e domina Kenneth.\n";
    }

    cout << "Com Kenneth imobilizado, o ladrao consegue fugir com os pertences do Kenneth e o deixa ferido e assustado. Kenneth decide ir para o hospital para tratar seus ferimentos e "
            "depois ir para a delegacia registrar um boletim de ocorrencia, na esperanca de que a policia consiga encontrar o ladrao e recuperar seus pertences roubados.\n";
}

void cena_porta_casa() {
    cout << "\nIndo na casa do amigo, ele decide invadi-la.\n";
    int escolha = 0;

    // while: repete o menu ate sair com 3 ou 4; && = E (as duas condicoes precisam ser verdade para continuar o loop)
    while (escolha != 3 && escolha != 4) {
        cout << "\nEntradas possiveis: 1 = janela, 2 = porta da frente, 3 = porta dos fundos, 4 = desistir e afastar-se.\nDigite um numero:\n";
        escolha = ler_int();

        if (escolha == 1) {
            cout << "A janela: tentou abrir, porem estava trancada; mesmo aplicando forca, ela nao abria.\n";
        } else if (escolha == 2) {
            cout << "A porta da frente: tentou chegar perto e abrir, porem estava trancada; nao quis bater para nao alertar quem estava la dentro.\n";
        } else if (escolha == 3) {
            cout << "A porta dos fundos: o pit bull que Kenneth sempre teve medo estava a solta. Decidiu voltar.\n";
        } else if (escolha == 4) {
            cout << "Kenneth congela: invadir a casa de um amigo, mesmo suspeito, nao parece mais o certo. Recua para a sombra da esquina.\n";
        } else {
            cout << "Opcao invalida. Digite numero do 1 ao 4.\n";
        }
    }

    cout << "\nCom janela e portas impossiveis de entrar, e a porta dos fundos sendo guardada pelo pit bull, as horas passam e fico cada vez mais ansioso, pois se tratava de algo muito importante. Sua unica pista, o chaveiro na mao; gritar ou arrombar so avisaria o culpado. "
            "Kenneth vai para a delegacia ao amanhecer, relata o roubo e a suspeita, e entrega o objeto. Com a investigacao, a policia encontra a colecao na casa do amigo. "
            "Kenneth recupera as cartas do pai entre alivio e dor: justica feita, mas a amizade que um dia parecia inquebravel fica em pedacos.\n";
}

// Texto do final emotivo (chamado depois do confronto com o amigo em certos ramos)
void final_memorias() {
    cout << "\nKenneth segura as cartas com cuidado, passando os dedos sobre o papel ja desgastado pelo tempo. "
            "Por um instante, todo o caos parece desaparecer. Aquilo nunca foi sobre valor, ele pensa. Era sobre memoria. "
            "Sobre presenca. Sobre tudo o que ainda restava do pai. Ele respira fundo, fecha os olhos por um breve segundo e toma sua decisao. "
            "Com um olhar firme, guarda as cartas e decide vende-las para ajudar o amigo. Nao porque elas perderam seu valor, mas porque, naquele momento, ajudar alguem tambem "
            "era uma forma de honrar tudo o que seu pai lhe ensinou sobre generosidade e amizade. Ele sabe que, mesmo sem as cartas, as memorias e o amor por seu pai continuarao vivos dentro dele.\n";
}

void cena_esperar_amigo() {
    int escolha = 0;

    while (escolha != 1 && escolha != 2) {
        cout << "\nEscolha 1 ou 2:\n"
                "1 = gravar o amigo e levar as filmagens a delegacia\n"
                "2 = confrontar o amigo diretamente\n";

        escolha = ler_int();

        if (escolha == 1) {
            cout << "\nResolveu gravar o amigo e levar essas filmagens a delegacia para entrega-lo. "
                    "Com isso, Kenneth leva as filmagens a policia junto com os documentos que "
                    "comprovam sua posse sobre a valiosa colecao e, enfim, resolve o caso, "
                    "recuperando seus pertences e prendendo o culpado. Sem querer saber o motivo, "
                    "Kenneth se sente aliviado por ter conseguido recuperar suas coisas e por ter feito justica; "
                    "mesmo assim, uma duvida pairava sobre sua cabeca: a duvida do por que ele fez isso.\n";
            cout << "\nNas semanas seguintes, com as cartas de volta as maos, Kenneth folheia o album em silencio. "
                    "A justica foi feita; a amizade, talvez, nunca mais seja a mesma. Ele guarda o chaveiro como lembrete de que confiar e uma porta de dois lados.\n";
        } else if (escolha == 2) {
            cout << "\nAo encontrar o amigo, Kenneth o confronta diretamente sobre o roubo. O amigo hesita e acaba confessando que pegou as cartas. "
                    "Kenneth pressiona o amigo, querendo saber o motivo do roubo. "
                    "O amigo admite que fez isso por desespero, pois precisava de ajuda, "
                    "precisava ajudar um familiar doente e nao tinha mais saida; as cartas eram a unica coisa de valor que ele encontrou.\n";

            final_memorias();
        } else {
            cout << "Opcao invalida. Digite o numero 1 ou 2.\n";
        }
    }
}

void investigacao_amigo() {
    cout << "\nKenneth analisou o objeto com calma e viu que era um chaveiro que ele ja havia visto antes. "
            "Seu amigo usou em uma das vezes que sairam juntos para beber e conversar sobre essa colecao. "
            "Foi uma boa memoria que tiveram juntos. Em choque ao perceber que era do seu amigo, ele decidiu:\n\n"
            "Escolha um numero entre 1 e 3 para decidir o que fazer:\n"
            "1 = ir pessoalmente a casa do amigo\n"
            "2 = ir a casa do seu amigo e, sem que ele percebesse, aguardar ate a saida dele\n"
            "3 = ligar para o amigo e pedir uma conversa calma antes de acusar\n";

    int decisao = 0;
    // || = OU: repete enquanto o numero estiver fora do intervalo valido
    while (decisao < 1 || decisao > 3) {
        decisao = ler_int();

        if (decisao == 1) {
            cout << "\nPreciso de respostas o quanto antes, nao posso deixar ele ir com a unica lembranca de meu pai... partiu em direcao a casa do amigo.\n";
            cena_porta_casa();
        } else if (decisao == 2) {
            cena_esperar_amigo();
        } else if (decisao == 3) {
            cout << "\nKenneth respira fundo e marca um encontro. No cafe, o amigo chega nervoso; ao ver o chaveiro na mesa, desmorona e confessa. "
                    "A conversa e dolorosa, mas honesta.\n";
            cout << "O amigo volta a casa e traz de volta a pasta das cartas, tremulo. Kenneth recebe o que era do pai com os olhos marejados. "
                    "Ainda assim, explica que precisam ir juntos a delegacia: a confissao nao apaga o furto, mas ele ainda pode se entregar na hora de depor.\n";
            cout << "O amigo concorda, e juntos vao a delegacia. Kenneth se sente aliviado por ter conseguido recuperar suas coisas, mas a amizade que um dia parecia inquebravel fica em pedacos. "
                    "Com as cartas recuperadas, o caso fica encerrado, com o coracao partido em dois com a descoberta de que o amigo era o ladrao, volto para casa. Justica e piedade nunca caberam direito na mesma frase.\n";
        } else {
            cout << "Opcao invalida. Digite o numero 1, 2 ou 3.\n";
        }
    }
}

// Cena da madrugada; tem_celular vem do main (lembranca da escolha de pegar ou nao o celular)
void jogar_noite(int tem_celular) {
    cout << "\nAo me dirigir em direcao ao som, percebo que tudo esta baguncado: comodas destruidas, objetos fora do lugar e sinais claros de invasao. "
            "De repente, avisto um vulto na sala. Assustado, ajo rapidamente e me escondo no banheiro, que fica logo antes da sala, tentando permanecer em silencio.\n";

    cout << "\nProcurar por um telefone para ligar para a policia? (sim/nao ou s/n)\n";
    string resposta3 = ler_sim_nao();

    if (resposta3 == "sim") {
        if (tem_celular == 1) {
            cout << "Como agir com o celular?\n"
                    "1 = ligar imediatamente para o 190\n"
                    "2 = enviar mensagem silenciosa pedindo ajuda\n";
            int forma_contato = ler_int();
            cout << "\nSorte a sua! Voce lembra que havia pegado o seu celular la antes de dormir. Escondido no banheiro, voce envia uma mensagem rapida ao 190. A policia chega silenciosamente e rende o ladrao em flagrante!\n"
                    "Com a situacao sob controle, volte a dormir tranquilo, sabendo que as coisas acabaram bem e o ladrao foi preso.\n";

            if (forma_contato == 1) {
                cout << "A ligacao e curta e objetiva; voce quase e ouvido, mas consegue manter a calma.\n";
            } else if (forma_contato == 2) {
                cout << "A mensagem evita barulho e ajuda a manter sua posicao escondida.\n";
            } else {
                cout << "Na duvida, voce faz os dois: mensagem e ligacao rapida.\n";
            }
            return;
        } else {
            cout << "\nVoce tenta olhar o bolso, mas se lembra que nao pegou o celular para dormir e o deixou longe do alcance!\n";
            cout << "Sem o seu celular na mao, precisara arriscar buscar outra saida pela casa...\n";
        }

        cout << "\nQual comodo devo ir primeiro procurar um telefone fixo?\n";
        cout << "1 = No meio da confusao, lembro de um telefone fixo que tenho na cozinha. E muito arriscado mas pode salvar a situacao.\n";
        cout << "2 = Voltar ao quarto com seguranca e tentar ver do que se trata a situacao, pois nao tenho certeza do que esta acontecendo.\n";

        int resposta4 = ler_int();

        if (resposta4 == 1) {
            cout << "\nFoi por pouco mas consigo me esgueirar por entre os destrocos sem que ele me perceba. Consigo chegar ao telefone e ligar para a policia, "
                    "conseguindo ajuda antes que o problema piorasse. Com a situacao sob controle, volto a dormir tranquilo, sabendo que minhas coisas estao seguras e que o ladrao foi preso, "
                    "mas a duvida ainda me assombrava. Quem era? O que queria? Porque logo a minha casa?\n";
        } else if (resposta4 == 2) {
            cout << "\nAo ir para o quarto sem querer piso em um dos destrocos e o vulto talvez me perceba.\n";
            cena_luta();
        } else {
            cout << "Opcao invalida. O barulho aumenta e Kenneth perde tempo precioso.\n";
            cena_luta();
        }
    } else {
        cout << "\nEm meio a escuridao ele tenta observar pela fresta na porta e percebe a silhueta de alguem que ele nunca houvera conhecido. E entao, em meio a incerteza do que fazer, ao ver que nao tem escolha, decide tentar se aproximar.\n";
        cout << "\nEscolha um numero entre 1 e 2 para decidir o que fazer:\n";
        cout << "1 = Consigo me aproximar sem fazer barulho\n";
        cout << "2 = Nao tenho chance de me esconder, preciso agir agora\n";

        int resposta6 = ler_int();

        if (resposta6 == 1) {
            cout << "Me aproximo, vejo que em minha volta tudo esta quebrado: meu computador, minha TV... E na verdade a presenca era um homem encapuzado roubando. "
                    "Vejo que nao tenho escolha, sem que a presenca perceba. Escolha um numero entre 1 e 2 para decidir o que fazer:\n"
                    "1 = procurar algo para se defender\n"
                    "2 = cair na porrada\n";

            int resposta7 = ler_int();

            if (resposta7 == 1) {
                cout << "\nEm meio aos destrocos percebo um cabo de vassoura quebrado; sem fazer barulho desfiro um golpe nele.\n";
                cout << "\nO ladrao e pego de surpresa e tenta se defender. Aproveitando a oportunidade. Digite um numero entre 1 e 5 para decidir o que fazer:\n";

                int resposta8 = ler_int();

                if (resposta8 == 1) {
                    cout << "\nO golpe acerta o ladrao, que cai desorientado.\n";
                } else if (resposta8 == 2) {
                    cout << "\nO golpe acerta somente as pernas do ladrao e em seguida Kenneth o imobiliza.\n";
                } else if (resposta8 == 3) {
                    cout << "\nKenneth acerta a cabeca do ladrao que em seguida desmaia.\n";
                } else if (resposta8 == 4) {
                    cout << "\nNo escuro Kenneth acerta os joelhos do ladrao derrubando-o no chao e assim, imobilizando-o.\n";
                } else if (resposta8 == 5) {
                    cout << "\nKenneth com adrenalina a flor da pele acerta varios ataques um seguido do outro.\n";
                } else {
                    cout << "\nNa confusao, Kenneth ainda assim ganha tempo e domina o ladrao.\n";
                }

                cout << "Com o ladrao imobilizado, Kenneth consegue chamar a policia e com a situacao sob controle, volta a dormir tranquilo, sabendo que suas coisas estao seguras e que o ladrao foi preso.\n";
            } else if (resposta7 == 2) {
                cout << "\nSem a oportunidade de pegar um objeto para me defender, decido cair na porrada com o ladrao.\n";
                cena_luta();
            } else {
                cout << "\nA hesitacao entrega sua posicao.\n";
                cena_luta();
            }
        } else if (resposta6 == 2) {
            cout << "\nSem a oportunidade de pegar um objeto para me defender, decido cair na porrada com o ladrao.\n";
            cena_luta();
        } else {
            cout << "\nOpcao invalida. O susto toma conta e Kenneth age no impulso.\n";
            cena_luta();
        }
    }
}

void jogar_manha() {
    cout << "\nAcordou as 7h da manha, ainda sonolento. Olhou a sua volta e notou que tudo estava baguncado; resolveu ir a sala e percebeu que tinha sido roubado. "
            "Entre os furtos notou que faltava sua carissima colecao de cartas de Pokemon. Ligar para a policia? (sim/nao ou s/n)\n";
    string resposta = ler_sim_nao();

    if (resposta == "sim") {
        cout << "\nA policia ao chegar no local pergunta o que aconteceu. Kenneth explica o ocorrido, diz o que foi roubado e comenta que precisa das suas coisas o quanto antes, "
                "pois essas cartas alem de serem uma colecao valiosa, tambem sao um presente de seu falecido pai. "
                "A policia entao assume o caso e quanto a mim sigo com o coracao apertado pela unica lembranca de meu pai ter sido roubado, cabe apenas esperar. Mas quem fez isso? Por que logo minha colecao?\n";
    } else {
        cout << "\nPor se tratar de sua valiosa colecao, ele decide ir procurar pelo culpado sozinho. Com isso, ele vai investigar os comodos de sua casa na esperanca do ladrao ter deixado pistas para tras.\n";
        cout << "Entre os destrocos, encontra um chaveiro estranho no chao da sala, nao e dele.\n";
        investigacao_amigo();
    }
}

// main: ponto de entrada; o sistema chama esta funcao primeiro
int main() {
    cout << "Apos um dia dificil Kenneth foi para o quarto.\n";
    cout << "Antes de deitar, ele olha o celular sobre a gaveta. Voce deseja levar o celular para debaixo de seu travesseiro? (1 = Sim, 2 = Nao)\n";

    int tem_celular = 0;
    int decisao_celular = ler_int();

    if (decisao_celular == 1) {
        tem_celular = 1;
        cout << "Voce estica o braco, pega o celular e o guarda perto de si na cama.\n";
    } else {
        cout << "Voce decide apenas deitar e deixa o celular longe da cama.\n";
    }

    cout << "\nHoras depois, no meio da madrugada, Kenneth ouviu um barulho. Levantar para ver o que e?\n";
    cout << "Digite sua resposta (sim/nao ou s/n):\n";

    string resposta = ler_sim_nao();

    if (resposta == "sim") {
        jogar_noite(tem_celular);
    } else {
        jogar_manha();
    }

    cout << "\nFIM DE JOGO.\n";
    return 0;
}
