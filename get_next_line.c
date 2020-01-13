/*
** EPITECH PROJECT, 2019
** MUL_my_runner_2019
** File description:
** get_next_line
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matchstick.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int replace(char *str, char a, char b)
{
    int found = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == a) {
            str[i] = b;
            found = 1;
        }
    return (found);
}

void shift_buffer(char *buffer, int buffer_size)
{
    int shift = 0;

    while (buffer[shift] != '\n')
        shift++;
    for (int i = 0; i < buffer_size - shift; i++) {
        buffer[i] = buffer[shift + i + 1];
    }
}

char *my_strcat(char **dest, char const *src)
{
    int len_src = my_strlen(src);
    int len_dest = *dest == NULL ? 0 : my_strlen(*dest);
    int index = 0;
    char *str = malloc(sizeof(char) * (len_dest + len_src + 1));

    if (!str)
        return (NULL);
    if (*dest != NULL)
        for (int i = 0; (*dest)[i] != '\0'; i++)
            str[i] = (*dest)[i];
    for (index = 0; src[index] != '\0'; index++)
        str[len_dest + index] = src[index];
    str[len_dest + index] = '\0';
    if (*dest != NULL)
        free(*dest);
    *dest = str;
    return (*dest);
}

char *get_next_line(int fd)
{
    static char buffer[READ_SIZE + 1] = {'\0'};
    char *next_line = NULL;
    int bytes_read = 0;

    if (fd < 0 || READ_SIZE < 0)
        return (NULL);
    my_strcat(&next_line, buffer);
    if (my_strcat(&next_line, buffer) == NULL)
        return (NULL);
    do {
        bytes_read = read(fd, buffer, READ_SIZE);
        if (bytes_read < 0)
            return (NULL);
        buffer[bytes_read] = '\0';
        my_strcat(&next_line, buffer);
        if (my_strcat(&next_line, buffer) == NULL)
            return (NULL);
    } while (!replace(next_line, '\n', '\0'));
    shift_buffer(buffer, (READ_SIZE + 1));
    return (next_line);
}