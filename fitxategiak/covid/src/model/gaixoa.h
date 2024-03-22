#ifndef GAIXOA_H
#define GAIXOA_H

#define GAIXOA_MAX_STR 60

typedef enum e_GAIXOA_EMAITZA {
	GAIXOA_POSITIBOA = 'p',
	GAIXOA_NEGATIBOA = 'n',
	GAIXOA_ZALANTZA = 'z'
} GAIXOA_EMAITZA;

typedef struct s_GAIXOA {
	int id;
	char izena[GAIXOA_MAX_STR];
	char abizena[GAIXOA_MAX_STR];
	int adina;
	char herria[GAIXOA_MAX_STR];
	GAIXOA_EMAITZA emaitza;
} GAIXOA;

#endif
