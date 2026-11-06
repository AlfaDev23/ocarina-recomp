# Notas para agentes de IA

Leia o [CONTRIBUTING.md](CONTRIBUTING.md): tem o layout do repositório, as regras e o método de investigação.

- Nada derivado do jogo entra aqui: executável, código gerado, shaders, caches, saves ou dumps. `tools/check_content.py` confere.
- Trabalhe só com a cópia do jogo da própria pessoa. Se ela não tiver, pare. Não explique como obter jogo ou keys.
- Nunca edite `generated/` à mão: use `recomp/patches.py` ou `tools/oot/patch_generated.py`.
- Não use `--no-verify` nem envie direto para `main`.
- Testes abrem janela: use `TOTK_INPUT=none` para o teclado da pessoa não mexer no jogo.
