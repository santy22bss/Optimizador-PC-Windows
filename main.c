#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <shellapi.h>
#include <ctype.h>    // Para tolower()
#include <psapi.h>    // Para funciones de procesos
#include <string.h>   // Para strcmp

// --- Definiciones de Colores para la Consola ---
#define COLOR_DEFAULT 7
#define COLOR_GREEN 10
#define COLOR_YELLOW 14
#define COLOR_RED 12
#define COLOR_CYAN 11
#define COLOR_MAGENTA 13
#define COLOR_BLUE 9
#define COLOR_WHITE 15

// --- Prototipos de Funciones ---
// Funciones de Utilidad General
void set_color(int color);
BOOL ask_for_confirmation(const char* message);
BOOL is_running_as_admin();
void show_success_message(const char* message);
void show_error_message(const char* message);
void pause_and_return_to_menu();

// Funciones del Menú
void print_main_menu();
void print_advanced_menu();
void run_easy_mode_wizard();

// Funciones de Limpieza y Optimizacion
void run_all_cleaning();
void clean_temp_files();
void clean_system_caches();
void empty_recycle_bin();
void clean_event_logs();
void reduce_memory();

// Funciones de Herramientas del Sistema
void run_disk_cleanup();
void run_startup_manager();
void show_system_info();
void optimize_drives();
void manage_restore_points();
void set_high_performance_power_plan();
void uninstall_programs_menu();
void run_winget_update();

// Funciones de Reparación
void run_dism_scan();
void run_sfc_scan();
void schedule_chkdsk();
void reset_network_settings();

// ===========================================================================
//                                    MAIN
// ===========================================================================
int main() {
    // Establece la página de códigos para poder mostrar algunos caracteres como '✓'
    SetConsoleOutputCP(437);
    SetConsoleTitle("Optimizador Profesional de PC v5.2");

    if (!is_running_as_admin()) {
        set_color(COLOR_RED);
        printf("Error: Este programa requiere privilegios de Administrador.\n");
        printf("Por favor, haz clic derecho sobre el ejecutable y selecciona 'Ejecutar como administrador'.\n");
        set_color(COLOR_DEFAULT);
        system("pause");
        return 1;
    }

    int choice;
    do {
        system("cls"); // Limpia la consola
        print_main_menu();

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        } else {
            while (getchar() != '\n');
        }

        switch (choice) {
            case 1:
                run_easy_mode_wizard();
                break;
            case 2: {
                int advanced_choice;
                do {
                    system("cls");
                    print_advanced_menu();

                    if (scanf("%d", &advanced_choice) != 1) {
                        while (getchar() != '\n');
                        advanced_choice = -1;
                    } else {
                        while (getchar() != '\n');
                    }

                    switch (advanced_choice) {
                        case 1: run_all_cleaning(); break;
                        case 2: clean_temp_files(); break;
                        case 3: clean_system_caches(); break;
                        case 4: empty_recycle_bin(); break;
                        case 5: clean_event_logs(); break;
                        case 6: reduce_memory(); break;
                        case 7: run_disk_cleanup(); break;
                        case 8: run_startup_manager(); break;
                        case 9: show_system_info(); break;
                        case 10: optimize_drives(); break;
                        case 11: manage_restore_points(); break;
                        case 12: set_high_performance_power_plan(); break;
                        case 13: uninstall_programs_menu(); break;
                        case 14: run_winget_update(); break;
                        case 15: run_dism_scan(); break;
                        case 16: run_sfc_scan(); break;
                        case 17: schedule_chkdsk(); break;
                        case 18: reset_network_settings(); break;
                        case 0: break;
                        default:
                            show_error_message("Opcion no valida. Por favor, intentalo de nuevo.");
                            break;
                    }
                    if (advanced_choice > 0 && advanced_choice <= 18) {
                        pause_and_return_to_menu();
                    }
                } while (advanced_choice != 0);
                break;
            }
            case 0:
                set_color(COLOR_CYAN);
                printf("\nGracias por usar el Optimizador. Saliendo...\n");
                break;
            default:
                show_error_message("Opcion no valida. Por favor, intentalo de nuevo.");
                pause_and_return_to_menu();
                break;
        }
    } while (choice != 0);

    set_color(COLOR_DEFAULT);
    return 0;
}

// ===========================================================================
//                       FUNCIONES DE UTILIDAD GENERAL
// ===========================================================================

