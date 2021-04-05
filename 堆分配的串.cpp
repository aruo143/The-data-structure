#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	char* ch;
	int length;
}HString;

bool StrAssign(HString& T, char* chars)
{
	if (T.ch) free(T.ch);
	int i;
	char* c;
	for(i = 0, c = chars;*c;++i, ++c);
	if (!i) { T.ch = NULL;T.length = 0; }
	else {
		if(!(T.ch=(char*)malloc(i*sizeof(char))))
			return false;
		for (int j = 0;j <= i - 1;j++)
			T.ch[j] = chars[j];
		T.length = i;
	}
	return true;
}

int Strlength(HString S)
{
	return S.length;
}


int StrCompare(HString S, HString T)
{
	for (int i = 0;i < S.length && i < T.length;++i)
		if (S.ch[i] != T.ch[i]) return S.ch[i] - T.ch[i];
	return S.length - T.length;
}

void ClearString(HString& S)
{
	if (S.ch) { free(S.ch);S.ch = NULL; }
	S.length = 0;
}

bool Concat(HString& T, HString S1, HString S2)
{
	if (T.ch) free(T.ch);
	if (!(T.ch = (char*)malloc((S1.length + S2.length - 1) * sizeof(char)))) return false;
	for (int i = 0;i <= Strlength(S1);i++)
		T.ch[i] = S1.ch[i];
	T.length = Strlength(S1) + Strlength(S2);
	for (int i = Strlength(S1);i <= T.length - 1;i++)
		T.ch[i] = S2.ch[i];
	return true;
}

bool SubString(HString& Sub, HString S, int pos, int len)
{
	if (pos<1 || pos>S.length || len<0 || len>S.length - pos + 1)
		return false;
	if (Sub.ch) free(Sub.ch);
	if (!len) { Sub.ch = NULL;Sub.length = 0; }
	else
	{
		Sub.ch = (char*)malloc(len * sizeof(char));
		for (int i = 0;i <= len - 1;i++)
			Sub.ch[i] = S.ch[pos - 1 + i];
		Sub.length = len;
	}
	return true;
}
