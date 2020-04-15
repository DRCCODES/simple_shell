#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
/**
* _memcpy - copies n bytes of src to dest
* @dest: the destination
* @src: the source
* @n: specifed bytes of data to copy
*
* Return: dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int lp;

	for (lp = 0; lp < n; lp++)
	{
		dest[lp] = src[lp];
	}
	return (dest);
}
/**
* _strlen - gets the length of a string
* @s: string being fed in
*
* Return: length
*/
int _strlen(char *s)
{
	if (*s != '\0')
	{
		return (_strlen(s + 1) + 1);
	}
	return (0);
}
/**
 * _strstr - finds the first occurrence of the substring
 * @haystack: str to search
 * @needle: chars to look for
 * Return: matched segment
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0;
	int j;
	int c = 0;
	char *k;

	while (haystack[i] != '\0')
	{
		j = 0;
		while (needle[j + c] != '\0' && haystack[i + c] != '\0'
		&& needle[j + c] == haystack[i + c])
		{
			if (haystack[i + c] != needle[j + c])
			{
				break;
			}
			c++;
		}
		if (needle[j + c] == '\0')
		{
			k = &haystack[i];
			return (k);
		}
			j++;
			i++;
	}
	return (0);
}
/**
* _strncpy - copies a string
* @dest: destination string
* @src: string to be copied
* @n: integer to represent bytes of dest to print
*
* Return: the copied string
*/
char *_strncpy(char *dest, char *src, int n)
{
	int len1;

	for (len1 = 0; len1 < n && src[len1] != '\0'; len1++)
	{
		dest[len1] = src[len1];
	}
	for (; len1 < n; len1++)
	{
		dest[len1] = '\0';
	}
	return (dest);
}
