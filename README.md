# 🐜 Amazed — Graph Pathfinding & Maze Solver

[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Module](https://img.shields.io/badge/Module-B--CPE--200-informational?style=for-the-badge)](#)
[![Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)](#)

## 📘 Description
**Amazed** est un algorithme de recherche de chemins et d'optimisation de flot dans un réseau de salles (labyrinthe). Le programme prend en entrée une description de réseau (salles de départ `##start`, d'arrivée `##end`, salles intermédiaires et tunnels) et calcule les trajectoires optimales pour déplacer un groupe de robots/fourmis de l'entrée à la sortie avec un minimum de tours d'horloge.

## ⚙️ Fonctionnalités
- Parsing robuste du format de fichier de labyrinthe (gestion des commentaires, coordonnées, commandes spéciales).
- Modélisation par graphe d'adjacence pondéré.
- Algorithme de recherche de chemins disjoints et calcul de flot maximal (BFS / Dijkstra / Edmonds-Karp).
- Ordonnancement sans collision : chaque salle ne peut contenir qu'un seul robot à la fois (sauf départ et arrivée).

## 🔨 Compilation & Utilisation
```bash
make
./amazed < maze.txt
```
