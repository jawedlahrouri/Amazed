[![Academic Year](https://img.shields.io/badge/Epitech-Tek1-blue?style=for-the-badge&logo=epitech&logoColor=white)](https://www.epitech.eu/)
[![Language: C](https://img.shields.io/badge/Language-C-00599C.svg?style=for-the-badge&logo=c)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Module](https://img.shields.io/badge/Module-B--CPE--200-informational?style=for-the-badge)](#)

# 🐜 Amazed — Résolveur de Labyrinthe & Routage de Graphes (Lem-In)

**Amazed** est un moteur de résolution de graphes et de routage de flux en C (problème du *Lem-In*). L'objectif est de faire transiter un nombre défini de fourmis d'une salle initiale (`##start`) vers une salle de sortie (`##end`) à travers un réseau de tunnels dans un nombre minimal de tours, sans jamais que deux fourmis ne se croisent ou n'occupent la même salle intermédiaire simultanément.

---

## 🧠 Algorithmes & Structures de Données

- **Parsing de Graphe** :
  - Détection du nombre initial de fourmis.
  - Enregistrement des salles avec leurs coordonnées (`nom x y`) et des balises spéciales `##start` et `##end`.
  - Construction des liaisons bidirectionnelles (tunnels `salleA-salleB`).
- **Représentation Matricielle & Files** :
  - Matrice d'adjacence (`matrice_t`) pour tester rapidement les connexions entre nœuds.
  - File d'attente FIFO (`queue_t`) pour le parcours en largeur (BFS - *Breadth-First Search*).
- **Recherche de Chemins Disjoints** :
  - Détermination de multiples chemins optimaux non bloquants pour maximiser le débit de fourmis par tour.
- **Simulation Tour par Tour** :
  - Ordonnancement du déplacement des fourmis sur la sortie standard au format strict `P<id_fourmi>-<nom_salle>`.

---

## 🛠️ Compilation & Utilisation

```bash
make        # Génère le binaire 'amazed'
make clean  # Supprime les fichiers objets temporaires
make fclean # Nettoie tous les artefacts de compilation
make re     # Recompile le projet

./amazed < maze.txt
```

### Exemple de Format de Sortie :
```text
#start
0 1 0
#rooms
1 5 0
2 9 0
#end
3 13 0
#tunnels
0-1
1-2
2-3
#moves
P1-1
P1-2 P2-1
P1-3 P2-2
P2-3
```