void set_color(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

BOOL ask_for_confirmation(const char* message) {
    char response;
    set_color(COLOR_YELLOW);
    printf("\n[ ? ] %s (S/N): ", message);
    set_color(COLOR_DEFAULT);

    scanf(" %c", &response);
    while (getchar() != '\n');

    return (tolower(response) == 's');
}

BOOL is_running_as_admin() {
    BOOL fIsAdmin = FALSE;
    HANDLE hToken = NULL;
    TOKEN_ELEVATION elevation;
    DWORD dwSize;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
        if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &dwSize)) {
            fIsAdmin = elevation.TokenIsElevated;
        }
    }
    if (hToken) {
        CloseHandle(hToken);
    }
    return fIsAdmin;
}

void show_success_message(const char* message) {
    set_color(COLOR_GREEN);
    printf("\n[ %c ] %s\n", 251, message);
    set_color(COLOR_DEFAULT);
}

void show_error_message(const char* message) {
    set_color(COLOR_RED);
    printf("\n[ ! ] %s\n", message);
    set_color(COLOR_DEFAULT);
}

void pause_and_return_to_menu() {
    set_color(COLOR_DEFAULT);
    printf("\n\nPresiona cualquier tecla para volver al menu anterior...");
    system("pause > nul");
}

// ===========================================================================
//                             FUNCIONES DE MENÚ
// ===========================================================================

void print_main_menu() {
    set_color(COLOR_CYAN);
    printf("\n");
    printf(" +-------------------------------------------------------+\n");
    printf(" |          OPTIMIZADOR PROFESIONAL DE PC v5.2           |\n");
    printf(" +-------------------------------------------------------+\n");
    set_color(COLOR_DEFAULT);
    printf("\n Bienvenido. Por favor, elige un modo de operacion:\n\n");

    set_color(COLOR_GREEN);
    printf(" [1] Modo Asistente (Recomendado)\n");
    set_color(COLOR_DEFAULT);
    printf("     - Te guiare paso a paso para optimizar tu PC de forma segura.\n\n");

    set_color(COLOR_YELLOW);
    printf(" [2] Modo Avanzado\n");
    set_color(COLOR_DEFAULT);
    printf("     - Accede a todas las herramientas por separado (usuarios expertos).\n\n");

    set_color(COLOR_MAGENTA);
    printf(" [0] Salir\n\n");
    set_color(COLOR_WHITE);
    printf(" Elige una opcion: ");
    set_color(COLOR_DEFAULT);
}

void print_advanced_menu() {
    set_color(COLOR_CYAN);
    printf("\n +-------------------------+\n");
    printf(" |       MODO AVANZADO       |\n");
    printf(" +-------------------------+\n\n");

    set_color(COLOR_BLUE);
    printf(" +-- Tareas de Limpieza y Optimizacion ------------------+\n");
    set_color(COLOR_DEFAULT);
    printf(" | [ 1] Limpieza Total (Ejecuta 2, 3, 4, 5, 6)         |\n"); // <-- TEXTO ACTUALIZADO
    printf(" | [ 2] Limpiar archivos temporales                     |\n");
    printf(" | [ 3] Limpiar caches del sistema                      |\n");
    printf(" | [ 4] Vaciar Papelera de Reciclaje                    |\n");
    printf(" | [ 5] Limpiar Registros de Eventos                    |\n");
    printf(" | [ 6] Liberar Memoria RAM (Reducir Uso)               |\n");
    printf(" +-------------------------------------------------------+\n\n");


    set_color(COLOR_BLUE);
    printf(" +-- Herramientas del Sistema ---------------------------+\n");
    set_color(COLOR_DEFAULT);
    printf(" | [ 7] Liberador de espacio en disco                   |\n");
    printf(" | [ 8] Gestionar programas de inicio                   |\n");
    printf(" | [ 9] Mostrar informacion del sistema                 |\n");
    printf(" | [10] Optimizar unidades (Desfragmentar)              |\n");
    printf(" | [11] Gestionar puntos de restauracion                |\n");
    printf(" | [12] Plan de energia 'Alto Rendimiento'              |\n");
    printf(" | [13] Desinstalar programas (Panel Control)           |\n");
    printf(" | [14] Actualizar todas las apps (WinGet)              |\n");
    printf(" +-------------------------------------------------------+\n\n");

    set_color(COLOR_BLUE);
    printf(" +-- Herramientas de Reparacion -------------------------+\n");
    set_color(COLOR_DEFAULT);
    printf(" | [15] Reparar imagen de Windows (DISM)                |\n");
    printf(" | [16] Reparar archivos del sistema (SFC)              |\n");
    printf(" | [17] Programar ChkDsk al reiniciar                   |\n");
    printf(" | [18] Restablecer config. de red (Winsock)            |\n");
    printf(" +-------------------------------------------------------+\n\n");


    set_color(COLOR_MAGENTA);
    printf(" [0] Volver al Menu Principal\n\n");
    set_color(COLOR_WHITE);
    printf(" Elige una opcion: ");
    set_color(COLOR_DEFAULT);
}

