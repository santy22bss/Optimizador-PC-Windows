 Windows System Optimizer v5.2
Windows System Optimizer es una herramienta de mantenimiento integral de código abierto diseñada para centralizar las tareas de limpieza, optimización y reparación del sistema operativo Windows en una interfaz de consola ligera y eficiente.

 * Contexto del Proyecto
Este software fue desarrollado como parte de mi formación en la Licenciatura en Ciberseguridad. El objetivo principal es la exploración práctica de:

Interacción de bajo nivel con Windows: Uso de la API nativa y comandos de administración.

Seguridad de Procesos: Gestión de memoria y privilegios de ejecución.

Automatización de Tareas: Centralización de comandos complejos en un entorno controlado.

Nota: Este es un proyecto de desarrollo personal con fines educativos y de optimización propia. Representa una fase de experimentación con flujos de trabajo AI-Assisted (Vibe Coding) para acelerar el ciclo de vida del desarrollo.

* Características Principales
El optimizador se divide en tres pilares fundamentales:

- Limpieza Profunda: Eliminación de archivos temporales (System y User), limpieza de caché de DNS, vaciado de caché de miniaturas y eliminación de registros de eventos antiguos.

- Optimización de Rendimiento: * RAM: Implementación de la API EmptyWorkingSet para liberar memoria no utilizada por procesos activos.

- Energía: Configuración instantánea del plan de "Alto Rendimiento".

WinGet: Automatización de actualizaciones de software mediante el Gestor de Paquetes de Windows.

- Reparación y Salud: Acceso directo a herramientas de bajo nivel como DISM (Image Repair), SFC (System File Checker), CHKDSK y restablecimiento de Winsock para solucionar problemas de red.

- Metodología: Vibe Coding & AI-Collaboration

A diferencia del desarrollo tradicional centrado en la sintaxis mecánica, este software fue construido mediante un flujo de iteración conversacional e ingeniería de prompts.

¿Qué significa esto en este proyecto?

Visión sobre Sintaxis: El enfoque principal fue la arquitectura de la solución y la experiencia del usuario, delegando la implementación de boilerplate a modelos de lenguaje avanzados.

Refactorización Ágil: La UI (ASCII ART y manejo de colores) y la lógica de "Limpieza Total" fueron refinadas mediante ciclos rápidos de feedback humano-IA.

* Detalles Técnicos
Lenguaje: C
IDE: Code::Blocks
Compilador: GCC (MinGW)
APIs Utilizadas: * windows.h: Manejo de consola, colores y privilegios.
psapi.h: Optimización de memoria de procesos.
shellapi.h: Ejecución de comandos del sistema.

* Instalación y Uso *
Clona el repositorio:

Bash
git clone https://github.com/tu-usuario/Optimizador-PC-Windows.git
Abre el archivo .cbp en Code::Blocks.

Compila el proyecto (F9).

IMPORTANTE: El ejecutable generado DEBE iniciarse con privilegios de Administrador para que las herramientas de sistema (DISM, SFC, WinGet) funcionen correctamente.

** Aviso Legal (Disclaimer) **
Esta herramienta interactúa con archivos críticos del sistema y configuraciones de red. Aunque ha sido diseñada siguiendo las mejores prácticas de seguridad, el autor no se hace responsable por cualquier pérdida de datos o inestabilidad del sistema causada por el uso de este software. Úsalo bajo tu propio riesgo.

Desarrollado por Santiago Moyano.
