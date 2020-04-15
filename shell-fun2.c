/**
 * _strcmp - compares strs like library strcmp
 *
 * @s1: main str compared too
 *
 * @s2: str compard to s1
 *
 * Return: s1 - s2
 *
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
		{
			break;
		}

	}

	return (s1[i] - s2[i]);
}
/**
* *_strcat - concatenates strings
* @dest: destination string to be concatenated to
* @src: source string to concatenate
*
* Return: destination string that has been concatenated to
*/
char *_strcat(char *dest, char *src)
{
	int len1;
	int len2;

		for (len1 = 0; dest[len1] != '\0'; len1++)
		{
			continue;
		}
		for (len2 = 0; src[len2] != '\0'; len2++, len1++)
		{
		dest[len1] = src[len2];
		}
	return (dest);
}
/**
* _strlen - returns length of string
* @str: string input
*
* Return: length
*/
int _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		continue;
	}
	if (i > 0)
	{
		return (i);
	}
	return (0);
}
/**
* _strdup - duplicates a string
* @str: string input
*
* Return: null, or string
*/
char *_strdup(char *str)
{
	char *p = NULL;
	int i;
	int len;

	if (str == NULL || str == 0)
		return (p);

	char *narr = (char *)malloc(len + 1);

	if (narr == NULL)
	{
		return (p);
	}

	len = _strlen(str);
	if (len > 0)
	{
		for (i = 0; i <= len; i++)
		{
			narr[i] = str[i];
		}
		return (narr);
	}
	return (p);
}
