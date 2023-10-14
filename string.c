#include "shell.h"

/**
 * _strlen - returns the length of  string
<<<<<<< HEAD
 * @s: The string  length to check
=======
 * @s:  string  length to check
>>>>>>> f4dc7a8c11827f9484a607030a11b016775815f3
 *
 * Return: integer length  string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of 2 strings
<<<<<<< HEAD
 * @s1: The first  string
 * @s2: The second string
=======
 * @s1: first  string
 * @s2: second string
>>>>>>> f4dc7a8c11827f9484a607030a11b016775815f3
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks wether it starts with haystack
<<<<<<< HEAD
 * @haystack: The string to search
 * @needle: the substring to find
=======
 * @haystack: string to search
 * @needle: substring to find
>>>>>>> f4dc7a8c11827f9484a607030a11b016775815f3
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
<<<<<<< HEAD
 * @dest:  The destination buffer
 * @src:  The source buffer
=======
 * @dest:  destination buffer
 * @src:  source buffer
>>>>>>> f4dc7a8c11827f9484a607030a11b016775815f3
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