void run_easy_mode_wizard() {
    system("cls");
    set_color(COLOR_CYAN);
    printf("\n +-----------------------------------------------+\n");
    printf(" |        ASISTENTE DE OPTIMIZACION DE PC        |\n");
    printf(" +-----------------------------------------------+\n");
    set_color(COLOR_DEFAULT);
    printf("\nHola! Te guiare a traves de varios pasos para mejorar el rendimiento de tu PC.\n");
    printf("Solo sigue las instrucciones y presiona 'S' para confirmar cada paso.\n\n");
    system("pause");

    system("cls");
    set_color(COLOR_YELLOW);
    printf("\n --- PASO 1: Liberar Memoria RAM ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Este paso le pide a Windows que recupere la memoria no utilizada de todos\n");
    printf("los programas, lo que puede hacer que el sistema se sienta mas rapido.\n");
    if (ask_for_confirmation("Quieres realizar esta optimizacion de memoria?")) {
        reduce_memory();
    } else {
        show_error_message("Optimizacion de memoria omitida por el usuario.");
    }
    pause_and_return_to_menu();

    system("cls");
    set_color(COLOR_YELLOW);
    printf("\n --- PASO 2: Limpieza General ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Esta tarea eliminara archivos temporales, caches, vaciara la papelera\n");
    printf("y limpiara registros para liberar espacio y mejorar el rendimiento.\n");
    if (ask_for_confirmation("Quieres realizar esta limpieza general?")) {
        run_all_cleaning();
    } else {
        show_error_message("Limpieza general omitida por el usuario.");
    }
    pause_and_return_to_menu();

    system("cls");
    set_color(COLOR_YELLOW);
    printf("\n --- PASO 3: Comprobar y Reparar Windows ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Este paso revisara si hay archivos de sistema danados y los intentara\nreparar automaticamente.\n");
    set_color(COLOR_RED);
    printf("\nADVERTENCIA: Este proceso puede tardar (15-30 min) y no debe interrumpirse.\n");
    if (ask_for_confirmation("Quieres iniciar la comprobacion y reparacion de Windows?")) {
        run_dism_scan();
        printf("\n");
        run_sfc_scan();
    } else {
        show_error_message("Reparacion del sistema omitida por el usuario.");
    }
    pause_and_return_to_menu();

    system("cls");
    set_color(COLOR_YELLOW);
    printf("\n --- PASO 4: Recomendacion Final ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Hemos terminado con las tareas automaticas!\n\n");
    printf("Como ultimo paso, te recomiendo revisar que programas se inician con tu PC.\n");
    printf("Muchos programas se inician solos y hacen que el arranque sea mas lento.\n");
    if (ask_for_confirmation("Quieres abrir ahora el gestor de programas de inicio?")) {
        run_startup_manager();
        printf("\nBusca en la lista programas que no necesites y deshabilitalos.\n");
    }

    printf("\n\n");
    set_color(COLOR_GREEN);
    printf("[ %c ] Asistente de optimizacion finalizado! Tu PC deberia funcionar mejor.\n", 251);
    set_color(COLOR_DEFAULT);
    pause_and_return_to_menu();
}

// ===========================================================================
//                  FUNCIONES DE LIMPIEZA Y OPTIMIZACIÓN
// ===========================================================================

void run_all_cleaning() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Ejecutando Limpieza Total ---\n\n");
    set_color(COLOR_DEFAULT);

    // --- LÓGICA ACTUALIZADA ---
    reduce_memory(); // Ejecuta la opción 6
    printf("\n");
    clean_temp_files(); // Ejecuta la opción 2
    printf("\n");
    clean_system_caches(); // Ejecuta la opción 3
    printf("\n");
    empty_recycle_bin(); // Ejecuta la opción 4
    printf("\n");
    clean_event_logs(); // Ejecuta la opción 5

    show_success_message("Todas las tareas de limpieza han sido completadas!");
}

void clean_temp_files() {
    set_color(COLOR_YELLOW);
    printf("--- Limpiando Archivos Temporales ---\n");
    set_color(COLOR_DEFAULT);
    printf("Limpiando carpeta Temp del Sistema...\n");
    system("del /f /s /q %systemroot%\\temp\\*.* > nul 2>&1");
    printf("Limpiando carpeta Temp del Usuario...\n");
    system("del /f /s /q %USERPROFILE%\\AppData\\Local\\Temp\\*.* > nul 2>&1");
    show_success_message("Limpieza de temporales finalizada.");
}

