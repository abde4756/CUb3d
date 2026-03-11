# Instructions pour intégrer MiniLibX (MLX) et compiler

Ce projet utilise MiniLibX pour l'affichage graphique. Voici deux méthodes pour obtenir MLX sur Linux.

1) Cloner et construire une copie locale (recommandé pour 42/MLX Linux)

```bash
git clone https://github.com/42Paris/minilibx-linux.git mlx
cd mlx
make
cd ..
```

Cela crée `libmlx.a` et les headers dans `mlx/`. Le `Makefile` du projet inclut `-I./mlx` et `-lmlx -lX11 -lXext -lm`.

2) Installer via le gestionnaire de paquets (si disponible)

Sur certaines distributions il existe un paquet, ex:

```bash
sudo apt-get install libmlx-dev    # si disponible
```

Compilation du projet

Depuis la racine du projet (où se trouve ce `Makefile`) :

```bash
make
```

Si vous n'avez pas cloné MLX dans `./mlx`, vous pouvez compiler en indiquant l'include et le path vers la librairie :

```bash
gcc -o cub3 main.c graphic.c map.c parcing.c utils.c -I/path/to/mlx -L/path/to/mlx -lmlx -lX11 -lXext -lm
```

Notes
- Le fichier `cub3.h` inclut maintenant `mlx.h`. Assurez-vous que le header `mlx.h` est présent dans `./mlx` ou dans un path système.
- Si vous rencontrez des erreurs de compilation, collez-les ici et je vous aiderai à les corriger.

  Project developed as part of the 42 Network curriculum.
