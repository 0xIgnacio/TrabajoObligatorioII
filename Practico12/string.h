#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

const int MAX = 80;
typedef char * string;

void strcrear(string &s);
void strdestruir(string &s);
int strlar(string s);
void strcop(string &s1, string s2);
void scan(string &s);
void strcon(string &s1, string s2);
void strswp(string &s1, string &s2);
void print(string s);
boolean strmen(string s1, string s2);
boolean streq(string s1, string s2);

// ==================== Archivos ====================
void bajarString(string s, FILE *a);
void levantarString(string &s, FILE *a);

# endif