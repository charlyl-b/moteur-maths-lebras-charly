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

J’ai réalisé la première version simple du déplacement du joueur.

Que se passe-t-il lorsque plusieurs touches directionnelles sont maintenues simulta-
nément ? Le comportement obtenu vous paraît-il satisfaisant ?
Quand on appuie sur deux touches à la fois, le comportement n’est pas celui attendu.
Par exemple, quand on appuie sur bas et gauche, on s’attend à ce que le joueur parte en diagonal. Sauf qu’avec cette méthode, le joueur suit la direction du dernier input enclenché, donc si c’est l’input gauche, le joueur part à gauche. C’est problématique car ce n’est pas intuitif. Même chose si le joueur appuie sur deux directions opposés : elles sont censées s’annuler (et donc le joueur devient immobile), mais ce n’est pas le cas avec cette méthode.

Séance du 23/09/2026 - 10H30 à 12H30

Dans le code fourni initialement la fonction update() est appelée avec une vitesse
de l’ordre de 50 FPS (frames per second). Voyez-vous dans le code où est appelée cette fonction ? et où est défini le taux de 50 FPS ?

Dans le code fourni pour le SFML, il n’y a pas de fonction update(), mais une fonction show(). Elle crée la fenêtre, puis passe dans une boucle while qui s'exécute tant que la fenêtre \_window est ouverte. Il est possible de paramétrer un taux limite de FPS, avec la méthode SetFramerateLimit() de la classe sf::RenderWindow.

La seconde version du déplacement du joueur vient d’être terminée.
J’ai eu quelques soucis de compilation / exécution externe au code. Les modifications de code n’étaient pas prises en compte. J’ai donc tourné en rond pendant presque 45 minutes en ne voyant aucune différence sur les déplacements du joueur. C’est en relançant Visual Studio que le bug est parti, sans que je sache d’où il provenait.

Séance du 24/09/2026 - 8H15 à 10H15

(1) Pour la fonction affichée sur la figure 2, calculez une approximation discrète de la
dérivée pour les points tn, puis tn+1. Vous pouvez considérer que les pas de grille valent une unité.

La formule P’(t) =( P(n+1) - P(n) ) / ( t(n+1) - t(n) )
P’(tn) = ( P(n+1) - P(n) ) / 1 = P(n+1) - P(n)
P’(tn+1) = ( P(n+1) - P(n) ) / 1 = P(n+1) - P(n)

(2) On souhaite résoudre l’équation proposée ci-dessous. Déterminez la solution de cette équation (en considérant P(0) = 0), à l’aide de vos cours de maths des années précédentes.

P’(t) = 2
⇔ P(t) = 2t

(3) Approximez cette équation en remplaçant la dérivée continue par la dérivée discrète, en utilisant un pas de temps ∆t (vous pouvez prendre 1 seconde). Établir la relation de récurrence entre Pn+1 et Pn : quel type de suite obtenez-vous ?

P’(t) = 2
⇔ ( P(n+1) - P(n) ) / ∆t = 2
⇔ P(n+1) - P(n) = 2 \* ∆t
⇔ P(n+1) = 2∆t + P(n)
⇔ P(n+1) = P(n) + 2 (si on estime que ∆t = 1)

On obtient une suite arithmétique de raison 2

Séance du 25/09/2026 - 9H15 à 12H30

(1) Montrez que la solution proposée ci-dessus est bien solution de l’équation différentielle
proposée.

v(t) = G/k + A \* e^(-t/τ)

dv/dt = -A/τ * e^(-t/τ) = -(A*k/m) \* e^(-t/τ)

m _ dv/dt = m _ ( -(A*k/m) * e^(-t/τ) ) = -A*k * e^(-t/τ)

G - k*v = G - k*( G/k + A*e^(-t/τ) )
= G - G - k*A*e^(-t/τ)
= -k*A \* e^(-t/τ)

m*dv/dt = -A*k*e^(-t/τ) = G - k*v

(2) Déterminez la constante A de la solution donnée.
v(0) = G/k + A
v0 = G/k + A
⇔ - (G/k) + v0 = A

(3) Tracez la solution dans un tableur pour une masse de 1208 kg et un coefficient de
frottement de 1, 8 USI. Vous pouvez prendre une vitesse initiale de 0 m.s−1 et une propulsion de 100 m.s−2
(4) Vers quelle vitesse se stabilise le joueur, d’après la forme de la solution ? de la courbe tracée ? cette vitesse d’équilibre vous semble-t-elle cohérente ?
Quand t devient très grand, le joueur se stabilise à une vitesse limite égale à G/k. C’est cohérent car à cette vitesse la propulsion et le frottement se compense, donc le joueur n’accélère plus. On remarque sur la courbe une asymptote horizontale autour de 55m/s.

(5) Rajoutez une seconde courbe avec un coefficient de frottement de 0, 65 SI (joueur au profil aérodynamique plus performant). Comment la forme de la courbe est-elle modifiée ? (vitesse à l’équilibre, variation de la vitesse)
Quand le coefficient de frottement est à 0.65, le joueur monte plus vite en vitesse au début, et se stabilise un peu plus haut (150m/s). C’est aussi cohérent car si le joueur est moins freiné par l’air, alors il peut accélérer davantage avant que le frottement se rapproche de la propulsion du joueur.

(6) Le coefficient τ est appelé temps caractéristique : que se passe-t-il à ce temps pour les 2 cas étudiés ? pour la solution théorique ?