void clean_system_caches() {
    set_color(COLOR_YELLOW);
    printf("--- Limpiando Caches del Sistema ---\n");
    set_color(COLOR_DEFAULT);
    printf("Limpiando carpeta Prefetch...\n");
    system("del /f /s /q %systemroot%\\Prefetch\\*.* > nul 2>&1");
    printf("Limpiando cache de DNS...\n");
    system("ipconfig /flushdns > nul 2>&1");
    printf("Limpiando cache de Miniaturas...\n");
    system("del /f /s /q /a:h %USERPROFILE%\\AppData\\Local\\Microsoft\\Windows\\Explorer\\thumbcache_*.db > nul 2>&1");
    printf("Limpiando cache de Windows Update...\n");
    system("net stop wuauserv > nul 2>&1");
    system("del /f /s /q %windir%\\SoftwareDistribution\\Download\\*.* > nul 2>&1");
    system("net start wuauserv > nul 2>&1");
    show_success_message("Limpieza de caches finalizada.");
}

void empty_recycle_bin() {
    set_color(COLOR_YELLOW);
    printf("--- Vaciando Papelera de Reciclaje ---\n");
    set_color(COLOR_DEFAULT);
    printf("Vaciando papelera para todos los usuarios...\n");
    system("powershell.exe -NoProfile -Command \"Clear-RecycleBin -Force -ErrorAction SilentlyContinue\" > nul 2>&1");
    show_success_message("Papelera de reciclaje vaciada.");
}

void clean_event_logs() {
    set_color(COLOR_YELLOW);
    printf("--- Limpiando Registros de Eventos ---\n");
    set_color(COLOR_DEFAULT);
    printf("Limpiando registros de eventos (esto puede tomar un momento)...\n");
    system("for /F \"tokens=*\" %%1 in ('wevtutil.exe el') DO wevtutil.exe cl \"%%1\" > nul 2>&1");
    show_success_message("Registros de eventos limpiados.");
}

void reduce_memory() {
    DWORD aProcesses[1024], cbNeeded, cProcesses;
    unsigned int i;

    set_color(COLOR_YELLOW);
    printf("--- Liberando Memoria RAM ---\n");
    set_color(COLOR_DEFAULT);
    printf("Optimizando el uso de memoria de los procesos en ejecucion...\n");

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
        show_error_message("Error: No se pudo obtener la lista de procesos.");
        return;
    }

    cProcesses = cbNeeded / sizeof(DWORD);
    int success_count = 0;
    int fail_count = 0;

    for (i = 0; i < cProcesses; i++) {
        if (aProcesses[i] != 0) {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_SET_QUOTA, FALSE, aProcesses[i]);
            if (NULL != hProcess) {
                if (EmptyWorkingSet(hProcess)) {
                    success_count++;
                } else {
                    fail_count++;
                }
                CloseHandle(hProcess);
            } else {
                fail_count++;
            }
        }
    }

    printf("Resultado: %d procesos optimizados, %d fallaron (normal para procesos del sistema).\n", success_count, fail_count);
    show_success_message("Optimizacion de memoria RAM completada.");
}


// ===========================================================================
//                   FUNCIONES DE HERRAMIENTAS DEL SISTEMA
// ===========================================================================

void run_disk_cleanup() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Ejecutando Liberador de Espacio en Disco ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Se abrira la herramienta de Windows. Sigue las instrucciones.\n");
    printf("Asegurate de seleccionar 'Limpiar archivos de sistema' para una limpieza profunda.\n\n");
    system("cleanmgr.exe");
    show_success_message("Proceso del Liberador de espacio en disco finalizado.");
}

void run_startup_manager() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Gestionar Programas de Inicio ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Se abrira la configuracion de 'Aplicaciones de inicio'.\n");
    printf("Desde alli puedes deshabilitar programas para acelerar el arranque.\n\n");
    system("start ms-settings:startupapps");
    show_success_message("Herramienta de gestion de inicio abierta.");
}

void show_system_info() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Informacion del Sistema ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Mostrando informacion detallada de tu sistema. Espera un momento...\n\n");
    system("systeminfo");
    show_success_message("Informacion del sistema mostrada.");
}

void optimize_drives() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Optimizando Unidades de Disco ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Se abrira la herramienta de Optimizacion de Unidades.\n");
    printf("Selecciona la unidad (ej: C:) y haz clic en 'Optimizar'.\n\n");
    system("dfrgui.exe");
    show_success_message("Proceso de optimizacion de unidades finalizado.");
}

