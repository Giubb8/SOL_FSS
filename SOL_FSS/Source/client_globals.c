
#define MAXPATH 100 //lunghezza del path massimo per raggiungere la socket
#define MAXNAME 100

/*Struct*/

int f_flag=0;//flag per vedere se socketname settata 2 volte
int p_flag=0;//flag per abilitare le stampe per le operazioni
int x_flag=0;//flag per uscita dal programma
int w_flag=0;//flag per scrittura serve per -D
int r_flag=0;//flag per lettura serve per -d
int D_flag=0;//flag per vedere se e' stata settata la dirname
int d_flag=0;//flag per vedere se e' stata settata la dirname per lettura
char socketname[MAXNAME]; //nome della socket
char overload_dir_name[MAXNAME];//nome della directory dove vengono messi i file che provocano overload
char d_overload_dir_name[MAXNAME];//nome della directory per gestire overload per opzione -d
int conn_set=0;//flag per vedere se la connessione con il server è attiva 
int wait_time=100;//tempo di attesa tra richieste successive,associato a -t
int fd_socket=-1;//file descriptor della socket
char * separator="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
char * opseparator="-------------------------------------------------------------------------------------------\n";