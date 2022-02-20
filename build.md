# Building ShellArchero

Esse arquivo contém um passo a passo para replicar o game em seu computador, após a compilação o game estará em ./build/.

## Windows

- Instale o [MinGW](https://www.mingw-w64.org/) e o gcc nas variáveis de ambiente;
- Instale o [Windows Terminal](https://www.microsoft.com/pt-br/p/windows-terminal/9n0dx20hk701?SilentAuth=1&wa=wsignin1.0#activetab=pivot:overviewtab).
  O jogo utiliza [ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code#24-bit) definidos pela norma [ISO/IEC 6429](https://www.ecma-international.org/publications-and-standards/standards/ecma-48/) de 1991, apenas com esse novo console é possível usar esse recurso no Windows, em outros sistemas operacionais esse padrão já é usado a bastante tempo;
- Execute no terminal:
  ```console
  make windows
  ```
- O caso queira executar o programa utilize comando: (**lembrando de usar o Windows Terminal para a execução**)
  ```console
  make runWindows
  ```

## Linux

- Instale a lib curses com:

  ```console
  sudo apt-get install libncurses5-dev libncursesw5-dev
  ```

- Instale o gcc, na maioria já vêm instalado na própria distro;
- Execute no terminal:

  ```console
  make
  ```

- Para executar basta usar o comando:
  ```console
  make run
  ```
- Caso queira compilar o código para Windows basta instalar:
  ```console
  sudo apt-get install mingw-w64
  ```
  - E executar:
    ```console
    make windowsLinux
    ```

# Para devs

Contém um passo a passo para permitir o desenvolvimento do game, está habilitado flags para gerar alarmes se houver problemas no código.

Para limpar o build basta executar:

```console
make clear
```

## Windows dev

- Para compilar execute no terminal:
  ```console
  make devWindows
  ```

## Linux

- Para compilar execute no terminal:
  ```console
  make dev
  ```
- Caso queira utilizar o Valgrind para ter uma melhor avaliação contra vazamentos de memória, instale o Valgrind com:
  ```console
  sudo apt-get install valgrind.
  ```
  - Para invocá-lo:
    ```console
    make valgrind
    ```
