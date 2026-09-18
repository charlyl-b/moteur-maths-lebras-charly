CHARLY LE BRAS

DOCUMENT DE SUIVI INDIVIDUEL

Séance du 09/09/2026 - 8H15 à 10H15
J’ai commencé les exercices du TP de révisions. J’ai priorisé ceux qui ont un lien avec le moteur de jeu.

Séance du 10/09/2026 - 13H45 à 15H45
J’ai continué les exercices du TP de révisions.

Séance du 10/09/2026 -16h00 à 17H00
J’ai continué et terminé les exercices du TP de révisions.

Séance du 14/09/2026 - 8H15 à 10H15
J’ai commencé par choisir la bibliothèque graphique que j’utiliserai pour réaliser le projet, parmi celles proposées dans le sujet.
J’ai sélectionné SFML pour plusieurs raisons :
J’ai déjà utilisé Qt tout au long de mon stage de deuxième année, ainsi que durant la formation. J’ai donc envie de découvrir de nouvelles technologies, plutôt que de risquer de revoir des choses que je connais déjà.
Le sujet décrit SFML comme étant la solution la plus complexe mais aussi la plus adaptée au sujet. En général les outils les plus complexes sont souvent ceux qui offrent le plus de liberté et de fonctionnalité. Donc si vers la fin du projet, j’ai le temps de faire mes propres extensions facultatives, je pense que SFML sera la solution la plus avantageuse sur ce point.

J’ai ensuite essayé d’importer cette bibliothèque. Je n’ai pas rencontré trop de difficultés, car j’avais déjà importé des bibliothèques de chiffrement en utilisant des CMakeLists. Le seul problème que j’ai rencontré vient du fait que j’avais installé une version de SFML supérieur à 3. Le CMakeLists.txt fourni exige SMFL 2.5

Séance du 14/09/2026 - 13H45 à 15H45

J’ai relu complètement le sujet ainsi que les livrables attendues, pour que tout soit plus clair pour moi. J’ai donc commencé à rédiger ce document durant cette séance.

Séance du 15/09/2026 - 10H30 à 12H30

(1) On note H la hauteur de l’écran en pixels et W sa largeur. Le monde physique sera
centré sur l’écran. Quelle est la position écran du centre du monde ?

(W/2, H/2), car en divisant par 2, on trouve le milieu d’une distance. Donc si l’on divise par 2 la largeur et la hauteur, on trouve respectivement le milieu de l’écran en x, et en y

(2) On note z le facteur de zoom, qu’on exprime en pixels par mètre. Pour une distance
d dans le monde physique, que vaut la distance D à l’écran ?

D = d\*z, car z est un facteur de zoom, en pixel/mètre. Par exemple si z = 10 pixels pour 1 pixel, et que d = 4 mètre alors d prendre 40 pixel à l’écran.

(3) Pour un point M de coordonnée horizontale x dans le monde physique, que vaut sa
coordonnée X dans le monde écran ?

X = W/2 + (x\*z). On sait que l’origine horizontale du monde physique est W/2, donc il suffit de partir de ce point, puis d’y ajouter la coordonnée x, multiplié par le facteur de zoom z, pour trouver la coordonnée X à l’écran.

(4) Inversement, connaissant X, comment retrouver x ?

On sait que X = W/2 + (x*z), donc on résout l’équation
⇔ X - (W/2) = x*z
⇔(X-W/2) / z = x

(5) Pour un point M de coordonnée verticale y dans le monde physique, que vaut sa
coordonnée Y dans le monde écran ? Attention : en général les bibliothèques graphiques
comptent les distances verticales à partir du haut de la fenêtre (l’axe des Y est donc
inversé !).

Y = H/2 - (y\*z). Même explication que la question 3, la seule différence est qu’on soustrait la multiplication position/facteur à cause de l’inversion de l’axe des Y.

(6) Inversement, connaissant Y , comment retrouver y ?

On sait que Y = H/2 - (y*z), donc on résout l’équation
⇔ Y - (H/2) = y*z
⇔ (Y-H/2) / -z = y
⇔ (H/2-Y) / z = y

J’ai commencé l’implémentation de toScreen, mais je ne vois pas comment représenter le facteur z (est-ce que ça doit être une valeur brut, ou alors une valeur qui s’adapte aux tailles de l’écran)
Séance du 18/09/2026 - 8H15 à 10H15

J’ai finis l’implémentation de toScreen et toPhysical,Je suis finalement parti sur une valeur du zoom en brut pour le moment (30 pixel / mètre).
Puis, j’ai réalisé des tests pour vérifier si le joueur se place correctement sur l’écran en fonction de la position physique donnée.

ScreenPoint pos = toScreen(WorldPoint(0, 0));
ScreenPoint pos = toScreen(WorldPoint(5, 0));
ScreenPoint pos = toScreen(WorldPoint(0, -5));
ScreenPoint pos = toScreen(WorldPoint(-5.2, 7.9));
circle.setPosition(pos.first - radius, pos.second - radius);

Pour se repérer, j’ai affiché les axes x et y avec une section \_DEBUG. Pour faire cela, j’ai dessiné des rectangles de la même manière que le cercle du joueur.

Séance du 18/09/2026 - 16H00 à 17H00
