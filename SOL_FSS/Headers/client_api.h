#pragma once
#include<stdbool.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

/**
 * Apre una connessione verso il server tramite la socket indicata.
 *
 *  sockname - nome della socket a cui connettersi
 *  msec - intervallo in ms dopo il quale si tenta la riconnessione
 *  abstime - al raggiungimento del tempo di timeout si interrompe il tentativo di connessione
 *  0 se OK, -1 in caso di errore, setta errno opportunamente
 */
int openConnection(const char* sockname, int msec, const struct timespec abstime);

/**
 *  Chiude la connessione verso il server tramite la socket indicata
 *
 *  sockname - nome della socket da cui disconnettersi
 *  0 se Ok, -1 in caso di errore, setta errno opportunamente
 */
int closeConnection(const char* sockname);
/**
 * Apre il file sul server
 * pathname - file da aprire
 * flags - modalità di apertura
 * 0 se OK, -1 in caso di errore, setta errno opportunamente
 */
int openFile(char* pathname, int flags);

/**
 * Legge il contenuto del file dal server
 *
 * pathname - nome del file da leggere
 * buf - buffer dove memorizzare il contenuto
 * size - dimensione del contenuto ricevuto in bytes
 * 0 se OK, -1 in caso di errore, setta errno opportunamente. In caso di errore buf e size non sono validi
 */
int readFile(const char* pathname, void** buf, size_t* size);

/**
 * Legge N files dal server
 *
 * N - Numero di file da leggere
 * dirname - eventuale cartella dove memorizzare i file letti
 * 0 se OK, -1 in caso di errore, setta errno opportunamente.
 */
int readNFiles(int N, const char* dirname);

/**
 * Scrive nel server il contenuto del file e salva nella cartella dirname eventuali file espulsi
 *
 * pathname - nome del file da scrivere
 * dirname - cartella in cui salvare eventuali file espulsi
 * 0 se Ok, -1 in caso di errore, setta errno opportunamente
 */
int writeFile(const char* pathname, const char* dirname);

/**
 * Scrive il contenuto dentro buf in aggiunta al file pathname sul server.
 * Salva nella cartella eventuali file espulsi
 *
 * pathname - nome del file a cui aggiungere il contenuto
 * uf - contenuto da aggiungere
 * size - dimensione del contenuto in bytes
 * dirname - cartella in cui salvare eventuali file espulsi
 * 0 se Ok, -1 in caso di errore, setta errno opportunamente
 */
int appendToFile(const char* pathname, void* buf, size_t size, const char* dirname);

/**
 * Acquisisce la mutua esclusione sul file
 *
 * pathname - file su cui acquisire la mutua esclusione
 * 0 se Ok, -1 in caso di errore, setta errno opportunamente
 */
int lockFile(const char* pathname);


/**
 * Rilascia la mutua esclusione sul file
 *
 * pathname - file su cui rilasciare la mutua esclusione
 * 0 se Ok, -1 in caso di errore, setta errno opportunamente
 */
int unlockFile(const char* pathname);

/**
 * Chiude il file nel server
 *
 * pathname - file da chiudere
 * 0 e Ok, -1 in caso di errore, setta errno opportunamente
 */
int closeFile(const char* pathname);

/**
 * Cancella il file dal server
 * pathname - file da rimuovere
 * se Ok, -1 in caso di errore
 */
int removeFile(const char* pathname);

