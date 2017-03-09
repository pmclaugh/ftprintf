#include "ft_printf.h"

char	*wint_to_str(wchar_t wint)
{
	char	*str;

	str = ft_memalloc(5);
	if (wint <= 0x7F)
	{
		str[0] = wint;
	}
	else if (wint <= 0x7FF)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
	}
	else if (wint <= 0xFFFF)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
	}
	else if (wint <= 0x10FFFF)
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
	}
	return (str);
}

char	*wstr_to_str(wchar_t *wstr)
{
	char *out;
	char *temp;
	char *ch;

	if(!wstr)
		return NULL;
	out = ft_strdup("");
	while(*wstr)
	{
		ch = wint_to_str(*wstr);
		temp = ft_strjoin(out, ch);
		free(out);
		free(ch);
		out = temp;
		wstr++;
	}
	return out;
}