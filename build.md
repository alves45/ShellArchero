# Building ShellArchero

Esse arquivo contém um passo a passo para replicar o game em seu computador, após o compilação o game irá estar em ./build.

## Windows

- Instale o [MinGW](https://www.mingw-w64.org/) e o gcc nas variáveis de ambiente
- Execute no terminal:
  ```console
  make windows
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