void manage_restore_points() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Gestionar Puntos de Restauracion ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Se abrira la ventana de 'Propiedades del Sistema'.\n");
    printf("Desde aqui puedes gestionar el espacio y eliminar puntos de restauracion.\n\n");
    system("systempropertiesprotection");
    show_success_message("Ventana de gestion de puntos de restauracion abierta.");
}

void set_high_performance_power_plan() {
    set_color(COLOR_YELLOW);
    printf("--- Configurando Plan de Energia a 'Alto Rendimiento' ---\n");
    set_color(COLOR_DEFAULT);
    printf("Cambiando el plan de energia para priorizar el rendimiento...\n");
    system("powercfg /setactive 8c5e7fd1-ce92-4676-88a9-ed4fdc738965 > nul");
    show_success_message("Plan de energia configurado a 'Alto Rendimiento'.");
}

void uninstall_programs_menu() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Desinstalar Programas ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Se abrira el Panel de Control en 'Programas y caracteristicas'.\n");
    printf("Desde alli, puedes desinstalar los programas que ya no necesites.\n\n");
    system("control appwiz.cpl");
    show_success_message("Panel de control de programas abierto.");
}

void run_winget_update() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Actualizando todas las aplicaciones con WinGet ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Buscando y aplicando actualizaciones para todos los programas instalados.\n");
    printf("Este proceso puede tardar varios minutos y requiere conexion a internet.\n");
    set_color(COLOR_RED);
    printf("No cierres esta ventana hasta que el proceso finalice.\n\n");
    set_color(COLOR_DEFAULT);
    system("winget upgrade --all --accept-package-agreements --accept-source-agreements");
    show_success_message("Proceso de actualizacion con WinGet completado.");
}


// ===========================================================================
//                        FUNCIONES DE REPARACIÓN
// ===========================================================================

void run_dism_scan() {
    set_color(COLOR_YELLOW);
    printf("--- Iniciando reparacion de imagen de Windows (DISM) ---\n");
    set_color(COLOR_DEFAULT);
    printf("Esto puede tomar bastante tiempo y requiere conexion a internet.\n");
    printf("No cierres esta ventana hasta que el proceso finalice.\n\n");
    system("DISM /Online /Cleanup-Image /RestoreHealth");
    show_success_message("Proceso DISM completado.");
}

void run_sfc_scan() {
    set_color(COLOR_YELLOW);
    printf("\n--- Escaneando y reparando archivos del sistema (SFC) ---\n");
    set_color(COLOR_DEFAULT);
    printf("Esto escaneara los archivos protegidos y reemplazara los corruptos.\n");
    printf("No cierres esta ventana hasta que el proceso finalice.\n\n");
    system("sfc /scannow");
    show_success_message("Escaneo SFC completado.");
}

void schedule_chkdsk() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Programar Comprobacion de Disco (CHKDGITSK) ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("La comprobacion de disco (CHKDSK) busca y repara errores en el disco duro.\n");
    set_color(COLOR_RED);
    printf("Esta operacion se ejecutara en el proximo reinicio del sistema.\n\n");
    set_color(COLOR_DEFAULT);
    printf("Para programarla, abre una NUEVA TERMINAL COMO ADMINISTRADOR, escribe:\n\n");
    set_color(COLOR_CYAN);
    printf("  chkdsk C: /f /r\n\n");
    set_color(COLOR_DEFAULT);
    printf("Confirma con 'S' y luego REINICIA tu PC para que comience el proceso.\n");
    show_success_message("Instrucciones para CHKDSK mostradas.");
}

void reset_network_settings() {
    system("cls");
    set_color(COLOR_YELLOW);
    printf("--- Restableciendo Configuracion de Red (Winsock) ---\n\n");
    set_color(COLOR_DEFAULT);
    printf("Esta operacion restablece la configuracion de red de Windows a sus valores\n");
    printf("predeterminados. Es muy util para solucionar problemas de conexion a internet.\n");
    set_color(COLOR_RED);
    printf("\nADVERTENCIA: Se requerira un reinicio del sistema para completar la operacion.\n");

    if (ask_for_confirmation("Quieres restablecer la configuracion de red ahora?")) {
        system("netsh winsock reset");
        show_success_message("La configuracion de red ha sido restablecida.");
        set_color(COLOR_YELLOW);
        printf("Por favor, guarda tu trabajo y REINICIA tu computadora para aplicar los cambios.\n");
        set_color(COLOR_DEFAULT);
    } else {
        show_error_message("Operacion cancelada por el usuario.");
    }
}
