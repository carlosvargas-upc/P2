PAV - P2: detección de actividad vocal (VAD) [MEMORIA DE LA PRACTICA ABAJO]
============================================

Esta práctica se distribuye a través del repositorio GitHub [Práctica 2](https://github.com/albino-pav/P2),
y una parte de su gestión se realizará mediante esta web de trabajo colaborativo.  Al contrario que Git,
GitHub se gestiona completamente desde un entorno gráfico bastante intuitivo. Además, está razonablemente
documentado, tanto internamente, mediante sus [Guías de GitHub](https://guides.github.com/), como
externamente, mediante infinidad de tutoriales, guías y vídeos disponibles gratuitamente en internet.


Inicialización del repositorio de la práctica.
----------------------------------------------

Para cargar los ficheros en su ordenador personal debe seguir los pasos siguientes:

*  Abra una cuenta GitHub para gestionar esta y el resto de prácticas del curso.
*  Cree un repositorio GitHub con el contenido inicial de la práctica (sólo debe hacerlo uno de los
  integrantes del grupo de laboratorio, cuya página GitHub actuará de repositorio central del grupo):
  -  Acceda la página de la [Práctica 2](https://github.com/albino-pav/P2).
  -  En la parte superior derecha encontrará el botón **`Fork`**. Apriételo y, después de unos segundos,
    se creará en su cuenta GitHub un proyecto con el mismo nombre (**P2**). Si ya tuviera uno con ese 
    nombre, se utilizará el nombre **P2-1**, y así sucesivamente.
*  Habilite al resto de miembros del grupo como *colaboradores* del proyecto; de este modo, podrán
  subir sus modificaciones al repositorio central:
  -  En la página principal del repositorio, en la pestaña **:gear:`Settings`**, escoja la opción 
    **Collaborators** y añada a su compañero de prácticas.
  -  Éste recibirá un email solicitándole confirmación. Una vez confirmado, tanto él como el
    propietario podrán gestionar el repositorio, por ejemplo: crear ramas en él o subir las
    modificaciones de su directorio local de trabajo al repositorio GitHub.
*  En la página principal del repositorio, localice el botón **Branch: master** y úselo para crear
  una rama nueva con los primeros apellidos de los integrantes del equipo de prácticas separados por
  guion (**fulano-mengano**).
*  Todos los miembros del grupo deben realizar su copia local en su ordenador personal.
  -  Copie la dirección de su copia del repositorio apretando en el botón **Clone or download**.
    Asegúrese de usar *Clone with HTTPS*.
  -  Abra una sesión de Bash en su ordenador personal y vaya al directorio **PAV**. Desde ahí, ejecute:

    ```.sh
    git clone dirección-del-fork-de-la-práctica
    ```

  -  Vaya al directorio de la práctica `cd P2`.

  -  Cambie a la rama **fulano-mengano** con la orden:

    ```.sh
    git checkout fulano-mengano
    ```

*  A partir de este momento, todos los miembros del grupo de prácticas pueden trabajar en su directorio
  local del modo habitual, usando el repositorio remoto en GitHub como repositorio central para el trabajo colaborativo
  de los distintos miembros del grupo de prácticas o como copia de seguridad.
  -  Puede *confirmar* versiones del proyecto en su directorio local con las órdenes siguientes:

    ```.sh
    git add .
    git commit -m "Mensaje del commit"
    ```

  -  Las versiones confirmadas, y sólo ellas, se almacenan en el repositorio y pueden ser accedidas en cualquier momento.

*  Para interactuar con el contenido remoto en GitHub es necesario que los cambios en el directorio local estén confirmados.

  -  Puede comprobar si el directorio está *limpio* (es decir, si la versión actual está confirmada) usando el comando
    `git status`.

  -  La versión actual del directorio local se sube al repositorio remoto con la orden:

    ```.sh
    git push
    ```

    *  Si el repositorio remoto contiene cambios no presentes en el directorio local, `git` puede negarse
      a subir el nuevo contenido.

      -  En ese caso, lo primero que deberemos hacer es incorporar los cambios presentes en el repositorio
        GitHub con la orden `git pull`.

      -  Es posible que, al hacer el `git pull` aparezcan *conflictos*; es decir, ficheros que se han modificado
        tanto en el directorio local como en el repositorio GitHub y que `git` no sabe cómo combinar.

      -  Los conflictos aparecen marcados con cadenas del estilo `>>>>`, `<<<<` y `====`. Los ficheros correspondientes
        deben ser editados para decidir qué versión preferimos conservar. Un editor avanzado, del estilo de Microsoft
        Visual Studio Code, puede resultar muy útil para localizar los conflictos y resolverlos.

      -  Tras resolver los conflictos, se ha de confirmar los cambios con `git commit` y ya estaremos en condiciones
        de subir la nueva versión a GitHub con el comando `git push`.


  -  Para bajar al directorio local el contenido del repositorio GitHub hay que ejecutar la orden:

    ```.sh
    git pull
    ```
  
    *  Si el repositorio local contiene cambios no presentes en el directorio remoto, `git` puede negarse a bajar
      el contenido de este último.

      -  La resolución de los posibles conflictos se realiza como se explica más arriba para
        la subida del contenido local con el comando `git push`.



*  Al final de la práctica, la rama **fulano-mengano** del repositorio GitHub servirá para remitir la
  práctica para su evaluación utilizando el mecanismo *pull request*.
  -  Vaya a la página principal de la copia del repositorio y asegúrese de estar en la rama
    **fulano-mengano**.
  -  Pulse en el botón **New pull request**, y siga las instrucciones de GitHub.


Entrega de la práctica.
-----------------------

Responda, en este mismo documento (README.md), los ejercicios indicados a continuación. Este documento es
un fichero de texto escrito con un formato denominado _**markdown**_. La principal característica de este
formato es que, manteniendo la legibilidad cuando se visualiza con herramientas en modo texto (`more`,
`less`, editores varios, ...), permite amplias posibilidades de visualización con formato en una amplia
gama de aplicaciones; muy notablemente, **GitHub**, **Doxygen** y **Facebook** (ciertamente, :eyes:).

En GitHub. cuando existe un fichero denominado README.md en el directorio raíz de un repositorio, se
interpreta y muestra al entrar en el repositorio.

Debe redactar las respuestas a los ejercicios usando Markdown. Puede encontrar información acerca de su
sintáxis en la página web [Sintaxis de Markdown](https://daringfireball.net/projects/markdown/syntax).
También puede consultar el documento adjunto [MARKDOWN.md](MARKDOWN.md), en el que se enumeran los
elementos más relevantes para completar la redacción de esta práctica.

Recuerde realizar el *pull request* una vez completada la práctica.

Ejercicios
----------

### Etiquetado manual de los segmentos de voz y silencio

- Grabe una señal de voz en la que haya distintos segmentos de voz y silencio. La señal debe ser de un
  solo canal (monofónica), grabada con una frecuencia de muestreo de 16 kHz y codificada con PCM lineal
  de 16 bits.

  Nombre a la señal como `pav_GGP#.wav`, donde GG es el grupo de clase (por ejemplo, 21 o 41), P es el
  número del puesto de trabajo y # es el número de señal (si sólo se entrega una señal, este número es
  1).

  > NOTA: es habitual que las grabaciones empiecen con un segmento de silencio de potencia extremadamente
  > bajo; mucho más bajo que el nivel de ruido normal durante el resto de la señal. Si esto ocurre, la
  > detección usando como nivel de referencia para el silencio el segmento inicial se ve seriamente
  > dificultada. Puede detectar esta situación visualizando el nivel de potencia estimado por el propio
  > `wavesurfer` y corregirla usando la herramienta de corte (:scissors:).

- Etiquete manualmente los segmentos de voz y silencio del fichero grabado al efecto. Inserte, a
  continuación, una captura de `wavesurfer` en la que se vea con claridad la señal temporal, el contorno de
  potencia y la tasa de cruces por cero, junto con el etiquetado manual de los segmentos.

- A la vista de la gráfica, indique qué valores considera adecuados para las magnitudes siguientes:

  * Incremento del nivel potencia en dB, respecto al nivel correspondiente al silencio inicial, para
    estar seguros de que un segmento de señal se corresponde con voz.

  * Duración mínima razonable de los segmentos de voz y silencio.

  * ¿Es capaz de sacar alguna conclusión a partir de la evolución de la tasa de cruces por cero?


### Desarrollo del detector de actividad vocal

- Complete el código de los ficheros de la práctica para implementar un detector de actividad vocal en
  tiempo real tan exacto como sea posible. Tome como objetivo la maximización de la puntuación-F `TOTAL`.

- Inserte una gráfica en la que se vea con claridad la señal temporal, el etiquetado manual y la detección
  automática conseguida para el fichero grabado al efecto. 

- Explique, si existen. las discrepancias entre el etiquetado manual y la detección automática.

- Evalúe los resultados sobre la base de datos `db.v4` con el script `vad_evaluation.pl` e inserte a 
  continuación las tasas de sensibilidad (*recall*) y precisión para el conjunto de la base de datos (sólo
  el resumen).


### Trabajos de ampliación

#### Cancelación del ruido en los segmentos de silencio

- Si ha desarrollado el algoritmo para la cancelación de los segmentos de silencio, inserte una gráfica en
  la que se vea con claridad la señal antes y después de la cancelación (puede que `wavesurfer` no sea la
  mejor opción para esto, ya que no es capaz de visualizar varias señales al mismo tiempo).

#### Gestión de las opciones del programa usando `docopt_c`

- Si ha usado `docopt_c` para realizar la gestión de las opciones y argumentos del programa `vad`, inserte
  una captura de pantalla en la que se vea el mensaje de ayuda del programa.


### Contribuciones adicionales y/o comentarios acerca de la práctica

- Indique a continuación si ha realizado algún tipo de aportación suplementaria (algoritmos de detección o 
  parámetros alternativos, etc.).

- Si lo desea, puede realizar también algún comentario acerca de la realización de la práctica que
  considere de interés de cara a su evaluación.


### Antes de entregar la práctica

Recuerde comprobar que el repositorio cuenta con los códigos correctos y en condiciones de ser 
correctamente compilados con la orden `meson bin; ninja -C bin`. El programa generado (`bin/vad`) será
el usado, sin más opciones, para realizar la evaluación *ciega* del sistema.

##
### MEMORIA PRACTICA PAV - P2: detección de actividad vocal 
##
Etiquetado manual de los segmentos de voz y silencio

![Captura WaveSurfer](img/WavesurferFoto.png)

A la vista de la gráfica y tras las pruebas empíricas realizadas con el código, considero adecuados los siguientes valores:

 - Incremento del nivel potencia en dB: Un incremento de entre 2 dB y 3 dB respecto al nivel de silencio inicial es suficiente para discriminar la voz si se usa un sistema de histéresis (doble umbral). Si se exige un valor mucho mayor, se pierden los principios y finales de las palabras.

 - Duración mínima razonable de los segmentos de voz y silencio: * Para la voz (inercia de subida / Hang-in): Unos 30 ms (3 tramas de 10 ms). Exigir menos hace que el sistema sea vulnerable a ruidos impulsivos (clicks).

 - Para el silencio (inercia de bajada / Hang-over): Unos 100 ms (10 tramas). Esta duración permite "puentear" las breves pausas oclusivas (como la pausa antes de soltar una "P" o una "T") sin cortar prematuramente la detección de voz.

 - Conclusión sobre la evolución de la tasa de cruces por cero (ZCR): La tasa de cruces por cero es vital para complementar a la potencia. Los fonemas fricativos sordos (como la /s/ o la /f/) tienen una potencia bajísima, casi a nivel del ruido de fondo, pero generan picos muy altos en la ZCR debido a su alta frecuencia. Sin la ZCR, estos fonemas se clasificarían erróneamente como silencio.

## Desarrollo del detector de actividad vocal

Comparativa entre el etiquetado manual y la salida automática del VAD.
Discrepancias entre etiquetado manual y automático: Las principales discrepancias suelen darse en las fronteras de las palabras. El etiquetado manual a menudo incluye el sonido de la respiración (inhalaciones previas a hablar) o deja un "colchón" de silencio visual por error humano. El detector automático, al regirse por umbrales matemáticos estrictos de energía y ZCR, ajusta el corte de forma mucho más ceñida a la fonética real. Además, los suspiros o exhalaciones suaves al final de una frase a veces son cortados por el algoritmo al caer por debajo del umbral de ruido adaptativo.


Evaluación de los resultados sobre la base de datos db.v4:
Los resultados obtenidos mediante el script vad_evaluation.pl con el código definitivo son los siguientes:

***************** Summary *****************
Recall V:568.17/590.75 96.18%   Precision V:568.17/630.38 90.13%   F-score V (2)  : 94.91%
Recall S:314.05/376.26 83.47%   Precision S:314.05/336.62 93.29%   F-score S (1/2): 91.15%
===> TOTAL: 93.007%

## Contribuciones adicionales y/o comentarios acerca de la práctica

Para conseguir un F-Score Total superior al 93%, se ha reescrito la máquina de estados y se han implementado múltiples mejoras combinadas respecto al diseño base propuesto:

 - Integración de ZCR condicionado a Suelo de Ruido: Se ha añadido la Tasa de Cruces por Cero (ZCR) como condición de actividad (||) para no perder consonantes fricativas. Para evitar que el ruido de cuantización o el ruido eléctrico en silencios profundos dispare el ZCR, se ha añadido una restricción: el ZCR solo es válido si la potencia del frame no cae por debajo de la potencia del ruido base (ZCR_NOISE_FLOOR_MARGIN = 0.0F).
 - Histéresis (Doble Umbral): Se ha diseñado una lógica de Schmitt Trigger. Se exige un umbral riguroso de potencia para transicionar de Silencio a Voz (thresh_p_on), pero se utiliza un umbral 2 dB más permisivo (HYSTERESIS_DB = 2.0F) para transicionar de Voz a Silencio (thresh_p_off). Esto evita el efecto de "tartamudeo" del VAD durante pequeñas caídas de energía.
 - Actualización Dinámica del Ruido (Background Noise Tracking): En lugar de fijar el ruido únicamente con las tramas iniciales (INIT_FRAMES), el sistema actualiza de forma progresiva el ruido de fondo (Potencia, ZCR y AM) cada vez que está firmemente en el estado ST_SILENCE, utilizando una tasa de olvido del 1% (NOISE_UPDATE_RATE = 0.01F). Esto permite al VAD adaptarse a grabaciones donde el entorno o el nivel de estática cambian con el tiempo.

 - Inclusión de la Magnitud de Amplitud (AM): Se ha incorporado también la energía AM calculada, empleando sus propios umbrales dinámicos (MULTIPLIER_AM = 5.0F), logrando mayor robustez ante fluctuaciones no lineales de la potencia.

	
