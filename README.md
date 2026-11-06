# Ocarina Recomp

[Read in English](README.en.md)

**The Legend of Zelda: Ocarina of Time (Switch 2) rodando nativo no Windows, sem emulador.**

O código do jogo é traduzido para C e compilado como um programa do Windows. Os gráficos do Switch 2 são convertidos para Vulkan. Tudo isso acontece **no seu PC, a partir do seu próprio arquivo do jogo**.

> [!IMPORTANT]
> Este repositório **não contém o jogo, keys nem executável**, e não explica como obtê-los. Você precisa da sua própria cópia. O que a instalação gera (o `ocarina.exe`, o código gerado, o cache de shaders e os saves) sai do seu jogo: **não compartilhe**.

## Estado do projeto

Experimental. Só foi testado em **um PC** (Ryzen 9 9950X3D, RTX 5090), na região do início do jogo.

| O quê | Situação |
|---|---|
| Vilarejo Kokiri: árvores, plantas, casas, luz | ✅ Funciona |
| Som, controle, saves e vídeos | ✅ Funciona |
| Desempenho na RTX 5090 | ✅ Cerca de 59 fps parado, 51 a 55 fps caminhando |
| Travadinhas ao entrar em áreas novas | ⚠️ Ainda acontecem, principalmente na primeira vez |
| Tocar a ocarina | ❓ Correção aplicada, ainda sem teste em jogo |
| Hyrule Field e o resto do jogo | ❓ Ainda não testados |
| Placas AMD e Intel | ❓ Nunca testadas |

## Como instalar

Você não precisa digitar nenhum comando.

1. Baixe o **[Instalar-Ocarina.bat](https://github.com/sostenesfreitas/ocarina-recomp/releases/latest/download/Instalar-Ocarina.bat)**.
2. Dê dois cliques nele. Se o Windows avisar que protegeu o PC, clique em **Mais informações** e depois em **Executar assim mesmo**.
3. Na janela, escolha o arquivo `.nup` do seu jogo (ou uma pasta com `exefs` e `romfs`) e clique em **Instalar**.
4. Quando o Windows pedir permissão para instalar as ferramentas, clique em **Sim**.
5. No fim, clique em **Jogar**, ou use o atalho **Ocarina Recomp** na Área de Trabalho.

A instalação leva de 30 minutos a 2 horas, e você pode usar o PC enquanto isso. Se fechar a janela ou faltar luz, abra o instalador de novo: ele continua de onde parou. Para atualizar o jogo, é só rodar o instalador outra vez.

### Do que você precisa

- Windows 10 ou 11 de 64 bits, com processador compatível com AVX2.
- Placa de vídeo com Vulkan 1.3 e mesh shaders, com o driver atualizado. Recomendamos NVIDIA.
- 16 GB de RAM ou mais.
- 60 GB livres, mais uns 15 GB no disco C: se as ferramentas ainda não estiverem instaladas.
- Internet durante a instalação.
- **Sua cópia do jogo na versão 1.1.1.** Outras versões não funcionam.

### Se algo der errado

| Problema | O que fazer |
|---|---|
| O instalador parou com erro | Abra de novo: ele continua de onde parou e muitas vezes resolve sozinho |
| "Este jogo não é a versão 1.1.1" | Confira se escolheu o jogo certo e atualizado |
| O jogo abre e fecha | Atualize o driver da placa de vídeo e veja o arquivo `ultima-partida-erros.log` na pasta de instalação |
| Travadinhas na primeira vez | É normal: os shaders estão sendo preparados. Melhora quando você passa de novo pelo mesmo lugar |

Se continuar, [abra uma issue](https://github.com/sostenesfreitas/ocarina-recomp/issues) com o registro `%TEMP%\ocarina-instalador.log` e o modelo da sua placa de vídeo. Nunca envie arquivos do jogo.

### Controles

Use um controle ou teclado e mouse. **F1** ou **Esc** abre o menu de opções, **F11** alterna a tela cheia e **F10** mostra o fps. A lista completa está em [docs/controls.md](docs/controls.md).

## Como funciona

1. `recomp/gen.py` traduz o código ARM64 do jogo para C.
2. `tools/build_game.py` compila esse C junto com o `runtime/`, que faz o papel do sistema do console.
3. `runtime/` converte as chamadas gráficas NVN 2 para Vulkan.
4. Os shaders Ampere do Switch 2 são rebaixados para Maxwell (`lower_to_maxwell.h`) e traduzidos para SPIR-V por um Ryujinx com patches (`tools/xlate/patches`).

## Quer ajudar?

Leia o **[guia de contribuição](CONTRIBUTING.md)**. Testar em outras placas de vídeo e relatar o resultado já ajuda muito.

## Créditos

Projeto mantido por **Miojo** ([sostenesfreitas](https://github.com/sostenesfreitas)). Dizem que ele deixou um recado escondido no instalador e outro dentro do jogo. 🍜

Este projeto existe graças ao trabalho de muita gente:

- **[Lucas-blip-png/dkb-pc-recomp](https://github.com/Lucas-blip-png/dkb-pc-recomp)** e TotK Recomp: a base deste projeto, cujo histórico continua preservado aqui.
- **[seedds/nxnative](https://github.com/seedds/nxnative)**: referência de como o jogo usa task e mesh, e correção do microfone.
- **[zortos293/Lichii](https://github.com/zortos293/Lichii)** e Eglantine/Eden: o rebaixamento de shaders Ampere e a referência para comparar os draws.
- **[Ryujinx](https://github.com/Ryujinx/Ryujinx)**: o tradutor de shaders.
- **[kinnay/zbic](https://github.com/kinnay/zbic)**: descompressão do executável, baixada durante a instalação.

A lista completa está em [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Licença

[GPL-3.0](LICENSE), como o projeto original. Partes de terceiros mantêm as próprias licenças, listadas em [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

Projeto de fãs, sem nenhuma relação com a Nintendo. The Legend of Zelda e Ocarina of Time são marcas da Nintendo.
