#include<stdio.h>
#include<stdlib.h>

#define MAXSTRLEN 255
typedef unsigned char String[MAXSTRLEN + 1];//0号单元存放串的长度


bool StrAssign(String& T, char* chars)
{
	int i ;
	for (i = 1;*chars!='\0';i++,chars++)
		T[i] = *chars;
	T[i] = '\0';
	T[0] = i - 1;
	if (i - 1 > 255) return false;
	return true;
}

//S复制得到T
bool StrCopy(String& T, String S)
{
	int i;
	if (!int(S[0])) return false;
	for ( i = 1;i <= int(S[0]);i++)
		T[i] = S[i];
	T[i] = '\0';
	T[0] = i - 1;
	return true;
	
}

int Strlength( String T)
{
	return int(T[0]) ;
}

bool StrEmpty(String S)
{
	if (int(S[0]) > 0) return true;
	else return false;
}

int StrCompare(String S, String T)
{
	for (int i = 1;i <= int(S[0]) && i <= int(T[0]);++i)
		if (S[i] != T[i]) return S[i] - T[i];
	return int(S[0]) - int(T[0]);
}

//bool SubString(char* &Sub, String S, int pos, int len)
//{
//	return;
//}

void Concat(String& T, String S1, String S2)
{
	int i;
	if (int(S1[0]) + int(S2[0]) <= MAXSTRLEN)
	{
		for ( i = 1;i <= int(S1[0]);i++)
			T[i] = S1[i];
		for (i = 1;i<int(S1[0]) + int(S2[0]);i++)
			T[i + int(S1[0])] = S2[i];
		T[0] =int(S1[0]) + int(S2[0]);
	}
	else if (int(S1[0]) < MAXSTRLEN)
	{
		for (i = 1;i <= int(S1[0]);i++)
			T[i] = S1[i];
		for (i = 1;i <= MAXSTRLEN-int(S1[0]);i++)
			T[i + int(S1[0])] = S1[i];
		T[0] = MAXSTRLEN;
	}
	else {
		for (i = 1;i <= MAXSTRLEN;i++)
			T[i] = S1[i];
	}
}

bool SubString(String& Sub, String S, int pos, int len)
{
	if (pos<1 || pos>Strlength(S) || len<0 || len>Strlength(S) - pos + 1)
		return false;
	for (int i = 1;i <= len;i++)
		Sub[i] = S[pos + i-1];
	Sub[0] = len;
	return true;
}

int Index(String S, String T, int pos)
{
	String sub;
	if (pos > 0)
	{
		int n = Strlength(S);
		int m = Strlength(T);
		int i = pos;
		while (i <= n - m + 1)
		{
			SubString(sub, S, i, m);
			if (StrCompare(sub, T) != 0) ++i;
			else return i;
		}
	}
	return 0;
}




int main()
{
	String a,s,T;
	char b[]= "dsskh";
	char c[] = "kh";
	StrAssign(a, b);
	StrAssign(s, c);
	printf("%d", Index(a, s, 2));

	//for(int i=1;i<=int(a[0]);i++)
	//   printf("%c", a[i]);
	//printf("\n\n");

	/*StrCopy(s, a);
	for (int i = 1;i <= int(s[0]);i++)
		printf("%c", s[i]);
	printf("%d", Strlength(s));
	putchar('\n');
	Concat(T, a, s);
	for (int i = 1;i <= MAXSTRLEN;i++)
		printf("%c", T[i]);*/

}
