/*
** EPITECH PROJECT, 2023
** B-PDG-300-MPL-3-1-PDGD05-lysandra.manuguerra
** File description:
** string
*/

#ifndef STRING_H_
    #define STRING_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

typedef struct string_s {
    char *str;
    void (*assign_c) (struct string_s *, const char *);
    void (*assign_s) (struct string_s *, const struct string_s *);
} string_t;

// Exercice 0
void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
// Exercice 1
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *s);
// Exercice 2
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);
// Exercice 3
char func_at(const string_t *this, size_t pos);
// Exercice 4
void clear(string_t *this);
// Exercice 5
int length(const string_t *this);
// Exercice 6
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);

#endif /* !STRING_H_ */
